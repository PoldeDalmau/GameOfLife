# Game of Life – Idle Project 

 
## Goal
Make Conway’s Game of Life and visualize it using C++ and Qt. 

## General learning objectives
Making a C++ project and compiling it using CMake, MingW, GoogleTest and Ninja. For the frontend, Qt can be used in combination with the MVC (Model, View and Controller) design pattern. Setting up a CI/CD pipeline with Cppcheck actions. Applying OOP principles. 

##  Project description
The Game of Life is a cellular automation, zero-player game developed by John Horton Conway in 1970. The fact it is zero-player, does not mean the player does not interact with the game. The player sets the initial conditions and enjoys watching Life unfold. 

The game is played on a 2D grid consisting of cells that are either live or dead. The player sets the initial state of the cells and once the game starts, cells can be born or die according to the state of their neighbors, i.e. the cells that are vertically, horizontally or diagonally adjacent to it. The rules are as follows: 

 - Any live cell with fewer than two live neighbors dies, as if by underpopulation. 

 - Any live cell with two or three live neighbors lives on to the next generation. 

 - Any live cell with more than three live neighbors dies, as if by overpopulation. 

 - Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction. 

##  Further ideas 

Many initial states that give rise to interesting patterns have been discovered since the game’s creation. One possibility would be to include a repository of these initial states and let the player select them and let them play out. The player could create their own file format to store them and import them as the game is running. 