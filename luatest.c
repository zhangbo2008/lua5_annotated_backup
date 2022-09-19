

#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

/* Lua解释器指针 */
lua_State *L;

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("usage: %s filename/n", argv[0]);
        printf("filename -- lua script file/n");
        return 0;
    }

    L = luaL_newstate(); /* 初始化Lua */
    luaL_openlibs(L); /* 载入Lua基本库 */

    luaL_dofile(L, argv[1]);             /* 运行脚本 */
    lua_close(L);                        /* 清除Lua */
    printf("Press enter to exit... /n"); /* 暂停 */
    getchar();
    return 0;
}