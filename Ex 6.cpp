#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <dirent.h>

struct file_node {
    FILE *file;
    SYSTEMTIME creation_time;
    file_node* next;
};

struct folder {
    file_node* first;
    file_node* last;
};

void init(folder *fld, const char *directory_path)
{
    fld->first = fld->last = 0;

    WIN32_FIND_DATA findFileData;
    HANDLE hFind;

    char search_path[MAX_PATH];
    snprintf(search_path, MAX_PATH, "%s\\*", directory_path); // Append \* to search for all files

    wchar_t wSearch_path[MAX_PATH];
    MultiByteToWideChar(CP_ACP, 0, search_path, -1, wSearch_path, MAX_PATH);
    hFind = FindFirstFile(wSearch_path, &findFileData);
    
    do {
        file_node*
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}
int main() {

    return 0;
}
