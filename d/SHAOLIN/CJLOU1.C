// Room: /d/shaolin/cjlou1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "藏经阁二楼");
	set("long", @LONG
千余年来少林寺执中原武林之牛耳，自达摩老祖以下，历代
人材辈出。其中有不少高僧遗著留存，汇集至今，终成名震天下
的少林七十二绝艺。少林精华，尽集于此。二楼四面开窗，确保
通风。中间排列着五排大书架。四周则陈列矮几，以供阅读。几
位老僧手执经卷，正在闭目凝思。
LONG );
	set("exits", ([
		"down" : __DIR__"cjlou",
	]));
        set("objects",([
                "d/shaolin/obj/fojing1"+random(2) : 1,
                "d/shaolin/obj/fojing2"+random(2) : 1,
		
		
	]));
//	set("no_clean_up", 0);
	setup();
}
int valid_leave(object me, string dir)
{
     me = this_player();
     if ((dir == "down") && ( present("shu", me)))
     {
         return notify_fail
                ("你想把经书拿走，上前轻声说道：本阁经书不外借。\n");
     }
     return ::valid_leave(me, dir);
}

