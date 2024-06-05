#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int data;
	struct Node * pNext;
}NODE,* PNODE;
typedef struct Stack{
	PNODE pTop;
	PNODE pBottom;
}STACK,* PSTACK;

void init(PSTACK);
void push(PSTACK,int);
bool pop(PSTACK,int*);
void traverse(PSTACK);
bool is_Empty(PSTACK);
void clear(PSTACK);
//void destroy(PSTACK);

int main(void){
	STACK s;
	int val;
	init(&s);
	push(&s,1);
	push(&s,2);
	push(&s,3);
	traverse(&s);
	if(pop(&s,&val)){
		printf("出栈成功！值为：%d\n",val);
	}
	traverse(&s);
	clear(&s);
	traverse(&s);
	return 0;
}
void init(PSTACK pS){
	//初始化头结点，构造出来栈(没有元素)。
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if(pS->pTop == NULL){
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	pS->pBottom = pS->pTop;
	pS->pBottom->pNext = NULL;
}
void push(PSTACK pS,int val){
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
	
	return;
}
void traverse(PSTACK pS){
	PNODE p = pS->pTop;
	if(pS->pBottom == pS->pTop){
		printf("空栈！\n");
		return;
	}
	while(p != pS->pBottom){
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
	
}
bool is_Empty(PSTACK pS){
	if(pS->pBottom == pS->pTop)
		return true;
	return false;
}
bool pop(PSTACK pS,int * pVal){
	if(is_Empty(pS)){
		return false;
	}
	PNODE r = pS->pTop;
	pS->pTop = r->pNext;
	*pVal = r->data;
	free(r);
	r = NULL;
	return true;
}
void clear(PSTACK pS){
	if(is_Empty(pS)){
		return;
	}
	
	/*while(pS->pTop != pS->pBottom){
		PNODE r = pS->pTop;
		pS->pTop = r->pNext;
		free(r);
		r = NULL;
	}*/
	
	PNODE p = pS->pTop;
	PNODE q;
	while(p != pS->pBottom){
		q = p->pNext;
		free(p);
		p = q;
	}
	pS->pBottom = pS->pTop;
}
/*void destroy(PSTACK pS){
	while(pS->pTop != pS->pBottom){
		PNODE p = pS->pTop;
		pS->pTop = p->pNext;
		free(p);
	}
	free(pS->pBottom);
}*/