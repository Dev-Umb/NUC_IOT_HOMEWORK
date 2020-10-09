#include "Contacts.h"
int main() {
    printf("开始创建通讯录:\n");
    contacts *head = create_phone_list();
    printf("通讯录已创建！\n");
    while(1) {
        char *p;//按任意键继续
        scanf("%s",p);
        printf("----------------------------------------\n"
               "输入序号进入选项:\n"
               "0.退出通讯录\n"
               "1.重置通讯录\n"
               "2.插入某位同学\n"
               "3.录入某位同学的通讯记录\n"
               "4.输出所有成员列表\n"
               "5.输出某位成员的通讯记录\n"
               "6.删除某位成员的记录\n"
               "--------------------------------------------\n");
        int num = 0;//选项
        scanf("%d",&num);
        char name[20];
        switch (num){
            case 0:
                return 0;
            case 1:
                head = create_phone_list();
                break;
            case 2:
                push_user(head);
                break;
            case 3:;
                printf("请输入同学的姓名");
                scanf("%s",name);
                input_call_log(head,name);
                break;
            case 4:
                print_contacts(head);
                break;
            case 5:
                printf("请输入同学的姓名");
                scanf("%s",name);
                contacts *user = search_user(head,name);
                print_user_call_log(user);
                break;
            case 6:
                printf("请输入同学的姓名");
                scanf("%s",name);
                head=delete_user(head,name);
                break;
            default:
                printf("输入有误，请重新输入！");
        }
        printf("按任意键继续\n");
    }
}