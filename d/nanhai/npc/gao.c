// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

//created by night 7/24/2000

inherit NPC;
string zhuzao(object me);

void create()
{
        set_name("高翔", ({"gao xiang", "gao"}));
        set("gender", "男性" );
        set("title", "妙手天师");
        set("age", 33);
        set("long", "方寸山三星洞第二代弟子中的杰出人物，精于武器铸造。\n");
        set("combat_exp", 60000);
        set("attitude", "friendly");
        set("int", 40);
        set("str", 40);
        set("spi", 40);
        set("per", 40);
        set("kar", 40);
        set("cps", 40);
        set("con", 40);
        set("cor", 40);
        set("class", "taoist");

        set("eff_dx", 40000);
        set("nkgain", 300);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("spells", 20);  
        set_skill("dao", 20);
        set_skill("literate", 20);
        set_skill("stick", 20);  
        set_skill("qianjun-bang", 20);
        set_skill("puti-zhi", 20);  
        set_skill("jindouyun", 20);
        set_skill("dodge", 20);
        set_skill("force", 20);   
        set_skill("wuxiangforce", 20);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");

        set("max_kee", 300);
        set("max_gin", 300);
        set("max_sen", 200);
        set("force", 200);
        set("max_force", 100);
        set("force_factor", 10);
        set("mana", 400);
        set("max_mana", 200);
        set("mana_factor", 10);
        
        set("inquiry", ([
                "name" : "在下姓高名翔，偏安于此。\n",
                "here" : "这里是盱眙山滨城所在。\n", 
            "铸造" : (: zhuzao :),
            "兵器" : (: zhuzao :),            
            "weapon" : (: zhuzao :),
         ]) );
        
        setup();
//        carry_object("/d/lingtai/obj/daoguan")->wear();
        carry_object("/d/lingtai/obj/cloth")->wear();
//        carry_object("/d/obj/weapon/stick/xiangmo")->wield();
}

string zhuzao(object me)
{
        object ob;
        me = this_player();

        if(me->query_temp("add_damage"))
        {
                message_vision("高翔自顾自地凝望着墙上的墨竹画，不理$N了。\n", me);
                return RANK_D->query_respect(me)+"已经来过，请回吧。\n";
        }       
        if( !me->query_temp("zhuzao/paid") )
        {
                if( me->query_temp("zhuzao/asked") ) 
                {
                        message_vision("高翔自顾自地凝望着墙上的墨竹画，不理$N了。\n", me);
                        return RANK_D->query_respect(me)+"请回。\n";
                }
                else
                {
                        me->set_temp("zhuzao/asked", 1);
                        message_vision("高翔看了$N一眼，摇了摇头。\n", me);
                        return "心已淡泊如松，望勿打扰。\n";
                }
        }
        else
        {
                me->delete_temp("zhuzao");
                message_vision("高翔叹了口气，对$N道："+RANK_D->query_respect(me)+"既然如此看得起在下，当尽绵力。\n", me);
                if (!(ob = me->query_temp("weapon")))
                        return "你没用兵刃，又怎能铸造？\n";
                else
                {
                message_vision("高翔接过"+ob->name()+"，打磨铸炼，过了一会，又交还给$N。\n",me);
                message_vision("只见寒光一闪，"+ob->name()+"的锋锐比以前更胜一筹。\n",me);                
                me->add_temp("apply/damage",random(8)+5);
                me->set_temp("add_damage",1);                
                return "武器已经铸好，请回吧。\n";
                }
        }
}

int accept_object(object me, object ob)
{
        if( ob->value() >= 200000 )
        {
                message_vision("高翔对$N道："+RANK_D->query_respect(me)+"予我重金，可是有事相求？\n", me);
                me->set_temp("zhuzao/paid", 1);
                return 1;
        }
        else
        {
            command("say 不敢当不敢当……您太客气了。");
            return 1;
        }
}

