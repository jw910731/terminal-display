//
// Created by jw910731 on 2020/10/23.
//
#include "Frame/Frame.h"
#include <sys/ioctl.h>
#include <unistd.h>

int main(int argc, const char **argv){
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    Frame f(STDOUT_FILENO, w.ws_col, w.ws_row);
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while(true){
        f.flush();
        usleep(3000);
    }
#pragma clang diagnostic pop
    return 0;
}
