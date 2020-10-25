//
// Created by 吳文元 on 2020/10/24.
//

#ifndef TERMINALDISPLAY_BASICFRAME_H
#define TERMINALDISPLAY_BASICFRAME_H
#include <cstdio>
#include <vector>

template<typename Payload>
class BasicFrame {
protected:
    std::vector<char16_t> frameBuf;
    int fd;
    unsigned short w, h;
public:
    BasicFrame(int fd, unsigned short w, unsigned short h):fd(fd){
        resize(w, h);
        putchar('\x1b[2J');
    }
    // resize the buffer to match the terminal character size
    void resize(unsigned short w, unsigned short h);
    // abstract set function for class specific set action
    virtual void set(int x, int y, Payload p) = 0;
    void flush();
};


#endif //TERMINALDISPLAY_BASICFRAME_H
