// Player.hpp
#ifndef BLOCK_HPP
#define BLOCK_HPP
#include <array> 
#include <tuple>

typedef std::array<std::array<int, 4>, 4> blockQ;

class Block {
public:
    Block();
    int blockType;
    blockQ nextBlock();
};

#endif


//4 Block types: (L,T,S,Square) = (0,1,2,3)
//handle request for new block

