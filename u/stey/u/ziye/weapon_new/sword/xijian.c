// thin_sword.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("ϸ��", ({ "xi jian", "jian", "sword" }) );
	set_weight(1400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 700);
              set("keenness", 5);
		set("material", "steel");
		set("long", "����һ����ϸ�ֳ��Ľ�����ƮƮ������Ů���Ӽҵ����⡣\n");
		set("wield_msg", "$N���һ�ѽ���ϸ���Ľ����������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
		set("weapon_prop/courage", -4);
	}
	init_sword(16);
	setup();
}