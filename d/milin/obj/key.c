// 密林宝库 白银钥匙 by Calvin

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIW"白银钥匙"NOR, ({ "yao shi","key" }));
  set_weight(1000);
  set("long", "这是一个白银制成的钥匙,样子很是别致。\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "把");
    set("no_sell", 1);
    set("material", "bone");
  }
  setup();
}
