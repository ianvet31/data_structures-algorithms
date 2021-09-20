#include "StickerSheet.h"
#include <iostream>
#include <cmath>
#include "Image.h"
using namespace cs225;

StickerSheet::StickerSheet(const Image & picture, unsigned max) {
    stickers_num = max;
    sheet = new Sticker[stickers_num];
    img = new Image(picture);
    render_img = new Image();
}


void StickerSheet::copy(const StickerSheet& other) {
    stickers_num = other.stickers_num;
    img = new Image(*other.img);
    delete[] sheet;
    sheet = new Sticker[stickers_num];
    for (unsigned i = 0; i < stickers_num; i++) {
        sheet[i].image_ = other.sheet[i].image_;
    }
}
StickerSheet::StickerSheet(const StickerSheet& other) {
    copy(other);
}

void StickerSheet::destruct() {
    delete[] sheet;
    for (unsigned i = 0; i < stickers_num; i++) {
        delete sheet[i].image_;
        sheet[i].image_ = NULL;
    }
    sheet = NULL;
}
StickerSheet::~StickerSheet() {
    destruct();
}


int StickerSheet::addSticker(Image & sticker, unsigned x, unsigned y) {
    for (unsigned i = 0; i < stickers_num; i++) {
        if (sheet[i].image_ == NULL) {
            sheet[i].image_ = new Image(sticker);
            sheet[i].x_ = x;
            sheet[i].y_ = y;
            return i;

        }
    }
    return -1;
}

void StickerSheet::changeMaxStickers(unsigned max) {
    Sticker* newSheet = new Sticker[max];
    for (unsigned i = 0; i < stickers_num; i++) {
        if (i < max) {
            newSheet[i].image_ = sheet[i].image_;
            newSheet[i].x_ = sheet[i].x_;
            newSheet[i].y_ = sheet[i].y_;

        } else if (sheet[i].image_ != NULL) {
            delete sheet[i].image_;
            sheet[i].image_ = NULL;
        }
    }
    delete[] sheet;
    sheet = newSheet;
    stickers_num = max;
}

Image* StickerSheet::getSticker(unsigned index) {
    if (index >= 0 & index < stickers_num) {
        Image* imgr = sheet[index].image_;
        return imgr;
    } else {
        return NULL;
    }
}

const StickerSheet& StickerSheet::operator=(const StickerSheet& other) {
    if (this != & other) {
        destruct();
        copy(other);
    }
    return *this;
}
void StickerSheet::removeSticker(unsigned index) {
    if (index >= 0 & index < stickers_num) {
        if (sheet[index].image_ != NULL) {
            delete sheet[index].image_;
            sheet[index].x_ = 0;
            sheet[index].y_ = 0;
        }
    }
}

Image StickerSheet::render() const {
    unsigned w = img->width();
    unsigned h = img->height();


    for (unsigned i = 0; i < stickers_num; i++) {
        Sticker cur = sheet[i];
        if (cur.image_ != NULL) {
            w = fmax(w, cur.x_ + cur.image_->width());
            h = fmax(h, cur.y_ + cur.image_->height());
        }
    }

    *render_img = *img;
    render_img->resize(w, h);
    
    for (unsigned i = 0; i < stickers_num; i++) {
        Sticker current = sheet[i];
        if (current.image_ != NULL) {
            for (unsigned x = 0; x < render_img->width(); x++) {
                for (unsigned y = 0; y < render_img->height(); y++) {
                    HSLAPixel & oP = render_img->getPixel(x, y);
                    HSLAPixel & sP = current.image_->getPixel(x, y);
                    if (oP.a != 0) {
                        oP = sP;
                    }
                }
            }
        }
        
    }
    return *render_img;
}

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {
    if (index < stickers_num) {
        sheet[index].x_ = x;
        sheet[index].y_ = y;
        return true;
    } else {
        return false;
    }
}

