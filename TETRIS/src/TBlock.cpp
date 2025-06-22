#include "../include/TBlock.hpp"
#include <iostream>
#include <array> 

TBlock::TBlock() {
};

blockMap TBlock::map(){
  blockMap map = {{{0,1,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0}}};
  return map;
}
