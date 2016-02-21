#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
       object weapon;
            int extra;        
	if( !target ) target = offensive_target(me);
       if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
       return notify_fail("你要对谁施展这一招双重极限？\n");
       if(!me->is_fighting())
       return notify_fail("双重极限只能在战斗中使用！\n");
	if(me->query("family/family_name")!="剑客联盟")
       return notify_fail("“双重极限”只有剑客联盟弟子才可以使用！\n");
       if((int)me->query("force") < 800 )
       return notify_fail("你的内力不够！\n");
       if((int)me->query_skill("kongshoudao", 1) < 100)
       return notify_fail("你的空手道级别还不够，使用这一招会有困难！\n");
	me->delete("env/brief_message");
	extra = me->query_skill("kongshoudao",1);
	message_vision(HIY "\n$N突然大喝一声，右拳挟风雷之势向$n的胸口击来。\n"NOR, me,target);
	me->add_temp("apply/attack", extra);	
	COMBAT_D->do_attack(me, target);
	me->add_temp("apply/attack", -extra);
            if((int)me->query_skill("kongshoudao",1)>=200 && random(me->query("str"))>random(target->query("str")))
            {
            message_vision(HIR "\n就在$n以为$N拳力不继之时，$N的右拳忽然再往前急速击出。
这一招，正是精妙无双的[双重极限]。\n"NOR,me,target);
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);	
	COMBAT_D->do_attack(me, target);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
            }
	me->start_busy(2+random(1));
	return 1;
}
