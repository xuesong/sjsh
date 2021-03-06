// jingang.c

#include <ansi.h>

inherit NPC;

void create()
{
	object ob1, ob2;
	
        string *order = ({"贤善", "接引", "须弥", "清净", "功德", "金刚", "伏虎", "庄严", "光明"});

        set_name((order[random(9)]) + "罗汉", ({ "luohan"}) );
        set("long", "这是一位来自少林寺的十八罗汉，专门担任护法之责。\n");
	set("attitude", "friendly");

        set("max_gin", 1000);
        set("max_kee", 1000);
        set("max_sen", 1000);

        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force", 1000);
        set("force", 1000);
	set("str", 40);
        set("cor", 40);
        set("cps", 40);

        set("combat_exp", 800000);
        set_skill("zui-gun", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("stick", 100);
        set_skill("shaolin-shenfa", 100);

	map_skill("dodge", "shaolin-shenfa");
	map_skill("stick", "zui-gun");
	map_skill("parry", "zui-gun");
        setup();

        ob1=carry_object("/d/shaolin/obj/xuan-cloth");
	ob1->wear();
	ob1->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
        ob2=carry_object("/d/shaolin/obj/qimeigun");
	ob2->wield();
	ob2->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
               HIY + name() + "说道：末罗汉奉法主召唤，现在已经完成护法任务，就此告辞！\n\n"
                + name() + "化成一片金光，消失不见了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
                HIY "只听轰！的一声，一团金光一闪，现出一个身穿护法袈裟手执棍棒的罗汉。\n\n"
                + name() + "说道：末罗汉奉法主召唤，特来护法！\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
}
