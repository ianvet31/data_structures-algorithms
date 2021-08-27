/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#include "HSLAPixel.h"
#include <cmath>
#include <iostream>
using namespace std;

namespace cs225 {
	HSLAPixel::HSLAPixel() {
		h_ = 0.;
		s_ = 0.;
		l_ = 0.;
		a_ = 1.0;
	}
	HSLAPixel::HSLAPixel(double h, double s, double l) {
		h_ = h;
		s_ = s;
		l_ = l;
		a_ = 1.0;
	}
	HSLAPixel::HSLAPixel(double h, double s, double l, double a) {
		h_ = h;
		s_ = s;
		l_ = l;
		a_ = a;
	}
}
