#include "optionPackage.h"

void OptionPackage::package(std::function<int()> main) {
    system("cls");
    std::fstream file;
    file.open("package.json", std::ios::app);
    if (file.is_open()) {
      file << "{ \"scripts\": { \"gui\": \"electron \" } }";
      file.close();
      std::system("npm i --save-dev electron");
      std::cout << "\n\033[32mCreated package.json\033[37m\n" << std::endl;
      std::cout << "Press any key to continue.";
      getch();
      main();
    } else {
      std::cout << "\n\033[32mError trying to create package.json file.\033[37m\n" << std::endl;
      std::cout << "Press any key to continue.";
      getch();
      main();
    }
}