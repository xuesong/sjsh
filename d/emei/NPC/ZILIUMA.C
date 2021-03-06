
// hongma.c 枣红马

#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <ansi.h>

inherit NPC;

void create()
{
	set_name(MAG "紫骝马" NOR, ({ "ziliuma"}));
	set("long", "这是一匹紫骝宝马，日行千里，夜行八百。\n"+
		"玩家可以骑上它去指定的地方(ride)。\n");
	set("race", "野兽");
	set("age", 5);
	set("ridable", 1);
	set("int", 30);
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 100);
	set("max_jing", 100);
	set("shen_type", 0);
	set("combat_exp",50000);
	set("attitude", "peaceful");

	set("limbs", ({ "头部", "腹部", "尾巴","后腿","前腿" }) );
	set("verbs", ({ "bite","hoof" }) );
	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);
	set("chat_chance", 3);
	set("chat_msg", ({
		MAG"紫骝马"NOR"「吁嘘嘘」一阵嘶鸣，不停地踢着脚掌。\n",
		MAG"紫骝马"NOR"的长尾巴很不老实地不停地甩来甩去。\n",
	}) );

	setup();
}
