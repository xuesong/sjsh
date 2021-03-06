// PK巡捕 by Calvin

#include <ansi.h>
#include
inherit NPC; 
void catchyou(object);
void copy_status(object me, object ob);

void create() 
{
string *surname=({"慕容","西门","公孙","上官","南宫","欧阳","司徒",});
set_name(surname[random(sizeof(surname))]+"巡捕", ({ "xun bu","police"}) );
set("age", 18+random(10));
set("title","行善去恶"); 
set("gender", "男性"); 
set("long","这时用来阻止随意PK的巡捕。\n");
set("attitude", "peaceful"); 
set("str", 20); 
set("combat_exp", 10000); 
set("max_kee", 800);
set("max_sen", 800); 
set("max_force", 500);
set("force", 500); 
set("force_factor", 40);
set_skill("unarmed", 40); 
set_skill("parry", 40); 
set_skill("dodge", 40);
set_skill("force", 40); 
set_skill("blade", 40);
set("chat_chance_combat", 140);
set("chat_msg_combat", ({ 
"巡捕说道：你想干什么? 还不跟我去县衙受审!?\n",
"巡捕说道：大胆! 居然敢当街拒捕! 想造反？\n", 
"巡捕手中的刀越砍越快，让你应接不暇。\n", 
"巡捕说道：别胡闹了，还是乖乖的跟我走吧。\n" 
}) );

/* set ("chat_chance",10);
set ("chat_msg", ({ 
(:random_move:),
}) );
*/ setup();
carry_object("/d/obj/weapon/blade/blade")->wield();
carry_object("/d/obj/cloth/bingfu")->wear();
}

void init()
{
object ob,who;
who=this_object();
::init();
if (interactive(ob = this_player()) && 
(int)ob->query_condition("killer")) { 
message_vision(HIC+"巡捕对$N喝道：大胆逃犯还不束手就擒？\n"+NOR, this_player()); 
who->set_leader(ob);
copy_status(who,ob); 
kill_ob(ob);
ob->kill_ob(who);

}

}

//copy from qianmian gui //felix
void copy_status(object me, object ob) 
{
mapping hp_status, skill_status, map_status; 
string *sname, *mname; 
int i,j;

// delete old skills.
if(skill_status = me->query_skills()) { 
sname = keys(skill_status);
j=sizeof(skill_status);
for(i=0 i me->delete_skill(sname[i]);
}
}

//copy new skills.
if (skill_status = ob->query_skills() ) { 
sname = keys(skill_status);
for(i=0 i me->set_skill(sname[i], skill_status[sname[i]]);
}
set_skill("blade", 140);
}

//delete old skill mappings.
if(map_status = me->query_skill_map()) { 
mname = keys(map_status);
j=sizeof(map_status);
for(i=0; i me->map_skill(mname[i]);
}
}

//add new skill mappings. 
if (map_status = ob->query_skill_map()) { 
mname = keys(map_status);
for(i=0; i me->map_skill(mname[i], map_status[mname[i]]);
}
}

hp_status = ob->query_entire_dbase(); 

me->set("str", hp_status["str"]);
me->set("int", hp_status["int"]); 
me->set("con", hp_status["con"]); 
me->set("cps", hp_status["cps"]); 
me->set("cor", hp_status["cor"]);
me->set("spi", hp_status["spi"]); 
me->set("per", hp_status["per"]);
me->set("kar", hp_status["kar"]);

me->set("eff_kee", hp_status["eff_kee"]);
me->set("kee", hp_status["kee"]);
me->set("eff_gin", hp_status["eff_gin"]);
me->set("gin", hp_status["gin"]);
me->set("eff_sen", hp_status["eff_sen"]);
me->set("sen", hp_status["sen"]);

me->set("max_kee", hp_status["max_kee"]);
me->set("max_gin", hp_status["max_gin"]);
me->set("max_sen", hp_status["max_sen"]);
me->set("max_force", hp_status["max_force"]); 
me->set("force", hp_status["force"]);
me->set("force_factor", hp_status["force_factor"]);
me->set("mana_factor", hp_status["mana_factor"]);
me->set("combat_exp",hp_status["combat_exp"]); 

return ;
}

void unconcious() 
{
die(); 
}
void kill_ob(object ob) 
{
object me=this_object();

copy_status(me,ob); 
::kill_ob(ob); 
}

