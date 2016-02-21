//kunlun
inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "后堂");
        set ("long", @LONG

这是一间石室，里面只有一位老道长。四周全是石壁，
只有道长身后有一根很细的绳索(rope)通向另外一边，
你可以试试(climb) 。
LONG);

           set("item_desc", ([ /* sizeof() == 1 */
  "rope" : "一根绳子。",
]));

         
        set("exits", 
  ([ //sizeof() == 2
                "south" : __DIR__"mishi",
        ]));
        set("objects", ([
                __DIR__"npc/guang" : 1,

   ]));
       setup();
}

void init()
{
  add_action("do_climb", "climb");
}



int do_climb(string arg)
{
  object me=this_player();
 
  if( (!arg) || !((arg == "rope") || (arg == "绳子")))
    return notify_fail("爬什么？\n");
	  message_vision(HIR"$N眼前一花,滑入了混沌中。\n"NOR, me);
          me->move(__DIR__"hundun");
      return 1;
}
