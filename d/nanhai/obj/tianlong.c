// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

#include <weapon.h>

inherit F_UNIQUE;
//inherit HALBERD;

void create()
{
        set_name("天龙戟", ({ "tianlong ji", "halberd" ,"ji"}));
        set("long", @LONG
这是一块黑黝黝的铜牌，上面写着“王府令牌”四个小字。?
LONG);
        set("weight", 100);

        if(clonep())
        set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("value", 20);
     //set("replace_file", "/d/obj/weapon/halberd/huaji");
                //set("material", "blacksteel");
        }
       // init_halberd(90);
       // set("is_monitored",1);
        setup();
}

