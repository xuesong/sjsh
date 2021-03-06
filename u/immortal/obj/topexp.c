#include <ansi.h>
#include <mudlib.h>

inherit ITEM;
void create()
{
        set_name(HIW"武学排名榜"NOR,({"paiming board","board"}));
	set_weight(500000);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("value",0);
		set("unit","块");
                set("long","你可以用命令 exp 来查看帮派在线高手。");
	}
	setup();
}

void init()
{
        add_action("do_list","exp");
}

int top_list(object ob1,object ob2);

int get_score(object ob);

int do_list(object me, string arg)
{
        
        object *list,*ob;
        int i,ppl;
        string msg;
	me = this_player();
	ob = filter_array(objects(), (: userp($1) && !wizardp($1) :));
        list = sort_array(ob, (: top_list :));
        msg =  "\n            　　　┏ "+BCYN HIW+"各大帮派在线高手武学值"NOR" ┓\n";
	msg += "┏━━━━┯━━━┻━━━━━━━━┯━━━┻━━━┯━━━━┓\n";
        msg += "┃  名次　│      高        手      │　 帮    派　 │ 评  价 ┃\n";
        msg += "┠────┴────────────┴───────┴────┨\n";
        ppl=0;
        i = sizeof(list);

                while( i-- ) {
                     if( !environment(list[i]) ) continue;
                     if( !me->visible(list[i]) ) continue;
                     if( wiz_level(list[i]) ) continue;
                     if( !interactive(list[i])) continue;
                     ppl++;
                }
        for (i = 0 ;i < 30 ; i++) {
        if( i >= ppl ) msg += "┃　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　┃ \n";
                else {
                if(list[i] == me) msg += BBLU HIY;
                msg += sprintf("┃  "HIY"%-6s"NOR"│"HIG"%-12s"NOR"  "HIC"%-10s"NOR"│"BBLU""HIW"%-14s"NOR"│"HIM"%8d"NOR"┃\n"NOR,chinese_number(i+1),list[i]->query("name"),"["+
        capitalize(list[i]->query("id"))+"]", list[i]->query("club")?  list[i]->query("club"):"无帮派人士",
        get_score(list[i]));
                }
                         }
        msg += "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
        msg += "  " + NATURE_D->game_time() + "记。\n";
        write(msg);
        return 1;

}

int top_list(object ob1, object ob2)
{
      int score1,score2;

        score1 = get_score(ob1);
        score2 = get_score(ob2);

      return score2 - score1;
}

int get_score(object ob)
{
        int tlvl,i,score;
        string *ski;
        mapping skills;

        reset_eval_cost();
        skills = ob->query_skills();
        if (!sizeof(skills)) return 1; 
        ski  = keys(skills);
        for(i = 0; i<sizeof(ski); i++) {
                        tlvl += skills[ski[i]];
                        }  // count total skill levels
        score = tlvl/(i+1);
        score += ob->query("max_force")/10;
        score += ob->query("max_mana")/10;
        score += ob->query("str") + ob->query("int") + ob->query("spi") + ob->query("con");
        score += (int)ob->query("combat_exp")/5000;

        return score;
}
