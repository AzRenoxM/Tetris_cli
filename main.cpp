#include "Tetris.hpp"

int main(int argc, char** arhv){
    
    Tetris game{};
    int success = game.run();

    return !success;
}
