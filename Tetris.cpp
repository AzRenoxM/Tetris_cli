#include "Tetris.hpp"

Tetris::Tetris(int width, int height, int score, bool gameover, char border_symbol, char empty_space, char block_symbol)
   : width(width), height(height), score(score), gameover(gameover), border_symbol(border_symbol), empty_space(empty_space), block_symbol(block_symbol) {
   border = new char*[height];
   for(size_t index{0}; index < height; index++){
      this->border[index] = new char[width];
   }
   for(size_t index{0}; index < height; index++){
      for(size_t inner_index{0}; inner_index < width; inner_index++){
         if(index == 0 || index == height - 1 || inner_index == 0 || inner_index == width - 1){
            border[index][inner_index] = border_symbol;
         }
         else{
            border[index][inner_index] = empty_space;
         }
      }
   }
   draw();
}

Tetris::~Tetris(){
   for(size_t index{0}; index < height; index++){
      delete[] border[index];
   }
   delete[] border;
}

void Tetris::draw(){
   std::system("clear");
   for(size_t index{0}; index < height; index++){
      for(size_t inner_index{0}; inner_index < width; inner_index++){
         bool block_exist{false};
         for(size_t block_index{0}; block_index < this->block_list.size(); block_index++){
            for(size_t block_inner_index{0}; block_inner_index < this->block_list[block_index]->position_block.size(); block_inner_index++){
               if(this->block_list[block_index]->position_block[block_inner_index].first == inner_index && this->block_list[block_index]->position_block[block_inner_index].second == index){
                  std::cout << this->block_symbol;
                  block_exist = true;
               }
            }
         }
         if(!block_exist) std::cout << border[index][inner_index];
      }
      std::cout << std::endl;
   }
   std::cout << std::endl;     
   std::cout << "Score: " << score << std::endl;
   
   //! for testing
   if(this->block_list.empty()){
      std::cout << "empty" << std::endl;
   } else {
      std::cout << "Stop Block value: " << this->block_list.back()->stop_block << std::endl;
   } 
   if(!this->block_list.empty()){
      for(size_t index{0}; index < this->block_list.back()->position_block.size(); index++){
         std::cout << this->block_list.back()->position_block[index].first << " " << this->block_list.back()->position_block[index].second << std::endl;
      }
   }
   std::system("sleep 2");
}

int Tetris::run(){
   while(!gameover){
      update();
      draw();
      // input();
   }
   return 1;
}

//TODO random blocks 
//TODO input
//TODO score with gameover if the block reach the top
//TODO check collision with other blocks X plane
//TODO line clear + points

void Tetris::update(){
   if(!this->block_list.empty()){ 
      if(this->block_list.back()->stop_block){ 
         this->block_list.push_back(new I_Block(this->block_symbol, this->width, this->height, false, false));
         std::cout << "the last block is stop block" << this->block_list[this->block_list.size() - 1]->stop_block << std::endl;
      } else if(this->check_collision_block() && !this->block_list.back()->stop_block){ 
         this->block_list.back()->stop_block = true;
      } else {
         this->block_list.back()->move_fall();
      }
   } else {
      this->block_list.push_back(new I_Block(this->block_symbol, this->width, this->height, 0, 0));
   }
}

bool Tetris::check_collision_block(){
   for(size_t index{0}; index < this->block_list.size() - 1; index++){
      for(size_t inner_index{0}; inner_index < this->block_list[index]->position_block.size(); inner_index++){
         for(size_t block_index{0}; block_index < this->block_list.back()->position_block.size(); block_index++){
            if(this->block_list.back()->position_block[block_index].second == this->block_list[index]->position_block[inner_index].second - 1 && this->block_list.back()->position_block[block_index].first == this->block_list[index]->position_block[inner_index].first){
               return true;
            }
         }
      }
   }
   return false;
}
   
