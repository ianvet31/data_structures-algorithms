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
		h = 0.;
		s = 0.;
		l = 1.0;
		a = 1.0;
	}
	HSLAPixel::HSLAPixel(double h_, double s_, double l_) {
		h = h_;
		s = s_;
		l = l_;
		a = 1.0;
	}
	HSLAPixel::HSLAPixel(double h_, double s_, double l_, double a_) {
		h = h_;
		s = s_;
		l = l_;
		a = a_;
	}
}
