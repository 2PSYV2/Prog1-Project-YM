#ifndef Enemies_H
#define Enemies_H

#define NAMEMAX 32
#include <stdio.h>


enum enemies{
    Black_Ooze, Black_Thing, Caribean, Dno, DraKek, Dummy, ExBlue, Hidra, Liche, Minotaur, Paleno, SillyLilGuy, Skeletik, Skuf, TheWock, TrollBlue
};

enum Enemy_skills{
    heal, buff, damage, ultimate
};

struct Skills{
    int strength;
    int cost;
};

struct Core{
    char name [NAMEMAX];
    int health;
    int defense;
    int evade;
    int strength;
    int agility;
    int luck;
    int inteligence;
    int level;
    int stamina;
    int position [2];
    struct Skills skill[20];
    int range_attack;
    int meled_attack;
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
    int meledamage;
    int rangedamage;
    int enemy_health_potion;
};

switch (enemies){
case Black_Ooze:
    enemy.core.name = "Black Ooze";
    enemy.core.health = 10;
    enemy.core.defence = 2;
    enemy.core.evade = 1;
    enemy.core.agility = 4;
    enemy.core.luck = 0;
    enemy.core.inteligence = 1;
    enemy.core.level = 5;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 0;
    enemy.core.mele_attack = 1;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case Black_Thing:
    enemy.core.name = "Black Thing";
    enemy.core.health = 10;
    enemy.core.defence = 3;
    enemy.core.evade = 1;
    enemy.core.agility = 1;
    enemy.core.luck = 0;
    enemy.core.inteligence = 1;
    enemy.core.level = 5;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 0;
    enemy.core.mele_attack = 1;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case Caribean:
    enemy.core.name = "Caribean";
    enemy.core.health = 10;
    enemy.core.defence = 3;
    enemy.core.evade = 1;
    enemy.core.agility = 2;
    enemy.core.luck = 0;
    enemy.core.inteligence = 2;
    enemy.core.level = 5;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 0;
    enemy.core.mele_attack = 2;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case Dno:
    enemy.core.name = "Dno";
    enemy.core.health = 15;
    enemy.core.defence = 3;
    enemy.core.evade = 1;
    enemy.core.agility = 3;
    enemy.core.luck = 0;
    enemy.core.inteligence = 1;
    enemy.core.level = 6;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 0;
    enemy.core.mele_attack = 3;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case DraKek:
    enemy.core.name = "DraKek";
    enemy.core.health = 20;
    enemy.core.defence = 5;
    enemy.core.evade = 1;
    enemy.core.agility = 1;
    enemy.core.luck = 0;
    enemy.core.inteligence = 1;
    enemy.core.level = 8;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 2;
    enemy.core.mele_attack = 2;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case Dummy:
    enemy.core.name = "Dummy";
    enemy.core.health = 1;
    enemy.core.defence = 1;
    enemy.core.evade = 0;
    enemy.core.agility = 0;
    enemy.core.luck = 0;
    enemy.core.inteligence = 0;
    enemy.core.level = 1;
    enemy.core.stamina = 0;
    enemy.core.range_attack = 0;
    enemy.core.mele_attack = 0;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case ExBlue:
    enemy.core.name = "ExBlue";
    enemy.core.health = 20;
    enemy.core.defence = 5;
    enemy.core.evade = 1;
    enemy.core.agility = 1;
    enemy.core.luck = 0;
    enemy.core.inteligence = 1;
    enemy.core.level = 8;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 2;
    enemy.core.mele_attack = 2;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case Hidra:
    enemy.core.name = "Hidra";
    enemy.core.health = 25;
    enemy.core.defence = 8;
    enemy.core.evade = 1;
    enemy.core.agility = 1;
    enemy.core.luck = 0;
    enemy.core.inteligence = 1;
    enemy.core.level = 10;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 2;
    enemy.core.mele_attack = 2;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case Liche:
    enemy.core.name = "Liche";
    enemy.core.health = 20;
    enemy.core.defence = 5;
    enemy.core.evade = 3;
    enemy.core.agility = 5;
    enemy.core.luck = 0;
    enemy.core.inteligence = 10;
    enemy.core.level = 10;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 5;
    enemy.core.mele_attack = 5;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case Minotaur:
    enemy.core.name = "Minotaur";
    enemy.core.health = 20;
    enemy.core.defence = 10;
    enemy.core.evade = 1;
    enemy.core.agility = 5;
    enemy.core.luck = 0;
    enemy.core.inteligence = 5;
    enemy.core.level = 10;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 0;
    enemy.core.mele_attack = 7;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case Paleno:
    enemy.core.name = "Paleno";
    enemy.core.health = 30;
    enemy.core.defence = 10;
    enemy.core.evade = 1;
    enemy.core.agility = 1;
    enemy.core.luck = 0;
    enemy.core.inteligence = 5;
    enemy.core.level = 10;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 0;
    enemy.core.mele_attack = 7;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case SillyLilGuy:
    enemy.core.name = "SillyLilGuy";
    enemy.core.health = 30;
    enemy.core.defence = 10;
    enemy.core.evade = 1;
    enemy.core.agility = 1;
    enemy.core.luck = 0;
    enemy.core.inteligence = 1;
    enemy.core.level = 10;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 0;
    enemy.core.mele_attack = 10;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case Skeletik:
    enemy.core.name = "Skeletik";
    enemy.core.health = 20;
    enemy.core.defence = 10;
    enemy.core.evade = 1;
    enemy.core.agility = 1;
    enemy.core.luck = 0;
    enemy.core.inteligence = 1;
    enemy.core.level = 10;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 0;
    enemy.core.mele_attack = 8;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case Skuf:
    enemy.core.name = "Skuf";
    enemy.core.health = 40;
    enemy.core.defence = 20;
    enemy.core.evade = 1;
    enemy.core.agility = 1;
    enemy.core.luck = 0;
    enemy.core.inteligence = 5;
    enemy.core.level = 15;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 0;
    enemy.core.mele_attack = 20;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case TheWock:
    enemy.core.name = "TheWock";
    enemy.core.health = 40;
    enemy.core.defence = 30;
    enemy.core.evade = 1;
    enemy.core.agility = 1;
    enemy.core.luck = 0;
    enemy.core.inteligence = 1;
    enemy.core.level = 15;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 0;
    enemy.core.mele_attack = 20;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case TrollBlue:
    enemy.core.name = "TrollBlue";
    enemy.core.health = 20;
    enemy.core.defence = 10;
    enemy.core.evade = 1;
    enemy.core.agility = 1;
    enemy.core.luck = 0;
    enemy.core.inteligence = 1;
    enemy.core.level = 8;
    enemy.core.stamina = 10;
    enemy.core.range_attack = 0;
    enemy.core.mele_attack = 10;
    enemy.core.skill[heal].cost = 5;
    enemy.core.skill[heal].stregth = 5;
    enemy.core.skill[damage].cost = 5;
    enemy.core.skill[damage].stregth = 5;
    enemy.core.skill[ultimate].cost = 10;
    enemy.core.skill[ultimate].stregth = 10;
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;
}

#endif