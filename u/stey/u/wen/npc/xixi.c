//xiaojie.c

inherit F_VENDOR_SALE;
// inherit NPC;
void create()
{
        

	set_name("玺玺", ({"boss xixi", "xixi","boss"}));
	set("gender", "女性" );
	set("age", 21);
        set("title", "专卖店老板");
	set("long", "巫师 心如止水 派来凡间体恤民情的,这个格格身上带了不少重要的书藉。\n");
	set("combat_exp", 26000);
	set("attitude", "peaceful");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	set("per", 40);
	set("max_kee", 350);

        set("vendor_goods", ([
         "fumo1" : "/u/wen/book/fumo",  
         "fumo2" : "/u/wen/book/fumo2",
         "xuanhu" : "/u/wen/book/xuanhu-blade",
         "taiyi" : "/u/wen/book/taiyi-book",
         "spear" : "/u/wen/book/spearbook",                            
         "parry2" : "/u/wen/book/sample_high",
         "parry1" : "/u/wen/book/parry_book",
         "mihou" : "/u/wen/book/mihou-book",
         "makeup" : "/u/wen/book/makeupbook",
                                               
        ]) );


	setup();
	carry_object("/d/obj/cloth/sunglass")->wear();
       add_money("coin", 100);

        
}

void init()
{
   add_action("do_vendor_list", "list");
}


int ask_name() {
  this_object()->command("shutup xiao jie");  
  return 1;
}
