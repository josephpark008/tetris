#ifndef LBLOCK_HPP
#define LBLOCK_HPP
#include <array> 

typedef std::array<std::array<int, 4>, 4> blockMap;



class LBlock {
  public: 
    LBlock();
    blockMap map();    
};

#endif