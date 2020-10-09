//
// Created by Administrator on 2020/10/7.
//
#include "Contacts.h"

contacts *create_phone_list(){         //����ͨѶ¼
    contacts *p = (contacts *)malloc(sizeof(contacts));
    printf("�������һ����ϵ������");
    scanf("%s",p->name);
    p->callLog=NULL;
    printf("¼��ɹ�");
    p->next = NULL;
    return p;
}


contacts *search_last_user(contacts *head,char name[]){    //����Ŀ��ڵ�ĸ��ڵ�(����ɾ��ĳ���ڵ㣩
    contacts *p = head;
    while (p->next){
        if (strcmp(p->next->name,name)==0)
            return p;
        p = p->next;
    }
    return NULL;
}


contacts *delete_user(contacts *head,char name[]){ //ɾ��Ŀ��ڵ�
    contacts *user = search_last_user(head,name);
    if (user!=NULL){  //Ŀ��ڵ㲻��ͷ��
        contacts *t = user->next;
        user->next = user->next->next;
        free(t);
        printf("ɾ���ɹ�");
    } else if (strcmp(head->name, name) == 0){ //Ŀ��ڵ���ͷ��
        contacts *t = head;
        head = head->next;
        free(t);
        printf("ɾ���ɹ�");
    } else{
        printf("û���ҵ�����ˣ�");
    }
    return head;
}


void print_user_call_log(contacts *user){
    if (user!=NULL){
        call_log *p = user->callLog;
        while (p!=NULL){
            printf("%s:%s \n",p->name,p->phone_number);
            p = p->next;
        }
    } else{
        printf("û���ҵ������Ա��");
    }
}


void print_contacts(contacts *user){ //��ӡ�û�
    while (user != NULL){
        printf("%s \n",user->name);
        user = user->next;
    }
}


void push_user(contacts *head){ //����û�����壩
    contacts *temp =(contacts*)malloc(sizeof(contacts));
    printf("¼��������");
    scanf("%s",temp->name);
    int name_size = strlen(temp->name);
    if (name_size > 20) {
        printf("����̫����");
        return;
    }
    temp->next = NULL;
    temp->callLog = NULL;

    contacts * p = head;
    while (p->next != NULL){
        p = p->next;
    }
    p->next = temp;
    printf("��ӳɹ���");
}


void input_call_log(contacts *head,char name[]){ //¼�루�޸ģ�Ŀ���ͨ����¼
    contacts *user = search_user(head,name);
    if (user != NULL){
        call_log *temp =(call_log*)malloc(sizeof(call_log));
        temp->next=NULL;
        printf("������%s��ͨ����¼\n",name);
        scanf("%s %s",temp->name, temp->phone_number);
        if (user->callLog==NULL){
            user->callLog = temp;
            return;
        }
        call_log * temp_callLog =user->callLog;
        while (temp_callLog->next!=NULL){
            temp_callLog = temp_callLog->next;
        }
        temp_callLog->next = temp;
        printf("¼��ɹ�\n");
    } else{
        printf("δ�ҵ�����\n");
    }
}


contacts *search_user(contacts *head,char name[]){ //����Ŀ��ڵ�
    contacts *p = head;
    while (p!=NULL){
        if (strcmp(p->name,name)==0)
            return p;
        p = p->next;
    }
    return NULL;
}
