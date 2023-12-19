#include <stdio.h>
#include <stdbool.h>
#include "map.h"

#define BOUND 40
#define MAX_MAPS 5

char map[BOUND][BOUND]; //Declaración de mapa

//Movimientos con el botton W
void WMoves(int head, int *X, int *Y){
    switch(head){
        case 1:
            (*X)--;
        break;
        case 2:
            (*Y)--;
        break;
        case 3:
            (*X)++;
        break;
        case 4:
            (*Y)++;
        break;
    }
}

//Movimientos con el botton D
void DMoves(int head, int *X, int *Y){
    switch(head){
        case 2:
            (*X)--;
        break;
        case 3:
            (*Y)--;
        break;
        case 4:
            (*X)++;
        break;
        case 1:
            (*Y)++;
        break;
    }
}

//Movimientos con el botton S
void SMoves(int head, int *X, int *Y){
    switch(head){
        case 3:
            (*X)--;
        break;
        case 4:
            (*Y)--;
        break;
        case 1:
            (*X)++;
        break;
        case 2:
            (*Y)++;
        break;
    }
}

//Movimientos con el botton A
void AMoves(int head, int *X, int *Y){
    switch(head){
        case 4:
            (*X)--;
        break;
        case 1:
            (*Y)--;
        break;
        case 2:
            (*X)++;
        break;
        case 3:
            (*Y)++;
        break;
    }
}

//Busca la posición de la empieza
void findPlayerStartPosition(int *playerX, int *playerY, int playerZ) {
    const char(*selectedMap)[BOUND][BOUND];
    
    switch(playerZ){
        case 0:
        selectedMap = &Tutorial;
        break;
        case 1:
        selectedMap = &map1;
        break;
        case 2:
        selectedMap = &map2;
        break;
        case 3:
        selectedMap = &map3;
        break;
        case 4:
        selectedMap = &map4;
        break;
    }
    
    bool found = false;
    for (int i = 0; i < BOUND; i++) {
        for (int j = 0; j < BOUND; j++) {
            if ((*selectedMap)[i][j] == 'S') {
                *playerX = i; //X position
                *playerY = j; //Y position
                found = true;
                break;
            }
        }
        if(found){
            break;
        }
    }
}

//Print map
void printMap(const char map[BOUND][BOUND]) {
    for (int i = 0; i < BOUND; i++) {
        for (int j = 0; j < BOUND; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

//Check if the player position on a map is valid
bool isValidMove(int x, int y, int *playerX, int *playerY, int *playerZ, bool *finished) {
    if (x >= 0 && x < BOUND && y >= 0 && y < BOUND) {
        if (map[x][y] != '#') { // Check if the position is not a barrier
            if (map[x][y] == 'U' || map[x][y] == 'E') {
                // Check if the position has a fight ('U' (useless) or 'E' (enemy))
                // Go to fight module
                printf("\nEntering fight mode!\n");
            } else if (map[x][y] == 'C') {
                // Check if the position has a chest ('C')
                // rewardChest() function here
                printf("\nOpening a chest!\n");
            } else if (map[x][y] == 'W') {
                // Teleport to position with 'I' if standing on 'W'
                for (int i = 0; i < BOUND; i++) {
                    for (int j = 0; j < BOUND; j++) {
                        if (map[i][j] == 'I') {
                            map[*playerX][*playerY] = ' ';
                            *playerX = i;
                            *playerY = j;
                            return true;
                        }
                    }
                }
            } else if (map[x][y] == '0') {
                // Teleport to position with 'L' if standing on '0'
                for (int i = 0; i < BOUND; i++) {
                    for (int j = 0; j < BOUND; j++) {
                        if (map[i][j] == 'L') {
                            map[*playerX][*playerY] = ' ';
                            *playerX = i;
                            *playerY = j;
                            return true;
                        }
                    }
                }
            } else if(map[x][y] == 'F'){
                    (*finished) = true;
                return true;
                } else {
                // If the position is not a barrier or special character, move the player
                map[*playerX][*playerY] = ' ';
                *playerX = x;
                *playerY = y;
                return true;
            }
        }
    }
    return false;
}

int main() {
    //Variables on position in a map and head
    Position player;

    int x, y;

    int head = 1;
    int mapsDone = 0;

    bool finished = false;

    while (mapsDone != MAX_MAPS){

    if(mapsDone == MAX_MAPS){
        break;
    }

    player.z = mapsDone;

    //Busca la posición principal de la mapa
    findPlayerStartPosition(&player.x, &player.y, player.z);

    switch (player.z){
    case 0:
        for (int i = 0; i < BOUND; i++){
            for (int j = 0; j < BOUND; j++){
                map[i][j] = Tutorial[i][j];
            }
        }
        break;
    case 1:
        for (int i = 0; i < BOUND; i++){
            for (int j = 0; j < BOUND; j++){
                map[i][j] = map1[i][j];
            }
        }
        break;
    case 2:
        for (int i = 0; i < BOUND; i++){
            for (int j = 0; j < BOUND; j++){
                map[i][j] = map2[i][j];
            }
        }
        break;
    case 3:
        for (int i = 0; i < BOUND; i++){
            for (int j = 0; j < BOUND; j++){
                map[i][j] = map3[i][j];
            }
        }
        break;
    case 4:
        for (int i = 0; i < BOUND; i++){
            for (int j = 0; j < BOUND; j++){
                map[i][j] = map4[i][j];
            }
        }
        break;
    }

    //escribimos jugador en la mapa
    map[player.x][player.y] = '@';

    bool running = true;
    char move;

    while (running) {
        printMap(map);

        printf("\nEnter movement (WASD) or (QE) for moving head: ");
        scanf(" %c", &move);

        int newX = player.x;
        int newY = player.y;

        switch (move) {
            case 'w':
            case 'W':
                WMoves(head, &newX, &newY);
                break;
            case 's':
            case 'S':
                SMoves(head, &newX, &newY);
                break;
            case 'a':
            case 'A':
                AMoves(head, &newX, &newY);
                break;
            case 'd':
            case 'D':
                DMoves(head, &newX, &newY);
                break;
            case 'q':
            case 'Q':
                head++;
                
                if(head == 5){
                    head = 1;
                }
                
                break;
            case 'e':
            case 'E':
                head--;
                
                if(head == 0){
                    head = 4;
                }
                
                break;
            default:
                printf("\nInvalid input!\n");
                continue;
        }

        if (isValidMove(newX, newY, &player.x, &player.y, &player.z, &finished)) {
            map[player.x][player.y] = '@'; // Set new player position
        } else {
            printf("\nInvalid move!\n");
        }
        
        if(finished == running){
            running = false;
        }
        
    }

    if (!running){
        mapsDone++;
    }
    
    }

    return 0;
}

