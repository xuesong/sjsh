// 密林宝库 by Calvin

inherit ROOM;
void create ()
{
        set ("short", "密林");
        set ("long", @LONG
这是一条阴深恐怖的小路,及少有人会来这里,一路上只听见鬼哭声不断.
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "up" : "/d/milin/qy/u1",   
       "south" : "/d/milin/qy/6",   
       "down" : "/d/milin/qy/d1",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
 call_other("/obj/board/milin_b","???");
        replace_program(ROOM);
}
