
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
	int success_adj, damage_adj;
	success_adj = 100;
	damage_adj = 100;
	if( !target ) target = offensive_target(me);
	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ��˭ʩչ��ڤ��𽣣�\n");
	if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
		return notify_fail("��ķ���������\n");
	if((int)me->query("sen") < 100 )
		return notify_fail("���޷����о�����\n");
	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);
	if( random(me->query("max_mana")) < 50 ) {
		write("��ڤ��𽣲�֪����ȥ�ˡ�\n");
		return 1; }
SPELL_D->attacking_cast( me, target, success_adj, 	damage_adj, 	"qi", 		
HIB "\n$N���һ������Ȼ��أ��������ֳ���һ����ڤ��𽣣�˲�仯��һ���������������$n��\n" NOR,
HIR "\nֻ�����ۡ���һ��$nͻ��һ����Ѫ�����⴫͸��$n�����壡\n" NOR, 
HIB "$n����ǰ�������ȫ��������ס����ڤ��𽣣������ϵ��������ơ�\n" NOR, 
HIB "�������ⱻ$n�Է������ƣ���ת������$N��ȥ��\n" NOR, 
HIR "\nֻ�����ۡ���һ��$nͻ��һ����Ѫ�����⴫͸��$n�����壡\n" NOR, 
	);
	me->start_busy(2+random(2));
	return 3+random(5); }
