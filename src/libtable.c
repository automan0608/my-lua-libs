
#include <string.h>
#include <stdlib.h>

#include <lua.h>
#include <lauxlib.h>

static int l_tbl_insert(lua_State *L)
{
	luaL_checktype(L, 1, LUA_TTABLE);
	int e = luaL_len(L, n) + 1;

	int pos;

	switch (lua_gettop(L))
	{
		case 2:
			pos = e;
			break;
		case 3:
			int i;
			pos = luaL_checkint(L, 2);
			luaL_argcheck(L, 1 <= pos && pos <= e, 2, "position out of bound");
			for (i = e; i > pos; i--)
			{
				lua_rawgeti(L, 1, i-1);
				lua_rawgeti(L, 1, i);
			}
			break;
		default:
			return luaL_error(L, "wrong number of arguments to 'insert'");
	}

	lua_rawseti(L, 1, pos);
}


static const luaL_Reg my_tbl_lib[] = {
	{"insert", l_tbl_insert},
//	{"", l_tbl_sub},

	{NULL, NULL}
};

extern int luaopen_libtbl (lua_State *L) {
  luaL_newlib(L, my_tbl_lib);
  return 1;
}
