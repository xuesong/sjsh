// 龙珠 by Calvin

# include <skill.h>
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY "黄龙珠" NOR, ({ "huang longzhu","zhu" }));
	set_weight(1);
	if( clonep() )
        set("long", "这是一个漂亮的小石头球,上面刻着|☆☆☆☆☆|,据说当把收集到的七颗龙珠放在一起时会出现 ...\n" );
        if( clonep() )
    		set_default_object(__FILE__);
  	else {
		set("no_sell",1);
		set("value",0);
		set("unit","颗");
	}
	setup();
}
void init()
{

  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
	add_action("do_combine","combine");
}
void destruct_me(object where, object me)
{
	object pearl;
        if( pearl=new("/d/npc/obj/jingshi"))
        	pearl->move(where);
	message_vision("$N手中的$n突炸裂开来，一道霞光过后便失去了颜色。\n",where,me);
	destruct(me);
}
int do_combine()
{
	object me,a,b,c,d,e,f,g,real;
	me=this_player();
	a=this_object();

	if( (int)me->query("force") < 2000)
                return notify_fail("你的内力不足，很难发挥龙珠的威力。\n");
	if( (int)me->query("mana") < 2000)
                return notify_fail("你的法力不足，不能洞悉龙珠的动向。\n");

         if ( !(b=present("liang longzhu",me)))
                return notify_fail("你将手中龙珠摆弄了几下，却一无所获，大概还没有收集够。\n");
         if ( !(b=present("fen longzhu",me)))
                return notify_fail("你将手中龙珠摆弄了几下，却一无所获，大概还没有收集够。\n");
         if ( !(b=present("bai longzhu",me)))
                return notify_fail("你将手中龙珠摆弄了几下，却一无所获，大概还没有收集够。\n");
         if ( !(b=present("lan longzhu",me)))
                return notify_fail("你将手中龙珠摆弄了几下，却一无所获，大概还没有收集够。\n");
         if ( !(b=present("qing longzhu",me)))
                return notify_fail("你将手中龙珠摆弄了几下，却一无所获，大概还没有收集够。\n");
         if ( !(b=present("hong longzhu",me)))
                return notify_fail("你将手中龙珠摆弄了几下，却一无所获，大概还没有收集够。\n");

        if( real=new("/d/longzhu/npc/long")){
		destruct(b);
                destruct(c);
                destruct(d);
                destruct(e);
                destruct(f);
                destruct(g);
	real->move(me);
        message_vision(HIW"$N"HIY"将手中"HIG"龙珠"HIY"按天罡之阵摆好，只见七颗"HIG"龙珠"HIY"光芒四射,随之出现了一只硕大无比的"HIW"祥龙"HIY",而"HIG"龙珠"HIY"也随之分飞各处。\n"NOR,me);
	destruct(a);
	}
	return 1;
}


