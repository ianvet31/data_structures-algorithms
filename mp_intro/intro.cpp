#include "cs225/PNG.h"
using cs225::PNG;
#include "cs225/HSLAPixel.h"
using cs225::HSLAPixel;
#include <string>
#include <math.h>

void rotate(std::string inputFile, std::string outputFile) {
  PNG img;
  img.readFromFile(inputFile);
  PNG imgout(img.width(), img.height());

  for (unsigned x = 0; x < img.width(); x++) {
    for (unsigned y = 0; y < img.height(); y++) {
      HSLAPixel & pixel = img.getPixel(x, y);
      HSLAPixel & pixel2 = imgout.getPixel(img.width() - x - 1, img.height() - y - 1);
      pixel2 = pixel;
    }
  }
  imgout.writeToFile(outputFile);
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  PNG png(width, height);
  for (unsigned x = 0; x < png.width(); x++) {
    for (unsigned y = 0; y < png.height(); y++) {
      HSLAPixel & pixel = png.getPixel(x, y);
      double m = cos(x / 4) * cos(y / 5);
      pixel.h = m * 360;
      pixel.l = m * 1;
      pixel.s = m * 1;
      pixel.a = 1.0;
    }
  }


  return png;
}
