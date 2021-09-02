#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>


void rotate(std::string inputFile, std::string outputFile) {
  PNG img;
  img.readFromFile(inputFile);
  PNG imgout(img.width(), img.height());

  for (unsigned x = 0; x < img.width(); x++) {
    for (unsigned y = 0; y < img.height(); y++) {
      HSLAPixel & pixel = img.getPixel(x, y);
      HSLAPixel & pixel2 = imgout.getPixel(img.width() - x - 1, img.height() - y - 1);
      pixel2 = pixel
    }
  }
  imgout.writeToFile(outputFile);
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3

  return png;
}
