//kunlun
inherit ROOM;

void create ()
{
        set ("short", "石阶");
        set ("long", @LONG
一条石阶小路蜿蜒而上，四处风吹草动，聆听空谷回音。四处见
山峦，路在这里显得宽畅一些，地面较平坦。
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "southdown" : __DIR__"gate",
                "westup" : __DIR__"shijie1",
        ]));
        set("objects", ([
   ]));
        set("outdoors", "changan");
       setup();
	replace_program(ROOM);
}

