#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int data;
	struct Node * pNext;
}NODE,* PNODE;//NODE == struct Node。PNODE == struct Node * 。

PNODE create_list();
void traverse_list(PNODE);
bool is_Empty(PNODE);
int length_list(PNODE);
bool insert_list(PNODE,int,int);
bool delete_list(PNODE,int,int*);
void sort_list(PNODE);

int main(void){
	PNODE pHead = NULL;
	int val;//插入的值
	int dVal;//删除的值
	pHead = create_list();//创建非循环单链表,将该链表的头结点地址赋值给pHead
	sort_list(pHead);
	insert_list(pHead,1,288);
	delete_list(pHead,4,&dVal);
	traverse_list(pHead);//打印链表数据
	int length = length_list(pHead);
	
	printf("%d\n",length);
	return 0;
}
PNODE create_list(){
	int len;
	int val;
	//头结点，不存放有效数据
	PNODE pHead = (PNODE)malloc(sizeof(NODE));//头结点
	if(pHead == NULL){
		printf("内存分配失败！\n");
		exit(-1);
	}
	printf("请输入您需要生成的链表的结点个数：\n");
	scanf("%d",&len);
	
	//一个时刻指向尾结点的指针
	PNODE pTail = pHead;
	pTail->pNext = NULL;//解决用户输入0的情况
	
	for(int i = 0;i < len;i++){
		
		printf("请输入第%d个结点的值：",i+1);
		scanf("%d",&val);
		
		//有效结点
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		
		if(pNew == NULL){
			printf("内存分配失败！\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}
void traverse_list(PNODE pHead){
	/*while(pHead->pNext != NULL){
		printf("%d\n",(pHead->pNext)->data);
		pHead = pHead->pNext;
	}
	printf("\n");*/
	
	PNODE p = pHead->pNext;
	while(p != NULL){
		printf("%d\n",p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}
bool is_Empty(PNODE pHead){
	if(pHead->pNext == NULL){
		return true;
	}
	return false;
}
int length_list(PNODE pHead){
	PNODE p = pHead->pNext;
	int count = 0;
	while(p != NULL){
		count++;
		p = p->pNext;
	}
	printf("\n");
	return count;
}
void sort_list(PNODE pHead){
	PNODE p;
	PNODE q;
	int i = 0;
	int j = 0;
	int count = length_list(pHead);
	for(i = 0,p = pHead->pNext;i < count - 1;i++,p = p->pNext){
		for(j = 0,q = p->pNext;j < count - 1 - i;j++,q = q->pNext){
			if(p->data > q->data){
				int t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}	
	}
}
//pHead指向的链表的第pos个位置上插入一个值
bool insert_list(PNODE pHead,int pos,int val){
	int i = 0;
	PNODE p = pHead;
	//得到插入位置的前一个位置的结点，为了获取插入的pos位置上的地址
	while(p != NULL && i < pos - 1){
		p = p->pNext;
		++i;
	}
	//解释i>pos-1是如何排除pos非法值的
	//i一定是根据while和pos得出来的pos-1。
	//如果i>pos-1说明不正常，要是走while了，i必定会正常。不正常就说明i没有走while得出来i = pos-1。
	//i不走while的情况就是pos小于1，因为i是从0开始的，判断条件是i<pos-1。
	//等价于if(pos < 1)
	if(i > pos - 1 || p == NULL){
		return false;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(pNew == NULL){
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;
	return true;
}
bool delete_list(PNODE pHead,int pos,int * pVal){
	int i = 0;
	PNODE p = pHead;
	//得到删除位置的前一个位置的结点，为了获取插入的pos位置上的地址
	while(p != NULL && i < pos - 1){
		p = p->pNext;
		++i;
	}
	//pos小于1就会false。至少等于1
	if(i > pos - 1 || p == NULL){
		return false;
	}
	PNODE q = p->pNext;
	*pVal = q->data;
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;
}