/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */

#include "Image.h"
#pragma once

namespace cs225 {
    class StickerSheet: public Image {
        public:

            StickerSheet(const Image &picture, unsigned max);

            ~StickerSheet();

            StickerSheet(const StickerSheet &other);

            const StickerSheet& operator=(const StickerSheet &other);

            void StickerSheet::changeMaxStickers(unsigned max);

            int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y);

            bool StickerSheet::translate(unsigned index, unsigned x, unsigned y);

            void StickerSheet::removeSticker(unsigned index);

            Image* StickerSheet::getSticker(unsigned index);

            Image StickerSheet::render() const;

        private:

            void copy(const StickerSheet & other);
            void destruct();

            typedef struct {
                Image* image_;
                unsigned x_;
                unsigned y_;
            } Sticker;

            unsigned stickers_num;

            Image* img;

            Image* render_img;

            Sticker* sheet;



    };
}


 
