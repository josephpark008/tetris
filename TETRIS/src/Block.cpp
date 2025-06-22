#include "../include/Block.hpp"
#include <iostream>
#include <utility>
#include <array> 
#include <random>  
#include "../include/LBlock.hpp"
#include "../include/TBlock.hpp"
#include "../include/SBlock.hpp"
#include "../include/S2Block.hpp"
#include "../include/IBlock.hpp"


Block::Block() {
};

blockQ Block::nextBlock(){
  std::array<int, 5> blockSelection = {0,1,2,3,4};
  std::random_device rd;  // Non-deterministic random device
  std::mt19937 gen(rd()); // Mersenne Twister engine seeded with rd()
  std::uniform_int_distribution<> distrib(0, blockSelection.size() - 1);
  int randomIndex = distrib(gen);

switch(randomIndex) {
         case 0: {
             IBlock I;
             return I.map();
         }
         case 1: {
             TBlock T;
             return T.map();
         }
         case 2: {
             SBlock S;
             return S.map();
         }
         case 3: {
             S2Block S2;
             return S2.map();
         }
         case 4: {
             LBlock L;
             return L.map();
         }
         default: {
             LBlock L;
             return L.map();
         }
}

};


