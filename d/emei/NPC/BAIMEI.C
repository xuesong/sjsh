
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name("��ü��ʦ", ({"bai mei", "bai", "mei","master"}));
       set("long", "�����ɿ�ɽ��ʦ, ִ�ƶ���������ǧ���ꡣ\n");
       set("title", HIW"���������ʦ��"NOR);
       set("gender", "����");
       set("age", 100);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "��ͷ");
       set("cor", 30);
       set("per", 30);
       set("looking", "һ�����ǳ");
       set("max_kee", 5000);
       set("max_sen", 5000);
       set("sen", 5000);
       set("kee", 5000);
       set("max_gin", 800);
       set("max_force", 3000);
       set("max_mana", 3000);
       set("mana", 3000);
       set("force", 3000);
       set("force_factor", 125);
       set("mana_factor", 160);
       set("combat_exp", 3500000);
       set("daoxing", 4500000);
       set_skill("literate", 200);
       set_skill("unarmed", 220);
       set_skill("dodge", 220);
       set_skill("force", 220);
       set_skill("parry", 220);
       set_skill("sword", 220);
       set_skill("spells", 220);
       set_skill("emeiforce", 220);
       set_skill("tianlei-sword", 220);
       set_skill("zhutian-bu", 220);
       set_skill("mahayana", 220);
       set_skill("jinding-zhang", 220);
       map_skill("sword", "tianlei-sword");
       map_skill("dodge", "zhutian-bu");
       map_skill("force", "emeiforce");
       map_skill("spells", "mahayana");
       map_skill("unarmed", "jinding-zhang");

	set("inquiry", ([
		"name": "���ǰ�ü��\n",
		"here": "����ɽ��\n",
	]) );


   create_family("������", 1, "��");
setup();

   carry_object("/d/emei/obj/haotianjing.c");
   carry_object("/d/emei/obj/shoes")->wear();
}
void init()
{
add_action("do_kneel","kneel");
}

void attempt_apprentice(object ob)

   {

   if ( (string)ob->query("family/family_name")=="������") {
   if (((int)ob->query("combat_exp") < 1500000 )) 
        {
   command("say " + RANK_D->query_respect(ob) + "����ѧ��Ϊ���������Щ��ѧ�ط�������������\n");
   return;
        }
   if( (int)ob->query_skill("emei-force") > 199 ) 
        {
   command ("say " + RANK_D->query_respect(ob) + "��Ķ����ķ���Ϊ������Ϊʦ��������Ϊͽ��");
   return;
        }
   if( (int)ob->query_skill("mahayana") > 199 ) 
        {
   command ("say " + RANK_D->query_respect(ob) + "��Ĵ�����͹���Ϊ������Ϊʦ��������Ϊͽ��");
   return;
        }
   if( (int)ob->query_skill("tianji-sword") > 1 ) 
        {
   command ("say " + RANK_D->query_respect(ob) + "�����ȷ�������ѧ�������ὣ����Ϊʦ��������Ϊͽ��");
   return;
        }
   if( (int)ob->query_skill("leiyan-sword") > 1 ) 
        {
   command ("say " + RANK_D->query_respect(ob) + "�����ȷ�������ѧ�������׽�����Ϊʦ��������Ϊͽ��");
   return;
        }

        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) + "���Ŭ���������Ƕ��ҷ�����\n");
        command("recruit " + ob->query("id") );
        ob->set("title", HIW"�����ɰ�ü�洫����"NOR);

   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) + "������ȥѧЩ��������ɡ�\n");
        return;
}
