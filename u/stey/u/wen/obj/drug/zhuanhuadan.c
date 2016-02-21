#include <ansi.h>

inherit ITEM;

int do_eat(string);
void create()
{
  set_name(HIB "特大转化丹" NOR, ({"bishui dan", "dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "蓝蓝的一颗转化丹。\n");
	set("value", 20000000);  
    set("value", 20000000);
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
    return notify_fail("你要吃什么？\n");

	
if ((int)me->query("potential") < 100000)  
 return notify_fail("你的你的装态现在没法吃转化丹\n");

	else {
 
  	message_vision(HIB"$N吃下一颗特大转化丹，脸色大变，但觉体内发生了莫名的变化。\n"NOR, me);  
  
	me->add("bellicosity", -random( (int)me->query_kar() * 10));
	if ((int)me->query("bellicosity") < 0 ) me->set("bellicosity", 0);
	me->add("potential", -100000);
    me->add("combat_exp",100000);

}
  destruct(this_object());
  return 1;
}
