#include <stdio.h>

void hannuota(int n,char A,char B,char C){
	if(n == 1){
		//printf("将编号为%d的盘子从柱子%c移到柱子%c\n",n,A,C);
	}
	else{
		hannuota(n-1,A,C,B);
		//printf("将编号为%d的盘子从柱子%c移到柱子%c\n",n,A,C);
		hannuota(n-1,B,A,C);
	}
}

int main(void){
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;
	printf("请输入要移动的盘子个数：");
	scanf("%d",&n);
	
	hannuota(n,'A','B','C');
}