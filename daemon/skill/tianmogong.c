// tianmogong.c  【天魔功】

#include <ansi.h>

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( 2*(int)me->query_skill("spells") <= (int)me->query_skill("tianmogong") )
        return notify_fail("你的法术修为还不够高深，无法学习天魔功。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("sanjie") + "/tianmogong/"+spell;
}

string type() { return "magic"; } 

int stage(int level)
{
	if( level <80 ) return 1;
	else if ( level < 160 ) return 2;
	else if ( level < 240 ) return 3;
	else if ( level < 280 ) return 4;
	else return 5;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return HIR "天魔蚀肉" NOR;
	else if ( stage(level) < 2 )
		return HIY "天魔蚀骨" NOR;
	else if ( stage(level) < 3 )
		return HIC "天魔蚀经" NOR;
	else if ( stage(level) < 4 )
		return HIM "天魔蚀魂" NOR;
	else 
		return HIW "天魔极乐" NOR;
}