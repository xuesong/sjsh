inherit NPC;
#include <ansi.h>
  int give_bonnet();
    int give_dan();
    int give_title();
   int accept_object(object who, object ob)
{
                    if( (string)ob->query("id")=="loyal bonnet" )
{
who->set("yudian/bonnet",0);
                    command("say 好借好还，再借不难。");
    return 1;
}
}
void create()
{
                        set_name(HIB"孙影"NOR, ({"sun ying","sun", "sunying"}));
   set ("long", @LONG
  据说是孙悟空的徒弟，现在在这里负责给大家发礼物(gift)，
  他身上还有天师法冠(bonnet)呢!
  不信你就去问问(ask)他。记得，天师法冠用完了要还哦！
LONG);
         set("gender", "男性");
            set("title",HIM"仙侣"HIG"情缘"NOR);
                 set("age", 20);
        set("per", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("inquiry", ([
            "bonnet":(:give_bonnet:),
           "title":(:give_title:),
]));
        setup();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
}
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
say(name()+"神秘地说：“想要礼物吗？找我啊！不过，你只有一次机会哦！哈哈！”\n"NOR);
}
int give_title()
{
object who=this_player();
 who->set("title",CYN"感觉有点冷"NOR);
  who->set("name", HIC "游戏兔子" NOR );
return 1;
}

