//
// Created by 吳文元 on 2020/10/24.
//

#include "Frame.h"

void Frame::set(int x, int y, bool s) {
    //TODO: Add braille converter and coordinate converter
}

char16_t &Frame::setHelper(int x, int y) {
   return super::frameBuf[x+y*super::w];
}

