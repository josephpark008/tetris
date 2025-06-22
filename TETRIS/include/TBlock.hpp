#ifndef TBLOCK_HPP
#define TBLOCK_HPP
#include <array> 

typedef std::array<std::array<int, 4>, 4> blockMap;


class TBlock {
    public:
    TBlock();
    blockMap map();
};

#endif