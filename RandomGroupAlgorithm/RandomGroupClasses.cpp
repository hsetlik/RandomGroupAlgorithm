//
//  RandomGroupClasses.cpp
//  RandomGroupAlgorithm
//
//  Created by Hayden on 8/11/20.
//  Copyright © 2020 Hayden Setlik. All rights reserved.
//
#include "RandomGroupClasses.hpp"
#include <cmath>

Space::Space() {
}

Space:: ~Space(){
    
}

void Space::init(int x, int y, int indexChoice){
    xPos = x;
    yPos = y;
    index = indexChoice;
    inGroup = false;
}

Grid::Grid(){
    
}
Grid::~Grid(){
}
void Grid::init(int width, int height){
    numIndeces = 256;
    int currentIndex = 0;
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            memberSpaces[x][y].init(x, y, currentIndex);
            currentIndex++;
        }
    }
}
bool Grid::areAdjacent(Space spaceA, Space spaceB){
    //making a list of all 8 adjacent tiles
    int testX = spaceA.xPos;
    int testY = spaceA.yPos;
    Space adjacentSpaces[8];
    adjacentSpaces[0] = memberSpaces[testX - 1][testY - 1]; // top left
    adjacentSpaces[0] = memberSpaces[testX][testY - 1]; //top center
    adjacentSpaces[0] = memberSpaces[testX + 1][testY - 1]; //top right
    adjacentSpaces[0] = memberSpaces[testX + 1][testY]; //right side
    adjacentSpaces[0] = memberSpaces[testX + 1][testY + 1]; //bottom right
    adjacentSpaces[0] = memberSpaces[testX][testY + 1]; // bottom center
    adjacentSpaces[0] = memberSpaces[testX - 1][testY + 1]; //bottom left
    adjacentSpaces[0] = memberSpaces[testX - 1][testY]; //left side
    
    for(int i = 0; i < 8; i++){
        if(adjacentSpaces[i].xPos == testX &
           adjacentSpaces[i].yPos == testY){
            return true;
            break;
        }
    }
    return false;
    }

Group::Group(){
}
Group::~Group(){
}
void Group::init(Space firstSpace, Grid grid){
    workingGrid = grid;
    members = 0;
    optionCount = 0;
    for(int x = 0; x < 16; x++){
        for(int y = 0; y < 16; y++){
            spacesFree[x][y] = false;
        }
    }
    int firstX = firstSpace.xPos;
    int firstY = firstSpace.yPos;
    _memberSpaces[0] = &workingGrid.memberSpaces[firstX][firstY];
    members++;
    for(int x = 0; x < 16; x++){
        for(int y = 0; y < 16; y++){
            if(workingGrid.areAdjacent(*_memberSpaces[0], workingGrid.memberSpaces[x][y])){
                spacesFree[x][y] = true;
            }
        }
    }
}

void Group::addSpace(){
    
    for(int x = 0; x < 16; x++){
    for(int y = 0; y < 16; y++){
        
    }
    }
    
    
}

