#pragma once

#include <random>

#include "ColorPicker.h"
#include "../cs225/HSLAPixel.h"
#include "../Point.h"

using namespace cs225;

#include "ColorPicker.h"
#include "../cs225/HSLAPixel.h"
#include "../Point.h"

using namespace cs225;

class MyColorPicker : public ColorPicker {
public:
    MyColorPicker(double factor);
    HSLAPixel getColor(unsigned x, unsigned y);

private:
    double factor_;
    double hue_;
};


