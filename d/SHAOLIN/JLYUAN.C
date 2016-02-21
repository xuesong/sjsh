// Room: /d/shaolin/jlyuan.c
// Date: YZC 96/01/19


#include <ansi.h>
#include <login.h>

inherit ROOM;

void create()
{
	set("short", "����Ժ");
	set("long", @LONG
��������Ż����գ��ܲ�͸�硣�������ڰ��磬Ҳ�����
ҹһ�㣬ÿ��������ǽ�ϣ���ȼ�ż�֦ţ�;����·�����һ
����������ˮţƤ�ޡ�������弰���������̾ߡ�����վ����
�ֱֳ��е�ִ��ɮ��������������������������㣬���㲻
����������������
LONG );
	set("no_fight", "1");
	set("exits", ([
		"southdown" : __DIR__"guangchang3",
	]));
	set("valid_startroom",1);
	set("objects",([
                __DIR__"npc/xuantong" : 1,
                __DIR__"npc/sengbing1" : 3,
			]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{	
	mapping fam;
	object ob;

	if( interactive(ob = this_player()) )
	{
		if( mapp(fam = ob->query("family")) 
                &&  fam["family_name"] == "������" )
			return;
		else 
		{
                        message_vision(HIY "$Nһ������Ժ��...ֻ��������ȣ���ͬը�װ��ڴ������졣\n"
  "$N����������������Ҳվ����ס����һ������ͨһ������������\n\n" NOR, ob);

                        ob->set("startroom", "/d/shaolin/jlyuan");

			remove_call_out("processing");
			call_out("processing", 3, ob);
		}
	}
}

void processing(object ob)
{
	mapping fam;

	write(HIW "\n�㶨�˶���̧ͷϸ����ֻ����ʮ���ֵ�ɮ�˽�������Χ������\n"
		"һƬѩ���ĵ���Ƶ����۶�����������ǰ���ĸ�̨�Ϸ���һ��\n"
		"̫ʦ�Σ����и�����λ�����ü����ɮ����ɫ���࣬Ŀ�侫�⣬\n"
		"�ݺݵص����㡣\n\n\n" NOR);

        if ( (fam = ob->query("class")) != "bonze" )
      message_vision(HIY "��ʹһ����ȣ����ȴ󵨿�ͽ���ô����½���Ժ�����ڲ��죬�õ����\n"
        "���������½���Ժ�������������С��˺�����Ϊ��ִ��ɮ�����ڣ�\n\n" NOR, ob);
	message_vision(HIR "ɮ������Ӧ���������ڣ�\n" NOR, ob);
        message_vision(HIR "ɮ����һӿ���ϣ��Ұ����£�$N�����˳�ȥ......\n\n\n" NOR, ob);
                        ob->move("/d/shaolin/guangchang3");
                        ob->add("combat_exp",40);
                        ob->start_busy(5);
                        ob->add("kee",-100);
                        return;

        if ( (fam = ob->query("class")) == "bonze" )
         message_vision(HIY "��ʹ����$N���˰��ã�˵����$N����Ͷ����ƣ��������������ñ��ã�"
        "ƶɮ��ʹ���ȥ����Ħ��ʦ��\n\n" NOR, ob);
        message_vision(HIR "��ʹ����$N��������������Ħ��......\n\n\n" NOR, ob);

                        ob->set("startroom", START_ROOM);
                        ob->add("combat_exp",50);
                        ob->add("kee",-20);
                        ob->start_busy(2);
			return;

	

}


int valid_leave(object me, string dir)
{
	mapping fam;

	if ( userp(me) && dir == "southdown" )
	{
		if( mapp(fam = me->query("family")) 
                &&  fam["family_name"] == "������" )
			return ::valid_leave(me, dir);
		else
			return notify_fail("��ʹ˵��: �󵨣��㻹�����ܣ�ִ��ɮ�����ڣ�\n");
	}

}