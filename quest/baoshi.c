// modi by tomcat 

#include <ansi.h>

inherit F_DBASE;
int random_place(string dirss,object bs);

string *dirs = ({
"/d/changan",
"/d/city",
"/d/eastway",
"/d/gao",
"/d/kaifeng",
"/d/lingtai",
"/d/moon",
"/d/nanhai",
"/d/sea",
"/d/westway",
"/d/qujing/wuzhuang",
"/d/ourhome/honglou",
"/d/death",
"/d/penglai",
"/d/xueshan",
"/d/qujing/baotou",
"/d/qujing/baoxiang",
"/d/qujing/bibotan",
"/d/qujing/biqiu",
"/d/qujing/chechi",
"/d/qujing/dudi",
"/d/qujing/fengxian",
"/d/qujing/firemount",
"/d/qujing/jilei",
"/d/qujing/jindou",
"/d/qujing/jingjiling",
"/d/qujing/jinping",
"/d/qujing/jisaiguo",
"/d/qujing/maoying",
"/d/qujing/nuerguo",
"/d/qujing/pansi",
"/d/qujing/pingding",
"/d/qujing/qilin",
"/d/qujing/qinfa",
"/d/qujing/qinglong",
"/d/qujing/tianzhu",
"/d/qujing/tongtian",
"/d/qujing/wudidong",
"/d/qujing/wuji",
"/d/qujing/xiaoxitian",
"/d/qujing/yinwu",
"/d/qujing/yuhua",
"/d/qujing/zhujie",
"/d/qujing/zhuzi",
});

string *dirname = ({
"������",
"��������",
"�����Ƕ�",
"����ׯ",
"����",
"��̨����ɽ",
"�¹�",
"�Ϻ�����ɽ",
"��������",
"��������",
"��ׯ��",
"��¥һ��",
"���޵ظ�",
"�����ɵ�",
"��ѩɽ",
"��ͷɽ",
"�����",
"�̲�̶",
"�����",
"���ٹ�",
"����ɽ",
"���ɿ�",
"����ɽ",
"����ɽ",
"��ɽ",
"������",
"��ƽ��",
"������",
"ëӱɽ",
"Ů����",
"��˿��",
"ƽ��ɽ",
"����ɽ",
"�շ���",
"����ɽ",
"���ù�",
"ͨ���",
"�޵׶�",
"�ڼ���",
"С����",
"����ɽ",
"����",
"���ɽ",
"���Ϲ�",
});


void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "�ڴ澫��");
        CHANNEL_D->do_channel( this_object(), "sys", "��ʯϵͳ�Ѿ�������\n"); 
        set("name","");
        remove_call_out("choose_baoshi");
        call_out("choose_baosi",10);
}

void choose_baosi()
{
        int i, j ,k,ppl,rd;
        object *list,newob;
        string str,m_name;
        string smp;
        
        j = random(sizeof(dirs));
        //newob = new("/d/quest/obj/");
        rd = random(3);
        if(rd==0) 
        {
                 newob = new("/quest/obj/bs_b1");
                 str = "��";
        }
        if(rd==1) 
        {
                 newob = new("/quest/obj/bs_g1");
                 str = "��";
        }
        if(rd==2)
        { 
                 newob = new("/quest/obj/bs_y1");
                 str = "��";
        }
        	
        if(random_place(dirs[j],newob)== 1 )
        message("channel:chat",HIG"��"+HIR"�����챦"+HIG"��"+HIW"ͻȻ���д��˸�ը��,һ�������ճ���,����һ��"+str+"����"+dirname[j]+"�ķ�����ȥ!\n"+NOR,users());
        remove_call_out("choose_baosi");
  call_out("choose_baosi",180);
}

int random_place(string dirss,object bs)
{
        int  j, k;
        object  newob,ob;
        mixed*  file;
        string id_name;
        file = get_dir( dirss+"/npc/*.c", -1 );
        
        if( !sizeof(file) ) return 0;

        for(k=0;k<50;k++) { // try 50 times
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirss+"/npc/"+file[j][0]);
             if(!newob) continue;
             id_name = newob->query("id");
             if(!id_name) continue;
             if(!objectp(ob=find_living(id_name))) continue; //���npc���ǻ�� 
             ob=find_living(id_name);
                     if(bs->move(newob)) {
                    CHANNEL_D->do_channel( this_object(), "sys", "��ʯ�䵽��"+ob->query("name")+"("+ob->query("id")+")�����ϡ�\n"); 
                    return 1;
                   }
             }
           }
         CHANNEL_D->do_channel( this_object(), "sys", "���α�ʯ����ʧ��\n");        
        return 0;
}

   