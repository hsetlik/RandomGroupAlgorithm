//
//  RandomGroupClasses.hpp
//  RandomGroupAlgorithm
//
//  Created by Hayden on 8/11/20.
//  Copyright © 2020 Hayden Setlik. All rights reserved.
//

#ifndef RandomGroupClasses_hpp
#define RandomGroupClasses_hpp
#include <stdio.h>
#include <fstream>

class Space{
public:
    Space();
    ~Space();
    void init(int x, int y);
    int xPos;
    int yPos;
};
class Grid{
public:
    Grid();
    ~Grid();
    void init(int width, int height);
    bool areAdjacent(Space spaceA, Space spaceB);
};
class Group{
public:
    Group();
    ~Group();
    
}


#endif /* RandomGroupClasses_hpp */
