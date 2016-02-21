// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

#include "message.h"

void create()
{
  set_name(HIM "ӣ��" NOR, ({ "ying hua", "sakura"}));
  set_weight(100);
  set("long","һ��ۺ��ӣ����ɢ����һ˿˿���㡣\n");
  set("unit", "��");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 3);
  set("material", "flower");
    set("value",50000);
  setup();
}

int init ()
{
  add_action ("do_wear", "wear");
  add_action ("do_remove", "remove");
  add_action ("do_smell", "smell");
  add_action ("do_smell", "wen");
  return 1;
}

int do_wear (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "rose" &&  arg != "flower" )
    return 0;
  msg = "$N����һ��"+name+"��������������ʱ�����������ˡ�\n"; 
  flower->set("wear_msg",msg);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower" && arg != "rose")
    return 0;

  msg = "$N��"+name+"�����ժ��������\n"; 
  flower->set("unequip_msg",msg);
  return 0;
}

int do_smell (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "flower" && arg!= "rose")
    return 0;

  msg = "$N��"+name+"���������ţ��ֵ��������Ĺ��ˡ�\n"; 
  message_vision (msg,me);
  return 1;
}