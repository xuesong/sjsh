//2001.5.22
//by yxm
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set ("short", HIW"穷极魔洞"NOR);
  set ("long", @LONG
这里就是关押魔佛无天的地方，黑暗之渊的地底。
[1;31m      穷[2;37;0m
[1;31m      极[2;37;0m
[1;31m      魔[2;37;0m
[1;31m      洞[2;37;0m
LONG);

  set("objects", ([ 
     __DIR__"npc/wutian" : 1,
]));
        setup();
}
