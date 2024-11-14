#include <windows.h>
#include <stdio.h>
#include <tchar.h> // For _TCHAR type compatibility

void printFileCreationTime(const char *filename) {
    // Chuyển đổi tên thành dạng widestring để tương thích với Windows
    wchar_t wFilename[MAX_PATH];
    MultiByteToWideChar(CP_ACP, 0, filename, -1, wFilename, MAX_PATH);

    HANDLE file = CreateFileW(wFilename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (file == INVALID_HANDLE_VALUE) {
        printf("Could not open file: %s\n", filename);
        return;
    }

    FILETIME creationTime;
    if (GetFileTime(file, &creationTime, NULL, NULL)) {
        SYSTEMTIME stUTC, stLocal;
        FileTimeToSystemTime(&creationTime, &stUTC);
        SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
        printf("Creation time: %02d/%02d/%d %02d:%02d\n", 
               stLocal.wMonth, stLocal.wDay, stLocal.wYear, 
               stLocal.wHour, stLocal.wMinute);
    } else {
        printf("Could not get file time.\n");
    }
    CloseHandle(file);
}

int main() {
    printFileCreationTime("Merge Sort.cpp");
    system("pause");
    return 0;
}
