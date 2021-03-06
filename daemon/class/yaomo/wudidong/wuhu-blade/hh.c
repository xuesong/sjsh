
//hh.c   wosshipg
#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int calculate_damage(object me, object target, int base_damage, int damge_bonus);
int perform(object me, object target)
{
	string msg, str;
	int mydf;
	int ap, dp, pp;
	int youcps, mycor, mystr, youstr;
	int damage_bonus, damage, wound;
	int delay;
	object ob;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                  return notify_fail("不在战斗中，怎么用pfm？\n");

mydf=(int)me->query_skill("wuhu-blade",1);
if(mydf<100) 
                return notify_fail("你的修为不够深，还不能领会五虎断门刀的精髓。\n");
                  if(me->query("family/family_name")!="陷空山无底洞")
                  return notify_fail("你不是无底洞的弟子，不能用此招！\n");

          mydf=(int)me->query_skill("huntian-qigong",1);
          if(mydf<100) 
                  return notify_fail("你的修为不够深，还不能领悟五虎断门刀的精髓。\n");
 if(environment(me)!=environment(target))
     notify_fail("你要攻击的人不在这里。\n");
	if((int)me->query("force")<500) return
	    notify_fail("你的内力不够了。\n");

            msg = HIR "$N使出一招--饿虎扑食,无比伶俐,眨眼间挥出数刀，斩向$n的左肩，\n";
	mycor=me->query_cor();
	youcps=target->query_cps();
	ob=target->query_temp("weapon");
          str="左肩";
	if(objectp(ob)) str="手中的"+ob->query("name");
	ap=COMBAT_D->skill_power(me, "unarmed", SKILL_USAGE_ATTACK);
	dp=COMBAT_D->skill_power(target,"dodge", SKILL_USAGE_DEFENSE);
	dp/=2;	
	pp=COMBAT_D->skill_power(target,"unarmed", SKILL_USAGE_DEFENSE);
	pp/=2;
	if(objectp(ob)) pp/=2;
	mystr=me->query_str();
	youstr=me->query_str();
	damage_bonus=mystr*(100+me->query("force_factor"))/100;

        if( random(youcps) < 10 || random(ap+dp)>dp) {
                  msg += "$n想用"+str+"挡开，不料却被$N拿刀挡开。\n";
                  msg += "$N趁势冲出，使出了「五虎灭」！\n\n" NOR;
                  msg += HIR "$N手中的兵器猛然斩向$n头顶，这一招也有一个响亮的名字,是五虎断门刀中的精髓,叫做:**虎跳峡**";
		if(random(ap+pp)>pp) {
                          msg += "结果呲的一声砍在$n的肩膀上。\n" NOR;
			damage=calculate_damage(me, target, 100, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("kee", damage, me);
				if(wound>0) target->receive_wound("kee", wound, me);
                                  msg+=COMBAT_D->damage_msg(damage, "严重的伤势");
			}
		}
                  else msg+="结果被$n搁挡开了。\n" NOR;
                   msg += HIR "\n紧跟着$N收兵器，提刀砍向$n，大叫一声:惟我独尊!正是五虎断门刀中的虎入群羊!凶狠无比,精妙绝伦.\n";
                  msg += "同时撞向$n.";
		if(random(ap+pp)>pp) {
			msg += "结果正中$n。\n" NOR;
			damage=calculate_damage(me, target, 120, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("kee", damage, me);
				if(wound>0) target->receive_wound("kee", wound, me);
				msg+=COMBAT_D->damage_msg(damage, "内伤");
			}
		}
		else msg+="结果被$n挡开了。\n" NOR;
                    msg += CYN "\n$N接着顺势又出一刀,朝着$n右臂砍来，犹如天神下凡,威力无比.原来这是五虎断门刀中的**虎啸声风**,结果正好砍中$n,$N捂住肩膀痛苦万分，";
		if(random(ap+pp)>pp) {
                          msg += "结果$n一跟头摔在地上。\n" NOR;
                        damage=calculate_damage(me, target, 150, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
                        if(damage>0) {
                                target->receive_damage("kee", damage, me);
				if(wound>0) target->receive_wound("kee", wound, me);
                  msg+=COMBAT_D->damage_msg(damage, "伤口");
                        }
                }
                else msg+="结果被$n一个踉跄，却没摔倒。\n" NOR;
		message_vision(msg, me, target);
		msg+=COMBAT_D->report_status(target, 0);
	} else {
		msg += "可是$p看破了$P的企图，向后越开。\n" NOR;
		message_vision(msg, me, target);
	}
  delay = random(3);
	me->start_busy(delay);
    me->add("force", -100);

	return 1;
}

int calculate_damage(object me, object target, int base_damage, int damage_bonus)
{
	int damage;
	int myexp, youexp;

	damage=base_damage+(damage_bonus+random(damage_bonus))/2;
	myexp=me->query("combat_exp");
	youexp=target->query("combat_exp");
	if(random(youexp)>myexp) {
		damage-=damage/3;
		youexp/=2;
	}
	if (wizardp(me) && me->query("env/combat")=="verbose")
		tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));

	return damage;
}

