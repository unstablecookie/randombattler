//
// Created by usr on 24.03.2024.
//

#ifndef LUATESTS_TESTSCRIPTRUNNER_H
#define LUATESTS_TESTSCRIPTRUNNER_H

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

class TestScriptRunner {
public:
    lua_State* L;
    TestScriptRunner();
    void run();
    static int stringPrinter(lua_State *L);
};


#endif //LUATESTS_TESTSCRIPTRUNNER_H
