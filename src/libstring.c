
#include <stdlib.h>
#include <math.h>

#include <lua.h>
#include <lauxlib.h>




static const luaL_Reg my_math_lib[] = {
	{"abs", l_math_abs},
	{"max", l_math_max},

	{NULL, NULL}
};

extern int luaopen_libmath (lua_State *L) {
  luaL_newlib(L, my_math_lib);
  lua_pushnumber(L, PI);
  lua_setfield(L, -2, "pi");
  return 1;
}
