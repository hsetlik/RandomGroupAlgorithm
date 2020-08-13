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
//areAdjacent is tested working
bool Grid::areAdjacent(Space spaceA, Space spaceB){
    //making a list of all 8 adjacent tiles
    int testX = spaceA.xPos;
    int testY = spaceA.yPos;
    int testAX[8];
    int testAY[8];
    //top left
    testAX[0] = testX - 1;
    testAY[0] = testY - 1;
    //top center
    testAX[1] = testX;
    testAY[1] = testY - 1;
    //top right
    testAX[2] = testX + 1;
    testAY[2] = testY - 1;
    //right side
    testAX[3] = testX + 1;
    testAY[3] = testY;
    //bottom right
    testAX[4] = testX + 1;
    testAY[4] = testY + 1;
    //bottom center
    testAX[5] = testX;
    testAY[5] = testY + 1;
    //bottom left
    testAX[6] = testX - 1;
    testAY[6] = testY + 1;
    //left side
    testAX[7] = testX - 1;
    testAY[7] = testY;
    bool returnBool = false;
    int checkXB = spaceB.xPos;
    int checkYB = spaceB.yPos;
    for(int i = 0; i < 8; i++){
        if(testAX[i] == checkXB){
            if(testAY[i] == checkYB){;
            returnBool = true;
        }
    }
    }
    return returnBool;
}
Group::Group(){
}
Group::~Group(){
}
void Group::init(Space firstSpace, Grid grid){
    printf("group begun at: [%d][%d]\n", firstSpace.xPos, firstSpace.yPos);
    workingGrid = grid;
    members = 0;
    optionCount = 1;
    for(int x = 0; x < 16; x++){
        for(int y = 0; y < 16; y++){
            spacesFree[x][y] = false;
        }
    }
    int firstX = firstSpace.xPos;
    int firstY = firstSpace.yPos;
    printf("first space chosen at: [%d][%d]\n", firstX, firstY);
    workingGrid.memberSpaces[firstX][firstY].inGroup = true;
    spacesFree[firstX][firstY] = false;
    _memberSpaces[0] = workingGrid.memberSpaces[firstX][firstY];
    members++;
    int doubleCheckX = _memberSpaces[0].xPos;
    int doubleCheckY = _memberSpaces[0].yPos;
    printf("first space assigned to _memberSpaces at: [%d][%d]\n", doubleCheckX, doubleCheckY);
    
    updateOptions();
    printf("Group initialized\n");
}

void Group::updateOptions(){
    printf("updateOptions started\n\n");
    for(int x = 0; x < 16; x++){
        for(int y = 0; y < 16; y++){
            if((workingGrid.areAdjacent(_memberSpaces[members - 1],workingGrid.memberSpaces[x][y])) &&
               (workingGrid.memberSpaces[x][y].inGroup == false))
            {
                bool duplicateChecker = false;
                for(int i = 0; i < optionCount; i++){
                    int optX = _optionSpaces[i].xPos;
                    int optY = _optionSpaces[i].yPos;
                    if((optX == x )&&( optY == y)){
                        duplicateChecker = true;
                    }
                }
                if(duplicateChecker == false){
                printf("Free space at: [%d][%d]\n", x, y);
                spacesFree[x][y] = true;
                _optionSpaces[optionCount] = workingGrid.memberSpaces[x][y];
                optionCount++;
                }
            }
        }
    }
    printf("updateOptions finished\n\n");
}

void Group::addSpace(){
    int spaceChoice = rand() % (optionCount);
    printf("Possible indeces: %d\n", optionCount);
    printf("Chosen space index: %d\n", spaceChoice);
    int testX = _optionSpaces[spaceChoice].xPos;
    int testY = _optionSpaces[spaceChoice].yPos;
    printf("X at chosen index: %d\n", testX);
    printf("Y at chosen indes: %d\n", testY);
    Space chosenSpace = _optionSpaces[spaceChoice];
    printf("chosen X: %d\n", chosenSpace.xPos);
    printf("chosen Y: %d\n", chosenSpace.yPos);
    int chosenX = chosenSpace.xPos;
    int chosenY = chosenSpace.yPos;
    spacesFree[chosenX][chosenY] = false;
    chosenSpace.inGroup = true;
    _memberSpaces[members] = chosenSpace;
    members++;
    
}

void Group:: fillGroup(int size){
    for(int i = 0; i < size; i++){
        addSpace();
        updateOptions();
    }
}

void Group::printGroup(){
    for(int i = 0; i < members; i++){
        int memberX = _memberSpaces[i].xPos;
        int memberY = _memberSpaces[i].yPos;
        printf("Group Member #%d: [%d][%d]\n", i, memberX, memberY);
    }
}



