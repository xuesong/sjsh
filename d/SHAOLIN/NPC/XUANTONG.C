//gunseng.c
#include <ansi.h>

int ask_name(); 

inherit NPC;
inherit F_MASTER;
void create()
{

set_name("��ʹ��ʦ", ({
		"xuantong dashi",
		"xuantong",
		"dashi",
	}));
        set("gender", "����" );
        create_family("������", 3, "����");
        set("title",HIC"�����½���Ժ����"NOR );
        set("age", 78);
set("long",
		"����һλ�����ü����ɮ������һϮ��˿�ػ����ġ������ĸߴ�\n"
		"���ֹ�ϥ��˫Ŀ������գ�ȴ��ʱ���һ�ƾ��⡣\n"
	);
	set("class", "bonze");
	set("attitude", "heroism");

        set("force", 1700);
        set("max_force", 1700);
        set("force_factor", 70);
        set("mana", 1700);
        set("max_mana", 1700);
        set("mana_factor", 20);
        set("combat_exp", 1200000);
        set("daoxing", 1500000);

        set_skill("banruo-zhang", 180);
        set_skill("jingang-leg", 180);
        set_skill("yijinjing", 200);
        set_skill("chanzong", 200);
        set_skill("spells", 180);
        set_skill("force", 180);
        set_skill("unarmed", 180);
        set_skill("literate", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        map_skill("unarmed", "banruo-zhang");
        map_skill("parry", "jingang-leg");
        map_skill("force", "yijinjing");
        map_skill("spells", "chanzong");

	set("max_kee", 1300);
	set("max_sen", 1300);
	setup();
        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();


}
void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "����" )
	{
		command ("say �����ӷ�Ůʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
		return;
	}

	if( (string)ob->query("class")!="bonze" )
	{
		command ("say �����ӷ�ƶɮ�������������׼ҵ��ӡ��ˡ�");
	}
	command("say �����ӷ����գ����գ�");
        command("recruit " + ob->query("id"));
        ob->set("title", HIG"��ɽ�����µ���"NOR);
}