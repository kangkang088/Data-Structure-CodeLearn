#include <stdio.h>
#include <malloc.h>//包含malloc函数
#include <stdbool.h>//包含bool定义
#include <stdlib.h>//包含exit函数

struct Arr{
	int * pBase;//数组第一个元素的地址
	int len;//数组所能容纳的最大元素的个数
	int count;//当前数组的有效元素个数
	//int increment;//自动增长因子
};
void init_arr(struct Arr *,int);//初始化数组
bool append_arr(struct Arr*,int);//追加元素
bool insert_arr(struct Arr*,int,int);//添加元素
bool delete_arr(struct Arr*,int,int*);//删除元素
int get();//得到值
bool is_Empty(struct Arr*);//是否为空
bool is_Full(struct Arr*);//是否为满
void sort_arr(struct Arr*);//排序元素
void show_arr(struct Arr*);//打印元素
void inversion_arr(struct Arr*);//倒置元素

int main(void){
	struct Arr arr;
	int val;
	init_arr(&arr,6);
	
	/*append_arr(&arr,1);
	append_arr(&arr,2);
	append_arr(&arr,3);
	append_arr(&arr,4);
	append_arr(&arr,5);
	insert_arr(&arr,6,99);//插入成功
	insert_arr(&arr,1,88);//插入失败
	*/
	
	//append_arr(&arr,6);
	/*if(append_arr(&arr,7)){
		printf("追加成功！\n");
	}
	else{
		printf("追加失败\n");
	}*/
	append_arr(&arr,1);
	append_arr(&arr,2);
	append_arr(&arr,3);
	append_arr(&arr,4);
	append_arr(&arr,5);
	append_arr(&arr,6);
	/*
	if(delete_arr(&arr,1,&val)){
		printf("删除成功\n");
		printf("删除的元素是：%d\n",val);
	}*/
	
	//inversion_arr(&arr);
	
	sort_arr(&arr);
	
	show_arr(&arr);
	//printf("%d\n",arr.len);
}
void init_arr(struct Arr * pArr,int length){
	pArr->pBase = (int*)malloc(sizeof(int) * length);
	if(NULL == pArr->pBase){
		printf("动态内存分配失败！\n");
		exit(-1);//终止整个程序
	}
	else{
		pArr->len = length;
		pArr->count = 0;
	}
	return;
	
}
bool is_Empty(struct Arr* pArr){
	if(pArr->count == 0){
		return true;
	}
	return false;
}
void show_arr(struct Arr* pArr){
	if(is_Empty(pArr)){
		printf("数组为空!\n");
		return;
	}
	for(int i = 0;i < pArr->count;i++){
		printf("%d ",(pArr->pBase)[i]);
	}
	printf("\n");
	return;
}
bool append_arr(struct Arr* pArr,int val){
	if(is_Full(pArr)){
		printf("数组已满！\n");
		return false;
	}
	pArr->pBase[pArr->count] = val;
	(pArr->count)++;
	return true;
}
bool is_Full(struct Arr* pArr){
	if(pArr->len == pArr->count){
		return true;
	}
	if(pArr->len > pArr->count){
		return false;
	}
}
//第pos个位置处插入指定元素。对应下标pos-1。
bool insert_arr(struct Arr* pArr,int pos,int val){
	//数组满了，不能插
	if(is_Full(pArr)){
		return false;
	}
	//数组没满，且插的位置小于1（对应【0】）不能插。
	//数组没满，且插的位置越过了最后一个有效数的后一位，不能插（因为连续）
	if(pos < 1 || pos > pArr->count + 1){
		return false;
	}
	for(int i = pArr->count - 1;i >= pos - 1;i--){
		pArr->pBase[i + 1] = pArr->pBase[i];
	}
	pArr->pBase[pos - 1] = val;
	pArr->count++;
	return true;
}
bool delete_arr(struct Arr* pArr,int pos,int * pVal){
	if(is_Empty(pArr)){
		return false;
	}
	if(pos < 1 || pos > pArr->count){
		return false;
	}
	*pVal = pArr->pBase[pos - 1];//将删除的元素值返回主函数记录
	for(int i = pos;i < pArr->count;i++){
		pArr->pBase[i - 1] = pArr->pBase[i];
	}
	pArr->count--;
	return true;
}
void inversion_arr(struct Arr* pArr){
	/*for(int i = 0,j = pArr->count - 1;i < j;i++,j--){
		int temp = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = temp;
	}*/
	int i = 0;
	int j = pArr->count - 1;
	int temp = 0;
	while(i < j){
		temp = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = temp;
		i++;
		j--;
	}
	return;
}
void sort_arr(struct Arr* pArr){
	int temp;
	for(int i = 0;i < pArr->count - 1;i++){
		for(int j = 0;j < pArr->count - i- 1;j++){
			//降序
			if(pArr->pBase[j] < pArr->pBase[j+1]){
				temp = pArr->pBase[j];
				pArr->pBase[j] = pArr->pBase[j + 1];
				pArr->pBase[j + 1] = temp;
			}
		}
	}
}