#ifndef OPTION_RUN_H
#define OPTION_RUN_H

#include <iostream>
#include <functional>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <filesystem>
#include <fstream>

class OptionRun {
  public: void run(std::function<int()> main);
};

void run(std::function<int()> main);

#endif