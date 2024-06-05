#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Queue{
	int * pBase;
	int front;
	int rear;	
}QUEUE;

void init(QUEUE *);
bool en_queue(QUEUE *,int);
void traverse_queue(QUEUE * );
bool full_queue(QUEUE *);
bool out_queue(QUEUE *,int *);
bool empty_queue(QUEUE *);

int main(void){
	QUEUE q;
	int val;
	init(&q);
	en_queue(&q,1);
	en_queue(&q,2);
	en_queue(&q,3);
	en_queue(&q,4);
	en_queue(&q,5);
	en_queue(&q,6);
	en_queue(&q,7);
	en_queue(&q,8);
	
	traverse_queue(&q);
	if(out_queue(&q,&val)){
		printf("出队成功！出队元素：%d\n",val);
	}
	traverse_queue(&q);
	return 0;
}
void init(QUEUE * pQ){
	pQ->pBase = (int *)malloc(sizeof(int) * 6);
	pQ->front = 0;
	pQ->rear = 0;
	return;
}
bool en_queue(QUEUE * pQ,int val){
	if(full_queue(pQ)){
		return false;
	}
	pQ->pBase[pQ->rear] = val;
	pQ->rear = (pQ->rear + 1) % 6;
	
	return true;
}
bool full_queue(QUEUE * pQ){
	if((pQ->rear + 1) % 6 == pQ->front){
		return true;
	}
	return false;
}
void traverse_queue(QUEUE * pQ){
	int i = pQ->front;
	while(i != pQ->rear){
		printf("%d\n",pQ->pBase[i]);
		i = (i + 1) % 6;
	}
	return;
}
bool out_queue(QUEUE * pQ,int * pVal){
	if(empty_queue(pQ)){
		return false;
	}
	*pVal = pQ->pBase[pQ->front];
	pQ->front = (pQ->front + 1) % 6;
	return true;
}
bool empty_queue(QUEUE * pQ){
	if(pQ->front == pQ->rear){
		return true;
	}
	return false;
}