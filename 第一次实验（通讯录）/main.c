#include "Contacts.h"
int main() {
    printf("开始创建通讯录:\n");
    contacts *head = create_phone_list();
    printf("通讯录已创建！\n");
    while(1) {
        printf("按任意数字键继续");
        int nums;//输入任意数字继续
        scanf("%d",&nums);
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
        int num = 0;
        scanf("%d",&num);
        if (num == 0){
            break;
        }
        char name[20];
        switch (num){
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
        }
        printf("\n");
    }
    return 0;
}