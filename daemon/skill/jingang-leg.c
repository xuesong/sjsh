//banruo-zhang.c 【般若掌】weiqi
//menpai skill(non manpai NPCs can also use it)

inherit SKILL;
#include <ansi.h>;

mapping *action = ({
([      "action" : "$N双手虚晃，左脚猛地飞起，一式"+BLINK""+HIW"「风起云涌」"NOR+"，脚尖晃动，踢向$n的屁股",
        "parry" : -10,
        "dodge" : -15,
        "damage_type" : "瘀伤",
        "skill_name" : "风起云涌"
]),
([      "action" : "$N左脚顿地，别转身来抽身欲走，只一刹那间一回身，右脚一式
"+BLINK""+HIB"「空谷足音」"NOR+"，猛踹$n的$l",
        "parry" : -20,
        "dodge" : -10,
        "damage_type" : "瘀伤",
        "skill_name" : "空谷足音"
]),
([      "action" : "$N左手一挣，反手扭搭住$n的右手，右脚同时踹出，既猛且准，一
式"+BLINK""+HIY"「碧渊腾蛟」"NOR+"，踢中的$n的胸口",
        "parry" : -25,
        "dodge" : 5,
        "damage_type" : "瘀伤",
        "skill_name" : "碧渊腾蛟"
]),
([      "action" : "$N突然跃起，双足连环圈转，一式"+BLINK""+HIG"「秋风落叶」"NOR+"，足带风尘，攻向$n的全身",
        "parry" : 10,
        "dodge" : -25,
        "damage_type" : "瘀伤",
        "skill_name" : "秋风落叶"
]),
([      "action" : "$N两手护胸，双脚交叉踢起，一式"+BLINK""+HIC"「风扫残云」"NOR+"，脚脚不离$n的面门左右",
        "parry" : 10,
        "dodge" : -10,
        "damage_type" : "瘀伤",
        "skill_name" : "风扫残云"
]),
([      "action" : "$N突然侧身，却步后退，一个前空翻，右脚自上而下一式"+BLINK""+HIR"「流星坠地」"NOR+"，照$n的面门直劈下来",
        "parry" : -20,
        "dodge" : 5,
        "damage_type" : "瘀伤",
        "skill_name" : "流星坠地"
]),
([      "action" : "$N使一式"+BLINK""+HIW"「朔风吹雪」"NOR+"，全身突然飞速旋转，双足忽前忽后，迅猛
无极踹向$n的胸口",
        "parry" : -20,
        "dodge" : -10,
        "damage_type" : "瘀伤",
        "skill_name" : "朔风吹雪"
]),
([      "action" : "$N抽身跃起，开声吐气，大喝一声：嗨！一式"+BLINK""+HIR"「雷动九天」"NOR+"，双脚
如旋风般踢向$n的$l",
        "parry" : 20,
        "dodge" : 5,
        "damage_type" : "瘀伤",
        "skill_name" : "雷动九天"
]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("练大力金刚腿必须空手。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("kee", 30);
	me->add("force", -10);

	return 1;
}

string perform_action_file(string func)
{
return CLASS_D("shaolin") + "/jingang-leg/" + func;
}
