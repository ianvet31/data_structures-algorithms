#include <random>

#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;

using namespace cs225;

MyColorPicker::MyColorPicker(double factor){
  hue_ = 0;
  factor_ = factor;
}
/**
 * Picks the color for pixel (x, y).
 */
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
    HSLAPixel pixel(hue_, 1, 0.49);
    hue_ = hue_ - factor_;
    while (hue_ > 360) { 
      hue_ = hue_ - 360;
    }
    return pixel;
  /* @todo [Part 3] */
}
