//
// Created by 吳文元 on 2020/10/24.
//

#ifndef TERMINALDISPLAY_BASICFRAME_H
#define TERMINALDISPLAY_BASICFRAME_H
#include <cstdio>
#include <vector>
#include <unistd.h>

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
    void resize(unsigned short w, unsigned short h){
        this->w = w; this->h = h;
        frameBuf.shrink_to_fit();
        frameBuf.reserve(w*h);
    }


    // abstract set function for class specific set action
    virtual void set(int x, int y, Payload p) = 0;
    void flush() {
        puts("\x1b[d");
        // naive flush strategy
        for(int i = 0 ; i < this->h ; ++i){
            write(this->fd, frameBuf.data()+w*i, sizeof(char)*w);
            write(this->fd, "\n", sizeof(char));
        }
    }
};


#endif //TERMINALDISPLAY_BASICFRAME_H
