#include <ansi.h>
#pragma save_binary

inherit F_DBASE;

void auto_save();

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "三界精灵");
        CHANNEL_D->do_channel( this_object(), "sys", "\n自动内存回收系统已经启动。\n");
        call_out("auto_clear", 10);
}

void auto_clear()
{
        int i,mem;
        object *ob, link_ob;
        string id;
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("系统自动清除 " + reclaim_objects() + " 个变数。\n"));
        CHANNEL_D->do_channel( this_object(), "chat",
                sprintf("本站ip地址:210.34.120.6 6666(7777，8888)"));
        CHANNEL_D->do_channel( this_object(), "chat",
                sprintf("本站总站网址:http://zmud.7i24.com"));
        CHANNEL_D->do_channel( this_object(), "chat",
                sprintf("本站网址:http://xlqysjsh.51.net"));
        remove_call_out("auto_clear");
        call_out("auto_clear", 1200+random(120));
remove_call_out("init_dynamic_quest");
  TASK_D->init_dynamic_quest(1);
    write("更新系统 TASK 完成!\n");
    rm("/log/dlog/money");
    if (random(5)==1) rm("/log/debug.log"); //防止debug very big
    rm("/log/monitord");
     "/adm/daemons/money"->move_money();
     "/adm/daemons/money"->move_money();
//     "/adm/daemons/money"->move_money();
//     "/adm/daemons/money"->move_money();
     "/adm/daemons/money"->move_money();
}
