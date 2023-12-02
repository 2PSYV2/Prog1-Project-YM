/*
Yevhenii Edelshteyn
Marat Galiullin
Abel López Rodríguez
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

enum atk{
    mele, ranged, skill
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

enum combat_actor{
    opponent,player
};

enum Heroes {
    Mage, Warrior, Rogue, knight
};

enum Items {
    potion_health, potion_strength, potion_stamina, potion_poison, potion_defense, sword, bow, axe, magic_wand
};

enum SkilList {
    fireball, Skills, Exchange,  hehe
};

enum Body_parts{
    head, body, l_hand, r_hand, l_finger, r_finger, legs
};

enum Item_statup{
    strenghtup, luckup, agilityup, evadeup, intelligenceup, defenceup
};

// Structs de los elementos básicos como personajes/enemigos, objetos, etc

struct Skills{
    int strength;
    int cost;
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
    int range_attack;
    int mele_attack;
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
    int time_effect;
};

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

struct Hero{
    struct Core core;
    struct Item loadout[7];
    struct Item inventory[20];
    int facing_direction[4];
    int class;
    int gold;
    int max_health;
    int experince;
    int perception;
    int time_effect;
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

int dice_roll(int dice_result){   // Módulo lógico de la tirada de dados virtuales    
    
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
    hero->core.range_attack = 1;
    hero->core.mele_attack = 0;
    hero->experince = 0;
    hero->gold = 10;
    hero->max_health = 10;
    hero->perception = 0;
    hero->inventory[0] = magic_wand;
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
    hero->inventory[0] = axe;
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
    hero->inventory[0] = bow;
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
    hero->inventory[0] = sword;
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

void combat(struct Enemy *enemy, struct Hero *hero){

}

void hero_attacks_1st(struct Enemy enemy, struct Hero hero, bool *hero_attacks1){                // Compración de las iniciativas de los opponentes
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
    int add_Damage = 0;
    bool evaded;
    bool usedskill;
    int ability;
    int i = 0;

    do
    {
        /* selección deacción */
    } while (/*acción válida*/);
    
    switch (player_choice)
    {
    case mele:
        do{
          add_Damage = add_Damage + hero.loadout[i]->Item_statup[strenghtup];
          i++;
        }while (i<8);

        usedskill = false;
        
        player_damage_out = hero.loadout->damage + hero.core.strenght + add_Damage;
        evaded=evade_attempt(mele,player,hero,enemy);
        
        break;
    case ranged:
        do{
          add_Damage=(hero.core.agility + hero.loadout->Item_statup[agilityup]);
          i++;
        }while (i<8);
        
        usedskill = false;

        player_damage_out = hero.loadout->damage + add_Damage;
        evaded=evade_attempt(ranged,player,hero,enemy);
        
        break;
    case skill:
        // selección de habilidad
        if(hero.core.stamina-hero.core.skill[ability]->cost <= 0){
            player_attack(hero,enemy);
        }
        else{
            
        use_skill(player,ability,hero,enemy);
        usedskill = true;
        }
        break;
    default:   //error de ataque  no existente
        break;
    }
 
    if (evaded == false && usedskill == false)
    {
        enemy->core.health = enemy->core.health-(player_damage_out-enemy->core.defence);
    }
}

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
    if (who == player){
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

void use_skill(int who, int ability, struct Hero *hero, struct Enemy *enemy){

    if (who == opponent){
        enemy->core.stamina = enemy->core.stamina - enemy->core.skill[ability]->cost;
        hero->core.health = hero->core.health - enemy->core.skill[ability].strength + enemy->core.inteligence;
    }
    if (who == player){
        hero->core.stamina = hero->core.stamina - hero->core.skill[ability]->cost;
        enemy->core.health = enemy->core.health - hero->core.skill[ability].strength + hero->core.inteligence;
    }
}

int IA(struct Hero hero, struct Enemy enemy){
    int range_chance = 0;
    int mele_chance = 0;
    int skill_chance = 0;
    int useitem_chance = 0;
    int totalherodef = 0;
    int i = 0;
    int heromele = 0;
    int herorange = 0;

    if (hero.core.mele_attack = 1){
        do{
            heromele = heromele + hero.loadout[i]->Item_statup[strenghtup];
            i++;
        }while (i<8);
        
        heromele = hero.loadout[l_hand]->damage + hero.loadout[r_hand]->damage + hero.core.strenght + heromele;
    }

    if (hero.core.range_attack = 1){
        do{
            herorange = herorange + hero.loadout[i]->Item_statup[agilityup];
            i++;
        }while (i<8);
        
        herorange = hero.loadout[l_hand]->damage + hero.loadout[r_hand]->damage + hero.core.agility + herorange;
    }
    
    do{
        totalherodef = totalherodef + hero.loadout[i]->Item_statup[defenceup];
        i++;
    }while (i<8);
    
    if(enemy.core.health < heromele || enemy.core.health < herorange){
        item_use(opponent,&hero,&enemy,potion_health);
    }

    else{
        if(hero->core.health > (hero->max_health/2)){
            if(hero->core.agility > enemy.core.agility){
                skill_chance++;
                mele_chance++;
            }
            if(hero->core.agility < enemy.core.agility){
                mele_chance++;
                range_chance++;
            }
            if(totalherodef > enemy.core.agility){
                mele_chance++;
            }
            if(totalherodef > enemy.core.strength){
                range_chance++;
            }
            if(enemy.core.strength > enemy.core.agility){
                mele_chance++;
            }
            if(enemy.core.agility >  enemy.core.strength){
                range_chance++;
            }
        }

        if(hero->core.health < (hero->max_health/2)){

        }
    }

    if(mele_chance > range_chance && mele_chance > skill_chance){
        return mele;
    }
    if (range_chance > mele_chance && range_chance > skill_chance){
        return ranged;
    }
    if (skill_chance > mele_chance && skill_chance > range_chance){
        return skill;
    }   
}

void enemy_attack(struct Hero *hero, struct Enemy enemy){                // EL ataque del enemigo

    int enemy_damage_out,range_chance,skill_chance,mele_chance;
    int used;
    bool evaded,usedskill;

    switch (IA(hero,enemy))
    {
    case mele:
        enemy_damage_out = enemy.core.strength;
        evaded = evade_attempt(mele,opponent,hero,enemy);
        usedskill = false;
        break;
    case ranged:
        enemy_damage_out = enemy.core.agility;
        evaded = evade_attempt(ranged,opponent,hero,enemy);
        usedskill = false;
        break;
    case skill:
        use_skill(opponent,enemy.core.skill[used],hero,enemy);
        usedskill = true;
        break;
    default:
        break;
    }

    if(evaded == false && usedskill == false){
        hero->core.agility = hero->core.health-(enemy_damage_out - hero->core.defence);
    }
}

void combat_reward(struct Hero *hero, struct Enemy *enemy){               // Módulo lógico de la recompensa
    hero->experince = hero->experince + enemy->exp_reward;
    hero->gold = hero->gold + enemy->gold_reward;
    
}

// enemyuse es de uso exclusivo de la ia, introduce el numero cualquiera para el jugador
void item_use(int who, struct Hero *hero, struct Enemy *enemy, int enemyuse){                    // Módulo lógico del uso de un objeto consumible/usable

    if(who == player){
        // item select
        switch (/*Item used from enum*/){
            case potion_health:
                hero->core.health = hero->core.health + 10;
                break;
            case potion_stamina:
                hero->core.stamina = hero->core.stamina + 10;
                break;
            case potion_strength:
                hero->core.strength = hero->core.strength + 10;
                hero->time_effect = hero.time_effect + ;;                          //Esta v=riable se usara como temporizador de el efecto que da el objeto (Por turnos).
                break;
            case potion_poison:
                enemy->core.health = enemy->core.health -1;
                enemy->time_effect = enemy->time_effect + 2;
                break;
            case potion_defense:
                hero->core.defence = hero->core.defence + 10;
                hero->time_effect = hero->time_effect + 2;
                break;  
            default: // error de ausencia del item
                break;
        }
    }
    if(who == opponent){
        switch (enemyuse)
        {
        case potion_health:
            enemy->core.health = enemy->core.health + 10;
            break;
        
        default:
            break;
        }
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

    hero->core.level = hero->core.level + 1;

    hero->max_health = hero->max_health + 100;
    hero->core.health = hero->max_health;

    do{

        /*solicitud de la opicon del jugador*/

        switch (/*case*/)
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

    }

}

void inspect(){                     // Módulo lógico del mensaje al inspeccionar un elemento del juego

}

void shop(struct Hero *hero){                        // Módulo lógico de las tiendas en el juego

    switch(hero->inverntory[]){         //Switch para vender objetos
        case 1:
            hero->gold = hero->gold + item.price;
            break;
        default:
            break;
    }

    switch (hero->core.position[/*z*/])
c>-or-orae
        default:
            break;
        }

    }while(stat_points>0);

}

void inspect(){                     // Módulo lógico del mensaje al inspeccionar un elemento del juego

}

void shop(struct Hero *hero){                        // Módulo lógico de las tiendas en el juego

    switch (hero->core.position[/*z*/])
c>-or-orae
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
    case potion_health:
        if(hero->gold >= item->price){
            
        }else{
            printf("Dinero insuficiente");
        }
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
