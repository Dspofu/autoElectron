#ifndef OPTION_GUIDE_H
#define OPTION_GUIDE_H

#include <iostream>
#include <locale.h>
#include <functional>
#include <windows.h>
#include <conio.h>
#include <filesystem>

class OptionGuide {
  public: void guide(std::function<int()> main, std::wstring instruction);
};

#endif