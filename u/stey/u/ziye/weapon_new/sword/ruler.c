//add keenness by ziye 2001/3

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("���", ({ "ruler" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�Ѻ�����Ľ�ߣ�\n");
                set("value", 80);
                set("material", "wood");
              set("keenness", 5);
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        init_sword(10);
        setup();
}
