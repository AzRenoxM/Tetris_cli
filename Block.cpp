#include"Block.hpp"

void Block::move_right(){
   for(size_t index{0}; index < this->position_block.size(); index++){
      if(check_collision){
			break;
      } else {
			this->position_block[index].first++;
		}		
   }
}

void Block::move_left(){
	for(size_t index{0}; index < this->position_block.size(); index++){
		if(check_collision){
			break;
		} else {
			this->position_block[index].first--;
		}		
	}
}

void Block::value_fall(){
    for(size_t index{0}; index < this->position_block.size(); index++){
        this->position_block[index].second++;
    }
}
