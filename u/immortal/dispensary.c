#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW "药 房" NOR);
set ("long", @LONG

          冶  金  练  药         长  生  养  颜

LONG);
set("exits", ([
"north": __DIR__"parlour",
]));
set("no_clean_up", 1);
set("outdoors", 0);
set("objects", ([
"/u/immortal/obj/cabinet": 1,]));
setup();
}
