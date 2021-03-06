

inherit NPC;
int give_book ();

string *msgs = ({
"经云《摩诃般若波罗蜜多心经》：观自在菩萨，行深般若波罗蜜多，时照见五蕴皆空，度一切苦厄。",
"舍利子，色不异空，空不异色；色即是空，空即是色。受想行识，亦复如是。",
"舍利子，是诸法空相，不生不灭，不垢不净，不增不减。"
"是故空中无色，无受想行识，无眼耳鼻舌身意，无色声香味触法，无眼界，乃至无意识界。",
"无无明，亦无无明尽，乃至无老死，亦无老死尽。无苦寂灭道，无智亦无得。以无所得故，菩提萨裰。",
"依般若波罗蜜多故，心无挂碍，无挂碍故，无有恐怖。",
"远离颠倒梦想，究竟涅槃，三世诸佛，依般若波罗蜜多故，得阿耨多罗三藐三菩提。",
"故知般若波罗蜜多，是大神咒，是大明咒，是无上咒，是无等等咒，能除一切苦，真实不虚。",
"故说般若波罗蜜多咒，即说咒曰：‘揭谛！揭谛！波罗揭谛！波罗僧揭谛！菩提萨婆诃！’",
});
void create()
{

  set_name("乌巢禅师", ({ "wuchao chanshi", "chanshi", "wuchao" }) );
  set("gender", "男性" );
  set("age",55);
  set("attitude", "peaceful");
  set("rank_info/self", "贫僧");
  set("class", "bonze");
  set("max_kee", 5000);
  set("max_gin", 5000);
  set("max_sen", 5000);
  set("force", 4000);
  set("max_force", 2000);
  set("force_factor", 145);
  set("max_mana", 3000);
  set("mana", 6000);
  set("mana_factor", 150);
  set("combat_exp", 2000000);
  set("daoxing", 10000000);

  set_skill("literate", 150);
  set_skill("spells", 200);
  set_skill("buddhism", 200);
  set_skill("unarmed", 150);
  set_skill("jienan-zhi", 150);
  set_skill("dodge", 180);
  set_skill("lotusmove", 180);
  set_skill("parry", 180);
  set_skill("force", 180);
  set_skill("lotusforce", 180);
  set_skill("staff", 180);
  set_skill("lunhui-zhang", 180);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
          (: cast_spell, "bighammer" :),
    }) );
  set("inquiry", ([
    "book" : (: give_book :),
  ]) );

  setup();
  carry_object("/d/obj/cloth/hufa-jiasha")->wear();
}
int give_book()
{
  object me = this_object();
  object who = this_player();
  object book;

  if (! who->query("obstacle/wuchao"))
  {
    message_vision ("$N对$n摇了摇头：伏魔山心经，只送有缘之人，我们大概没有缘分。\n",me,who);
    return 1;
  }
  if( (int)who->query("daoxing")<200000 )
{
    message_vision ("$N对$n摇了摇头：伏魔山心经，只送有缘之人，我们大概没有缘分。\n",me,who);
    return 1;
}
  if (me->query_temp("given_book"))
  {
    message_vision ("$N对$n摇了摇头：不要贪得无厌。\n",me,who);
    return 1;
  }
  book = new ("/d/obj/book/fumo2");
  command ("nod");
  message_vision("$N给$n一本"+book->query("name")+"。\n",me,who);
  if(!book->move(who)) {
      destruct(book);
  }
  command ("give "+who->query("id")+" book");
  me->set_temp("given_book",1);
  call_out("reset_give",180);
  return 1;
}
void reset_give ()
{
  object me = this_object();
  me->set_temp("given_book",0);
}
	
void init ()
{
  add_action ("do_tingjing", "tingjing");
}

int do_tingjing ()
{
  object who = this_player();
  int size = sizeof(msgs);
  int i = who->query("obstacle/wuchao_tingjing");
  int j;

  if (who->is_busy())
    return notify_fail ("你正忙着呢！\n");

  message_vision ("$N开始认真听乌巢禅师讲经说法。\n",who);
  if (i >= size)
{
    message_vision ("\n$N已经听完了经书。\n",who); 
  who->set("obstacle/wuchao",1);
  }  
  else
  {
    j = 180;
    who->start_busy (j,j);
    call_out ("start_tingjing",5,who,i);
    call_out ("finish_tingjing",j,who);
  }
  return 1;
}

void start_tingjing (object who, int i)
{
  message_vision ("\n乌巢禅师念道："+msgs[i]+"\n",who); 
  who->set("obstacle/wuchao_tingjing",i+1);
}

void finish_tingjing (object who)
{
  object where = environment(who);

  who->interrupt_me ();
  message_vision ("\n$N听完一句经文，默默的回忆了一遍。\n",who); 
  }






