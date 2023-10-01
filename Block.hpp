#ifndef BLOCK_HPP
#define BLOCK_HPP

#include<iostream>
#include<vector>
#include <functional>



class Block{
protected:
    std::vector<std::pair<int, int>> position_block; //derived
    char block_symbol; //base class 
    unsigned int width, height; //base class
    unsigned int center_block; //derived

    bool check_collision() const; //base class
public:
    bool stop_block; //base class
    bool eliminate_object; //base class
    void check_delete_block(); //base class

    std::vector<std::pair<int, int>> get_position_block() const; //base class
    void move_right(); //base class
    void move_left(); //base class
    void move_fall(); //base class
    void eliminate_row(unsigned int row_point); //base class
    void stop_from_fall(); //base class    
    virtual void rotate(); //base class


    Block(char block_symbol, unsigned int width, unsigned int height, bool stop_block = false, bool eliminate_object = false);
    ~Block();
};
//! Derived classes from Block

class I_Block : public Block{

    I_Block(std::vector<std::pair<int, int>> position_block, char block_symbol, unsigned int width, unsigned int height, bool stop_block, bool eliminate_object);
    ~I_Block();
};

class L_Block : public Block{

    L_Block(std::vector<std::pair<int, int>> position_block, char block_symbol, unsigned int width, unsigned int height, bool stop_block, bool eliminate_object);
    ~L_Block();
};

class O_Block : public Block{
    void rotate() override;

    O_Block(std::vector<std::pair<int, int>> position_block, char block_symbol, unsigned int width, unsigned int height, bool stop_block, bool eliminate_object);
    ~O_Block();
};

class T_Block : public Block{

    T_Block(std::vector<std::pair<int, int>> position_block, char block_symbol, unsigned int width, unsigned int height, bool stop_block, bool eliminate_object);
    ~T_Block();
};

class Z_Block : public Block{

    Z_Block(std::vector<std::pair<int, int>> position_block, char block_symbol, unsigned int width, unsigned int height, bool stop_block, bool eliminate_object);
    ~Z_Block();
};

#endif