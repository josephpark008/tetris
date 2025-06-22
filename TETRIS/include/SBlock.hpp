#ifndef SBLOCK_HPP
#define SBLOCK_HPP
#include <array> 

typedef std::array<std::array<int, 4>, 4> blockMap;

class SBlock {
  public:
    SBlock();
    blockMap map();
};

#endif