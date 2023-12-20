/*
Yevhenii Edelshteyn
Marat Galiullin
Abel López Rodríguez
2023-2024
*/

// Bibliotecas requeridas para el juego.
#include <math.h>                   // Libreria matemática
#include <stdbool.h>                // Libreria de los buleanos
#include <stdio.h>                  // Libreria del input-Output
#include <stdlib.h>                 // Libreria estándart del C
#include <time.h>                   // Libreria del tiempo, relevante para los numeros aleatorios
#include "item.h"                  // Header de los objetos del juego
#include "maps.h"                   // Header de los mapas del juego
#include "enemies.h"                // Header de los enemigos del juego

//Constantes utilizadas en le juego
#define NAMEMAX 32
#define BOUND 40
#define MAX_MAPS 5

char map[BOUND][BOUND]; // Global

//Enum de diferentes elementos del juego
// Lista de dificultades presentes en el juego
enum Difficulty{                
    Trivial, Easy, Medium, Hard, Extreme
};

// Lista de posibles acciones del enemigo
enum atk{
    mele, ranged, hability, used_item
};

enum enemy_atk{
    e_mele, e_ranged, e_dmg_attack, e_ult_attack, e_used_item, e_used_heal
};

// Lista de habilidades de los enemigos
enum Enemy_skills{
    heal, buff, damage, ultimate
};

// Lista de actores (Jugador y enemigo)
enum combat_actor{
    opponent
};

// Lista declases de heroes
enum Heroes {
    Mage, Warrior, Rogue, knight
};

// Lista de objetos
enum Items {
    potion_health, potion_strength, potion_stamina, potion_poison, potion_defense, sword, bow, axe, magic_wand
};

// Lista de habilidades
enum SkilList {
    Minor_heal, Greater_heal, Minor_Fireball, Greater_Fireball, Health_Drain, Stamina_Drain, Health_Swap, CBT
};

// Lista de laspartes del cuerpo
enum Body_parts{
    head, body, l_hand, r_hand, l_finger, r_finger, legs
};

// Lista de mejoras de estadisiticas que pueden aportar los objetos
enum Item_statup{
    strenghtup, luckup, agilityup, evadeup, intelligenceup, defenceup
};

// Structs de los elementos básicos como personajes/enemigos, objetos, etc
// Struct delas habilidades
struct Skills{
    int strength;
    int cost;
};

// Struct base de un actor
struct Core{
    char name[NAMEMAX];   
    int health;
    int defence;
    int evade;
    int strength;
    int agility;
    int luck;
    int inteligence;
    int level;
    int stamina;
    int position[2];                 // x-y-z
    struct Skills skill[5];         // El enemigo siempre tiene hasta 4 (curación, bufo, daño, ultimate)
    int range_attack;
    int mele_attack;
};

// Struct del actor enemigo
struct Enemy{
    struct Core core;
    int difficulty;
    int gold_reward;
    int exp_reward;
    int item_reward_chance;
    int item_reward_set[10];          // Objetos que pueden ser recibidos
    bool item_reward;
    int time_effect;
    int meledamage;
    int rangedamage;
    int enemy_health_potion;
};

// Struct de los objetos
struct Item{
    int body_part;
    int price;
    int damage;
    int min_lvl;
    int Item_statup[6];
    int rarity;
    bool range;
    bool mele;
};

// Struct del jugador
struct Hero{                        
    struct Core core;
    int facing_direction[4];
    int class;
    int gold;
    int max_health;
    int experince;
    int perception;
    int time_effect;
    int X_pos;
    int Y_pos;
    int Z_pos;
};

// Main del programa
int main(){

    // Struct game elements declaration
    struct Hero hero;
    struct Enemy enemy;
    struct Position *player;
    hero.core.health = 1;

    main_menu();

    srand(time(NULL));
        do{
            main_menu();
            charcter_create(&hero);
            move(&player, &enemy, &hero);
        }while(hero.core.health != 0);
    
    return 0;
}

int move(struct Position *player, struct Enemy *enemy, struct Hero *hero) {
    //Variables on position in a map and head

    int x, y;

    int head = 1;
    player->direction = 1;
    int mapsDone = 0;

    bool finished = false;

    while (mapsDone != MAX_MAPS){

    if(mapsDone == MAX_MAPS){
        break;
    }

    player->z = mapsDone;

    //Busca la posición principal de la mapa
    findPlayerStartPosition(&player->x, &player->y, player->z);

    switch (player->z){
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
    map[player->x][player->y] = '@';

    bool running = true;
    char move;

    while (running) {
        printMap(map);

        printf("\nEnter movement (WASD) or (QE) for moving head: ");
        scanf(" %c", &move);

        int newX = player->x;
        int newY = player->y;

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
                player->direction = head;
                
                if(head == 5){
                    head = 1;
                    player->direction = head;
                }
                
                break;
            case 'e':
            case 'E':
                head--;
                player->direction = head;
                
                if(head == 0){
                    head = 4;
                    player->direction = head;
                }
                
                break;
            default:
                printf("\nInvalid input!\n");
                continue;
        }

        if (isValidMove(newX, newY, &player->x, &player->y, &player->z, &finished, &enemy, &hero)) {
            map[player->x][player->y] = '@'; // Set new player position
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
bool isValidMove(int x, int y, int *playerX, int *playerY, int *playerZ, bool *finished, struct Enemy *enemy, struct Hero *hero) {
    if (x >= 0 && x < BOUND && y >= 0 && y < BOUND) {
        if (map[x][y] != '#') { // Check if the position is not a barrier
            if (map[x][y] == 'U' || map[x][y] == 'E') {
                combat(&enemy,&hero,&playerX,&playerY,&playerZ);
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

void main_menu(){

    char enter;
    
    printf("Labyrinth by Frög");
    printf("press `c` to continue");
    do{
    scanf("%c",enter);
    }while(enter != "c");
    
}

// Módulo que devueleve un núemro aleatorio entre 0 y 20
int dice_roll(){    
    int dice_result=rand()%21; 
    return dice_result;
}

// Módulo de la creacion del personaje del jugador
void charcter_create(struct Hero *hero){             

printf(" Dime tu nombre: ");
scanf("%c", *hero->core.name);
printf(" elige tu clase: ");
printf(" 1 - Mage ");
printf(" 2 - Warrior ");
printf(" 3 - Rogue ");
printf(" 4 - Knight ");

do{

    scanf("%d",hero->class);

    switch (hero->class)
    {
    case Mage:
        hero->core.agility  = 1;
        hero->core.defence = 3;
        hero->core.evade = 0;
        hero->core.health = 1;
        hero->core.inteligence = 3;
        hero->core.level = 0;
        hero->core.luck = 1;
        hero->core.stamina = 1;
        hero->core.strength = 2;
        hero->core.range_attack = 1;
        hero->core.mele_attack = 0;
        hero->experince = 0;
        hero->gold = 10;
        hero->max_health = 10;
        hero->perception = 0;
        break;
    case Warrior:
        hero->core.agility  = 2;
        hero->core.defence = 2;
        hero->core.evade = 1;
        hero->core.health = 2;
        hero->core.inteligence = 1;
        hero->core.level = 0;
        hero->core.luck = 1;
        hero->core.stamina = 2;
        hero->core.strength = 2;
        hero->gold = 10;
        hero->core.range_attack = 0;
        hero->core.mele_attack = 1;    
        hero->experince = 0;
        hero->max_health = 10;
        hero->perception = 0;   
        break;
    case Rogue:
        hero->core.agility  = 3;
        hero->core.defence = 1;
        hero->core.evade = 2;
        hero->core.health = 1;
        hero->core.inteligence = 3;
        hero->core.level = 0;
        hero->core.luck = 1;
        hero->core.stamina = 2;
        hero->core.strength = 1;
        hero->gold = 10;
        hero->core.range_attack = 1;
        hero->core.mele_attack = 0;    
        hero->experince = 0;    
        hero->max_health = 10;
        hero->perception = 0;
        break;
    case knight:
        hero->core.agility  = 1;
        hero->core.defence = 1;
        hero->core.evade = 1;
        hero->core.health = 1;
        hero->core.inteligence = 1;
        hero->core.level = 0;
        hero->core.luck = 1;
        hero->core.stamina = 1;
        hero->core.strength = 1;
        hero->gold = 20;
        hero->core.range_attack = 0;
        hero->core.mele_attack = 1;    
        hero->experince = 0;    
        hero->max_health = 10;
        hero->perception = 0;
    }
}while(hero->class != 1 || hero->class != 2 || hero->class != 3 ||hero->class != 4);

}

void combat(struct Enemy *enemy, struct Hero *hero){

    int Herofirst;
    int turn;

    hero_attacks_1st(*enemy, *hero, Herofirst);
    turn = Herofirst; // Poco práctico por usar void en hero_attacks_1st

    do{

       if (turn == 1){ // Primero ataca jugador
        printf("Turno del jugador");
        player_attack(*hero, *enemy);
            if(enemy->core.health > 0){
                printf("Turno del enemigo");
                enemy_attack(*hero, *enemy);
            }
       }

       if(turn == 0){ // Primero ataca el enemigo
        printf("Turno del enemigo");
        enemy_attack(*hero, *enemy);
            if(hero->core.health > 0){
                printf("Turno del jugador")
                player_attack(*hero, *enemy);
            }
       }

    } while (hero->core.health > 0 || enemy->core.health > 0);
    
    if(enemy->core.health < 0){
        combat_reward(*hero,*enemy);
    }
    if(hero->core.health < 0){
        game_over();
    }

}

// Módulo que decide quien tiene el primer turno
void hero_attacks_1st(struct Enemy enemy, struct Hero hero, int *hero_attacks1){
    // a lo mejor sustituir el modulo de void al bool
    if(hero.core.agility>enemy.core.agility){
        hero_attacks1= 1;
    }
    else{
        hero_attacks1= 0;
    }

}

// CON EL CAMBIO A ITEMS HACE FALTA EDITAR EL MODULO!!!!!
// El ataque del jugador
void player_attack(struct Hero hero, struct Enemy *enemy){

    int player_damage_out = 0;
    int player_choice = 0;
    int add_Damage = 0;
    bool evaded = false;
    bool usedskill = false;
    bool ended_turn = false;
    int ability;
    int item;
    int i = 0;

    do{

        do{
            scanf("%d",player_choice);
        } while (player_choice != mele || player_choice != ranged || player_choice != hability || player_choice != used_item);
        
        switch (player_choice){
        case mele:
            do{
            add_Damage = add_Damage + hero->loadout[i]->Item_statup[strenghtup];
            i++;
            }while (i<8);

            usedskill = false;
            
            player_damage_out = hero.loadout->damage + hero.core.strength + add_Damage;
            evaded=evade_attempt(mele,1,hero,*enemy);

            ended_turn = true;
            
            break;
            
        case ranged:
            do{
            add_Damage=(hero.core.agility + hero.loadout->Item_statup[agilityup]);
            i++;
            }while (i<8);
            
            usedskill = false;

            player_damage_out = hero.loadout->damage + add_Damage;
            evaded=evade_attempt(ranged,1,hero,*enemy);

            ended_turn = true;
            
            break;

        case hability:
            scanf("%d",ability);
            if(hero.core.stamina-hero.core.skill[ability]->cost < 0){
                // Do nothing
            }
            else{
            use_skill(ability,hero,enemy);
            usedskill = true;
            ended_turn = true;
            }
            break;

        case used_item: // due to rework
            used_item(1,item);
            ended_turn = true;
            break;
        }
    

    }while(ended_turn == false);

    if (evaded == false && usedskill == false) // Change
    {
        enemy->core.health = enemy->core.health-(player_damage_out-enemy->core.defence);
    }

}

// Módulo que comprueba si el actor puedo esquivar un ataque
bool evade_attempt(int atk, int who, struct Hero hero, struct Enemy enemy){
    
    int evadenum;
    int evademax;
    int i = 0;

    if (who == opponent){
        while (i<hero.core.evade)
        {
            evadenum = evadenum + dice_roll();
            i++;
        }
        evadenum = evadenum - enemy.core.agility*8;
    }
    if (who == 1){
        while (i<enemy.core.evade)
        {
            evadenum = evadenum + dice_roll();
            i++;
        }
        evadenum = evadenum - hero.core.agility*10;
    }
    
    evademax = i*12;
    
    if(atk == mele){
        evademax = evademax + (evademax/2);
    }
    if (atk == ranged)
    {
        evademax = evademax - (evademax/2);
    }
    
    if(evadenum>rand()%evademax){
        return true;
    }
    else{
        return false;
    }
}

// Módulo de uso de una habilidad
void use_skill(int ability, struct Hero *hero, struct Enemy *enemy){

    hero->core.stamina = hero->core.stamina - hero->core.skill[ability]->cost;
    
    switch (ability)
    {
    case Minor_Fireball:
        enemy->core.health = enemy->core.health - hero->core.inteligence/2;
        break;
    case Greater_Fireball:
        enemy->core.health = enemy->core.health - (hero->core.inteligence+hero->core.luck);
        break;
    case Minor_heal:
        hero->core.health = hero->core.health + hero->core.inteligence/2;
        break;
    case Greater_heal:
        hero->core.health = hero->core.health + (hero->core.inteligence+hero->core.luck);
        break;
    case Health_Drain:
        hero->core.health = hero->core.health + (enemy->core.health - hero->core.inteligence/2);
        enemy->core.health = enemy->core.health - hero->core.inteligence/2;
        break;
    case Stamina_Drain:
        hero->core.stamina = hero->core.stamina + (enemy->core.stamina - hero->core.inteligence/2);
        enemy->core.stamina = enemy->core.stamina-hero->core.inteligence/2;
        break;
    case CBT:
        enemy->core.health = 0;
        break;
    }

}

// Módulo de la IA del enemigo en el combate
int IA(struct Hero hero, struct Enemy enemy){
    int i = 0;
    bool evade;
    int mele_chance = 0;
    int range_chance = 0;
    int totalherodef = 0;
    int heromele = 0;
    int herorange = 0;
    int heroskill = 0;
    int enemyskill = 0;
    int agro = 0;
    int enemyhealitem = enemy.core.health+10;
    int enemyhealskill = enemy.core.health+enemy.core.skill[heal].strength;

    if (hero.core.mele_attack = 1){ // Daño H2H del heroe
        i = 0;
        do{
            heromele = heromele + hero.loadout[i]->Item_statup[strenghtup];
            i++;
        }while (i<8);
        
        heromele = hero.loadout[l_hand]->damage + hero.loadout[r_hand]->damage + hero.core.strength + heromele;
    }

    if (hero.core.range_attack = 1){ // Daño de ataque a distancia del heroe
        i = 0;
        do{
            herorange = herorange + hero.loadout[i]->Item_statup[agilityup];
            i++;
        }while (i<8);
        
        herorange = hero.loadout[l_hand]->damage + hero.loadout[r_hand]->damage + hero.core.agility + herorange;
    }
    
    i = 0;
    do{ // Defensa máxima del heroe
        totalherodef = totalherodef + hero.loadout[i]->Item_statup[defenceup];
        i++;
    }while (i<8);
    totalherodef = hero.core.defence + totalherodef;

    i = 0;
    do{ // Probabilidad de dar ataque a mele
        evade = evade_attempt(mele,opponent,*hero,*enemy);
        if(evade == false){
            mele_chance++;
        }
        i++;
    }while(i < 10);

    i = 0;
    do{ // Probabilidad de dar ataque a distancia
        evade = evade_attempt(ranged,opponent,*hero,*enemy);
        if(evade == false){
            range_chance++;
        }
        i++;
    }while(i < 10);

    if(hero.core.health < hero.max_health/2){ // Cáluclo de la agresividad de la IA
        agro = 1;
        if(hero.core.health < hero.max_health/4){
            agro = 2;
        }
    }

    if(hero.core.health <= enemy.meledamage || hero.core.health <= enemy.rangedamage || hero.core.health <= enemy.core.skill[damage]){ // El caso de agresividad máxima
        agro = 3;
    }

    if(enemy.core.health <= heromele || enemy.core.health <= herorange || enemy.core.health <= heroskill || agro != 3){ // El caso donde la IA intenta sobrevivir
        if(enemy.enemy_health_potion != 0 && enemyhealitem > heromele && enemyhealitem > herorange && enemyhealitem > heroskill){
            return e_used_item;
        }
        if(enemy.core.stamina >= enemy.core.skill[heal].cost && enemyhealskill > heromele && enemyhealskill > herorange && enemyhealskill > heroskill){
            return e_used_heal;
        }
    }

    // Secuencia que implica que el enemigo no hace daño ni a mele ni a rango con un ataque básico
    if(totalherodef > enemy.meledamage && totalherodef > enemy.rangedamage){
        if(totalherodef > enemy.core.skill[damage].strength || enemy.core.stamina < enemy.core.skill[damage].cost){
            if(totalherodef > enemy.core.skill[ultimate].strength || enemy.core.stamina < enemy.core.skill[ultimate].cost){
                if(enemy.core.mele_attack = 1){
                    return mele;
                }
                else{
                    return ranged;
                }
            }
            else{
                return e_ult_attack;
            }
        }
        else{
            return e_dmg_attack;
        }
    }
    // Secuencia donde el enemigo puede meter daño de ataque básico
    else{
        if(enemy.core.skill[damage].strength > enemy.meledamage && enemy.core.skill[damage].strength > enemy.rangedamage && enemy.core.skill[damage].cost <= enemy.core.stamina){
            if (enemy.core.skill[ultimate].strength > enemy.core.skill[damage].strength && enemy.core.skill[ultimate].cost <= enemy.core.stamina){
                return e_ult_attack;
            }
            else{
                return e_dmg_attack;
            }
        }
        else{
            if(hero.core.agility > enemy.core.agility){
                if(agro > 1){
                    if(agro > 2){
                        if(enemy.meledamage > enemy.rangedamage){
                            return e_mele;
                        }
                        else{
                            return e_ranged;
                        }
                    }
                    else{
                        if(enemy.meledamage > enemy.rangedamage && mele_chance >= 7){
                            return e_mele;
                        }
                        else{
                            if(enemy.meledamage < enemy.rangedamage && range_chance >= 7){
                                return e_ranged;
                            }
                            else{
                                if(range_chance < mele_chance && enemy.core.range_attack == 1){
                                    return e_ranged;
                                }
                                else{
                                    return e_mele;
                                }
                            }
                        }
                    }
                }
                else{ // asdkajsflkjflajñfkañsf
                    if(enemy.meledamage > enemy.rangedamage && mele_chance >= 5){
                        return e_mele;
                    }
                    else{
                        if(enemy.meledamage < enemy.rangedamage && range_chance >= 5){
                        return e_ranged;
                        }
                        else{
                            if(range_chance < mele_chance && enemy.core.range_attack == 1){
                                return e_ranged;
                            }
                            else{
                                return e_mele;
                            }
                        }
                    }
                }
            }
            else{
                if(enemy.meledamage > enemy.rangedamage){
                    return e_mele;
                }
                else{
                    return e_ranged;
                }
            }
        }
    }
}

// Módulo del  ataque del jugador
void enemy_attack(struct Hero *hero, struct Enemy enemy){                // EL ataque del enemigo

    int enemy_damage_out = 0;
    int used;
    bool evaded = false;
    bool usedskill;
    switch (IA(*hero,enemy))
    {
    case e_mele:
        enemy_damage_out = enemy.meledamage; // otra formula parael daño
        evaded = evade_attempt(mele,opponent,*hero,enemy);
        usedskill = false;
        break;
    case e_ranged:
        enemy_damage_out = enemy.rangedamage;
        evaded = evade_attempt(ranged,opponent,*hero,enemy);
        usedskill = false;
        break;
    case e_dmg_attack:
        enemy.core.stamina = enemy.core.stamina - enemy.core.skill[damage].cost;
        enemy_damage_out = enemy.core.skill.[damage].strength;
        usedskill = true;
        break;
    case e_ult_attack:
        enemy.core.stamina = enemy.core.stamina - enemy.core.skill[ultimate].cost;
        enemy_damage_out = enemy.core.skill[ultimate].strength;
        usedskill =  true;
        break;
    case e_used_heal:
        enemy.core.stamina = enemy.core.stamina - enemy.core.skill[heal].cost;
        enemy.core.health = enemy.core.health + enemy.core.skill[heal].strength;
        break;
    case e_used_item:
        enemy.enemy_health_potion = enemy.enemy_health_potion-1;
        enemy.core.health = enemy.core.health+10;
        break;
    default:
        break;
    }

    if(evaded == false){
        hero->core.health = hero->core.health - enemy_damage_out;
    }
    
}

// Módulo de la recompensa del combate
void combat_reward(struct Hero *hero, struct Enemy *enemy){
    hero->experince = hero->experince + enemy->exp_reward;
    hero->gold = hero->gold + enemy->gold_reward;
    
}

// Módulo lógico del uso de un objeto consumible/usable
void item_use(struct Hero *hero, struct Enemy *enemy){
    
    int itemused;

    scanf("%d", itemused);

    switch (itemused){
        case potion_health:
            hero->core.health = hero->core.health + 10;
            break;
        case potion_stamina:
            hero->core.stamina = hero->core.stamina + 10;
            break;
        case potion_strength:
            hero->core.strength = hero->core.strength + 10;
            hero->time_effect = hero.time_effect + 2;    //Esta variable se usara como temporizador de el efecto que da el objeto (Por turnos).
            break;
        case potion_poison:
            enemy->core.health = enemy->core.health -1;
            enemy->time_effect = enemy->time_effect + 2;
            break;
        case potion_defense:
            hero->core.defence = hero->core.defence + 10;
            hero->time_effect = hero->time_effect + 2;
            break;  
    }
}

// Módulo del ascenso del nivel del jugador
void player_lvlup(struct Hero *hero){
    /*Pense en el concepto de abrir una ventana aparte con el spreadshit del jugador para modificar en ella las estats  deseadas*/
    int stat_points = 5;
    int choice;

    hero->core.level = hero->core.level + 1;

    hero->max_health = hero->max_health + 100;
    hero->core.health = hero->max_health;

    do{
        scnaf("%d",choice);

        switch (choice)
        {
        case 1:
            hero->core.agility = hero->core.agility + 1;
            break;
        case 2:
            hero->core.defence = hero->core.defence + 1;
            break;
        case 3:
            hero->core.evade = hero->core.evade + 1;
            break;
        case 4:
            hero->core.inteligence = hero->core.inteligence + 1;
            break;
        case 5:
            hero->core.luck = hero->core.luck + 1;
            break;
        case 6:
            hero->core.stamina = hero->core.stamina + 1;
            break;
        case 7:
            hero->core.strength = hero->core.strength + 1;
            break;      
        }
        stat_points--;
    }while(stat_points != 0);

}
