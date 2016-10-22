

#include <stdlib.h>
#include <math.h>

#include <lua.h>
#include <lauxlib.h>

#define PI ((lua_Number)(3.1415926535897932384626433832795028841971))

static int l_math_abs(lua_State *L)
{
	lua_Number d = luaL_checknumber(L, 1);
	lua_pushnumber(L, abs(d));
	return 1;
}

static int l_math_max(lua_State *L)
{
	int n = lua_gettop(L);
	lua_Number dmax = luaL_checknumber(L, 1);

	int i;
	for (i = 2; i < n; ++i)
	{
		lua_Number d = luaL_checknumber(L, i);
		if (d > dmax)
		{
			dmax = d;
		}
	}

	lua_pushnumber(L, dmax);
	return 1;
}

static int l_math_min(lua_State *L)
{
	int n = lua_gettop(L);
	lua_Number dmin = luaL_checknumber(L, 1);

	int i;
	for (i = 2; i < n; ++i)
	{
		lua_Number d = luaL_checknumber(L, i);
		if (d < dmin)
		{
			dmin = d;
		}
	}

	lua_pushnumber(L, dmin);
	return 1;
}

static int l_math_log(lua_State *L)
{
	lua_Number n = luaL_checknumber(L, 1);

	lua_pushnumber(L, log(n));
	return 1;
}

static int l_math_sin(lua_State *L)
{
	lua_Number n = luaL_checknumber(L, 1);

	lua_pushnumber(L, sin(n));
	return 1;
}

static int l_math_cos(lua_State *L)
{
	lua_Number n = luaL_checknumber(L, 1);

	lua_pushnumber(L, cos(n));
	return 1;
}

static int l_math_top(lua_State *L)
{
	int n = lua_gettop(L);

	lua_pushnumber(L, n);
	return 1;
}

static const luaL_Reg my_math_lib[] = {
	{"abs", l_math_abs},
	{"max", l_math_max},
	{"min", l_math_min},
	{"log", l_math_log},
	{"sin", l_math_sin},
	{"cos", l_math_cos},

	{"top", l_math_top},
	{NULL, NULL}
};

extern int luaopen_libmath (lua_State *L) {
  luaL_newlib(L, my_math_lib);
  lua_pushnumber(L, PI);
  lua_setfield(L, -2, "pi");
  return 1;
}
