#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <array>
#include "./include/Block.hpp"

typedef std::vector<std::vector<int> > map;
typedef std::vector<std::vector<std::array <int, 2> > > mapCoordinates;

class Map
{

  public:
    int points = 0;
    map currentMap;
    Map(map currentMap = map(), bool blockPlaced = false)
    {
      if (currentMap.empty()){
       this->currentMap = this->newMap();
      } else {
        if (blockPlaced == true){
          this->currentMap = currentMap;
          for (int i = this->currentMap.size() - 1; i >= 0; i--){
              bool rowComplete = true;
              for (int j = 0; j < this->currentMap[i].size(); j++){
                if (this->currentMap[i][j] != 2){
                    rowComplete = false;
                    break;
                }
              }
              if (rowComplete){
                for (int l = i; l > 0; l--) {
                    this->currentMap[l] = this->currentMap[l - 1]; // Shift row down
                }
                // Clear the new top row (row 0)
                for (int k = 0; k < this->currentMap[0].size(); k++) {
                    this->currentMap[0][k] = 0;
                }
                points++;
                i++;
              }
          }
          Block newBlock;
          std::array<std::array<int, 4>, 4>  block = newBlock.nextBlock();
          for (int i = 0; i < block.size(); i++){
              for (int j = 0; j < block[i].size(); j++){
                  if (block[i][j] == 1){
                    this->currentMap[i][3 + j] = 1;
                  }
              }
          }
        } else {
          this->currentMap = currentMap;
        }
      }
    };

    //CREATE new grid
    map newMap(){
          const int rows = 20;
          const int columns = 10;
          map grid;
          for (int i = 0; i < rows; i++){
            std::vector<int> row;
            for (int j = 0; j < columns; j++){
              row.push_back(0);
            }
            grid.push_back(row);
          }

          //then insert new block in grid
          Block newBlock;
          std::array<std::array<int, 4>, 4>  block = newBlock.nextBlock();
          for (int i = 0; i < block.size(); i++){
              for (int j = 0; j < block[i].size(); j++){
                  if (block[i][j] == 1){
                    grid[i][3 + j] = 1;
                  }
              }
          }
          return grid;
    }

    //CONVERT matrix to SMFL grid
    mapCoordinates convert()
    {
      mapCoordinates windowCoordinates;
      for (int i = 0; i < currentMap.size(); i++)//columns
      {
        std::vector<std::array<int, 2> > row;
        for (int j = 0; j < currentMap[i].size(); j++) //rows
        {
          std::array<int, 2> newCoordinate;
          int newX = j * 25.f;
          int newY = i * 25.f;
          newCoordinate[0] = newX;
          newCoordinate[1] = newY;
          row.push_back(newCoordinate);
        }
	    windowCoordinates.push_back(row);
      }
    return windowCoordinates;
    }
};


int main()
{
  sf::RenderWindow window(sf::VideoMode(250, 500), "SFML 3 Test");
    const int rows = 20;
    const int columns = 10;
    Map freshMap;
    int totalPoints = 0;
    mapCoordinates convertedGrid = freshMap.convert();
    // window.setKeyRepeatEnabled(false);
    sf::Clock clock;  // Starts the clock
    float interval = 1.0f;
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Space)
            {
              //PRINT convertedGrid **WORKS AS EXPECTED
              // std::cout << "[" << std::endl;
              // for (const auto& row : convertedGrid) {
              //     std::cout << "  [" << std::endl;
              //     for (const auto& point : row) {
              //         std::cout << "    [ " << point[0] << ", " << point[1] << " ]" << std::endl;
              //     }
              //     std::cout << "  ]" << std::endl;
              // }
              // std::cout << "]" << std::endl;  
            }
            if (event.key.code == sf::Keyboard::Right){
              bool canMove = true;
              std::vector<std::array<int, 2> > blockS2s;
              for (int i = 0; i < freshMap.currentMap.size(); i++){
                  for (int j = freshMap.currentMap[i].size() - 1; j >= 0; j--){
                        if (freshMap.currentMap[i][j] == 1){
                          if (j != freshMap.currentMap[i].size() - 1){
                              if (freshMap.currentMap[i][j + 1] != 2){
                                  std::array<int, 2> coordinates = {i, j};
                                  blockS2s.push_back(coordinates);
                              } else {
                                canMove = false;
                              }
                          } else {
                            canMove = false;
                          }
                        }
                  }
              }
              if (canMove == true){
                for (int i = 0; i < blockS2s.size(); i++){
                  freshMap.currentMap[blockS2s[i][0]][blockS2s[i][1]] = 0;
                  freshMap.currentMap[blockS2s[i][0]][blockS2s[i][1] + 1] = 1;
                }
              }
            }
            if (event.key.code == sf::Keyboard::Left){
              bool canMove = true;
              std::vector<std::array<int, 2> > blockS2s;
              for (int i = 0; i < freshMap.currentMap.size(); i++){
                  for (int j = 0; j < freshMap.currentMap[i].size(); j++){
                        if (freshMap.currentMap[i][j] == 1){
                          if (j != 0){
                              if (freshMap.currentMap[i][j - 1] != 2){
                                  std::array<int, 2> coordinates = {i, j};
                                  blockS2s.push_back(coordinates);
                              } else {
                                canMove = false;
                              }
                          } else {
                            canMove = false;
                          }
                        }
                  }
              }
              if (canMove == true){
                for (int i = 0; i < blockS2s.size(); i++){
                  freshMap.currentMap[blockS2s[i][0]][blockS2s[i][1]] = 0;
                  freshMap.currentMap[blockS2s[i][0]][blockS2s[i][1] - 1] = 1;
                }
              }
            }
            if (event.key.code == sf::Keyboard::Down) {
              
              bool canMove = true;
              std::vector<std::array<int, 2> > blockS2s;
              for (int i = freshMap.currentMap.size() - 1; i >= 0; i--){
                  for (int j = 0; j < freshMap.currentMap[i].size(); j++){
                        if (freshMap.currentMap[i][j] == 1){
                          if (i != freshMap.currentMap.size() - 1){
                              if (freshMap.currentMap[i + 1][j] != 2){
                                  std::array<int, 2> coordinates = {i, j};
                                  blockS2s.push_back(coordinates);
                              } else {
                                canMove = false;
                              }
                          } else {
                            canMove = false;
                          }
                        }
                  }
              }
              if (canMove == true){
                for (int i = 0; i < blockS2s.size(); i++){
                  freshMap.currentMap[blockS2s[i][0]][blockS2s[i][1]] = 0;
                  freshMap.currentMap[blockS2s[i][0] + 1][blockS2s[i][1]] = 1;
                }
              }

            }
            if (event.key.code == sf::Keyboard::Up){
                std::vector<std::array<int, 2> > currentBlocks;

                    for (int i = 0; i < freshMap.currentMap.size(); i++) {
                        for (int j = 0; j < freshMap.currentMap[i].size(); j++) {
                            if (freshMap.currentMap[i][j] == 1) {
                                std::array<int, 2> coordinates = {i, j};
                                currentBlocks.push_back(coordinates);
                            }
                        }
                    }

                    int pivotRow = currentBlocks[0][0]; // Example pivot: top-left block
                    int pivotCol = currentBlocks[0][1];

                    std::vector<std::array<int, 2> > rotatedBlocks;
                    bool rotatable = true;

                    for (auto& coord : currentBlocks) {
                        int r = coord[0];
                        int c = coord[1];

                        // Translate to origin
                        int relativeR = r - pivotRow;
                        int relativeC = c - pivotCol;

                        // Apply 90° rotation clockwise: (r, c) => (c, -r)
                        int rotatedR = relativeC;
                        int rotatedC = -relativeR;

                        // Translate back
                        int newRow = pivotRow + rotatedR;
                        int newCol = pivotCol + rotatedC;

                        // Check bounds
                        if (newRow < 0 || newRow >= freshMap.currentMap.size() || newCol < 0 || newCol >= freshMap.currentMap[0].size()) {
                            rotatable = false;
                            break;
                        }

                        // Check collision
                        if (freshMap.currentMap[newRow][newCol] == 2) {
                            rotatable = false;
                            break;
                        }
                        std::array<int, 2> coordinates = {newRow, newCol};
                        rotatedBlocks.push_back(coordinates);
                    }

                    // 3. Apply new positions if rotatable
                    if (rotatable) {
                        for (auto& coord : currentBlocks) {
                            freshMap.currentMap[coord[0]][coord[1]] = 0;
                        }
                        for (auto& coord : rotatedBlocks) {
                            freshMap.currentMap[coord[0]][coord[1]] = 1;
                        }
                    }
            }
        }
      if (event.type == sf::Event::Closed)
        {
          window.close();
        }
   }

    if (clock.getElapsedTime().asSeconds() >= interval) {
    bool blockPlaced = false;
    std::vector<std::array<int, 2> > fallBlockS2s; 

    // std::cout << "[" << std::endl;
    // for (const auto& row : freshMap.currentMap) {
    //   std::cout << "  [ ";
    //   for (int val : row) std::cout << val << " ";
    //   std::cout << "]" << std::endl;
    // }
    // std::cout << "]" << std::endl;

        //check 1 row below, see if it is a 1 or if the current block is placed on the last row
    for (int i = freshMap.currentMap.size() - 1; i >= 0; i--) {
        for (int j = 0; j < freshMap.currentMap[0].size(); j++) {
            int currentBlock = freshMap.currentMap[i][j];

            if (currentBlock == 1) {
                bool placed = false;

                // Check if it's on the bottom row
                if (i == freshMap.currentMap.size() - 1) {
                    placed = true;
                }
                // Check if there's a placed block (2) below
                else if (freshMap.currentMap[i + 1][j] == 2) {
                    placed = true;
                }

                if (placed) {
                    blockPlaced = true;
                } 
                std::array<int, 2> coordinates = {i, j};
                fallBlockS2s.push_back(coordinates);
            }
        }
    }

    //Falling block logic
    for (int i = 0; i < fallBlockS2s.size(); i++){
      int row = fallBlockS2s[i][0];
      int column = fallBlockS2s[i][1];
      if (blockPlaced == true){
        freshMap.currentMap[row][column] = 2; 
      } else {
        freshMap.currentMap[row][column] = 0;
        freshMap.currentMap[row + 1][column] = 1;
      }
    }

    if (blockPlaced == true){
        map refreshedMap = freshMap.currentMap;
        Map map(refreshedMap, true);
        freshMap = map.currentMap;
        totalPoints += map.points;
        std::cout << "SCORE: " << totalPoints << std::endl;
    }

    clock.restart();
    }

  //RENDER grid
    window.clear();
    for (int i = 0; i < rows; i++){
      for (int j = 0; j < columns; j++){
        sf::RectangleShape square(sf::Vector2f(25.f, 25.f));
        if (freshMap.currentMap[i][j] == 1 || freshMap.currentMap[i][j] == 2){
          square.setFillColor(sf::Color::Blue);
          square.setOutlineColor(sf::Color::White);
          square.setOutlineThickness(1.f); 
          square.setPosition(sf::Vector2f(convertedGrid[i][j][0], convertedGrid[i][j][1]));
          window.draw(square);
        }
      }
    }

    window.display();
  }

  return 0;
}
