#include <ansi.h>

inherit ROOM;

void create ()
{
      set ("short", BLINK HIC"流"+HIY"星"+HIR"花"+HIW"园"NOR);
set ("long","^O^天边划过一颗美丽的流星……………………快许个愿吧^O^"+HIW"(wish)\n"
HIC"∴°"+BLINK HIY"★"NOR+HIC"．"+HIW"☆"+HIC"° ．"+BLINK HIY"★"NOR+HIC"·°∴°"+BLINK HIY"★"NOR+HIC"．° ．·。∴°·。∴°
"+HIW"☆"+HIC" ．·°∴° "+HIW"☆"+HIC"．．·°∴°．"+HIW"☆"+HIC"°"+BLINK HIY"★"NOR+HIC"°∴°"+HIW"☆"+HIC" ．·°
°∴ "NOR+BLINK HIR"那怕星际无垠 "NOR+HIW"☆"+HIC"° ．·"+BLINK HIY"★"NOR+HIC"°∴°．°°"+HIW"☆"+HIC"° ．·
∴°．°"+BLINK HIY"★"NOR+HIC" ．·°∴°．°∴°．"+BLINK HIY"★"NOR+HIW"☆"+HIC"° ．·∴°．°
°．☆° ．"+BLINK HIY"★"NOR+HIC"·"+BLINK HIG"我也要追到你"NOR+HIC"  °．°°．"+BLINK HIY"★"NOR+HIC"．"+HIW"☆"+HIC"°．
．·°∴"+BLINK HIY"★"NOR+HIC"°．°∴°．"+HIW"☆"+HIC"° ．·°∴°．"+HIW"☆"+HIC"° ．·°
"+HIW"☆"+HIC"·°∴°★．°．∴·°°"+BLINK HIB"并永远爱你"NOR+HIC"∴"+HIW"☆"+HIC"°．·°
．·°∴"+BLINK HIY"★"NOR+HIC"°．°∴°"+BLINK HIY"★"NOR+GRN"　　 ◢◣　"NOR+HIC"∴°．"NOR+HIW"☆"+HIC"° ．·"NOR+GRN"
　　　　　　　　　　　　  ◢◢◣　　　
　　　　　  "+WHT"/○\\ ● 　　 "+GRN"◢◢◣◣　　　"+YEL"┌─────────┐
 　　　　　 "+WHT"/■\\/■\\　"+GRN" ◢◢◢◣◣◣　"+YEL"　│"+BLINK HIC"泥娃娃"NOR+HIY"的"+HIW"露天工作室"NOR+YEL"│
 ═╪═╪═ "+WHT" <|  || "+YEL"═╪═╪═╪═╪═ └┬───────┬┘
"NOR);

        set("exits", 
        ([ //sizeof() == 2
              "ws" : "/d/wiz/wizroom",
                "kz" : "/d/city/kezhan",
              "tj" : "/d/guzhanchang/sky",
          "ljg":"/d/xueshan/lingjiu",
       "ydn":"/d/12gong/palace",
        "down"   : "/u/mudbaby/room/liangong",
       "li" : "/d/dntg/yunlou/yunloutai",
]));
set("valid_startroom", 1);
        set("no_fight",1);
        set("no_time",1);
      set("objects", ([
//   "/u/mudbaby/obj/dan": 1,
//      "/obj/wiz/rack" : 1,
//     "/u/mudbaby/npc/dog": 1,
//   "/u/mudbaby/npc/chunjiedashi": 1,
//     "/d/xueshan/npc/shizhe": 1,
     ]));
        setup();
//   call_other( "/obj/board/baby_b","???");
}
void init()
{
      add_action("do_wish","wish");
}
int do_wish()
{
object me;
me = this_player();
     if( time() - me->query("wish/time_start") <77)
     return notify_fail("你怎么这么贪心？愿望太多可是实现不了的哦！！\n"); 
message("channel:chat",HIC"【美梦成真】"+HIW"听说"HIG+me->query("name")+HIW"在"+BLINK HIC"流"+HIY"星"+HIR"花"+HIW"园"NOR+HIW"对着美丽的流星许下了一个美好的心愿。\n"
+HIC"                        大家祝他早日美梦成真!\n"NOR,users());
      me->set("wish/time_start", time());
 return notify_fail(HIY"\n你对着美丽的流星许下了一个美好的心愿。祝愿你早日美梦成真!\n"NOR);
}

