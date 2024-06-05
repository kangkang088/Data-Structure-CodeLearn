#include <stdio.h>
#include <malloc.h>

struct BTNode{
	char data;
	struct BTNode * pLchild;//p是指针，L是左，child是孩子
	struct BTNode * pRchild;
};

struct BTNode * CreateBTree(void);
void PreTraverseBTree(struct BTNode *);
void InTraverseBTree(struct BTNode *);
void PostTraverseBTree(struct BTNode *);

int main(void){
	struct BTNode * pT = CreateBTree();//返回根节点地址，动态构造
	
	PreTraverseBTree(pT);//先序
	InTraverseBTree(pT);//中序
	PostTraverseBTree(pT);//后序
	
	return 0;
}
struct BTNode * CreateBTree(void){
	struct BTNode * pA = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pB = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pC = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pD = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pE = (struct BTNode *)malloc(sizeof(struct BTNode));
	
	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';
	
	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;
	
	return pA;
}
void PreTraverseBTree(struct BTNode * pT){
	//先根再左再右
	if(pT != NULL){
		printf("%c\n",pT->data);
		if(pT->pLchild != NULL){
			PreTraverseBTree(pT->pLchild);
		}
		if(pT->pRchild != NULL){
			PreTraverseBTree(pT->pRchild);
		}
	}
}
void InTraverseBTree(struct BTNode * pT){
	//先左再中再右
	if(pT != NULL){
		if(pT->pLchild != NULL){
			InTraverseBTree(pT->pLchild);
		}
		printf("%c\n",pT->data);
		if(pT->pRchild != NULL){
			InTraverseBTree(pT->pRchild);
		}
	}
}
void PostTraverseBTree(struct BTNode * pT){
	//先左再右再根
		if(pT != NULL){
		if(pT->pLchild != NULL){
			PostTraverseBTree(pT->pLchild);
		}
		if(pT->pRchild != NULL){
			PostTraverseBTree(pT->pRchild);
		}
		printf("%c\n",pT->data);
	}
}