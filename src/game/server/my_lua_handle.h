#pragma once

#include "cbase.h"  // Required for Source SDK types

extern "C" {
#include "..\..\Lua\include\lua.h"
#include "..\..\Lua\include\lualib.h"
#include "..\..\Lua\include\lauxlib.h"
}

class MyLuaHandle {
public:
    MyLuaHandle();
    ~MyLuaHandle();

    void Init();         // Load and run Lua script
    void Shutdown();     // Cleanup
    void RegGlobals();   // Register global variables
    void RegFunctions(); // Register native functions

    lua_State* GetLuaState(); // Access Lua state

private:
    lua_State* L;        // The Lua interpreter
    bool LoadLuaScript(const char* filePath); // Helper to load Lua file
};

// Global access
extern MyLuaHandle* g_LuaHandle;
MyLuaHandle* GetLuaHandle();