// created 17-06-2001 ����Ʈ(piao)

inherit ROOM;
void create()
{
        set("short", "��÷��");
        set("long", @LONG
�˸����������ٶ����İ�÷ľ����ϸ�����ɡ���÷ľ��
��������ľ�ʽ�ײ���Ӳ�����ʯ����ɢ����һ�ɵ��������㣬
���겻˥�������ĵ�һ�������÷ľ���졣����ΰ��������ţ�
����ľ�Ƽ��Ե�׺�����һ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" :__DIR__"guodao",
 "northeast" : __DIR__"backyard",
 "northwest" : __DIR__"kitchen",


]));
        set("objects", ([
		__DIR__"npc/ximen" :1,
                        ]) );

        set("coor/x",180);
	set("coor/y",-400);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}