//2001.5.22
//by yxm
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set ("short", HIW"阿修罗界之门"NOR);
  set ("long", @LONG
门口矗立两座恶鬼塑像，张牙舞爪，令人不寒而栗！
这里就是传说中的阿修罗界入口，只见门上写着：
[1;31m      进     万[2;37;0m
[1;31m      此     劫[2;37;0m
[1;31m      门     不[2;37;0m
[1;31m      者     复[2;37;0m
LONG);
set("exits", ([ /* sizeof() == 1 */
"north" : "/u/tianlin/阿修罗界/lu1",
]));
  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/egui" : 2,
]));
        setup();
}
int valid_leave(object me, string dir)
{       if (dir == "north") {
        if (objectp(present("xiuluo egui", environment(me))))
        return notify_fail("修罗恶鬼怪叫道：“你给老子找死吗？竟敢来我阿修罗界！\n");
        }

        return ::valid_leave(me, dir);
        }
