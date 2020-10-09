//
// Created by Administrator on 2020/10/7.
//

#ifndef PHONELIST_CONTACTS_H
#define PHONELIST_CONTACTS_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct call_log{ // 用户的通讯记录结构体
    char name[20];
    char phone_number[13];
    struct call_log *next;
}call_log;

typedef struct contacts{ // 通讯录结构体
    char name[20];
    call_log *callLog;
    struct contacts *next;
}contacts;

contacts *create_phone_list(); // 创建一个通讯录列表
contacts *search_last_user(contacts *head,char name[]); // 搜索目标用户的父节点用户（用于删除）
contacts *search_user(contacts *head,char name[]); // 搜索目标用户
contacts *delete_user(contacts *head,char name[]); // 删除目标用户
void input_call_log(contacts *user,char name[]); //录入目标用户的单条通话记录
void push_user(contacts *head); // 插入用户
void print_user_call_log(contacts *user); // 输出目标用户的通讯记录
void print_contacts(contacts *head); // 输出用户列表


#endif //PHONELIST_CONTACTS_H
