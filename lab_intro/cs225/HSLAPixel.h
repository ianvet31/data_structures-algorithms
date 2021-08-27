/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#pragma once

#include <iostream>
#include <sstream>

namespace cs225 {
	class HSLAPixel {
		public:
			double h_;
			double s_;
			double l_;
			double a_;

			//constructors
			
			HSLAPixel();
			HSLAPixel(double hue, double saturation, double luminance);
			HSLAPixel(double hue, double saturation, double luminance, double alpha);


	}
}
