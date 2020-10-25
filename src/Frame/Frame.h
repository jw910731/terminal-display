//
// Created by 吳文元 on 2020/10/24.
//

#ifndef TERMINALDISPLAY_FRAME_H
#define TERMINALDISPLAY_FRAME_H
#include "BasicFrame.h"

class Frame : public BasicFrame<bool>{
    using super=BasicFrame<bool>;
private:
    char16_t &setHelper(int x, int y);
public:
    //
    void set(int x, int y, bool s) override;
};

#endif //TERMINALDISPLAY_FRAME_H
