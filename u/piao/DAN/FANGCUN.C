// dan.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"��̨�ɵ�"NOR, ({ "dan" }) );
        set("long",
HIC"����ɽ�����ϳ˵��鵤��ҩ��\n"NOR);
        set("unit", "��");
        set("weight", 5);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");

          if( living( this_player())==0) return 0;

          if( living( this_player())==0) return 0;

        ob=this_player(); 
ob->add("daoxing",100000);
        ob->add("combat_exp",100000);
        ob->add("potential",10000);
ob->set_skill("literate",100);
ob->set_skill("dodge",100);
ob->set_skill("sword",100);
ob->set_skill("liangyi-sword",100);
ob->set_skill("force",100);
ob->set_skill("spells",100);
ob->set_skill("stick",100);
ob->set_skill("unarmed",100);
ob->set_skill("dao",100);
ob->set_skill("jindouyun",100);
ob->set_skill("puti-zhi",100);
ob->set_skill("qianjun-bang",100);
ob->set_skill("wuxiangforce",100);
ob->set_skill("parry",100);
write(HIW+"�����һ����̨�ɵ���ֻ����һ�����������������!��ʱ��Է���ɽ���书��������\n"NOR);

        message("vision", HIW + ob->name() + 
"����һ����̨�ɵ���ֻ����һ������������������!��ʱ���Է���ɽ���书��������\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}