
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
		return notify_fail("你要对谁施展南冥离火剑？\n");
	if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");
	if((int)me->query("sen") < 100 )
		return notify_fail("你无法集中精力！\n");
	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);
	if( random(me->query("max_mana")) < 50 ) {
		write("南冥离火剑不知道哪去了。\n");
		return 1; }
SPELL_D->attacking_cast( me, target, success_adj, 	damage_adj, 	"qi", 		
HIB "\n$N大喝一声「浩然天地！」，右手出现一把南冥离火剑，瞬间化作一道蓝光闪电般劈向$n！\n" NOR,
HIR "\n只见「噗」地一声$n突出一口鲜血，蓝光传透了$n的身体！\n" NOR, 
HIB "$n见眼前不妙，运用全身法力挡住了南冥离火剑，但身上的衣衫尽破。\n" NOR, 
HIB "但是蓝光被$n以法力反逼，旋转方向朝着$N射去！\n" NOR, 
HIR "\n只见「噗」地一声$n突出一口鲜血，蓝光传透了$n的身体！\n" NOR, 
	);
	me->start_busy(2+random(2));
	return 3+random(5); }

