// feilong.c, created 17-06-2001 ����Ʈ(piao)


#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
  set_name(WHT "����ǹ" NOR, ({ "feilong spear","qiang","spear" ,"feilong" }));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 54000);
    set("material", "steel");
    set("long", "һ������ȫ���������ɳ�ǹ���������һ�����������������˵���������ǹ����\n");
    set("wield_msg", "$N������һ��$n����Ȼ�������ݡ�\n");
    set("unwield_msg", "$N����$n����˳������һ������̵ķ�����\n");
  }
  init_spear(160);
  setup();
}
