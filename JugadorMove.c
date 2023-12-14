#include <stdio.h>
#include <stdbool.h>
#include "map.h"

#define BOUND 40

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
        selectedMap[BOUND][BOUND] == Tutorial[BOUND][BOUND];
        break;
        case 1:
        selectedMap[BOUND][BOUND] == map1[BOUND][BOUND];
        break;
        case 2:
        selectedMap[BOUND][BOUND] == map2[BOUND][BOUND];
        break;
        case 3:
        selectedMap[BOUND][BOUND] == map3[BOUND][BOUND];
        break;
        case 4:
        selectedMap[BOUND][BOUND] == map4[BOUND][BOUND];
        break;
    }
    
    for (int i = 0; i < BOUND; i++) {
        for (int j = 0; j < BOUND; j++) {
            if (selectedMap[i][j] == 'S') {
                *playerX = i; //X position
                *playerY = j; //Y position
                return;
            }
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
bool isValidMove(int x, int y, int *playerX, int *playerY) {
    if (x >= 0 && x < BOUND && y >= 0 && y < BOUND) {
        if (map[x][y] != '#') { // Check if the position is not a barrier
            if (map[x][y] == 'U' || map[x][y] == 'E') {
                // Check if the position has a fight ('U' (useless) or 'E' (enemy))
                // Go to fight module
                printf("\nEntering fight mode!\n
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
    int playerX, playerY;
    int head = 1;
    int playerZ = 0;

    //Busca la posición principal de la mapa
    findPlayerStartPosition(&playerX, &playerY, playerZ);

    //Pone la mapa a la pantalla
    for (int i = 0; i < BOUND; i++) {
        for (int j = 0; j < BOUND; j++) {
            map[i][j] = map2[i][j];
        }
    }

    //escribimos jugador en la mapa
    map[playerX][playerY] = '@';

    bool running = true;
    char move;

    while (running) {
        printMap(map);

        printf("\nEnter movement (WASD) or (QE) for moving head: ");
        scanf(" %c", &move);

        int newX = playerX;
        int newY = playerY;

        switch (move) {
            case 'w':
                WMoves(head, &newX, &newY);
                break;
            case 's':
                SMoves(head, &newX, &newY);
                break;
            case 'a':
                AMoves(head, &newX, &newY);
                break;
            case 'd':
                DMoves(head, &newX, &newY);
                break;
            case 'q':
                head++;
                
                if(head == 5){
                    head = 1;
                }
                
                break;
            case 'e':
                head--;
                
                if(head == 0){
                    head = 4;
                }
                
                break;
            default:
                printf("\nInvalid input!\n");
                continue;
        }

        if (isValidMove(newX, newY, &playerX, &playerY)) {
            map[playerX][playerY] = '@'; // Set new player position
        } else {
            printf("\nInvalid move!\n");
        }
        
    }

    return 0;
}

