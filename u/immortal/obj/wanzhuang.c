// lianyi.c 连衣晚装
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIM"连衣晚装"NOR, ({"lianyi wanzhuang","wanzhuang", "cloth"}));
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", HIM"一件出席盛大宴会穿的连衣长裙，\n露背低胸，裙脚到地，华光锦衣，光彩夺目。\n谁穿上去，一定美艳动人，艳压群芳。\n"NOR);
                set("material", "cloth");
                set("value", 10000);
                set("armor_prop/armor", 255);
                set("armor_prop/spells", 255);
		set("armor_prop/dodge", 255);
        }
        setup();
}
