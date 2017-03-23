# Sokoban

## Game
Sokoban is a text based block pusher game written in C++. The user controls a 'Pusher' sprite and his/her objective is to push all the boxes into holes. This strategic puzzle game implements an adjacency list graph structure and utilization of dijkstra's algorithm in order to generate the most optimal solution paths for each level of the game. The gameplay is triggered by typing the directional chars a, w, s, or d.

## Installation & usage
```bash
$ git clone https://github.com/changangela/sokoban
$ cd sokoban/sokoban-game
$ g++ *.cpp
$ ./a.out
```

## Solver

Comes equipped with a solver that implements a breadth first search algorithm for shortest path finding.

## Installation & usage
```bash
$ git clone https://github.com/changangela/sokoban
$ cd sokoban/sokoban-solver
$ g++ sokoban-solver.cpp -std=c++11
$ ./a.out < map1.txt
```
