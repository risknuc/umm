#!/bin/bash

mkdir -p BuildScripts/Bin && mkdir -p BuildScripts/Bin/Resources
cp -r Resources/* BuildScripts/Bin/Resources/

g++ -std=c++17 \
-O3 -march=native -ffast-math -flto -fvisibility=hidden -DNDEBUG \
-lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window \
RunWindow.cpp Scripts/Window.cpp Scripts/Cursor.cpp Scripts/Objects/Object.cpp Scripts/Objects/Character.cpp Scripts/Functionality/RenderQueue.cpp Scripts/Functionality/Modules/Animator.cpp Scripts/Functionality/Modules/Camera.cpp \
-o BuildScripts/Bin/BuildOutput.bin

strip BuildScripts/Bin/BuildOutput.bin
