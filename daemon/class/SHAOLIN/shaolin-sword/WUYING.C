//��ȥ������ wuying.c
// write by piao 2001-10-04

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
void wuying_ok(object); 
inherit SSERVER; 

void remove_effect(object me, int a_amount, int d_amount);

int perform(object me, object target)
{
        object weapon,ob;
        string str;
        int skill;
	int extra;
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��"HIW"������Ӱ"NOR"��ֻ����ս����ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
              return notify_fail(" ��ʹ�õ��������ԣ��޷�ʩչ��"HIW"������Ӱ"NOR"����\n");
        if((int)me->query("sen") < 800 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if( (int)me->query_skill("shaolin-sword", 1) < 150 )
                return notify_fail("���������Ӱ��������죬�޷�ʩչ��"HIW"������Ӱ"NOR"����\n");
        if( (int)me->query_skill("shaolin-shenfa", 1) < 150 )
                return notify_fail("�����������������죬�޷�ʩչ��"HIW"������Ӱ"NOR"����\n");
        if( (int)me->query_skill("yijinjing", 1) < 150 )
                return notify_fail("����׽������죬�޷�ʩչ��"HIW"������Ӱ"NOR"����\n");
        if( (int)me->query("force") < 800  ) 
                return notify_fail("�������������\n");
        if( (int)me->query("max_force") < 2500  ) 
                return notify_fail("����������㣬�޷�ʩչ��"HIW"������Ӱ"NOR"����\n");
        if((int)me->query("combat_exp") < 1000000 )
                return notify_fail("����ѧ���鲻�������򲻵���"HIW"������Ӱ"NOR"����\n");
//-------------------------------------------------------------------
        skill = me->query_skill("shaolin-sword");
	extra = me->query_skill("shaolin-sword",1) / 10;
	extra += me->query_skill("shaolin-sword",1) /10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

        msg = HIC "\n$N����ͻ�䣬һ��"HIW"��������Ӱ��"HIC"˲������ֳ�������Ӱ��������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);
        me->set_temp("QJB_perform", 5); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("QJB_perform", 6); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("QJB_perform", 7); 
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

message_vision(HIW"              ��������  ��������  ��������  ��������  ��������\n"NOR,me,target); 
message_vision(HIW"              �� "HIR"��"HIW" ��  �� "HIY"ȥ"HIW" ��  �� "HIG"��"HIW" ��  �� "HIB"��"HIW" ��  �� "HIM"��"HIW" ��\n"NOR,me,target); 
message_vision(HIW"              ��������  ��������  ��������  ��������  ��������\n"NOR,me,target); 
        me->set_temp("DLB_perform", 8);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 9);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

//--------------------------------------------------------------
        if( (int)me->query_skill("shaolin-sword", 1) > 159 ){
message_vision(HIR"      ���־���\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("shaolin-sword", 1) > 169 ){
message_vision(HIY"            ȥ�־���\n"NOR,me,target); 
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("shaolin-sword", 1) > 179 ){
message_vision(HIG"                 ���־���\n"NOR,me,target); 
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("shaolin-sword", 1) > 189 ){
message_vision(HIB"                        ���־���\n"NOR,me,target); 
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("shaolin-sword", 1) > 199 ){
message_vision(HIM"                           ���־���\n"NOR,me,target); 
       
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
//-------------------------------------------------------------------
                     if (target->query("eff_kee")<0 || !living(target))
{str=target->name()+"��"+""HIW""+me->name()+""HIM""+"�������µľ��С�"HIW"������Ӱ"HIM"��ɱ���ˡ���˵ʬ����ǧ���ٿף�";
        message("channel:rumor",HIM"��"HIW"��Ѩ����"HIM"��ĳ�ˣ�"+str+"\n"NOR,users());
	               }
        me->start_busy(3);
         me->add("force", -150);
//        me->set_temp("no_wuying",1);
        me->receive_damage("sen", 50+random(50));
        call_out("wuying_ok",10+random(10),me); 
        me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);

        return 1;
}
void wuying_ok(object me)
{ if (!me) return; 
      me->delete_temp("no_wuying"); 
}          
