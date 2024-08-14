//
// Created by usr on 24.03.2024.
//
#include <iostream>
#include <stdio.h>
#include "Actions.h"
#include "HeroTemplate.h"
#include <chrono>
#include <thread>
#include <random>

std::uniform_int_distribution<int> dist;//random values for a static hero
std::mt19937 rng((std::random_device()()));//random values for a static hero
HeroTemplate Actions::heroTemplate = HeroTemplate((srand(time(0)), rand() % 100 + 10),
        (srand(time(0)), rand() % 10 + 1));

Actions::Actions() {}

void Actions::runBattle()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);//load base libraries
    lua_register(L, "battle", Actions::battle);//register our function
    lua_register(L, "rest", Actions::rest);
    lua_register(L, "bless", Actions::bless);
    lua_register(L, "heroStats", Actions::heroStats);
    luaL_dofile(L, "battle.lua");//run the script
    lua_close(L);//cleanup lua
}

int Actions::battle(lua_State *L) //,  HeroTemplate hero
{
    int n = lua_gettop(L);
    if (n < 2)
    {
        std::cout << "wrong number of arguments for a battle" << std::endl;
        return 0;
    }
    int monsterHp = lua_tointeger(L, 1);
    int monsterAttack = lua_tointeger(L, 2);

    printf("fight between hero with %i hp and %i attack and monster with %i hp and %i attack\n",
           heroTemplate.hp, heroTemplate.attack, monsterHp, monsterAttack);
    while( heroTemplate.hp > 0) {
        heroTemplate.hp -= monsterAttack;
        monsterHp -= heroTemplate.attack;
        printf("hero: %i hp . monster: %i hp \n", heroTemplate.hp, monsterHp);
        if (monsterHp <= 0) {
            heroTemplate.kills += 1;
            printf("hero WON! %i hp remaining. \n", heroTemplate.hp);
            lua_pushnumber(L, heroTemplate.hp);
            return 1;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    if(heroTemplate.hp <= 0)
    {
        printf("your hero is DEAD! GAME OVER .\n");
        printf("congratulations! you've killed %i monsters so far! .\n", heroTemplate.kills);
    }
    lua_pushnumber(L, heroTemplate.hp);
    return 1;
}

int Actions::rest(lua_State *L)
{
    printf("You are touching some grass and feel safe. +1hp\n");
    heroTemplate.hp += 1;
    return 0;
}

int Actions::bless(lua_State *L)
{
    printf("You feel the presense of the divine spirit. +1 attack\n");
    heroTemplate.attack += 1;
    return 0;
}

int Actions::heroStats(lua_State *L)
{
    printf("your hero has %i hp and %i attack \n", heroTemplate.hp, heroTemplate.attack);
    return 1;
}
