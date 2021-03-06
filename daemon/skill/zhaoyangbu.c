// zhaoyangbu.c 【朝阳步】

#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
	"$n轻轻一纵，使个"YEL"「破山势」"NOR"，避开了这一招。\n",
	"$N眼一花，$n使出"HIR"「破火势」"NOR"一个筋斗从$N头顶越过。\n",
	"$n一声：好！一招"HIC"「破海势」"NOR"连翻几个筋斗，连影子都没了。\n",
	"$n左足一点，一招"HIG"「破林势」"NOR"腾空而起，避了开去。\n",
	"但是$n使一招"HIY"「破金势」"NOR"，身子轻轻飘了开去。\n",
	"只见$n卷起一股疾风，身形亦腾风而起，正是“朝阳步”中的"HIW"「破天势」"NOR"！\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
	return notify_fail("你的内力不够，没有办法练朝阳步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练朝阳步。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}

int stage(int level)
{
	if( level <20 ) return 1;
	else if ( level < 60 ) return 2;
	else if ( level < 80 ) return 3;
	else if ( level < 140 ) return 4;
	else if ( level < 180 ) return 5;
	else return 6;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return YEL "破山势　" NOR;
	else if ( stage(level) < 2 )
		return HIR "破火势　" NOR;
	else if ( stage(level) < 3 )
		return HIC "破海势　" NOR;
	else if ( stage(level) < 4 )
		return HIG "破林势　" NOR;
	else if ( stage(level) < 5 )
		return HIY "破金势　" NOR;
	else 
		return HIW "破天势　" NOR;
}