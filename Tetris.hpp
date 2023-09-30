#ifndef TETRIS_HPP
#define TETRIS_HPP

#include<cstdlib>
#include<iostream>
#include "Block.hpp"

class Tetris{
private:
    std::vector<Block*> block_list;
    char border_symbol, empty_space, block_symbol;
    char **border;
    unsigned int width, height, score;
    bool gameover;
    Block *block;
    
public:
    void draw();
    void update();
    int input();
    int run();

    bool check_collision_block(); //TODO check collision between blocks for now it's only for border
    

    Tetris(int width = 15, int height = 15, int score = 0, bool gameover = 0, char border_symbol = '#', char empty_space = ' ', char block_symbol = 'X');
    ~Tetris();
    
};

#endif