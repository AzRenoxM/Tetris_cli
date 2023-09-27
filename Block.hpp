#ifndef BLOCK_HPP
#define BLOCK_HPP

#include<iostream>
#include<vector>

class Block{
protected:
    std::vector<std::pair<int, int>> position_block;
    char block_symbol;
    unsigned int width, height;
    bool check_collision() const;
public:
    virtual void rotate() = 0;
    void move_right();
    void move_left();
    void value_fall();
    std::vector<std::pair<int, int>> get_position_block() const;

    Block(char block_symbol, unsigned int width, unsigned int height);
    ~Block();
};

class I_Block : public Block{
    void rotate() override;
};

class L_Block : public Block{
    void rotate() override;
};

class O_Block : public Block{
    void rotate() override;
};

class T_Block : public Block{
    void rotate() override;
};

class Z_Block : public Block{
    void rotate() override;
};

#endif