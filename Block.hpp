#ifndef BLOCK_HPP
#define BLOCK_HPP

#include<iostream>
#include<map>

class Block{
private:
    std::map<unsigned int, unsigned int> block;
    char block_symbol;
public:
    void rotate();
    void move();
    void value_fall();

    Block(char block_symbol);
    ~Block();
};

#endif