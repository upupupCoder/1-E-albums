//定义元素类型和函数声明

#ifndef __DOUBLE_LIST_H__
#define __DOUBLE_LIST_H__
#include<stdio.h>
#include<stdlib.h> //for malloc
#include<string.h>
#define File_NAME_SIZE 256
//链表是用来保存数据的,为了使链表通用性更强
//数据节点(既要保存数据,又要保存指针)
typedef struct node 
{
	char photo[File_NAME_SIZE];//数据域
	char music[File_NAME_SIZE];//数据域
	struct node *next; //指针域
	struct node *prev; 
}Node;

//头结点(管理数据节点的节点)
typedef struct
{
	Node *first;
	Node *last;
	int num;
}Head;

/*
create_linkedlist:根据用户输入的数据,建立一个带头节点的双向链表
返回值:
	返回双向链表的头结点的地址
*/

Head *create_linkedlist(); //函数声明

/*
create_linkedlist2:根据用户输入的数据,建立一个升序带头节点双向链表
返回值:
	返回双向链表的头结点的地址
*/
Head *create_linkedlist2();

/*
insert_node:把一个指定的数据x,插入head表示的带头结点双向链表中,分别实现“头插法”“尾插法”“建立有序链表”
@head：指向带头结点双向链表的头结点
@x:表示你要插入链表的数据
返回值:
	返回双向链表的头结点的地址
*/
Head *insert_node(Head *head,char * x);


/*
print_list:打印带头节点双向链表中的每一个节点的数据
@head:链表的头结点的地址
返回值:
	无
*/
void print_list(Head *head);

/*
clear_list:清空链表,释放head指向的链表的所有数据节点
@head:链表的头结点的地址
返回值:
	无
*/
void clear_list(Head *head);

/*
delete_list:删除链表,先释放所有的数据节点，再释放头结点
@head:链表的头结点的地址
返回值:
	无
*/
void delete_list(Head *head);


/*
delete_min:删除head指向的带头节点双向链表的最小值(最小值唯一)
@head:指向要处理的双向链表的头结点的地址
返回值:
	可以没有
	返回处理后的头结点地址(其实没变)
*/

Head *delete_min(Head *head);


/*
delete_x:删除head指向的双向链表中的x
@head:指向要处理的双向链表的头结点的地址
@x:要删除的数据的值
返回值:
	可以没有
	返回处理后的头结点地址(其实没变)
*/

Head *delete_x(Head *head,char * x);


/*
delete_all_x:删除head指向的双向链表中所有的x
@head:指向要处理的双向链表的头结点的地址
@x:要删除的数据的值
返回值:
	可以没有
	返回处理后的头结点地址(其实没变)
*/

Head *delete_all_x(Head *head,char * x);

/*
find_mid:找双向链表的中间的节点(数据节点)
@head:你要操作的双向链表的头结点的指针
返回值:
	返回双向链表中间节点的指针
*/
Node *find_mid(Head *head);

#endif







