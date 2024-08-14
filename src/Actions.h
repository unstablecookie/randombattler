//
// Created by usr on 24.03.2024.
//

#ifndef RANDOMBATTLER_ACTIONS_H
#define RANDOMBATTLER_ACTIONS_H

#include "HeroTemplate.h"

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class Actions {
public:
    lua_State* L;
    static HeroTemplate heroTemplate;
    Actions();
    static void runBattle();
    static int battle(lua_State *L);
    static int rest(lua_State *L);
    static int bless(lua_State *L);
    static int heroStats(lua_State *L);
};


#endif //RANDOMBATTLER_ACTIONS_H
