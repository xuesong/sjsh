// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
void create()
{
       set_name("水猿大圣", ({"shuiyuan dasheng","shuiyuan", "dasheng"}));

        set("long","居于蠙城海底，久练成精，翻江倒海，令蠙城人民深受其祸。\n");
        set("gender", "男性");
        set("age", 60);
        set("int", 25);
        set("attitude", "heroism");
        set("combat_exp", (random(8)+1)*1200000);
        set("daoxing", (random(8)+1)*1200000);
        set("eff_dx", -50000);
        set("nkgain", 500);

       set("class","yaomo");
       set("per", 10);
   set("str", 30);
       set("max_kee", 2600);
       set("kee", 2600);
       set("max_sen", 2600);
       set("sen", 2600);
       set("force", 3000);
       set("max_force", 1500);
       set("force_factor", 150);
       set("max_mana", 1000);
       set("mana", 3000);
       set("mana_factor", 60);
       set_skill("unarmed", 120);
       set_skill("dodge", 110);
       set_skill("force", 110);
       set_skill("parry", 110);
       set_skill("spells", 120);
   set_skill("fork", 110);
   set_skill("yueya-chan", 140);
   map_skill("parry", "yueya-chan");
   map_skill("fork", "yueya-chan");
        setup();
   carry_object("/d/qujing/bibotan/obj/moonstaff")->wield();
}

void die ()
{
  object me = this_object();
  object ob, corpse;

        if( !ob = query_temp("last_damage_from") )
                ob= this_player();
      ob->set_temp("kill_yuan", 1);
  message_vision ("\n$N翻倒在地，死了。\n",me);
  corpse = CHAR_D->make_corpse(me,ob);
  corpse->move(environment(me));
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
} 


void unconcious ()
{
  die ();
}


void destruct_me (object me)
{
  destruct (me);
}

