#include "Image.h"
#include "StickerSheet.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <stdlib.h> 
using namespace cs225;

int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  Image alma; alma.readFromFile("tests/alma.png");
  Image i;    i.readFromFile("tests/i.png");

  StickerSheet sheet(alma, 690);

  for (unsigned z = 0; z < 690; z++) {
    sheet.addSticker(i, rand() % 700, rand() % 300);
  }
  

  Image output = sheet.render();
  output.writeToFile("myImage.png");

  return 0;
}
