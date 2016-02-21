#include <ansi.h>
#include <weapon.h>
inherit THROWING;

void create()
{
        set_name("�ѻ���ǹ",({"zhuji buqiang","buqiang","qiang"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("base_unit", "��");
                set("material","iron");
                set("long","shoot [����] <Ŀ��>�����Ϊ02��\n");
                set("wield_msg", "$N��ţ�ƵĴӱ���ж��һ֧$n�������ϡ�\n");
                set("unequip_msg", "$N���������е�$n��\n");
        }
        set_amount(1);
        init_throwing(1);

        setup();

}
void init()
{
        add_action("do_shoot","shoot");
}
int do_shoot(string str)
{
        object me,target,room;
        string dir,name;
        me=this_player();

       if(!wizardp(this_player())) return notify_fail("�㿴�˰��죬ҲŪ������Ҫ��ô�ã�������̫���ˣ�\n");
        if(!str)
        return notify_fail("shoot [����] <����>\n");
        if(sscanf(str,"%s %s",dir,name)==2)  {
                if(!environment(me)->query("exits/"+dir))
                return notify_fail("û���������\n");
                if(!room=find_object(environment(me)->query("exits/"+dir)))
                room=load_object(environment(me)->query("exits/"+dir));
                room=load_object(environment(me)->query("exits/"+dir));
        }
        else    {
                name=str;
                room=environment(me);
        }
                target=present(name,room);
                if(!target)     return notify_fail("�Ƕ�û�����Ŀ�꣡\n");
                if(!target->is_character())     return notify_fail("�ǲ��Ǹ����\n");
                tell_room(environment(me),HIY""+me->query("name")+"��Цһ�����������еľѻ���ǹ......��ϥ��أ�����"+target->query("name")+"��\n"NOR);
                tell_room(environment(me),RED"��ƹ����һ��ǹ�죬�ӵ�����"+target->query("name")+"��Х��ȥ��\n"NOR);
                message_vision(RED"һ���ӵ���Х�������������֮��$N����һ���ҽе���Ѫ��֮�У�\n"NOR,target);
                target->die();
                return 1;
}
