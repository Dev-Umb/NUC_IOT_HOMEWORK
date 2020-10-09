//
// Created by Administrator on 2020/10/7.
//
#include "Contacts.h"

contacts *create_phone_list(){         //创建通讯录
    contacts *p = (contacts *)malloc(sizeof(contacts));
    printf("请输入第一个联系人名字");
    scanf("%s",p->name);
    p->callLog=NULL;
    printf("录入成功");
    p->next = NULL;
    return p;
}


contacts *search_last_user(contacts *head,char name[]){    //查找目标节点的父节点(用于删除某个节点）
    contacts *p = head;
    while (p->next){
        if (strcmp(p->next->name,name)==0)
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


void print_user_call_log(contacts *user){
    if (user!=NULL){
        call_log *p = user->callLog;
        while (p!=NULL){
            printf("%s:%s \n",p->name,p->phone_number);
            p = p->next;
        }
    } else{
        printf("没有找到这个成员！");
    }
}


void print_contacts(contacts *user){ //打印用户
    while (user != NULL){
        printf("%s \n",user->name);
        user = user->next;
    }
}


void push_user(contacts *head){ //添加用户（后插）
    contacts *temp =(contacts*)malloc(sizeof(contacts));
    printf("录入姓名：");
    scanf("%s",temp->name);
    int name_size = strlen(temp->name);
    if (name_size > 20) {
        printf("名字太长了");
        return;
    }
    temp->next = NULL;
    temp->callLog = NULL;

    contacts * p = head;
    while (p->next != NULL){
        p = p->next;
    }
    p->next = temp;
    printf("添加成功！");
}


void input_call_log(contacts *head,char name[]){ //录入（修改）目标的通话记录
    contacts *user = search_user(head,name);
    if (user != NULL){
        call_log *temp =(call_log*)malloc(sizeof(call_log));
        temp->next=NULL;
        printf("请输入%s的通话记录\n",name);
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
        printf("录入成功\n");
    } else{
        printf("未找到此人\n");
    }
}


contacts *search_user(contacts *head,char name[]){ //查找目标节点
    contacts *p = head;
    while (p!=NULL){
        if (strcmp(p->name,name)==0)
            return p;
        p = p->next;
    }
    return NULL;
}
