//
// Created by 吳文元 on 2020/10/24.
//

#ifndef TERMINALDISPLAY_BASICFRAME_H
#define TERMINALDISPLAY_BASICFRAME_H
#include <vector>

template<typename Payload>
class BasicFrame {
protected:
    std::vector<char16_t> frameBuf;
    int w, h, fd;
public:
    // disable copy
    BasicFrame() = delete;
    BasicFrame(BasicFrame<Payload> &b) = delete;
    BasicFrame &operator=(BasicFrame<Payload> &p) = delete;
    BasicFrame(int fd, int w, int h):fd(fd){resize(w, h);}
    // resize the buffer to match the terminal character size
    void resize(int w, int h);
    // abstract set function for class specific set action
    virtual void set(int x, int y, Payload p) = 0;
    void flush();
};


#endif //TERMINALDISPLAY_BASICFRAME_H
