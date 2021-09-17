/**
 * @file sketchify.cpp
 * Implementation of the sketchify function.
 */
#pragma GCC diagnostic ignored "-Wuninitialized"
#include <cstdlib>
#include <cmath>
using namespace std;

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace cs225;

/**
 * Creates a new output image.

 * @param w width of the image
 * @param h height of the image

 * @return a pointer to the newly-created image
 */
PNG* setupOutput(unsigned w, unsigned h) {
    PNG* image = new PNG(w, h);
    return image;
}

/**
 * Used to customize the color of the sketchified image.

 * @return a pointer to the color to use when sketchifying
 */
HSLAPixel* myFavoriteColor() {
    HSLAPixel *p = new HSLAPixel(1, 0.8, 0.5); //fixed to return HSLAPixel pointer
    return p;
}

void sketchify(std::string inputFile, std::string outputFile) {
    // Load in.png
    PNG* original = NULL;
    original = new PNG(); //needed to create a PNG for original before arrow
    original->readFromFile(inputFile);
    unsigned width = original->width();
    unsigned height = original->height();
    

    // Create out.png
    PNG* output;
    output = setupOutput(width, height); //initialized output PNG pointer
    // Load our favorite color to color the outline
    HSLAPixel* myPixel = myFavoriteColor();

    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output
    for (unsigned y = 1; 0 < y && y < height; y++) {
        for (unsigned x = 1; 0 < x && x < width; x++) { //change loop condition to x && x because x and y are unsigned
            // Calculate the pixel difference
            HSLAPixel& prev = original->getPixel(x - 1, y - 1);
            HSLAPixel& curr = original->getPixel(x, y);
            double diff = std::fabs(curr.h - prev.h);

            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
            HSLAPixel &currOutPixel = output->getPixel(x, y);
            if (diff > 20) {
                currOutPixel.h = myPixel->h;  //copies all attributes from my pixel to current
                currOutPixel.s = myPixel->s;
                currOutPixel.a = myPixel->a;
                currOutPixel.l = myPixel->l;
            }
        }
    }

    // Save the output file
    output->writeToFile(outputFile);

    // Clean up memory
    delete myPixel;
    delete output;
    delete original;
}
