// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ɽׯ��Ժ");
        set("long", @LONG
��Ժ��ǰ��ͨ��ׯ����͵İ�÷��������������ɽׯ����
��ƫԺ��ɽ�紩�ö������ļ����еİ��������Ű�÷�󡣸�ǰ��
��ʯ�ײ����˸�ɫ�Ļ��ꡣ
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"cleft",
  "east" : __DIR__"cright",
  "north" : __DIR__"guodao",
  "south" : __DIR__"road",
]));
                   set("objects", ([  
                        __DIR__"npc/zhangmen" :1,  
                          ]) );  

        set("outdoors", "wanmei");

        set("coor/x",170);
	set("coor/y",-400);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}