
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("½ѹ", ({"luya","lu","ya"}));
        set("gender", "����" );
        create_family("����ɽ���鶴", 3, "����");
        set("title",HIG"����ɽ���鶴�ܼ�"NOR);
        set("age", 41);
       set("class", "xian");
        set("long", "����ɽ���鶴ɢ��½ѹ���ڶ��м��ιܼ�ְ֮��\n");
        set("combat_exp", 30);
        set("attitude", "peaceful");
        setup();
  carry_object("/d/obj/cloth/linen")->wear();;
}

