// shenpao.c
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("三界神袍", ({"sanjie shenpao", "cloth","pao"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件神袍,它是三重天神专用的。\n");
    set("material", "cloth");
    set("unit", "件");
    set("value", 0);
    set("armor_prop/armor", 45);
   set("armor_prop/dodge", 25);
    set("armor_prop/spells", 10);
    set ("armor_prop/force", 45);
    set("armor_prop/parry", 30);
  }
  setup();
}
