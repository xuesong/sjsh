// tianji.c ���ὣ��  �������� ����Ʈ(piao)
// writted by piao 2001-10-1
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill, str;
        int myskill, myskill1, tparryb, tparryh, myforce, tforce, myexp, texp, damage;
        object weapon,tweapon;
        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("sword",1);
          myskill1= (int)me->query_skill("tianji-sword",1);
        myforce = (int)me->query("force");
        myexp = (int)me->query("combat_exp");
        msg = "";
        if(!objectp(weapon)||(string)weapon->query("skill_type")!="sword")
        return notify_fail("���õ��������ԣ��޷�ʩչ���������ޡ���");
          if ( myskill1 < 150) return notify_fail("������ὣ����Ϊ��������ʹ����һ�л������ѣ�\n");
        if(me->query("family/family_name") != "������" )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á��������ޡ�?\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���������ޡ�ֻ����ս����ʹ�á�\n");
        if ((int)me->query("force")< 500)
                return notify_fail("�������������\n"); 
        tweapon = target->query_temp("weapon");  
        tparryb= (int)target->query_skill("parry",1);
        tforce = (int)target->query("force");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("force",-300);
        me->receive_damage("sen", 20);
     message_vision(HIM"$N�˽���һ���ų�����"+weapon->name()+HIM"����һ���ʺ磬��ʹ���˶���ɽ���ὣ��ѧ--��"HIW"����ɺ�"HIM"����\n\n" NOR,me,target);        
     message_vision(HIC"$N������������֮��׷����ס"+weapon->name()+HIC"��ֻ��������Ӱ������\n"NOR,me);
     message_vision(HIM"��Ӱ���Ųʺ�ֱ����������"HIW"����ɺ�"HIM"������������\n\n"NOR,me);
     if (random(myexp)>(int)(texp/10) && random(myforce) > (int)(tforce/3)) 
        {
             msg = HIR"$n���������񣬲ʺ��е�������Ӱ��Ȼֱ�£�\n"
                                "��ಡ���һ������$n�����ϴ��������Ѫ�����أ�\n\n"NOR;
	damage= (int)(((int)me->query("max_force")/2+myforce -  (int)target->query("max_force")/2 - tforce)/3);
 	if(damage<1)damage = 1;
 	target->receive_damage("kee", me->query("eff_kee")*damage/80, me);
 	target->receive_wound("kee", me->query("eff_sen")*damage/100, me);
     	message_vision(msg, me, target);
        COMBAT_D->report_status(target);

     	}
     else {
            msg = HIW"$n����һ�ۣ�֪������֮�а�������ɱ�����������������С�"HIM"����ɺ�"HIW"��\n\n"NOR;
            message_vision(msg, me, target);
        }


     message_vision(HIM"$N����ת����ԭ�����к��У�ת�ۼ���ɱ��һ����\n" NOR,me,target);
     message_vision(HIM"��һ�С�"HIW"��������"HIM"���ȸղ����и��죬����Ҫһ��������ն����ħ��\n\n" NOR,me,target);
     if(random(myexp)>(int)(texp/10)&& random((int)(myskill + myskill1*3/2))>(int)((tparryb+tparryh)/2))
     {msg = HIR"$n��û���м�ס�ղŵĹ��ƣ��Ϳ�ɱ��Ϯ������֪���룡\n"
        "��$N��"+weapon->name()+HIR"�̵ı������ˣ�ͻ��һ����Ѫ��\n\n"NOR;
     damage=random(100)+me->query("force_factor");
     if(damage<1)damage = 1;
     target->receive_damage("kee", me->query("eff_kee")*damage/80, me);
     target->receive_wound("kee", me->query("eff_sen")*damage/100, me);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
     else{
            msg = HIW"$n��Σ���ң�ʹ�������������ڻ�����$N�Ĺ��ơ�\n\n"NOR;
             message_vision(msg, me, target);
        }
          message_vision(HIM"$NͻȻ��ס���Σ��ز�����������ڱ�������ʤ���У�����ʤ���Ρ�\n"NOR,me);
          message_vision(HIM"��һ���������ὣ�ľ��������ڡ�"HIW"��������"HIM"����\n\n"NOR,me);
if(random(myexp)>(int)(texp/2))
{msg = HIR"$n��Ϊ$N�����ٳ�����ϲ֮�£���æ��ǰ��������\n"
"����֪$N����ɱ�����ޣ�$n��һ������ֻ������һ������$n�ؿڴ��������\n"
"$nû���뵽����֮�������������Щ����������\n\n"NOR;
damage=(int)(random((int)(myskill1/2))+me->query("force_factor")*3/2);
if(damage<1)damage = 1;
target->receive_damage("kee", me->query("eff_kee")*damage/80, me);
target->receive_wound("kee", me->query("eff_sen")*damage/100, me);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);

                     if (target->query("eff_kee")<0 || !living(target))  
{str=target->name()+"��"+""HIW""+me->name()+""HIM""+"�ö���ɽ�ľ��С�"HIW"��������"HIM"��ɱ���ˡ���˵����ʧ�����꣡";
        message("channel:rumor",HIM"��"HIW"��Ѩ����"HIM"��ĳ�ˣ�"+str+"\n"NOR,users());
                       }

     }
else{
         msg = HIW"$n���������е���ʵ�����ƾͼƣ���װ����ǰ��ȴ��$N������һ˲���ڿ�Ծ�������־�����һ�У�\n\n"NOR;
            message_vision(msg, me, target);
        COMBAT_D->do_attack(target, me, tweapon);

                     if (target->query("eff_kee")<0 || !living(target))  
{str=target->name()+"��"+""HIW""+me->name()+""HIM""+"�ö���ɽ�ľ��С�"HIW"��������"HIM"��ɱ���ˡ���˵����ʧ�����꣡";
        message("channel:rumor",HIM"��"HIW"��Ѩ����"HIM"��ĳ�ˣ�"+str+"\n"NOR,users());
	               }

        }
        
 me->start_busy(2);
        
     
        return 1;
}







