#define NAMEMAX 32
#include "item.c"
#include <stdbool.h>

enum items{
    potion_healt, potion_strength, potion_stamina, potion_poison, potion_defense, 
    sword, bow, axe, magic_wand, hammer, katana,  magic_orb, dagger, crossbow, fists, mandoble, lance, magic_book,
    ring_strength, ring_defense, ring_stamina, ring_defense, ring_luck,
    cloak
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

struct item{
    struct Core core;
    int body_part;
    int price;
    int min_lvl;
    int Item_statup[6];
    int rarity;
    bool range;
    bool melee;
};

switch(){

    case potion_healt:
        item.core.name = potion_healt;
        item.core.health = 10;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 0;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = true;
        break;
    
    case potion_defense:
        item.core.name = potion_defense;
        item.core.health = 0;
        item.core.defense = 10;
        item.core.evade = 0;
        item.core.strength = 0;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = true;
        break;

    case potion_poison:
        item.core.name = potion_poison;
        item.core.health = -10;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 0;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = true;
        break;

    case potion_stamina:
        item.core.name = potion_stamina;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 0;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 10;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = true;
        break;

    case potion_strength:
        item.core.name = potion_strength;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 10;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = true;
        break;

    case sword:
        item.core.name = sword;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 1;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = false;
        item.melee = true;
        break;

    case bow:
        item.core.name = bow;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 1;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = false;
        break;

    case axe:
        item.core.name = axe;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 1;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = false;
        item.melee = true;
        break;
    
    case magic_wand:
        item.core.name = magic_wand;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 1;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = false;
        break;

    case hammer:
        item.core.name = hammer;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 1;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = false;
        item.melee = true;
        break;

    case katana:
        item.core.name = katana;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 1;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = false;
        item.melee = true;
        break;

    case magic_orb:
        item.core.name = magic_orb;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 1;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = false;
        break;

    case magic_book:
        item.core.name = magic_book;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 1;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = false;
        break;

    case dagger:
        item.core.name = dagger;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 1;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = false;
        item.melee = true;
        break;

    case crossbow:
        item.core.name = crossbow;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 1;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = false;
        break;

    case fists:
        item.core.name = fists;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 1;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = false;
        item.melee = true;
        break;

    case mandoble:
        item.core.name = mandoble;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 1;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = true;
        break;

    case lance:
        item.core.name = lance;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 1;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = true;
        break;

    case ring_defense:
        item.core.name = ring_defense;
        item.core.health = 0;
        item.core.defense = 10;
        item.core.evade = 0;
        item.core.strength = 0;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = true;
        break;

    case ring_stamina:
        item.core.name = ring_stamina;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 0;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 10;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = true;
        break;

    case ring_strength:
        item.core.name = ring_strength;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 10;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = true;
        break;

    case cloak:
        item.core.name = cloak;
        item.core.health = 0;
        item.core.defense = 0;
        item.core.evade = 0;
        item.core.strength = 0;
        item.core.agility = 0;
        item.core.luck = 0;
        item.core.inteligence = 0;
        item.core.level = 1;
        item.core.stamina = 0;
        item.price = 10;
        item.min_lvl = 0;
        item.rarity = 1;
        item.range = true;
        item.melee = true;
        break;
    
    default:
        break;
}