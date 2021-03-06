inherit SKILL;
#include <ansi.h>
mapping *action = ({
	([	"name":			"叁番涉世反相嗔",
		"action":
"$N手中神魔锏横腰一扫，一招"+BLINK""+HIG"「叁番涉世反相嗔」"NOR"一片鞭影扫向$n",
		"dodge":		-5,
		"parry":		5,
		"damage":		20,
		"damage_type":		"砸伤"
	]),
	([	"name":			"白首牢骚类野人",
		"action":
"只见$N几个急转，使出"+BLINK""+HIW"「白首牢骚类野人」"NOR"，一声大喝中冲天而起，砸向$n的$l",
		"dodge":		-5,
		"parry":		-15,
		"damage":		35,
		"damage_type":		"砸伤"
	]),
	([	"name":			"溪未入飞熊梦",
		"action":
"$N你手中神魔锏一抖，只见漫天黑影。遮天蔽日。\n"
"这一招"+BLINK""+HIM"「溪未入飞熊梦」"NOR" 只看得$n眼花缭乱，哪里还能招架",
		"dodge":		-15,
		"parry":		-5,
		"damage":		35,
		"damage_type":		"砸伤"
	]),
	([	"name":			"渭水安知有瑞麟",
		"action":
"$n只觉得眼前一花，$N已悄然间闪至$n身后，手中神魔锏直指$n的后心， \n"
"正是一式"+BLINK""+HIC"「渭水安知有瑞麟」"NOR"",
		"dodge":		10,
		"parry":		-10,
		"damage":		20,
		"damage_type":		"震伤"
	]),
	([	"name":			"会际风云开帝业",
		"action":
"$N不闪不避，一式"+BLINK""+HIY"「会际风云开帝业」"NOR"，气定神闲， 蓄势待发，\n"
"掌中神魔锏直指$n破绽所在",
		"dodge":		-10,
		"parry":		0,
		"damage":		25,
		"damage_type":		"戳伤"
	]),
	([	"name":			"几度束身成老拙",
		"action":
"$N运气发劲，一式"+BLINK""+HIR"「几度束身成老拙」"NOR"舞出无数幻影, \n"
"$n只觉得漫天乌光袭来，不知该如何闪躲",
		"dodge":		-5,
		"parry":		-5,
		"damage":		15,
		"damage_type":		"割伤"
	]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力修为不够深，不能学打神鞭法。\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "mace" )
		return notify_fail("手里没有兵器怎么练？\n");
	return 1;
}
	
int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你体质欠佳，强练打神鞭法有害无益。\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你内力不足，强练打神鞭法有走火入魔的危险。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("只见一团黑影中走出$N，原来刚练完打神鞭法。\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="mace"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
string perform_action_file(string action)
{
        return CLASS_D("kunlun") + "/dashen-bian/" + action;
}
