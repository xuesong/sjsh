#include <ansi.h>
inherit NPC;

void create()
{
	int skill;

	set_name(YEL"安慈"NOR, ({ "mingwang anci","mingwang","anci" }) );
       set("title", WHT"明王"NOR);
	set("gender", "男性" );
	set("age", 40);
	set("long", "怀着对维新政府极度的仇恨，明王安慈化身为修罗，誓以双拳改造
这个世界。\n");
       set("per",20);
	set("combat_exp",1800000);
       set("daoxing",1800000);
       create_family("剑客联盟", 2, "弟子");
        set_skill("unarmed", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("spells", 180);  
        set_skill("renshu", 180);
        set_skill("literate", 180);
        set_skill("sword", 180);  
        set_skill("doom-sword", 180); 
        set_skill("kongshoudao", 200); 
        set_skill("fengyu-piaoxiang", 180);
        set_skill("dodge", 180);  
        set_skill("force", 180);   
        set_skill("guixi-force", 180);
        map_skill("spells", "renshu");
        map_skill("force", "guixi-force");
          map_skill("sword", "doom-sword");
        map_skill("parry", "doom-sword");
        map_skill("unarmed", "kongshoudao");
        map_skill("dodge", "fengyu-piaoxiang");
        set("max_kee", 2500);
        set("max_gin", 2500);
        set("max_sen", 2500);
        set("force", 4800);
        set("max_force", 2400);
        set("force_factor", 200);
        set("mana", 4800);
        set("max_mana", 2400);
        set("mana_factor", 200);
        setup();
	carry_object("/d/obj/cloth/zhanpao")->wear();
}
