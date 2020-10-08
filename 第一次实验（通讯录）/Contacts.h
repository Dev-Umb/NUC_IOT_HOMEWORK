//
// Created by Administrator on 2020/10/7.
//

#ifndef PHONELIST_CONTACTS_H
#define PHONELIST_CONTACTS_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct contacts{    //ͨѶ��¼
    char name[20];
    char phone_number[13];
    struct contacts *next;
}contacts;


contacts *create_phone_list(){         //����ͨѶ¼
    contacts *p = (contacts *)malloc(sizeof(contacts));
    printf("�������һ����ϵ�����ֺ͵绰:");
    scanf("%s %s",p->name,p->phone_number);
    printf("¼��ɹ�");
    p->next = NULL;
    return p;
}

contacts *search_last_user(contacts *t,char name[]){    //����Ŀ��ڵ�ĸ��ڵ�(����ɾ��ĳ���ڵ㣩
    contacts *p = t;
    while (p->next){
        if (strcmp(p->next->name,name)==0)
            return p;
        p = p->next;
    }
    return NULL;
}



contacts *search_user(contacts *t,char name[]){ //����Ŀ��ڵ�
    contacts *p = t;
    while (p!=NULL){
        if (strcmp(p->name,name)==0)
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



void input_call_log(contacts *p,char name[]){ //¼�루�޸ģ�Ŀ���ͨ����¼
    contacts *user = search_user(p,name);
    if (user != NULL){
        printf("������%s��ͨ����¼\n",name);
        scanf("%s",&user->phone_number);
        printf("¼��ɹ�\n");
    } else{
        printf("δ�ҵ�����\n");
    }
}

void push_user(contacts *head){ //����û�����壩
    contacts * p = head;
    while (p->next!=NULL){
        p = p->next;
    }
    contacts *t =(contacts*)malloc(sizeof(contacts));
    printf("¼��������");
    scanf("%s",t->name);
    int name_size = strlen(t->name);
    if (name_size > 20) {
        printf("����̫����");
        return;
    }
    t->next = NULL;
    p->next = t;
    printf("��ӳɹ���,��¼��%sͬѧ�ĵ绰\n",t->name);
    scanf("%s",p->next->phone_number);
}

void print_contacts(contacts *p){ //��ӡ�û���¼
    while (p!=NULL){
        printf("%s:%s \n",p->name,p->phone_number);
        p=p->next;
    }

}
#endif //PHONELIST_CONTACTS_H
