#include <iostream>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <filesystem>
#include <fstream>

#include "class/optionRun.h"
#include "class/optionPackage.h"
#include "class/optionGuide.h"

/*
╔═══════════════════════════════Folder picker for Electron Apps════════════════════════════╗
║                                                                                          ║
║   [0] - Initialize project.                                                              ║
║   [1] - Create a package.json for the application to communicate better with Electron.   ║
║   [2] - Instructions on how to use.                                                      ║
║   [3] - Set language GUI * EN / PT-BR                                                    ║
║                                                                                          ║
╚══════════════════════════════════════════════════════════════════════════════════════════╝

╔═════════════════════════════════════════════════════════════════Instructions══════════════════════════════════════════════════════════════════╗
║                                                                                                                                               ║
║   - Create a folder.                                                                                                                          ║
║   - Create subfolders that will serve as your Electron projects.                                                                              ║
║   - The name of the subfolders will serve as code to choose which one you want to start.                                                      ║
║   - Inside the \"Parent\" folder, this executable must be pasted and the option \"1\" must be listed.                                             ║
║   - Initialize the executable and download the Electron package using NPM. NOTE: This executable only creates commands for use in Electron.   ║
║   - The main file of your App in electron must be \"main.js\"                                                                                   ║
║                                                                                                                                               ║
╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝
*/

void SetWindowSize(int width, int height) {
  HWND console = GetConsoleWindow();
  RECT r;
  GetWindowRect(console, &r);
  MoveWindow(console, r.left, r.top, width, height, TRUE);
}

std::wstring headerEN = L"\033[33mExec: \033[34mfastExecElectron\033[33m | Version: \033[34m0.2.0\033[33m | Discord: \033[34mDspofu\n\033[37mSelect the desired option number.\n\n\033[36m╔═════════════════════════════Folder picker for Electron Apps═════════════════════════════╗\n║                                                                                          ║\n║   [0] - Initialize project.                                                              ║\n║   [1] - Create a package.json for the application to communicate better with Electron.   ║\n║   [2] - Instructions on how to use.                                                      ║\n║                                                                                          ║\n╚═════════════════════════════════════════════════════════════════════════════════════════╝\033[37m";
std::wstring instructionEN = L"\n\n\033[36m╔═════════════════════════════════════════════════════════════════Instructions═════════════════════════════════════════════════════════════════╗\n║                                                                                                                                               ║\n║   - Create a folder.                                                                                                                          ║\n║   - Create subfolders that will serve as your Electron projects.                                                                              ║\n║   - The name of the subfolders will serve as code to choose which one you want to start.                                                      ║\n║   - Inside the \"Parent\" folder, this executable must be pasted and the option \"1\" must be listed.                                             ║\n║   - Initialize the executable and download the Electron package using NPM. NOTE: This executable only creates commands for use in Electron.   ║\n║   - The main file of your App in Electron must be \"main.js\"                                                                                   ║\n║                                                                                                                                               ║\n╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";

void loop(std::string &opt) {
  SetWindowSize(800, 500);
  while (opt != "0" && opt != "1" && opt != "2") {
    system("cls");
    std::wcout << headerEN << "\n\n\033[32m> \033[35m";
    std::cin >> opt;
  }
}

int main() {
  setlocale(LC_ALL, "");
  system("title Start in project");
  std::string opt;
  loop(opt);
  if (opt == "0") {
    OptionRun().run(main);
  } else if (opt == "1") {
    OptionPackage().package(main);
  } else if (opt == "2") {
    SetWindowSize(1200, 500);
    OptionGuide().guide(main, instructionEN);
  }
    std::cout << "Press any key to continue.";
    getch();
    main();
  return 0;
}