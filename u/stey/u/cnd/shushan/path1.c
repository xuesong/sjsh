//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;

void create()
{
        set("short", "蜀山山脚");
        set("long", @LONG
蜀山山路。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"paifang",
  "southdown" : __DIR__"shanjiao",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
