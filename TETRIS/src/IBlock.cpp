#include "../include/IBlock.hpp"
#include <iostream>
#include <array> 


IBlock::IBlock() {
};

blockMap IBlock::map(){
  blockMap map = {{{1,1,1,1}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}}};
  return map;
}
 