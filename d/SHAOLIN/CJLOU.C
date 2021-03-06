// Room: /d/shaolin/cjlou.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "藏经阁一楼");
	set("long", @LONG
不愧为中原佛法的总源，少林寺此处藏经之富，天下罕有其
匹。这里都是密密麻麻，高及顶棚的书架，书架间仅有容身一人
通行的空隙。几排大书架中间，间隔地放着数丈长的书桌。目光
及处，你看到桌上放了几本佛经。
LONG );
	set("exits", ([
                "east" : __DIR__"hsyuan4",
		"up" : __DIR__"cjlou1",
	]));
	set("objects",([
                "d/shaolin/obj/book-iron.c":1,
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{

    mapping myfam;
    me = this_player();
    myfam = (mapping)me->query("family");
    if ((!myfam || (myfam["family_name"] != "少林寺")) && (dir == "up"))
      return notify_fail("非少林弟子，到此止步吧。\n");
    else  return 1;
}



