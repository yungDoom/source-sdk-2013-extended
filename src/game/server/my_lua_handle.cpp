#include "cbase.h"
#include "my_lua_handle.h"
#include <iostream>

extern MyLuaHandle* g_LuaHandle = nullptr;

MyLuaHandle* GetLuaHandle() {
    return g_LuaHandle;
}

MyLuaHandle::MyLuaHandle() {
    L = luaL_newstate();
    luaL_openlibs(L);
    g_LuaHandle = this;
    Init();
}

MyLuaHandle::~MyLuaHandle() {
    Shutdown();
}

void MyLuaHandle::Init() {
    RegGlobals();
    RegFunctions();

    const char* scriptPath = "scripts/game_script.lua";
    if (!LoadLuaScript(scriptPath)) {
        std::cerr << "[Lua] Failed to load script: " << scriptPath << "\n";
    }
}

void MyLuaHandle::Shutdown() {
    if (L) {
        lua_close(L);
        L = nullptr;
    }
}

void MyLuaHandle::RegGlobals() {
    lua_pushnumber(L, 42.0);
    lua_setglobal(L, "ANSWER_TO_EVERYTHING");

    lua_pushstring(L, "Hello from C++!");
    lua_setglobal(L, "GREETING");
}

void MyLuaHandle::RegFunctions() {
    lua_register(L, "PrintMessage", [](lua_State* L) -> int {
        const char* msg = lua_tostring(L, 1);
        std::cout << "[Lua] " << msg << "\n";
        return 0;
        });
}

bool MyLuaHandle::LoadLuaScript(const char* filePath) {
    if (luaL_loadfile(L, filePath) || lua_pcall(L, 0, LUA_MULTRET, 0)) {
        std::cerr << "[Lua] Error: " << lua_tostring(L, -1) << "\n";
        lua_pop(L, 1);
        return false;
    }
    return true;
}

lua_State* MyLuaHandle::GetLuaState() {
    return L;
}