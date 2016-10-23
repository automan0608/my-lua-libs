
#include <string.h>
#include <stdlib.h>

#include <lua.h>
#include <lauxlib.h>


static int l_bit_and(lua_State *L)
{
	int n = lua_gettop(L);
	int i;

	unsigned int r = luaL_checkunsigned(L, -1);

	for (i = 2; i <= n; ++i)
	{
		r &= luaL_checkunsigned(L, -i);
	}

	lua_pushunsigned(L, r);
	return 1;
}

static int l_bit_not(lua_State *L)
{
	unsigned int r = luaL_checkunsigned(L, -1);

	lua_pushunsigned(L, ~r);
	return 1;
}

static int l_bit_or(lua_State *L)
{
	int n = lua_gettop(L);
	int i;

	unsigned int r = luaL_checkunsigned(L, -1);

	for (i = 2; i <= n; ++i)
	{
		r |= luaL_checkunsigned(L, -i);
	}

	lua_pushunsigned(L, r);
	return 1;
}

static int l_bit_xor(lua_State *L)
{
	int n = lua_gettop(L);
	int i;

	unsigned int r = luaL_checkunsigned(L, -1);

	for (i = 2; i <= n; ++i)
	{
		r ^= luaL_checkunsigned(L, -i);
	}

	lua_pushunsigned(L, r);
	return 1;
}

static const luaL_Reg my_bit_lib[] = {
	{"band", l_bit_and},
	{"bnot", l_bit_not},
	{"bor", l_bit_or},
	{"bxor", l_bit_xor},

	{NULL, NULL}
};

extern int luaopen_libbit (lua_State *L) {
  luaL_newlib(L, my_bit_lib);
  return 1;
}
