#include "optionGuide.h"

void OptionGuide::guide(std::function<int()> main, std::wstring instruction) {
    std::wcout << instruction << "\n" << std::endl;
    std::cout << "\033[37mPress any key to continue.";
    getch();
    main();
}