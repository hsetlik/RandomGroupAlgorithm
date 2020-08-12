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



