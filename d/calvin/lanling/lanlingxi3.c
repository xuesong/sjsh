//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "兰陵西郊");
        set ("long", @LONG

这里是美丽的兰陵城的西郊,这里一路上景致密人,好不动人!
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "westdown" : "/d/changan/eastseashore",
                "east" : "/d/calvin/lanling/lanlingxi2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
