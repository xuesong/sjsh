// 乐平 by Calvin

#include <ansi.h> 
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIM"乐平"NOR, ({"le ping","le", "ping","tianshen"}));
       set("long", "原为多林寺巡使,龙珠守卫者之一。\n");
       set("title", HIW"百色星君"NOR);
  set("gender", "男性");
       set("age", 3000);
       set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "多林寺巡使");
       set("per", 32);
       set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 2500);
       set("force_factor", 150);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
       set("daoxing", 10000000);

       set_skill("literate", 350);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("parry", 350);
       set_skill("stick", 350);
       set_skill("sword", 350);
       set_skill("liangyi-sword", 350);
       set_skill("spells", 350);
       set_skill("dao", 350);
       set_skill("puti-zhi", 350);
       set_skill("wuxiangforce", 350);
       set_skill("force", 350);
       set_skill("qianjun-bang", 350);
       set_skill("jindouyun", 350);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");
        map_skill("sword", "liangyi-sword");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: cast_spell, "light" :),
                (: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) );

create_family("方寸山三星洞", 1, "蓝");
setup();
        carry_object("/d/zj/armor/xingtian")->wear();
        carry_object("/d/zj/armor/xue")->wear();
        carry_object("/d/zj/weapon/qiankun")->wield();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="方寸山三星洞") {
        if ((int)ob->query("daoxing") < 5000000 ) {
        command("say 我们修真之士最重的就是道行，" + RANK_D->query_respect(ob) + "还需多加努力才能早悟大道。\n");
        return;
        }
/*
        if( (int)ob->query("pending/kick_out")) {
        command("say 这位" + RANK_D->query_respect(ob) + "反复无常，小仙不原再收你为徒了！\n");
        command("sigh");
        return;
        }
*/
        if ((int)ob->query_int() < 40) {
        command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
        command("sigh");
        return;
        }
        if( (int)ob->query_skill("dao", 1) < 250 ) {
        command("say 这位" + RANK_D->query_respect(ob) + "对我道家仙法领会还不够深，现在收你也是勉为其难，不如作罢！\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
        return;
        }
        command("shake");
        command("say 小仙不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
}

int accept_fight(object me, object ob)
{       ob=this_player();
        command("say " + RANK_D->query_rude(ob) + "杀心太重，恐祸不久已！\n");
        return 0;
}
//void die()
//{
//        if( environment() ) {
//        message("sound", "\n\n乐平微皱眉头，道：这厮果是个天成地就的！\n\n", environment());
//        command("sigh");
//        message("sound", "\n乐平身形一转，化做青烟走了。。。\n\n", environment());
//        }
//        destruct(this_object());
//}
