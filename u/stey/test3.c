//奖励npc
inherit F_VENDOR_SALE;

#include <ansi.h>
int give_wx();
int give_wx2();
int answer_me();

void create()
{
         set_name(HIC"玉宝宝"NOR, ({"baobao"}));
   set ("long", @LONG
他是在这里负责给大家发武学奖励的可爱的玉宝宝。（ask baobao about 奖励）
LONG);
           set("gender", "男性");
        set("title",HIY"活泼可爱的"NOR);
        set("age", 28);
        set("per", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("vendor_goods", ([
                "armor":        "/d/obj/armor/jinjia",
                "spellsbook":    "/d/obj/book/mihou-book.c",
                "sword":    "/u/stey/sttt.c",
                "whip":    "/u/stey/yaowhip1.c",
                "hammer":    "/u/stey/tianhammer.c",
                "stick":    "/u/stey/tianbang.c",
                "qin":    "/u/stey/moqin.c",
                "blade":    "/u/stey/guiblade.c",
                "staff":    "/u/stey/shenstaff.c",
                "parrybook":    "/d/obj/book/parrybook2",
                "forcebook":    "/d/obj/book/forcebook2",
        ]) );
        set("inquiry", ([
            "奖励"    :(:give_wx:),
            "武学奖励"    :(:give_wx:),
            "jiangli"    :(:give_wx:),
            "100万"    :(:give_wx2:),
   ]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
}
int answer_me()
{
        command("say 小心我扁你！嘿嘿 。\n");
        return 1;
}
int give_wx()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say 什么小猫小狗也来要礼物?");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 500000 ){
                command("hammer "+who->query("id") );
                command("say 你再努力努力，很快可以拿奖励的。");
                command("addoil "+who->query("id") );
                return 1;
         }
         if (this_player()->query("jjj") > 0 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 奖励只有一份！领过就不给了！\n");
        return 1;
        }
        who->add("potential",50000);
        who->add("balance",5000000);
        who->add("daoxing",50000);
        who->set("jjj",1);
message_vision("$N对着$n神秘的笑了笑，$n觉得身体发生剧烈的变化，顿时晕倒在地。\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
               你的道行增加了五十年!\n 
               你现在存款增加了500gold。\n");
          command("chat 恭喜恭喜，"+who->query("name")+"得到了武学50万的奖励！\n");
        return 1;
}
void init()
{
     call_out("greeting", 1, this_player());
      ::init();
   add_action("do_vendor_list", "list");
}
