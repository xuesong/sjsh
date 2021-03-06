// force.c
// modi by xintai 3/10/2001

inherit SKILL;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage;

	me->add("force", - factor );
	// enforce 1和enforce 0之间的差距太大了，所以加上这个判断。
	damage = factor - random(victim->query("force_factor"));
	if (damage > 0) {
	damage += (int)me->query("force")/20 - (int)victim->query("force")/25;
	    }
	else 
	    {	
	    	damage +=  (int)me->query("force")/20 - (int)victim->query("force")/25;
	    	if (damage > 0) damage = 0;
	    	if( !me->query_temp("weapon")
		&&	random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
			damage = - damage-1;
			me->receive_damage( "kee", damage * 2 );
			me->receive_wound( "kee", damage );
			if( damage < 10 ) return "$N受到$n的内力反震，闷哼一声。\n";
			else if( damage < 20 ) return "$N被$n以内力反震，「嘿」地一声退了两步。\n";
			else if( damage < 40 ) return "$N被$n以内力一震，胸口有如受到一记重击，连退了五六步！\n";
			else return "$N被$n的内力一震，眼前一黑，身子向后飞出丈许！！\n";
		}
		if( damage_bonus + damage < 0 ) return - damage_bonus;
		return damage;
	}

	damage -= victim->query_temp("apply/armor_vs_force");
	if( damage_bonus + damage < 0 ) return - damage_bonus;
	if( random(me->query_skill("force")) < damage )
		return damage;
}
