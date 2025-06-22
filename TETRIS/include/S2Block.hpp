#ifndef S2BLOCK_HPP
#define S2BLOCK_HPP
#include <array> 

typedef std::array<std::array<int, 4>, 4> blockMap;


 
class S2Block {
  public:
    S2Block();
    blockMap map();
};

#endif