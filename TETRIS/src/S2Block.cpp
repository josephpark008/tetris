#include "../include/S2Block.hpp"
#include <iostream>
#include <array> 

S2Block::S2Block() {
};

blockMap S2Block::map(){
  blockMap map = {{{1,1,0,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0}}};
  return map;
}

