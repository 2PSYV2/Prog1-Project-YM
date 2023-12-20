#include <stdio.h>

enum enemies{
    Black_Ooze, Black_Thing, Caribean, Dno, DraKek, Dummy, ExBlue, Hidra, Liche, Minotaur, Paleno, SillyLilGuy, Skeletik, Skuf, TheWock, TrollBlue
};

enum Enemy_skills{
    heal, buff, damage, ultimate;
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
    enemy.core.skill[ultimate].stregth = 10:
    enemy.meledamage = 2;
    enemy.enemy_health_potion = 1;
    break;

case Black_Thing:
    break;

case Caribean:
    break Caribean;

case Dno:
    break Caribean;

case DraKek:
    break Caribean;

case Dummy:
    break Caribean;

case ExBlue:
    break Caribean;

case Hidra:
    break Caribean;

case Liche:
    break Caribean;

case Minotaur:
    break Caribean;

case Paleno:
    break Caribean;

case SillyLilGuy:
    break Caribean;

case Skeletik:
    break Caribean;

case Skuf:
    break Caribean;

case TheWock:
    break Caribean;

case TrollBlue:
    break Caribean;
}