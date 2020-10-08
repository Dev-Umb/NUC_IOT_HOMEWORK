//
// Created by Administrator on 2020/10/7.
//

#ifndef PHONELIST_CONTACTS_H
#define PHONELIST_CONTACTS_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct contacts{    //通讯记录
    char name[20];
    char phone_number[13];
    struct contacts *next;
}contacts;


contacts *create_phone_list(){         //创建通讯录
    contacts *p = (contacts *)malloc(sizeof(contacts));
    printf("请输入第一个联系人名字和电话:");
    scanf("%s %s",p->name,p->phone_number);
    printf("录入成功");
    p->next = NULL;
    return p;
}

contacts *search_last_user(contacts *t,char name[]){    //查找目标节点的父节点(用于删除某个节点）
    contacts *p = t;
    while (p->next){
        if (strcmp(p->next->name,name)==0)
            return p;
        p = p->next;
    }
    return NULL;
}



contacts *search_user(contacts *t,char name[]){ //查找目标节点
    contacts *p = t;
    while (p!=NULL){
        if (strcmp(p->name,name)==0)
            return p;
        p = p->next;
    }
    return NULL;
}



contacts *delete_user(contacts *head,char name[]){ //删除目标节点
    contacts *user = search_last_user(head,name);
    if (user!=NULL){  //目标节点不在头部
        contacts *t = user->next;
        user->next = user->next->next;
        free(t);
        printf("删除成功");
    } else if (strcmp(head->name, name) == 0){ //目标节点在头部
        contacts *t = head;
        head = head->next;
        free(t);
        printf("删除成功");
    } else{
        printf("没有找到这个人！");
    }
    return head;
}



void input_call_log(contacts *p,char name[]){ //录入（修改）目标的通话记录
    contacts *user = search_user(p,name);
    if (user != NULL){
        printf("请输入%s的通话记录\n",name);
        scanf("%s",&user->phone_number);
        printf("录入成功\n");
    } else{
        printf("未找到此人\n");
    }
}

void push_user(contacts *head){ //添加用户（后插）
    contacts * p = head;
    while (p->next!=NULL){
        p = p->next;
    }
    contacts *t =(contacts*)malloc(sizeof(contacts));
    printf("录入姓名：");
    scanf("%s",t->name);
    int name_size = strlen(t->name);
    if (name_size > 20) {
        printf("名字太长了");
        return;
    }
    t->next = NULL;
    p->next = t;
    printf("添加成功！,请录入%s同学的电话\n",t->name);
    scanf("%s",p->next->phone_number);
}

void print_contacts(contacts *p){ //打印用户记录
    while (p!=NULL){
        printf("%s:%s \n",p->name,p->phone_number);
        p=p->next;
    }

}
#endif //PHONELIST_CONTACTS_H
