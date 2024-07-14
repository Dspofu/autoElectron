#ifndef OPTION_PACKAGE_H
#define OPTION_PACKAGE_H

#include <iostream>
#include <locale.h>
#include <functional>
#include <windows.h>
#include <conio.h>
#include <filesystem>
#include <fstream>

class OptionPackage {
  public: void package(std::function<int()> main);
};

#endif