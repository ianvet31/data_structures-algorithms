#include "Image.h"
using cs225::HSLAPixel;

void Image::darken() {
    for (int i = 0; i < this->width(); i++) {
        for (int j = 0; j < this->height(); j++) {
            HSLAPixel & pixel = this->getPixel(i, j);

            if (pixel.l > 0.1) {
                pixel.l -= 0.1;
            } else {
                pixel.l = 0;
            }

        }
    }
}

void Image::darken(double amount) {
    for (int i = 0; i < this->width(); i++) {
        for (int j = 0; j < this->height(); j++) {
            HSLAPixel & pixel = this->getPixel(i, j);

            if (pixel.l > amount) {
                pixel.l -= amount;
            } else {
                pixel.l = 0;
            }

        }
    }
}

void Image::desaturate() {
    for (int i = 0; i < this->width(); i++) {
        for (int j = 0; j < this->height(); j++) {
            HSLAPixel & pixel = this->getPixel(i, j);

            if (pixel.s > 0.1) {
                pixel.s -= 0.1;
            } else {
                pixel.s = 0;
            }

        }
    }
}

void Image::desaturate(double amount) {
    for (int i = 0; i < this->width(); i++) {
        for (int j = 0; j < this->height(); j++) {
            HSLAPixel & pixel = this->getPixel(i, j);

            if (pixel.s > amount) {
                pixel.s -= amount;
            } else {
                pixel.s = 0;
            }

        }
    }
}

void Image::grayscale() {
    for (int i = 0; i < this->width(); i++) {
        for (int j = 0; j < this->height(); j++) {
            HSLAPixel & pixel = this->getPixel(i, j);

            pixel.s = 0
            }

        }
    }
}

void Image::illinify() {
    for (int i = 0; i < this->width(); i++) {
        for (int j = 0; j < this->height(); j++) {
            HSLAPixel & pixel = this->getPixel(i, j);
            double oh = pixel.h;
            if (oh > 113.5 && oh < 293.5 ) {
                pixel.h = 216.;
            }  else {
                pixel.h = 11.;
            }

        }
    }
}

void Image::lighten() {
    for (int i = 0; i < this->width(); i++) {
        for (int j = 0; j < this->height(); j++) {
            HSLAPixel & pixel = this->getPixel(i, j);

            if (pixel.l < 0.9) {
                pixel.l += 0.1;
            } else {
                pixel.l = 1;
            }

        }
    }
}

void Image::lighten(double amount) {
    for (int i = 0; i < this->width(); i++) {
        for (int j = 0; j < this->height(); j++) {
            HSLAPixel & pixel = this->getPixel(i, j);

            if (pixel.l < (1 - amount)) {
                pixel.l += amount;
            } else {
                pixel.l = 1;
            }

        }
    }
}

void Image::rotateColor(double degrees) {
    for (int i = 0; i < this->width(); i++) {
        for (int j = 0; j < this->height(); j++) {
            HSLAPixel & pixel = this->getPixel(i, j);

            pixel.h += degrees;

            if (pixel.h > 360) {
                pixel.h -= 360;
            } else if (pixel.h < 0) {
                pixel.h += 360;
            }

        }
    }
}

void Image::saturate() {
    for (int i = 0; i < this->width(); i++) {
        for (int j = 0; j < this->height(); j++) {
            HSLAPixel & pixel = this->getPixel(i, j);

            if (pixel.s < 0.9) {
                pixel.s += 0.1;
            } else {
                pixel.s = 1;
            }

        }
    }
}

void Image::saturate(double amount) {
    for (int i = 0; i < this->width(); i++) {
        for (int j = 0; j < this->height(); j++) {
            HSLAPixel & pixel = this->getPixel(i, j);

            if (pixel.s < (1 - amount)) {
                pixel.s += amount;
            } else {
                pixel.s = 1;
            }

        }
    }
}

void Image::scale(double factor) {

    PNG pimg(*this);
    this->resize((factor*this->width()), (factor*this->height()));
    for (int i = 0; i < this->width(); i++) {
        for (int j = 0; j < this->height(); j++) {
            HSLAPixel & Npixel = this->getPixel(i, j);
            px = i / factor;
            py = j / factor;
            HSLAPixel & OPixel = pimg.getPixel(px, py);
            Npixel = OPixel;
        }
    }
}

void Image::scale(unsigned w, unsigned h) {

    wid = width/this->width();
    hei = height/this->height();
    if (wid > hei) {
        scale(hei);
    } else {
        scale(wid);
    }
}


