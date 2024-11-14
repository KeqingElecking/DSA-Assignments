#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <dirent.h>

struct file_node {
    FILE *file;
    char filename[MAX_PATH];
    SYSTEMTIME creation_time;
    file_node* next;
};

struct folder {
    file_node* first;
    file_node* last;
};

SYSTEMTIME creation_local_time (FILETIME ft){
    SYSTEMTIME utc, local;
    FileTimeToSystemTime(&ft, &utc);
    SystemTimeToTzSpecificLocalTime(0, &utc, &local);
    return local;
}

void init(folder *fld, const char *directory_path)
{
    fld->first = fld->last = 0;

    WIN32_FIND_DATAW findFileData;
    HANDLE hFind;

    char search_path[MAX_PATH];
    snprintf(search_path, MAX_PATH, "%s\\*", directory_path);

    wchar_t wSearch_path[MAX_PATH];
    if (MultiByteToWideChar(CP_ACP, 0, search_path, -1, wSearch_path, MAX_PATH) == 0) {
        printf("Error converting search path to wide characters. Error: %lu\n", GetLastError());
        return;
    }
    hFind = FindFirstFileW(wSearch_path, &findFileData);

    do {
        file_node* newfolder = new file_node;
        char fptr[MAX_PATH];
        wchar_t filename[MAX_PATH];
        wcscpy(filename, findFileData.cFileName);
        WideCharToMultiByte(CP_ACP, 0, filename, -1, fptr, MAX_PATH, NULL, NULL);
        newfolder->file = fopen(fptr, "r");
        strcpy(fptr, newfolder->filename);

        GetFileTime(hFind, &findFileData.ftCreationTime, 0, 0);
        SYSTEMTIME utc, local;
        FileTimeToSystemTime(&findFileData.ftCreationTime, &utc);
        SystemTimeToTzSpecificLocalTime(0, &utc, &local);
        newfolder->creation_time.wYear = local.wYear;
        newfolder->creation_time.wMonth = local.wMonth;
        newfolder->creation_time.wDay = local.wDay;
        newfolder->creation_time.wHour = local.wHour;
        newfolder->creation_time.wMinute = local.wMinute;
        newfolder->creation_time.wSecond = local.wSecond;
        newfolder->creation_time.wMilliseconds = local.wMilliseconds;
        printf("This is file %99s, with Creation time: %02d/%02d/%d %02d:%02d\n", newfolder->filename,
               newfolder->creation_time.wMonth, newfolder->creation_time.wDay, newfolder->creation_time.wYear, 
               newfolder->creation_time.wHour, newfolder->creation_time.wMinute);
        if (fld->first == 0) fld->first = fld->last = newfolder;
        else
        {
            fld->last->next = newfolder;
            fld->last = newfolder;
        }
    } while (FindNextFileW(hFind, &findFileData) != 0);

    FindClose(hFind);
}

void insert(folder *fld, const char *directory_path){
    
}
int main() {
    const char *directory_path = "D:\\Local Disk\\C++\\DSA Assignments";
    folder fld;
    folder* fldptr = &fld;
    init(fldptr, directory_path);

    system("pause");
    return 0;
}
