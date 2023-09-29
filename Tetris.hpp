#ifndef TETRIS_HPP
#define TETRIS_HPP

#include<iostream>
#include "Block.hpp"

class Tetris{
private:
    char border_symbol, empty_space, block_symbol;
    char **border;
    unsigned int width, height, score;
    bool gameover;
    Block *block;
    
public:
    int init();
    void update();
    void draw();
    int input();
    int run();
    

    Tetris(int width = 10, int height = 20, int score = 0, bool gameover = 0, char border_symbol = '#', char empty_space = ' ', char block_symbol = 'X');
    ~Tetris();
    
};

#endif