//tianpei 天篷
//by calvin and leox 共同开发
//版权所有,未经许可不得翻录

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "云斩洞");
        set ("long", @LONG
这是一个不是很大的山洞,但是里面似乎很是开阔,好象洞连着洞...
洞的前上方有几个石刻的大字:

                 *********************
                 ****云***斩***洞*****
                 *********************
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
           "enter" :"/d/tianpeng/sandong1",
           "southeast" :"/d/tianpeng/hualu3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
