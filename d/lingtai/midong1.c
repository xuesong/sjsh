// changan wusheng
// midong3.c

inherit ROOM;

void create ()
{
  set ("short", "����ɽ�ܶ�");
  set ("long", @LONG

������߼�Ϊ΢��������ǿ�ؿ�����������ԼԼ��һЩ������
ȴ�ֿ��ò���ʮ��������㲻������������Ŷ��ڣ�С�ĵ���
�����ж���Ϊʲô�ڷ���ɽ��������ܶ����ѵ������б��

LONG);

  set("exits", ([
        "down" : __DIR__"room7",
      ]));
  set("objects", ([
        __DIR__"obj/sword"  : 1,
      ]));
  set ("sleep_room",1);

  setup();
}


