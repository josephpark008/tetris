#include "../include/SBlock.hpp"
#include <iostream>
#include <array> 

SBlock::SBlock() {
};

blockMap SBlock::map(){
  blockMap map = {{{0,0,1,1}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0}}};
  return map;
}
