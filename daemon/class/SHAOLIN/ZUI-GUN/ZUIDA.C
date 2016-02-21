// zuida.c �������� [��������]

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void remove_effect(object me, int amount, int amount1);

int perform(object me, object target)
{
	object weapon;	
  	string msg;
	int count, count1, cnt, skill;
	
	if( !me->is_fighting() )
            return notify_fail("��"HIB"��������"NOR"��ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "stick")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_temp("zuida") ) 
		return notify_fail(HIY"���Ѿ����˹����ˡ�\n"NOR);

	if( (int)me->query_temp("powerup"))
		return notify_fail(HIG"���Ѿ������ڹ������ˣ�û�и��������ʹ�ð�������\n"NOR);

	if( (int)me->query_str() < 25 )
		return notify_fail("��ı���������Ŀǰ����ʹ�ô˾���! \n");

	if( (int)me->query_skill("yijinjing", 1) < 60)
                return notify_fail("����׽��������������ʹ�ô��������\n");

	if( (int)me->query_skill("stick") < 90)
		return notify_fail("��Ĺ�����Ϊ����������ʹ�ô������! \n");

	if( (int)me->query("force") < 500 )
		return notify_fail("����������㣡\n");

	
	
        message_vision(HIY"\n$Nʹ�����������ľ������������򡹣�������Ȼ����, ������Ȼ�ӿ죡\n"NOR,me);
	skill = me->query_skill("zui-gun",1);
	count = me->query("str") * random(cnt + 2);
	count1 = me->query("dex") * random(cnt + 2);

	me->add_temp("str", count);
	me->add_temp("dex", count1);
	me->set_temp("zuida", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count, count1 :), skill /3 );

	me->add("force", -150);
   	return 1;
}

void remove_effect(object me, int amount, int amount1)
{
	
	if ( (int)me->query_temp("zuida", 1) ) 
	{
		me->add_temp("str", -amount);
		me->add_temp("dex", -amount1);
		me->delete_temp("zuida");
		tell_object(me, HIY "��İ��������˹���ϣ��������ջص��\n" NOR);
		me->start_busy(4);
	}
}