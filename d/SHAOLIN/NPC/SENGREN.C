// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("僧人", ({"seng ren"}));
        set("gender", "男性" );
        create_family("少林寺", 10, "弟子");
        set("title", HIG"少林寺"NOR);
        set("age", 13);
        set("long", "一个年轻僧人正肃容入定，看来已颇得禅宗三昧。\n");
        set("combat_exp", 30);
        set("attitude", "peaceful");
        setup();
}

