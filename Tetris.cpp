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
   std::system("sleep 1");
}

int Tetris::run(){
   while(!gameover){
      update();
      draw();
      // input();
   }
   return 1;
}

void Tetris::update(){
   //! create random block if last block stop_block is true, or if it empty, or if it is at the bottom
   if(!this->block_list.empty()){
      if(this->block_list.back()->stop_block){
         this->block_list.push_back(new I_Block(this->block_symbol, this->width, this->height, false, false)); //! I'm initializating a virtual class pure error
         std::cout << this->block_list[this->block_list.size() - 1]->stop_block << std::endl;
         std::cout << "test 1" << std::endl;
      } else if(this->check_collision_block() && !this->block_list.back()->stop_block){
         this->block_list.back()->stop_block = true;
         std::cout << "test 2" << std::endl;

      } else {
         this->block_list.back()->move_fall();

         std::cout << "test 3" << std::endl;

      }
   } else {
      this->block_list.push_back(new I_Block(this->block_symbol, this->width, this->height, 0, 0));
      std::cout << "test 4" << std::endl;

   }
}

bool Tetris::check_collision_block(){
   // this->block_list
   //! make an algorithm to check if the block is colliding with another block
   
   return false;
}
   
