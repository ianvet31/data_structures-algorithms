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

            StickerSheet(const StickerSheet &other);

            const StickerSheet& operator=(const StickerSheet &other);

            ~StickerSheet();



            void changeMaxStickers(unsigned max);

            int addSticker(Image &sticker, unsigned x, unsigned y);

            bool translate(unsigned index, unsigned x, unsigned y);

            void removeSticker(unsigned index);

            Image* getSticker(unsigned index);

            Image render() const;

        private:
            typedef struct {
                Image* image_;
                unsigned x_;
                unsigned y_;
            } Sticker;

            void copy(const StickerSheet & other);
            void destruct();

            unsigned stickers_num;

            Image* img;

            Image* render_img;

            Sticker* sheet;

    };
}


 
