inherit NPC;
#include <ansi.h>
int give_newbie();
int give_family();
int give_51liwu();
int answer_me();

void create()
{
         set_name("小石头", ({"xiao shitou","stone"}));
   set ("long", @LONG
一块石头。
LONG);
           set("gender", "男性");
        set("age", 20);
        set("per", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("inquiry", ([
            "newbie"    :(:give_newbie:),
            "gift"    :(:give_newbie:),
            "礼物"    :(:give_newbie:),
            "family"    :(:give_family:),
            "节日礼物"  :(:give_51liwu:),
            "五一礼物"  : (:give_51liwu:),
            "门派礼物"  :(:give_family:),
]));
        setup();

        carry_object("/d/lingtai/obj/faguan")->wear();
}

int answer_me()
{
        command("say 不行。\n");
        return 1;
}

/*
int give_51liwu()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                command("say 不给");
                command("qi");
                return 1;
        }
         if (who->query("combat_exp") < 0 ){
command("hammer "+who->query("id") );
                command("say 不给");
                return 1;
         }

         if (this_player()->query("liwuu") > 0 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 不给了\n");
        return 1;
        }

        who->add("balance",20000000); 
        who->add("daoxing",90000000);
        who->add("force",12000);
        who->add("mana",12000);
        who->add("potential",0);
        who->set("liwuu",1);
        if (this_player()->query("age") > 24 ){
        who->add("mud_age",-500000);    
         message_vision("$N对着$n说道，恭喜你又变成小孩了!\n",this_object(),this_player());
message_vision("$N对着$n神秘的笑了笑，$n觉得身体发生剧烈的变化，顿时晕倒在地。\n",this_object(),this_player());
        command("tell "+who->query("id")+" 为了我们的前途PK吧。\n");
        command("say 不好啦，"+who->query("name")+"来了!\n",);
        command("say 你现在最好backup!\n");
        return 1;
}
*/

int give_newbie()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                command("say 不给");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") > 10000000 ){
                command("hammer "+who->query("id") );
                command("say 不给了");
return 1;
         }
/*
 if (who->query(
"combat_exp") < 0){
 command("sigh "+who->query("id") );
command("say 太低");
                return 1;
              }
*/

         if (this_player()->query("lucky") > 0 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 不给了\n");
        return 1;
        }

        who->add("combat_exp",9000000);
        who->add("daoxing",9000000);
        who->add("force",12000);
        who->add("mana",12000);
        who->add("maximum_force",12000);
        who->add("max_mana",12000);
        who->add("max_force",12000);
       who->add("maximum_mana",12000);
        who->add("potential",0);
        who->set("lucky",1);
message_vision("$N对着$n神秘的笑了笑，$n觉得身体发生剧烈的变化，顿时晕倒在地。\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
你的道行增加了二十年!\n
        你的潜能增加了20000。\n
        你现在有400点内力和法力。\n");
        command("say 不好啦，"+who->query("name")+"来了！\n");
        return 1;
}
int give_family()
{
        object who=this_player();
        string family;
        family=who->query("family/family_name");
        if (!userp(who))
        {
                command("heng");
                command("say 不给");
                command("qi");
                return 1;
        }
if (this_player()->query("lucky") > 1 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 不给了！\n");
        return 1;
        }
        if (who->query("combat_exp") > 40000000 ) {
                        command("hammer "+who->query("id") );
                command("say 就不给");
   return 1;
         }
 if (who->query("combat_exp") < 10000 ){
 command("sigh "+who->query("id") );
command("say 去死");
                return 1;
              }
        if ( family == 0 )
        {
                command("heng");
                command("say "+who->query("name")+"你还是先去拜师吧，只有两个门派可以。\n");
                return 1;
        }
        switch(family) {
         case "大雪山":

who->set_skill("literate",500);
who->set_skill("dodge",500);
who->set_skill("force",500);
who->set_skill("spells",500);
who->set_skill("parry",500);
who->set_skill("ningxie-force",500);
who->set_skill("dengxian-dafa",500);
who->set_skill("throwing",500);
who->set_skill("unarmed",500);
who->set_skill("xiaoyaoyou",500);
who->set_skill("blade",500);
who->set_skill("bingpo-blade",500);
who->set_skill("cuixin-zhang",500);
who->set_skill("sword",500);
who->set_skill("bainiao-jian",500);
break;
                case "将军府": 
who->set_skill("literate",500);
who->set_skill("baguazhou",500);
who->set_skill("force",500);
who->set_skill("dodge",500);
who->set_skill("spells",500);
who->set_skill("parry",500);
who->set_skill("unarmed",500);
who->set_skill("archery",500);
who->set_skill("bawang-qiang",500);
who->set_skill("changquan",500);
who->set_skill("lengquan-force",500);
who->set_skill("mace",500);
who->set_skill("spear",500);
who->set_skill("wusi-mace",500);
who->set_skill("xuanyuan-archery",500);
who->set_skill("yanxing-steps",500);
who->set_skill("jinglei-mace",500);
break;
default:
                command("heng");
                command("say "+who->query("name")+"你还是先去拜师吧，但只有两个门派。\n");
                return 1;
}       
        who->set("lucky",2);
        command("nod "+who->query("id") );
        command("say "+family+"弟子"+who->query("name")+"来报仇啦。\n");
        return 1;
}
void init()
{
    call_out("greeting", 1, this_player());
    ::init();
}
*/

void greeting(object who) {
if( who->query("combat_exp") < 1000)
        tell_object(who,"有你的信。\n");
        tell_object(who,"门派问题。\n");
}
/*
int give_dan1()
 {
        object who=this_player();
        object dan;
        dan=new("/u/stey/obj/dan1.c");
        if (this_player()->query("dann") > 0 ){
         message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
                command("say 什么?\n");
        return 1;
        }

        dan->move(who);
        message_vision("$N给你吧。\n",this_object(),this_player());
        who->set("dann",1);
 return 1;
}
*/ 
