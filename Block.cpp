#include"Block.hpp"

bool Block::check_collision() const {
	for(size_t index{0}; index < this->position_block.size(); index++){
		if(this->position_block[index].first - 1 == 0 || this->position_block[index].first + 1 == this->width - 1){
			return true;
		} else if(this->position_block[index].second + 1 == this->height - 1){
			return true;
		}
	}
	return false;
}

void Block::check_delete_block(){
	if(this->position_block.size() == 0){
		this->eliminate_object = true;
	}
}

std::vector<std::pair<int, int>> Block::get_position_block() const{
	return this->position_block;
}

void Block::move_right(){
	if(this->check_collision()) return;
   for(size_t index{0}; index < this->position_block.size(); index++){
      if(check_collision){
			break;
      } else {
			this->position_block[index].first++;
		}		
   }
}

void Block::move_left(){
	if(this->check_collision()) return;
	for(size_t index{0}; index < this->position_block.size(); index++){
		if(check_collision){
			break;
		} else {
			this->position_block[index].first--;
		}		
	}
}

void Block::value_fall(){
	if(this->stop_block) return;
	if(this->check_collision()) return;
   for(size_t index{0}; index < this->position_block.size(); index++){
      if(check_collision){
			break;
		} else {
			this->position_block[index].second++;
		}
   }
}

void Block::eliminate_row(unsigned int row_point){
	for(size_t index{0}; index < this->position_block.size(); index++){
		if(this->position_block[index].second == row_point){
			this->position_block.erase(this->position_block.begin() + index);
		}
	}
	this->check_delete_block();
}

void Block::stop_from_fall(){
	this->stop_block = true;
}

Block::Block(char block_symbol, unsigned int width, unsigned int height, bool stop_block, bool eliminate_object)
	: block_symbol(block_symbol), width(width), height(height), stop_block(stop_block), eliminate_object(eliminate_object) {}

Block::~Block(){}
	
//! I_Block

I_Block::I_Block(std::vector<std::pair<int, int>> position_block, char block_symbol, unsigned int width, unsigned int height, bool stop_block, bool eliminate_object)
	: Block(block_symbol, width, height, stop_block, eliminate_object) {
		for (size_t index{1}; index <= 4; index++){
			std::pair<int, int> *pointer_block = new std::pair<int, int>(this->width / 2, index);
			this->position_block.push_back(*pointer_block);
		}
	}

I_Block::~I_Block(){
	for(size_t index{0}; index < this->position_block.size(); index++){
		delete &this->position_block[index];
	}
}

//! L_Block

L_Block::L_Block(std::vector<std::pair<int, int>> position_block, char block_symbol, unsigned int width, unsigned int height, bool stop_block, bool eliminate_object)
	: Block(block_symbol, width, height, stop_block, eliminate_object) {
		for(size_t index{1}; index <= 3; index++){
			std::pair<int, int> *pointer_block = new std::pair<int, int>(this->width / 2, index);
			this->position_block.push_back(*pointer_block);
		}
		std::pair<int, int> *pointer_block = new std::pair<int, int>(this->width / 2 + 1, 3);
	}

L_Block::~L_Block(){
	for(size_t index{0}; index < this->position_block.size(); index++){
		delete &this->position_block[index];
	}
}

//! O_Block

O_Block::O_Block(std::vector<std::pair<int, int>> position_block, char block_symbol, unsigned int width, unsigned int height, bool stop_block, bool eliminate_object)
	: Block(block_symbol, width, height, stop_block, eliminate_object) {
		for(size_t index{1}; index <= 2; index++){
			std::pair<int, int> *pointer_block = new std::pair<int, int>(this->width / 2, index);
			this->position_block.push_back(*pointer_block);
			std::pair<int, int> *pointer_block = new std::pair<int, int>((this->width + 1) / 2, index);
			this->position_block.push_back(*pointer_block);
		}		
	}

O_Block::~O_Block(){
	for(size_t index{0}; index < this->position_block.size(); index++){
		delete &this->position_block[index];
	}
}

//TODO T_Block



//TODO Z_Block
