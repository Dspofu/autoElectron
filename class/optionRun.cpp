#include "optionRun.h"

void OptionRun::run(std::function<int()> main) {
  system("cls");
  std::string inp;
  std::cout << "\033[33mFolders detected:\n" << std::endl;
  std::filesystem::path path = std::filesystem::current_path();
  int countPath = 0;
  for (const auto &entry: std::filesystem::directory_iterator(path/inp)) {
    if (std::filesystem::is_directory(entry.status())) {
      if (entry.path() == path/"node_modules") { std::cout << "\033[31mX " << entry.path() << std::endl; }
      else if (!entry.path().empty()) { std::cout << "\033[36m* " << entry.path() << std::endl; countPath++; }
    }
  }
  if (countPath == 0) {
    std::cout << "\033[36m[ No folders found ]" << std::endl;
    std::cout << "\n\033[33mPress any key to continue.";
    getch();
    main();
  } else {
    std::cout << "\n\033[33mWhat is the folder?\n\n\033[32m> \033[35m";
    std::cin >> inp;
    std::cout << "\033[37m" << std::endl;
    system("cls");
    std::cout << "Starting application...\nDir: " + inp + "/main.js" << std::endl;
    system(("npm run gui -- " + inp + "/main.js").c_str());
    std::cout << "\n\nPress any key to continue.";
    getch();
    main();
  }
}