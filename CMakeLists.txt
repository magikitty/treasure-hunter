cmake_minimum_required(VERSION 3.17)
project(treasure-hunter)

set(CMAKE_CXX_STANDARD 14)

add_executable(treasure-hunter main.cpp
        gameObjects/GameObject.cpp gameObjects/GameObject.h
        gameObjects/Player.cpp gameObjects/Player.h
        gameObjects/Monster.cpp gameObjects/Monster.h
        gameObjects/Gem.cpp gameObjects/Gem.h
        gameObjects/MagicApple.cpp gameObjects/MagicApple.h
        helperClasses/Position.cpp helperClasses/Position.h
        helperClasses/EventLogger.cpp helperClasses/EventLogger.h
        levels/Map.cpp levels/Map.h
        levels/Level.cpp levels/Level.h
        managers/GameManager.cpp managers/GameManager.h
        managers/LevelManager.cpp managers/LevelManager.h
        Constants.h
        )