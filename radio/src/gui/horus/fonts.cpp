/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x 
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "opentx.h"

uint16_t font_tinsize_specs[] = {
#include "font_tinsize.specs"
};

pm_uchar font_tinsize[] = {
#include "font_tinsize.lbm"
};

uint16_t font_smlsize_specs[] = {
#include "font_smlsize.specs"
};

pm_uchar font_smlsize[] = {
#include "font_smlsize.lbm"
};

uint16_t font_stdsize_specs[] = {
#include "font_stdsize.specs"
};

pm_uchar font_stdsize[] = {
#include "font_stdsize.lbm"
};

uint16_t font_midsize_specs[] = {
#include "font_midsize.specs"
};

pm_uchar font_midsize[] = {
#include "font_midsize.lbm"
};

uint16_t font_dblsize_specs[] = {
#include "font_dblsize.specs"
};

pm_uchar font_dblsize[] = {
#include "font_dblsize.lbm"
};

uint16_t font_xxlsize_specs[] = {
#include "font_xxlsize.specs"
};

pm_uchar font_xxlsize[] = {
#include "font_xxlsize.lbm"
};

uint16_t font_stdsizebold_specs[] = {
#include "font_stdsizebold.specs"
};

pm_uchar font_stdsizebold[] = {
#include "font_stdsizebold.lbm"
};

const uint16_t * const fontspecsTable[16] = { font_stdsize_specs, font_tinsize_specs, font_smlsize_specs, font_midsize_specs, font_dblsize_specs, font_xxlsize_specs, font_stdsizebold_specs };
const uint8_t * const fontsTable[16] = { font_stdsize, font_tinsize, font_smlsize, font_midsize, font_dblsize, font_xxlsize, font_stdsizebold };

BitmapBuffer * fontCache[2];

BitmapBuffer * createFontCache(const uint8_t * font, LcdFlags fg, LcdFlags bg)
{
  coord_t width = *((uint16_t *)font);
  coord_t height = *(((uint16_t *)font)+1);

  BitmapBuffer * buffer = new BitmapBuffer(BMP_RGB565, width, height);
  buffer->clear(bg);
  buffer->drawBitmapPattern(0, 0, font, fg);

  return buffer;
}

void loadFontCache()
{
  fontCache[0] = createFontCache(fontsTable[0], TEXT_COLOR, TEXT_BGCOLOR);
  fontCache[1] = createFontCache(fontsTable[0], TEXT_INVERTED_COLOR, TEXT_INVERTED_BGCOLOR);
}
