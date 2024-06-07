#include <iostream>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <filesystem>

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

std::wstring headerEN = L"\033[33mExec: \033[34mfastExecElectron\033[33m | Version: \033[34m0.2.0\033[33m | Discord: \033[34mDspofu\n\033[37mSelect the desired option number.\n\n\033[36m╔═════════════════════════════Folder picker for Electron Apps═════════════════════════════╗\n║                                                                                          ║\n║   [0] - Initialize project.                                                              ║\n║   [1] - Create a package.json for the application to communicate better with Electron.   ║\n║   [2] - Instructions on how to use.                                                      ║\n║                                                                                          ║\n╚═════════════════════════════════════════════════════════════════════════════════════════╝\033[37m\n\033[32m> \033[35m";
std::wstring headerBR = L"";
std::wstring instructionEN = L"\n\n\033[36m╔═════════════════════════════════════════════════════════════════Instructions═════════════════════════════════════════════════════════════════╗\n║                                                                                                                                               ║\n║   - Create a folder.                                                                                                                          ║\n║   - Create subfolders that will serve as your Electron projects.                                                                              ║\n║   - The name of the subfolders will serve as code to choose which one you want to start.                                                      ║\n║   - Inside the \"Parent\" folder, this executable must be pasted and the option \"1\" must be listed.                                             ║\n║   - Initialize the executable and download the Electron package using NPM. NOTE: This executable only creates commands for use in Electron.   ║\n║   - The main file of your App in Electron must be \"main.js\"                                                                                   ║\n║                                                                                                                                               ║\n╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
std::wstring instructionBR = L"";

void loop(std::string &opt) {
  SetWindowSize(800, 500);
  while (opt != "0" && opt != "1" && opt != "2") {
    system("cls");
    std::wcout << headerEN;
    std::cin >> opt;
  }
}

int main() {
  setlocale(LC_ALL, "");
  system("title Start in project");
  std::string opt;
  loop(opt);
  if (opt == "0") {
    system("cls");
    std::string inp;
    std::cout << "\033[33mFolders detected:\n" << std::endl;
    std::filesystem::path path = std::filesystem::current_path();
    for (const auto &entry: std::filesystem::directory_iterator(path/inp)) {
      if (std::filesystem::is_directory(entry.status())) {
        if(entry.path() == path/"node_modules") { std::cout << "\033[31mX " << entry.path() << std::endl; }
        else { std::cout << "\033[36m* " << entry.path() << std::endl; }
      }
    }
    std::cout << "\n\033[33mWhat is the folder?\n\033[32m> \033[35m";
    std::cin >> inp;
    if(inp.empty()) { loop(opt); } else {
      std::cout << "\033[37m" << std::endl;
      system("cls");
      std::cout << "Starting application...\nDir: " + inp + "/main.js" << std::endl;
      system(("npm run gui -- " + inp + "/main.js").c_str());
      std::cout << "\n\nPress any key to continue.";
      getch();
      main();
    }
  } else if (opt == "1") {
    system("echo { \"scripts\": { \"gui\": \"electron \" }, \"devDependencies\": { \"electron\": \"^30.0.8\" } } > package.json");
    std::cout << "\n\033[32mCreated package.json\033[37m\n" << std::endl;
    std::cout << "Press any key to continue.";
    getch();
    main();
  } else if (opt == "2") {
    SetWindowSize(1200, 500);
    std::wcout << instructionEN << "\n" << std::endl;
    std::cout << "Press any key to continue.";
    getch();
    main();
  }
  std::cout << "\nRestart me!" << std::endl;
  system("cmd /k > nul");
  return 0;
}