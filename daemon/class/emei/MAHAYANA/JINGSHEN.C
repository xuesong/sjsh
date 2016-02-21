// thunder.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 120;
	damage_adj = 120;


	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��ڤ���\n");

	if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("���޷����о�����\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 50 ) {
                write("�����ڤ���̫����û�и���������κ��˺���\n");
		return 1;
	}

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"shen", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
HIB "\n$N���һ������Ȼ��أ��������ֳ���һ����ڤ�������$n��\n" NOR,
			//initial message
HIR "\nֻ�����ۡ���һ��$nͻ��һ����Ѫ��$n���յ����������\n" NOR, 
			//success message
HIB "$n����˵����ڤ��������������һ�����㿪�ˡ�\n" NOR, 
			//fail message
HIB "�����ڤ���$n�Է������ƣ���$N�����ˣ�\n" NOR, 
			//backfire initial message
HIR "\nֻ�����ۡ���һ��$nͻ��һ����Ѫ��$n���յ����������\n" NOR, 
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}
