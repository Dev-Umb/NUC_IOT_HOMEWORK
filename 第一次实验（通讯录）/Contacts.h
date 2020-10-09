//
// Created by Administrator on 2020/10/7.
//

#ifndef PHONELIST_CONTACTS_H
#define PHONELIST_CONTACTS_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct call_log{ // �û���ͨѶ��¼�ṹ��
    char name[20];
    char phone_number[13];
    struct call_log *next;
}call_log;

typedef struct contacts{ // ͨѶ¼�ṹ��
    char name[20];
    call_log *callLog;
    struct contacts *next;
}contacts;

contacts *create_phone_list(); // ����һ��ͨѶ¼�б�
contacts *search_last_user(contacts *head,char name[]); // ����Ŀ���û��ĸ��ڵ��û�������ɾ����
contacts *search_user(contacts *head,char name[]); // ����Ŀ���û�
contacts *delete_user(contacts *head,char name[]); // ɾ��Ŀ���û�
void input_call_log(contacts *user,char name[]); //¼��Ŀ���û��ĵ���ͨ����¼
void push_user(contacts *head); // �����û�
void print_user_call_log(contacts *user); // ���Ŀ���û���ͨѶ��¼
void print_contacts(contacts *head); // ����û��б�


#endif //PHONELIST_CONTACTS_H
