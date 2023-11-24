/*
Yevhenii Edelshteyn
Marat Galiullin

2023-2024
*/

/*
tecla de cambio entre mivimiento y manipulacion del menu con flechas;;
*/

// Bibliotecas requeridas para el juego.
#include <math.h>                   // Libreria matemática
#include <stdbool.h>                // Libreria de los buleanos
#include <stdio.h>                  // Libreria del input-Output
#include <stdlib.h>                 // Libreria estándart del C
#include <time.h>                   // Libreria del tiempo, relevante para los numeros aleatorios
#include "tigr.h"                   // Libreria gráfica tigr
//#include "items.h"

//Constantes utilizadas en le juego
#define NAMEMAX 32

//Enum de diferentes elementos del juego
enum Difficulty{
    Trivial, Easy, Medium, Hard, Extreme
};

enum Characters_Greece_and_Boss{
    Minotauro, Ares, Titan, Chimera, Uroboros, Talos, Spartak 
};

enum Characters_Scandi{
    Odin, Loki, Freyr, Ullr, Magni, Skadi, Vali, Frigg, Heimdall, Idunn
};

enum Characters_Slavic{
    Perun, Morena, Baba_Yaga, Kikimora, Svarog, Chernoslav, Nija, Korab, Chernobog, Belobog, Khotabych
};

enum Secret_Lvls{
    Cthulhu, Kali, Boss_of_the_Gym, Disney, Giant_Sphinx
};


enum Heroes {
    Mage, Warrior, Rogue
};

enum Items {
    potion_health, potion_strength, sword, bow, skills
};

enum SkilList {
    fireball, Skills, Exchange,  hehe
};

enum Body_parts{
    head, body, l_hand, r_hand, l_finger, r_finger, legs
};

enum Item_statup{
    strenghtup, luckup, agilityup, evadeup, intelligenceup
};

// Structs de los elementos básicos como personajes/enemigos, objetos, etc

struct Skills{
    int strength;
    int coste;

};
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
    struct Skills skill[20];
    bool range_attack;
    bool mele_attack;
};

struct Map_tile{
    int position[2];                 // x-y-z
};

struct Enemy{
    struct Core core;
    int difficulty;
    int gold_reward;
    int exp_reward;
    int item_reward_chance;
    int item_reward_set[10];          // Objetos que pueden ser recibidos
    bool item_reward;
};

struct Item{
    int body_part;
    int price;
    int damage;
    int defennce;
    int min_lvl;
    int Item_statup[5];
    int rarity;
    bool range;
    bool mele;
};

struct Hero{
    struct Core core;
    struct Item loadout[6];
    int facing_direction[4];
    int class;
    int gold;
    int max_health;
    int experince;
    int perception;
};

struct GameOp{
    int window_w;
    int window_h;
};

// Main del programa
int main(){

    // Struct game elements declaration
    struct GameOp game;
    struct Hero hero;
    struct Map_tile tile[2];
    
    // ej: hero.core.name
    // Default settings
    game.window_w = 1920;
    game.window_h = 1080;

    srand(time(NULL));

    Tigr *screen = tigrWindow(game.window_w,game.window_h,"PR1",0);            // Módulo proncipal de la ventana gráfica

    while(!tigrClosed(screen) || !tigrKeyDown(TK_ESCAPE) /* o incluso gameover == true*/){                        // Secuencia de salida del juego
        /*game logic*/
        /*main_menu*/
        /*Character_create // a lo mejor lo hacemos fuera del bucle, irrelevante*/
    }
    tigrFree(screen);
    return 0;
}

void main_menu(){

    while(!tigrKeyDown(TK_SPACE)){
        /*Animación de "press space to continue"*/
    }

    while(event_game_menu_start){
        /*mostrar el menú con opciones del juego "partda nueva etc."*/
    }

}

void event_game_menu_start(){

}

void settings( struct GameOp *game){

    switch (/*Opcion de las probablemente 2 opciones*/)
    {
    case 1:
        game->window_w = 1920;
        game->window_h = 1080;
        break;
    case 2:
        game->window_w = 1280;
        game->window_h = 720;
        break;    
    default:    // Error de resolcion no existente
        break;
    }

    Tigr *screen = tigrWindow(game->window_w,game->window_h,"PR1",0);

}

void dice_roll(int *dice_result){   // Módulo lógico de la tirada de dados virtuales    
    
    dice_result=rand()%21;
    
}

void charcter_create(struct Hero *hero){             // Módulo lógico de la creacion del protagonista

scanf("%c", *hero->core.name);

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
    hero->core.range_attack = true;
    hero->core.mele_attack = false;
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
    hero->core.range_attack = false;
    hero->core.mele_attack = true;    
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
    hero->core.range_attack = true;
    hero->core.mele_attack = false;    
    hero->experince = 0;    
    hero->max_health = 10;
    hero->perception = 0;    
    break;
default:
    break;
}


/*EL resto de estats comunes que se asignen fuera del switch*/

}

void enemy_selector_area(struct Hero hero){// Selección de la lista de enemigos dependiendo del area

    switch(hero.core.position[/*z*/]){
        case 1: enemy_creator_Tutorial();
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12: enemy_creator_Greece();
            break;
        case 13: enemy_creator_Minotaur();
            break;
        default: // Error
            break;
    }

}

void enemy_creator_Tutorial(){

    switch (){
    case /*caso*/:
        break;
    
    default: // Error
        break;
    }

}

void enemy_creator_Greece(){

}

void enemy_creator_Minotaur(){

}

void enemy_creator_Slavic(){

}

void enemy_creator_Scandinavia(){

}

void enemy_creator_Asia(){

}

void enemy_creator_Mesopotamia(){

}

void enemy_creator_Aztec(){

}

void enemy_creator_Svalka(){

}

void enemy_creator_Chulhu(){

}

void enemy_creator_Kali(){

}

void enemy_creator_Egypt(){

}

void enemy_creator_Gym(){

}

void hero_attacks_1st(struct Enemy enemy, struct Hero hero, bool *hero_attacks1){                // Compración de las iniciativas de los oponentes
    // a lo mejor sustituir el modulo de void al bool
    if(hero.core.agility>enemy.core.agility){
        hero_attacks1=true;
    }
    else{
        hero_attacks1=false;
    }

}

void player_attack(struct Hero hero, struct Enemy *enemy){               // El ataque del jugador

    int player_attack_choice; // Tipo de ataque deljugador
    int player_damage_out;
    int player_choice;

    switch (player_choice)
    {
    case 1: // mele
        player_damage_out = hero.loadout->damage + (hero.core.strength + hero.loadout->Item_statup[strenghtup]);
        break;
    case 2: // ranged
        player_damage_out = hero.loadout->damage + (hero.core.agility + hero.loadout->Item_statup[agilityup]);
        break;
    default:   //error de ataque  no existente
        break;
    }

}

void enemy_attack(struct Enemy *enemy){                // EL ataque del enemigo

}

void combat_reward(struct Hero *hero, struct Enemy *enemy){               // Módulo lógico de la recompensa

}

void item_use(struct Hero *hero, struct Enemy *enemy){                    // Módulo lógico del uso de un objeto consumible/usable

    switch (/*Item used from enum*/)
    {
    case 1:
        /*item 1 effect*/;
        break;
    default: // error de ausencia del item
        break;
    }

}

void player_move(struct Hero *hero){                // Módulo lógco del movimineto del jugador en vértices xyz
    if(/*x*/){
        hero->core.position[1] = hero->core.position[1] + hero->facing_direction[1];
    }
    if (/*y*/)
    {
        hero->core.position[2] = hero->core.position[2] + hero->facing_direction[2];
    }
    if (/*z*/)
    {
        hero->core.position[3] = hero->core.position[3] + /*en fuincion de la escalera en la que estamos*/;
    }
    
}


    // !!!! Se pueede optimizar a numeros de 1 a 4 con suma siendo el giro a la derecha y resta a la izquierda, donde 0 es 4 y 5 es 1

void player_turn_right(struct Hero *hero){ // Módulo lógico del cambio de la dirección a la derecha

    bool have_turned = false;

}

void player_turn_left(struct Hero *hero){ // Módulo lógico del cambio de la dirección a la izquierda

    bool have_turned = false;

}

void player_lvlup(struct Hero *hero){                 // Módulo lógico del ascenso del nivel del jugador
    /*Pense en el concepto de abrir una ventana aparte con el spreadshit del jugador para modificar en ella las estats  deseadas*/
    int stat_points = 5;
    int choice;

    hero->max_health = hero->max_health + 100;
    hero->core.health = hero->max_health;

    do{

        /*solicitud de la opicon del jugador*/

        switch (/*case*/)
        {
        case 1:
            hero->core.defence = hero->core.defence + 1;
            break;
                /*etc*/
        default:
            break;
        }

    }while(stat_points>0);

}

void inspect(){                     // Módulo lógico del mensaje al inspeccionar un elemento del juego

}

void shop(struct Hero *hero){                        // Módulo lógico de las tiendas en el juego

    switch (hero->core.position[/*z*/])
    {
    case /*ya veremos como lo hacemos*/:
        /* code */
        break;

    default:
        break;
}

}

void pov_change(/*Dependendo de la situacion mostrara una cosa u otra*/){                  // Módulo del cambio de los menús en la pantalla del juego
/*pensé en usar este módulo tmb para crear una ventana aparte con cosas como el spreadsheet del  personaje, seria bastante parecido alos juegos de rol a papel  (d&d)*/
}

void game_over(struct Hero *hero){                   // Módulo lógico de la pérdida del partido
/*purge the fucking game, alt F4 him*/
/*A lo mejor pasarlo al bool, que así se puede cerrrar el juego con la condiocion true/dalse del modulo*/
}

void save_game(){                    // Guardar el partido actual

}

void load_game(){                    // Cargar partido guardado

}

void event_stat_check(struct Hero *hero){            // Módulo lógico del tiro de dados virtual en un evento

    switch (hero->core.position[/*z*/])
    {
    case /* constant-expression */:
        /* code */
        break;

    default:
        break;
}

}
