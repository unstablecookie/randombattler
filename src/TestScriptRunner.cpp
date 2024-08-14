//
// Created by usr on 24.03.2024.
//
#include <stdio.h>
#include <string>
#include "TestScriptRunner.h"

TestScriptRunner::TestScriptRunner() {}

void TestScriptRunner::run()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);//load base libraries
    lua_register(L, "stringPrinter", TestScriptRunner::stringPrinter);//register our function
    luaL_dofile(L, "strptr.lua");//run the script
    lua_close(L);//cleanup lua
}

int TestScriptRunner::stringPrinter(lua_State *L) {
    int n = lua_gettop(L);//get number of args
    for (int i = 1; i <= n; i++) {
        std::string inputString = lua_tostring(L, i);
        printf("i: %i  ->  ", i);
        printf("input string: %s END \n", inputString.c_str());//format string to c style string
    }
    return 0;
}