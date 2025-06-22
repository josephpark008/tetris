#include "../include/LBlock.hpp"
#include <iostream>
#include <array> 


LBlock::LBlock() {
};

blockMap LBlock::map(){
  blockMap map = {{{1,0,0,0}, {1,0,0,0}, {1,1,0,0}, {0,0,0,0}}};
  return map;
}

