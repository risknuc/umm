#!/bin/bash

mkdir -p BuildScripts/Debug && mkdir -p BuildScripts/Debug/Resources
cp -r Resources/* BuildScripts/Debug/Resources/

g++ -std=c++17 \
-lsfml-graphics -lsfml-audio -lsfml-system -lsfml-window \
RunWindow.cpp Scripts/Window.cpp Scripts/Cursor.cpp Scripts/Objects/Object.cpp Scripts/Objects/Character.cpp Scripts/Functionality/RenderQueue.cpp Scripts/Functionality/Modules/Animator.cpp Scripts/Functionality/Modules/Camera.cpp \
-o BuildScripts/Debug/DebugBuildOutput.bin

./BuildScripts/Debug/DebugBuildOutput.bin
