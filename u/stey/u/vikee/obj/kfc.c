#include <ansi.h>
inherit ITEM;

int do_eat(string);
void create()
{
  set_name(HIR "�ϵ»�" NOR, ({"KFC"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ��������Ŀϵ»�,�����м�����ɫ�ļ���,һ�������ȵ�..�����˴��Ѱ�!\n");
    set("value", 5000);
    set("no_sell", 1);
  }
  
  setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
    
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");

        message_vision(HIR"һҶ֪�������̵����˹���,��$N˵:�ý��,�����ҵ�����,����?\nһҶ֪��������߿���.��һ��û��ס,�������������ĵ�����.\n"NOR, me);  
        message_vision(HIG"$N����һҶ֪���Ϳϵ»�,���ип���ǧ,��֪��˵ʲô��...һ���Ӱ�һҶ֪��§�ڻ���������....\n"NOR,me);   

  destruct(this_object());
  return 1;
}
