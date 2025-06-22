#ifndef IBLOCK_HPP
#define IBLOCK_HPP
#include <array> 

typedef std::array<std::array<int, 4>, 4> blockMap;



class IBlock {
  public: 
    IBlock();
    blockMap map();    
};

#endif