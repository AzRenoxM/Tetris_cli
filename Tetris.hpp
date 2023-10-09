#ifndef TETRIS_HPP
#define TETRIS_HPP

#include<cstdlib>
#include<iostream>
#include<array>
#include<ctime>
#include<cstdlib>
#include "Block.hpp"

class Tetris{
private:
    std::vector<Block*> block_list;
    char border_symbol, empty_space, block_symbol;
    char **border;
    unsigned int width, height, score;
    bool gameover;
    Block *block;

    Block* create_block();
    
public:
    void draw();
    void update();
    int input();
    int run();

    bool check_collision_block(); 
    

    Tetris(int width = 15, int height = 15, int score = 0, bool gameover = 0, char border_symbol = '#', char empty_space = ' ', char block_symbol = 'X');
    ~Tetris();
    
};

#endif