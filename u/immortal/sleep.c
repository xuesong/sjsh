#include <ansi.h>
inherit ROOM;
void create()
{
set ("short",HIW "睡 房" NOR);
set ("long",@LONG

           抱  得  美  人         入  梦  黄  梁

　　家庭始终是温暖的，神宫大仙和老婆终于经历万难走在一起，在月老下共
蒂良缘，她们家庭生活美满幸福，快快乐乐地在他们地在神宫大殿里生活着。
　　神宫大殿装修比较简朴，不过在他老婆的努力下，打理得干干净净，有条
不絮。阳光从窗外透过窗纱投射在神宫大殿的地面上，加上香炉寥寥轻烟，显
得分外格雅。小孩子的床用玄山灵石经过神宫大仙用七七四十九年精心雕琢，
上有龙凤图案，神宫大仙和小仙的心爱结晶肯定能在灵石的庇佑下茁壮成长。
孩床就放在左边主人房的旁边，为了孩子的安全，神宫大仙和老婆合用自己的
元神幻化成龙凤双像摆放在孩子房门的左右两侧，妖魔鬼怪不能进入。
　　寒玉床（ＢＥＤ）就摆放在房中。
　　看着他们这个幸福的家，不由得羡慕他们俩的幸福生活。
LONG);
set("item_desc",(["bed":"睡觉用的床铺(gosleep,gobed,bed)。 \n", ]));
set("exits",([
"out" : __DIR__"parlour",
]));
set("outdoors", 0);
set("objects", ([
__DIR__"obj/bed": 1,
]) );
setup();
}
void init()
{
add_action("do_bed", "gosleep");
add_action("do_bed", "gobed" );
add_action("do_bed", "bed");
}
int do_bed()
{
object me;
me=this_player();
message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
me->move("/u/immortal/bed");
message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me);
return 1;
}
