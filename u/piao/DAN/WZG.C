// dan.c 升级丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"镇元伏虎丹"NOR, ({ "dan" }) );
        set("long",
HIY"无庄观中最上乘的灵丹妙药。\n"NOR);
        set("unit", "粒");
        set("weight", 5);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("你要吃什麽？\n");

          if( living( this_player())==0) return 0;

          if( living( this_player())==0) return 0;

        ob=this_player(); 
        ob->set_skill("force",50);
        ob->set_skill("spells",50);
        ob->set_skill("sword",50);
        ob->set_skill("parry",50);
        ob->set_skill("dodge",50);
        ob->set_skill("blade",50);
        ob->set_skill("staff",50);
        ob->set_skill("unarmed",50);
        ob->set_skill("literate",50);
        ob->set_skill("baguazhen",50);
        ob->set_skill("fumo-zhang",50);
        ob->set_skill("hammer",50);
        ob->set_skill("kaishan-chui",50);
        ob->set_skill("sanqing-jian",50);
        ob->set_skill("taiyi",50);
        ob->set_skill("wuxing-quan",50);
        ob->set_skill("yange-blade",50);
        ob->set_skill("zhenyuan-force",50);
write(HIY+"吃下一颗镇元伏虎丹，只觉得一种神力融入你的体内!顿时你对五庄观的武功有所大悟。\n"NOR);

        message("vision", HIY + ob->name() + 
"吃下一颗镇元伏虎丹，只觉得一种神力融入他的体内!顿时对他五庄观的武功有所大悟。\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
