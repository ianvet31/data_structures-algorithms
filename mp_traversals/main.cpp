
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.

  PNG png;      
  png.readFromFile("flower.png");

  FloodFilledImage image(png);
  BFS bfs(png, Point(png.width()/2,png.height()/2), 0.1);
  DFS dfs1(png, Point(png.width()/3,png.height()/3), 0.2);
  DFS dfs2(png, Point(png.width()/4,png.height()/4), 0.3);
  
  HSLAPixel color1(234, 1, 0.6);
  HSLAPixel color2(27, 1, 0.4);
  SolidColorPicker solid1(color1);
  SolidColorPicker solid2(color2);
  RainbowColorPicker rain(0.05);


  MyColorPicker mycolor(0.6);
  image.addFloodFill( bfs, mycolor );
  image.addFloodFill( dfs1, solid1 );
  image.addFloodFill( dfs2, solid2 );
  Animation animation = image.animate(500);
  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");
  return 0;
}