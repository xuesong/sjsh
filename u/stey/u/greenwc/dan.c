// jinchuang.c 金创药

inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("跌打丸", ({"dieda wan", "wan", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("base_unit", "颗");
                set("unit", "些");
                set("long", "这是一颗治伤的跌打药。\n");
                set("value", 1500);
				set("drug_type", "良药");
        }
    set_amount(1);
        setup();
}

int do_eat(string arg)
{
object me = this_player();
int i = me->query_skill(arg,1);
me->set_skill(arg,i+1);
           add_amount(-1);
                return 1;
        }

