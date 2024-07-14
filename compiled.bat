@echo OFF
g++ main.cpp -static class/optionRun.cpp class/optionGuide.cpp class/optionPackage.cpp -o compiled/electronBuilder.exe
echo Finished
cmd /k > nul