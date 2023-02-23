search :

void RegisterGlobalFunctionTable(lua_State* L)


before add:

	struct FPurgeMonsters
	{
		void operator() (LPENTITY ent)
		{
			if ( ent->IsType(ENTITY_CHARACTER) == true )
			{
				LPCHARACTER lpChar = (LPCHARACTER)ent;
				if (lpChar->IsStone() == true or lpChar->IsMonster() == true)
				{
					M2_DESTROY_CHARACTER(lpChar);
				}
			}
		}
	};

	ALUA(_set_clean_regen_map)
	{
		int iMapIndex = static_cast<int>(lua_tonumber(L, 1));
		LPSECTREE_MAP pkMap = SECTREE_MANAGER::instance().GetMap(iMapIndex);

		if ( pkMap != NULL )
		{
			struct FPurgeMonsters f;
			pkMap->for_each( f );
		}

		return 0;
	}

search :

			{	"__get_guild_priv",				_get_guild_privilege			},

add:

			{	"set_clean_regen_map",			_set_clean_regen_map			},
