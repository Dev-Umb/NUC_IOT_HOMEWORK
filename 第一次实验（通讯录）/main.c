#include "Contacts.h"
int main() {
    printf("��ʼ����ͨѶ¼:\n");
    contacts *head = create_phone_list();
    printf("ͨѶ¼�Ѵ�����\n");
    while(1) {
        char *p;//�����������
        scanf("%s",p);
        printf("----------------------------------------\n"
               "������Ž���ѡ��:\n"
               "0.�˳�ͨѶ¼\n"
               "1.����ͨѶ¼\n"
               "2.����ĳλͬѧ\n"
               "3.¼��ĳλͬѧ��ͨѶ��¼\n"
               "4.������г�Ա�б�\n"
               "5.���ĳλ��Ա��ͨѶ��¼\n"
               "6.ɾ��ĳλ��Ա�ļ�¼\n"
               "--------------------------------------------\n");
        int num = 0;//ѡ��
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
                printf("������ͬѧ������");
                scanf("%s",name);
                input_call_log(head,name);
                break;
            case 4:
                print_contacts(head);
                break;
            case 5:
                printf("������ͬѧ������");
                scanf("%s",name);
                contacts *user = search_user(head,name);
                print_user_call_log(user);
                break;
            case 6:
                printf("������ͬѧ������");
                scanf("%s",name);
                head=delete_user(head,name);
                break;
            default:
                printf("�����������������룡");
        }
        printf("�����������\n");
    }
}