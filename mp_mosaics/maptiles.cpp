/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"


using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    vector<Point<3>> points;
    map<Point<3>, TileImage*> map_;
    
    for (auto iter = theTiles.begin(); iter != theTiles.end(); iter++) {

    	LUVAPixel pixel_ = iter->getAverageColor();

    	Point<3> point_ = convertToXYZ(pixel_);

    	points.push_back(point_);

    	map_[point_] = &*iter;
    }

    KDTree<3> kdt_avgcolor(points);
    
    MosaicCanvas * canvas = new MosaicCanvas(theSource.getRows(), theSource.getColumns());
    
    for (int i = 0; i < canvas->getRows(); i++) {
    	for (int j = 0; j < canvas->getColumns(); j++) {

    		Point<3> ideal = convertToXYZ(theSource.getRegionColor(i, j));

    		Point<3> best_ = kdt_avgcolor.findNearestNeighbor(ideal);

    		TileImage* yestile = map_[best_];
            
    		canvas->setTile(i, j, yestile);
    	}
    }
    return canvas;
}