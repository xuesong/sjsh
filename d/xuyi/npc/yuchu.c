// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

//created bye night

inherit NPC;

void create()
{
        set_name("御厨", ({ "yu chu", "yuchu" }));
        set("str", 50);
        set("gender", "男性");
        set("age", 50);
        set("long", "他是皇宫御厨，精通天下美食的烹饪。\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");

        setup();
        carry_object("/d/xuyi/obj/guazi")->wear();
}

