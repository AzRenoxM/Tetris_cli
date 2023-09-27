#include "Tetris.hpp"

Tetris::Tetris(int width, int height, int score, bool gameover, char border_symbol, char empty_space, char block_symbol)
   : width(width), height(height), score(score), gameover(gameover), border_symbol(border_symbol), empty_space(empty_space), block_symbol(block_symbol) {
   border = new char*[height];
   for(size_t index{0}; index < height; index++){
      this->border[index] = new char[width];
   }
   draw();
}

Tetris::~Tetris(){
   for(size_t index{0}; index < height; index++){
      delete[] border[index];
   }
   delete[] border;
}

void Tetris::update(){
   for(size_t index{0}; index < this->height; index++){
      for(size_t jndex{0}; jndex < this->width; jndex++){
         if((index == 0 || index == this->height - 1) || jndex == 0 || jndex == this->width - 1){
            this->border[index][jndex] = this->border_symbol;
         }
      }
   
   }
   
}