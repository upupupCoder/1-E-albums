#include"DoubleList.h"

/*
create_linkedlist:根据用户输入的数据,建立一个带头节点的双向链表
返回值:
	返回双向链表的头结点的地址
*/

Head *create_linkedlist()
{

	Head *h = (Head*)malloc(sizeof(Head)); 
	h->first = NULL;
	h->last = NULL;
	h->num = 0;
	return h;
}

/*
insert_node:把一个指定的数据x,插入head表示的带头结点双向链表中,分别实现“头插法”“尾插法”“建立有序链表”
@head：指向带头结点双向链表的头结点
@x:表示你要插入链表的数据
返回值:
	返回双向链表的头结点的地址
*/
Head *insert_node(Head *head,char *x)
{
	//为x创建一个数据节点
	Node * new= (Node *)malloc(sizeof(Node));
	strncpy(new->photo,x,File_NAME_SIZE);
	//把数据节点加入head指向的链表
	if (head->num == 0)
	{
		head->first = new;
		head->last = new;
		new->prev = head->last;
		new->next = head->first;
	}
	else
	{
		head->last->next = new;
		new->prev = head->last;
		new->next = head->first;
		head->last = new;
		head->first->prev = new;
	}
	head->num++;
	return head;
}

/*
print_list:打印带头节点双向链表中的每一个节点的数据
@head:链表的头结点的地址
返回值:
	无
*/
//双向链表两边应该都可以遍历
void print_list(Head *head) 
{
	if(head == NULL)
	{
		return ; //仅表示函数结束
	}
	Node *p = head->first;
	int num = head->num;
	while(num--)
	{
		printf("%s\n",strrchr(p->photo,'/'));
		p = p->next;
	}
	printf("\n");
}

/*
clear_list:清空链表,释放head指向的链表的所有数据节点
@head:链表的头结点的地址
返回值:
	无
*/
void clear_list(Head *head)
{
	if (head == NULL)
	{
		return;
	}
	Node* del;
	del = head->first;
	while (head->first != NULL)
	{
		head->first = del->next;
		free(del);
		del = head->first;
	}
	head->last = NULL;
	head->num = 0;
}
void destroy_list(Head *head)
{
	clear_list(head);
	free(head);
}