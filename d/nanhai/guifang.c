
inherit ROOM;
#include <ansi.h>;
void create()
{
        set("short", "闺房");
        set("long", @LONG

这里是水母娘娘的闺房，一进门就闻到一阵悠悠的香气，只见房中点了一
支大红烛，照的满室生春，床上珠罗纱的帐子，白色缎被上绣着一只黄色
的凤凰，壁上挂着一幅工笔仕女图。西首一张几上供着一盆兰花，架子上
停着一只白鹦鹉。靠窗处有个梳妆台(tai)，墙上挂着一口宝剑(sword)，
蛇皮吞口，看来很是锋利。
LONG );
        set("exits", ([ /* sizeof() == 1 */
             "east" : __DIR__"door",
             "west" : __DIR__"huayuan",
        ]));
        set("objects", ([
  "/d/nanhai/npc/shuimu" : 1,
  "/d/nanhai/npc/yahuan" : 1,
        ]));
        set("item_desc", ([
                "sword"  : "这是水母娘娘惯用的水月宝剑。\n",
                "tai"    : "这是一张红漆梳妆台，半开的抽屉斜插着几朵鲜花。\n"
        ]));
//        set("no_clean_up", 0);

        setup();
}
void init()
{
 //       add_action("do_move", "push");
//        add_action("do_move", "move");
        add_action("do_pick", "pick");
        add_action("do_pick", "zhai");
}
 /*
int do_move(string arg)
{
        object paper, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="tai" )
        {
                if ((me->query("family/master_id") !="shuimu niangniang") &&
                        objectp(present("shuimu niangniang", environment(me))))
                {
                        return notify_fail(
"水母娘娘喝道：这位" + RANK_D->query_respect(me) + "，你不能随便翻人家东西。\n");
                        return 1;
                }
                if (!query("had_book"))
                {
                        message_vision(
"$N轻轻的拉开抽屉，发现里面有一本书……\n", this_player());
                        paper = new("/d/obj/book/halberd2");
                        paper->move(this_player());
                        set("had_book", 1);
                        return 1;
                }
                message_vision(
"$N轻轻的拉开抽屉，可是里面啥都没有……\n", this_player());
                return 1;
        }
        return 0;
}
   */
int do_pick(string arg)
{
        object sword, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="sword" )
        {
                if (objectp(present("shuimu niangniang", environment(me))))
                {
                        return notify_fail(
"水母娘娘喝道：这位" + RANK_D->query_respect(me) + "，你怎么能随便拿人家东西呢？\n");
                        return 1;
                }
                if (!query("had_sword"))
                {
  if ("/d/obj/weapon/sword/wsword"->in_mud()){
                message_vision(
"$N伸手去摘宝剑，才发现只剩剑鞘了，宝剑早就被别人取走了……\n", this_player());
                        return 1;
                     }
                        message_vision(
"$N轻轻的摘下宝剑，哈哈，真开心……\n", this_player());
                        sword = new("d/obj/weapon/sword/wsword");
                        sword->move(me);
                        set("had_sword", 1);
                        return 1;
                }
                message_vision(
"$N伸手去摘宝剑，才发现只剩剑鞘了，宝剑早就被别人取走了……\n", this_player());
                return 1;
        }
        return 0;
}

