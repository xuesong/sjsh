#include <ansi.h>
inherit NPC;
void create()
{ set_name(HIG"衣青"NOR,({"plava", "xiao yiq"}));
  set("long","澜舟的老公衣青。\n");
  set("title",HIM"舟儿的挚爱"NOR);
  set("gender","男性");
  set("per",40);
  set("age",20);
  set("str",35);
  set("con",30);
  set("int",30);
  set("max_kee", 1000);
  set("eff_kee", 1000);
  set("kee", 1000);
  set("max_force",2000);
  set("force",400);
  set("combat_exp", 1000000);
    set("inquiry",([
       "yiq": "衣青就是我，是舟儿的老公，小舟儿的爸爸啦。\n",
       "衣青": "衣青就是我，是舟儿的老公，小舟儿的爸爸啦。\n",
       "rainy": "她是我老婆啊！携着舟儿的手，抱着宝宝逛街聊天，是我们一家最快乐的时候。\n",
       "澜舟": "她是我老婆啊！携着舟儿的手，抱着宝宝逛街聊天，是我们一家最快乐的时候。\n",
       "舟儿": "她是我老婆啊！携着舟儿的手，抱着宝宝逛街聊天，是我们一家最快乐的时候。\n",
        ]));

  set("chat_chance",8);
  set("chat_msg", ({
  HIG"衣青轻声告诉你:舟儿不是恐龙，可是我叫她恐龙妹妹，她是我心中最爱的恐龙妹妹！\n"NOR,
  HIG"衣青又在思念了:舟儿还没来吗？我想她了！\n"NOR,

          }));

  setup();
  carry_object("/u/yiq/obj/zuanjie")->wear();
}
