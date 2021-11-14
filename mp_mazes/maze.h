#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "dsets.h"
using namespace std;
using namespace cs225;

class SquareMaze {

public:
 
  SquareMaze();

  void 	makeMaze (int width, int height);

  bool 	canTravel (int x, int y, int dir) const;

  void 	setWall (int x, int y, int dir, bool exists);

  std::vector<int> solveMaze();

  cs225::PNG* drawMaze() const;

  cs225::PNG* drawMazeWithSolution();

  PNG* drawCreativeMaze() const;

private:

  vector<pair<bool, bool>> walls;

  DisjointSets dsets;

  int _width;

  int _height;


};
