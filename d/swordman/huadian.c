// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "花店");
  set ("long", @LONG

花店里一阵清香扑鼻，沿街的门口种着一些鲜花，店里面墙头挂着五
颜六色的干花草，柜台上则是许多漂亮的花瓶，瓶内插着各式各样的
鲜花。

LONG);

  set("exits", ([
        "south"   : __DIR__"dalu6",
      ]));
  set("objects", ([
        __DIR__"npc/flowergirl"   : 1,
      ]));

  setup();
}


