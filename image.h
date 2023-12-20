#ifndef _IMAGE_H_
#define IMAGE_H_

#include "maps.h"

char S1 = "#";
char S2 = "0";

int north = player.x--;
int east = player.y--;
int west = player.y++;
int south = player.x++;

struct Position player;

/*
void RightImage(int playerX, int playerY, struct Position here, int playerZ){
    
    switch(playerZ){
        case 0:
            map[BOUND][BOUND] == Tutorial[BOUND][BOUND];
            break;
        .....
    }

    All directions
    map[playerX][playerY] == '#'

}
*/

switch (player.direction)
{
case 1:
    switch (north)
    {
    case S1:
    
        break;
    
    default:
        break;
    }
    break;
case 2:
    break;
case 3:
    break;
case 4:
    break;
}

#endif