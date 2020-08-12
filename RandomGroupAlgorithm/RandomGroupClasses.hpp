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
    void init(int x, int y, int index);
    int xPos;
    int yPos;
    int index;
    bool inGroup;
};
class Grid{
public:
    Grid();
    ~Grid();
    void init(int width, int height);
    static int numIndeces;
    int width;
    int height;
    Space memberSpaces[16][16];
    int memberIndeces[256];
    bool areAdjacent(Space spaceA, Space spaceB);
};
class Group{
public:
    Group();
    ~Group();
    Grid workingGrid;
    int members;
    int optionCount;
    void init(Space firstSpace, Grid grid);
    void addSpace();
    void updateOptions();
    bool spacesFree[16][16];
   
private:
    Space *_memberSpaces[15];
    Space *_optionSpaces[15 * 8];
}
#endif /* RandomGroupClasses_hpp */
