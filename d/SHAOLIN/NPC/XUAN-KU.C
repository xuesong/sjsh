//gunseng.c
#include <ansi.h>

int ask_name(); 

inherit NPC;
inherit F_MASTER;
void create()
{

set_name("�����ʦ", ({
		"xuanku dashi",
		"xuanku",
		"dashi",
	}));
        set("gender", "����" );
        create_family("������", 2, "����");
        set("title",HIY"��ɽ�������޺�������"NOR );
        set("age", 70);
set("long",
		"����һλ�����ü����ɮ������һϮ��˿�ػ����ġ��������ݸߣ�\n"
		"�����������ƣ��ֱ۴������¶���ƺ��þ���˪��\n"
	);
	set("class", "bonze");
	set("attitude", "heroism");

        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 50);
        set("mana", 2000);
        set("max_mana", 3000);
        set("mana_factor", 20);
        set("combat_exp", 1800000);
        set("daoxing", 2500000);

        set_skill("yijinjing", 300);
        set_skill("chanzong", 300);
        set_skill("spells", 300);
        set_skill("force", 300);
        set_skill("dodge", 280);
        set_skill("shaolin-shenfa", 280);
        set_skill("stick", 280);
        set_skill("zui-gun", 280);
        set_skill("parry", 280);
        map_skill("stick", "zui-gun");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "zui-gun");
        map_skill("force", "yijinjing");
        map_skill("spells", "chanzong");

	set("max_kee", 1300);
	set("max_sen", 1300);
	setup();
        carry_object("/d/shaolin/obj/qimeigun")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();


}
void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");
	name = ob->query("name");

        if( (string)ob->query("gender") != "����" )
	{
		command ("say �����ӷ�Ůʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
		return;
        }

          if( (int)ob->query_skill("chanzong",1) < 180)
        {
        command("say " + RANK_D->query_respect(ob) + "����������Ϊ����������Խ����ʦ��");
                return;
        }

        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

        if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	command("say �����ӷ����գ����գ�");
        command("recruit " + ob->query("id"));
        ob->set("title", HIY"��ɽ�������޺��ô����"NOR);
}