inherit SSERVER;
#include <ansi.h>


int cast(object me)
{
        int howlong;
        int spell,tt;
        spell=me->query_skill("spells")/2 + me->query_skill("mahayana");
        if(spell < 100)
                return notify_fail("你还没有掌握峨嵋的重生力量。\n");

        if (me->query_temp("no_heal_up/yinshen"))
                return notify_fail("你已经在运用重生了!\n");
         if(me->query("family/family_name") != "峨嵋派" )
                return notify_fail("你不是峨嵋派弟子，无法领悟重生的力量！\n");
        if ( ((tt=(int)me->query_temp("lastyinshen")) <= time()) && 
             (tt+20 > time()))
                return notify_fail("你刚刚使用过重生力量，还是先休息一下吧!\n");

        if( (int)me->query("mana") < 2*(int)me->query_skill("spells"))
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("sen") < 50 )
                return notify_fail("你的精神无法集中！\n");

        message_vision("$N默默地念道：三元合一，重生在于自己。。。\n", me);

        if( random(me->query("max_mana")) < 200 ) {
                me->add("mana",-(int)me->query_skill("spells"));
                me->receive_damage("sen",10);
                message("vision", "但是在你身上没有发生任何变化。\n", environment(me));
                return 5+random(5);
        }

        me->add("mana", -2*(int)me->query_skill("spells"));
        me->receive_damage("sen", 20);

        howlong = 15 + random((me->query_skill("spells") -100));
                call_out("free", howlong, me, howlong);

        me->set("env/invisibility", 1);
        me->set_temp("no_heal_up/yinshen",1);
        
        message_vision(HIB"\n一声“浩然天地！正气长存！”之后，$N进入了二度空间，在你眼前消失了。\n\n"NOR, me);
        
        return 5+random(5);
}

void free(object user, int howlong)
{
        if(!user) return;
        user->delete_temp("no_heal_up/yinshen");
        if (!user->query("env/invisibility")) return;
        user->delete("env/invisibility");      
        user->save();
        message_vision(HIB"\n一道蓝光闪过，$N出现在了你的眼前。\n\n"NOR, user);
        user->set_temp("lastyinshen",time());
        return;
}

