// 神话世界·西游记之（世纪）
 
// create by jing 2000.7.24

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG

这是一条平直的大路，向北一直就可以到到市中心的十字路口，喧哗声不
断传来，再往北就可以看到蠙城的皇宫，远远望去，自有一股气势，南面
是南城门，出入城门的人来来往往。
LONG);

  set("exits", ([
        "south"   : __DIR__"nanmen",
        "north"   : __DIR__"lukou",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

