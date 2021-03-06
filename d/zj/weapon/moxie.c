// 莫邪剑 by Calvin

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name(HIW"莫邪剑"NOR,({ "moxie sword", "moxie", "sword", "jian" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100);
                set("rigidity", 10);
                set("sharpness", 10);
                set("unique", 1);
                set("material", "steel");
                set("weapon_prop/dodge", 10);
                set("weapon_prop/parry", 10);
                set("treasure",1);              
                set("no_sell",1);              
                set("long", "这是一柄四尺来长,全身乌黑的天地间自然形成的神剑。\n"); 
                set("wield_msg", "刹那间，一道气壮山河的黑虹，宛似天际忽起的闪电一般，在尚不及眨眼的微小空隙，出现在众人眼前！\n");
                set("unwield_msg", "\n但见$N将$n向天一直，数匹布条随风而起，将$n严严实实地裹了起来！\n");
        }
        init_sword(100);
        setup();
}

int wield()
{
        object ob = environment();
        object me = this_object();
        mapping weapon_prop;
        object *obj, *inv, weapon;
        int ret, i, j;
        if (ob->query("combat_exp") < 100000 
            || ob->query_str() < 20 || ob->query("max_force") < 1000 
            || ob->query("force") < 1000){
                message_vision(HIY"$N的手刚刚触摸到$n的剑把，突然一股由天而生的力量自剑中穿来，将$N击出丈远！$n也随之掉落地上。\n"NOR, ob, me);
                ob->receive_damage("qi", 100);
                ob->receive_wound("qi", 100);
                me->move(environment(ob));
                return 0;
                }
       else if (ret=::wield()){
           message_vision(HIB"\n只见$N将一裹在帆布里的长剑缓缓抽出，乌黑的剑身带出来的却是王霸的气势！\n\n"NOR, ob, me);
           ob->add("force", -200);
           obj = all_inventory(environment(ob));
           if(sizeof(obj) > 1)
               message_vision(HIY"忽然，众人身上所带之剑纷纷自动跃出，插在$N身前的地上，剑尖指天！\n"NOR, ob);
           for(i=0; i<sizeof(obj); i++) {
                if(obj[i]==ob ) continue;
                inv = all_inventory(obj[i]);
                for(j= 0;j< sizeof(inv);j++){
                       if(!mapp(weapon_prop = inv[j]->query("weapon_prop"))) continue;        
                       if(inv[j]->query("skill_type")!="sword") continue;
                       if(inv[j]->query("equipped")){
                          if(obj[i]->query("force") > 1000){
                             obj[i]->add("force", -100);
                             tell_object(obj[i], HIW"你觉得手中之"+inv[j]->name()+HIW"在猛烈震动，幸而你双手紧握，才没有让它飞出！\n"NOR);
                             continue;  
                             }
                           else {
                                tell_object(obj[i], HIW"你觉得手中之"+inv[j]->name()+HIW"在猛烈震动，你把握不住，竟然脱手飞出！\n"NOR);
                                tell_room(environment(ob), YEL+obj[i]->name()+"一个把握不住，手中"+inv[j]->name()+YEL"竟然脱手飞出！\n"NOR,({ obj[i] }));
                                }
                           }
                       inv[j]->move(environment(ob));
                       }
           }
           return ret;
       }
}
