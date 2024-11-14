#include <windows.h>
#include <stdio.h>

struct file_node {
    char file_name[MAX_PATH];
    SYSTEMTIME creation_time;
    struct file_node* next;
};

struct folder {
    struct file_node* first;
    struct file_node* last;
};

SYSTEMTIME creation_local_time(FILETIME* ft) {
    SYSTEMTIME utc, local;
    FileTimeToSystemTime(ft, &utc);
    SystemTimeToTzSpecificLocalTime(NULL, &utc, &local);
    return local;
}

void init(struct folder* fld, const char* directory_path) {
    fld->first = fld->last = NULL;

    WIN32_FIND_DATA findFileData;
    HANDLE hFind;

    char search_path[MAX_PATH];
    snprintf(search_path, MAX_PATH, "%s\\*", directory_path);

    wchar_t wSearch_path[MAX_PATH];
    if (MultiByteToWideChar(CP_ACP, 0, search_path, -1, wSearch_path, MAX_PATH) == 0) {
        printf("Error converting search path to wide characters. Error: %lu\n", GetLastError());
        return;
    }
    hFind = FindFirstFile(wSearch_path, &findFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Failed to open directory: %s. Error: %lu\n", directory_path, GetLastError());
        return;
    }

    do {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            continue;  // Skip directories
        }

        struct file_node* newfile = (struct file_node*)malloc(sizeof(struct file_node));
        if (!newfile) {
            perror("Failed to allocate memory");
            break;
        }

        #ifdef UNICODE
        // Convert `wchar_t` to `char` if Unicode is enabled
        WideCharToMultiByte(CP_ACP, 0, findFileData.cFileName, -1, newfile->file_name, MAX_PATH, NULL, NULL);
        #else
        // Direct copy if `findFileData.cFileName` is already a `char` array
        strncpy(newfile->file_name, findFileData.cFileName, MAX_PATH);
        newfile->file_name[MAX_PATH - 1] = '\0'; // Ensure null termination
        #endif

        FILETIME filetime = findFileData.ftCreationTime;
        newfile->creation_time = creation_local_time(&filetime);
        newfile->next = NULL;

        printf("This is file %s, with Creation time: %02d/%02d/%d %02d:%02d\n",
               newfile->file_name,
               newfile->creation_time.wMonth,
               newfile->creation_time.wDay,
               newfile->creation_time.wYear,
               newfile->creation_time.wHour,
               newfile->creation_time.wMinute);

        if (fld->first == NULL) {
            fld->first = fld->last = newfile;
        } else {
            fld->last->next = newfile;
            fld->last = newfile;
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

int main() {
    const char* directory_path = "D:\\Local Disk\\C++\\DSA Assignments\\Test files";
    struct folder fld;
    init(&fld, directory_path);

    struct file_node* current = fld.first;
    while (current != NULL) {
        struct file_node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
