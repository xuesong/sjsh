//奖励示范程序
//by koker@sjsh 2002.01

inherit NPC;
int ask_aoyun();
void create()
{
      set_name("申奥成功使者", ({"shizhe","shi"}));
      set ("long", @LONG
他是在这里负责给大家发奥运奖励(aoyun)的，
大家赶快向他要（ask）吧。
LONG);
set("inquiry", ([
"aoyun": (: ask_aoyun :),
        ]));
setup();
}
int ask_aoyun()
{
        object me=this_player();
        int sss;

//这个奖励是个示范程序。当奖励曾经发过一次，这次又要发。那么，
//就要防止第一次没领过的人连续要两遍。

        if (this_player()->query("sss")>1){
message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
        command("say 奥运申办成功了，大补也给你了，你怎么还要啊！小心整蛊你！\n");
 return 1;
}
        if (this_player()->query("sss")<1){
message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
        command("say 奥运申办成功了， 可你也不要用大米来领奖励啊。小心整蛊你！\n");
 return 1;
}
        me->add("potential",150000);
        me->add("sss",1);//每要一次增加一个参数。
        command("say 奥运申办成功了，大家也有一份功劳,给你些潜能吧!\n");
 return 1;
}
