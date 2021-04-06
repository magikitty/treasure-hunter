cmake_minimum_required(VERSION 3.17)
project(treasure-hunter)

set(CMAKE_CXX_STANDARD 14)

add_executable(treasure-hunter main.cpp
        gameObjects/GameObject.cpp gameObjects/GameObject.h
        helperClasses/Position.cpp helperClasses/Position.h
        helperClasses/Dungeon.cpp helperClasses/Dungeon.h
        gameObjects/Player.cpp gameObjects/Player.h
        gameObjects/Monster.cpp gameObjects/Monster.h
        gameObjects/Gem.cpp gameObjects/Gem.h
        Constants.h
        gameObjects/MagicApple.cpp gameObjects/MagicApple.h
        helperClasses/EventLogger.cpp helperClasses/EventLogger.h
        helperClasses/GameManager.cpp helperClasses/GameManager.h
        helperClasses/Level.cpp helperClasses/Level.h)