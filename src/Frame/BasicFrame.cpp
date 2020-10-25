//
// Created by 吳文元 on 2020/10/24.
//

#include "BasicFrame.h"
#include <unistd.h>

template<typename Payload>
void BasicFrame<Payload>::resize(int w, int h){
    this->w = w; this->h = h;
    frameBuf.shrink_to_fit();
    frameBuf.reserve(w*h);
}

template<typename Payload>
void BasicFrame<Payload>::flush() {
    // naive flush strategy
    for(int i = 0 ; i < this->h ; ++i){
        write(this->fd, frameBuf.data()+w*i, sizeof(char)*w);
        write(this->fd, "\n", sizeof(char));
    }
}