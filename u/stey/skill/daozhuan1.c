#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob, where;
        int i, skill, damage, forcee;
        int kee_wound;

	where=environment(me);
	if( where->query("no_fight") )
		return notify_fail("安全区内不能引动九天灵气！\n");
        if( !me->is_fighting() )
                return notify_fail("倒转乾坤只能在战斗中使用。\n");
        if( me->query("family/family_name")!="三界山")
                return notify_fail("不是三界山的不能用「倒转乾坤」！\n");
        if( (int)me->query("force") < 800 )
                return notify_fail("你的内力不够。\n");
	if( (int)me->query("kee") < 200)
		return notify_fail("你的力气不够了。\n");
        if( (int)me->query_skill("huntianforce", 1) < 120 )
                return notify_fail("你的混天宝鉴修为还不够，使用这一招会有困难！\n");
                
        skill = me->query("force");
	forcee = target->query("force")-50;
        me->add("force", -400);
        me->receive_damage("kee", 150);

        me->start_busy(2);
	message_vision(HIR "\n$N飞身而上，屏气凝神，双手对天一指，引动出九天灵气归于己用！\n顿时天昏地暗，日月无光，天地颠倒！\n好一招灭绝众生的「倒转乾坤」！\n\n"
NOR, me);
        if( skill*2 +random(skill) > target->query("max_force"))
        {
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));


        kee_wound = me->query("eff_kee")/(2+random(5));
	me->receive_damage("kee", 50);
	target->add("kee", -kee_wound);	
	target->add("eff_kee", -(kee_wound));
	target->add("force",-(forcee));
	me->add("force", -100);
	message_vision(HIW"$n翻倒在地。受伤严重，全身内力顿失！\n"NOR,me, target);
	target->start_busy(3);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
         }
         }
         else 	message_vision(HIY"可是$p看破了$P的企图，并没有上当。\n" NOR, me, target);
         	       
        return 1;
}

