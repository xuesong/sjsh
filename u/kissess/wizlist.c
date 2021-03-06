// wizlist.c

#include <ansi.h>

inherit F_CLEAN_UP;

mapping lists = ([
        "(admin)"      : HIW"【系统管理】："NOR,
        "(arch)"       : HIR"【程序开发】："NOR,
        "(wizard)"     : HIY"【站点维护】："NOR,
        "(apprentice)" : HIG"【见习管理】："NOR,
        "(immortal)"   : HIM"【客座巫师】："NOR,
        "(elder)"      : HIB"【荣誉玩家】〖  eld  〗："NOR,
]);
int level(mixed, mixed);

int main(object me, string arg)
{
        string *list, hood = "", str;
        int j = 0;
        list = sort_array(SECURITY_D->query_wizlist(), (: level :) );
str = HIR"三界神话"HIG"泉州师院总站 "HIR"★ "+HIY"巫师全家福 "HIR"★"NOR+CYN" ：\n";
        str += "────────────────────────────\n";
        for(int i=0; i<sizeof(list); i++, j++) {
                if (hood != wizhood(list[i]) ) {
                        hood = wizhood(list[i]);
                        if (j%7) str += "\n";
                        str += lists[hood] ;
                        j = 0;
                }
 
 if (list[i]!="kissess" && list[i]!="chm"&& list[i]!="peaceful") str +=sprintf("%s%s",capitalize(list[i]),
                        ( j%7==6 ) ? "\n" : ( i<sizeof(list)-1 && hood ==wizhood(list[i+1]) ) ? ", " : ""  );
        }
str += CYN"\n────────────────────────────\n"NOR;
  str += "目前共有" +HIW+ chinese_number(sizeof(list)-2) +NOR+ "位巫师。\n\n";
        me->start_more(str);
        return 1;
}
int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob1) - wiz_level(ob2);
        return ob1 < ob2?-1:1;
}
int help(object me)
{
        write("\n指令格式 : wizlist\n"
        "用途 : 列出目前所有的巫师名单。\n"
        );
        return 1;
}
