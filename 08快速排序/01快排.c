#include <stdio.h>

void QuickSort(int *,int,int);
int FindPos(int *,int,int);

int main(void){
	int a[6] = {2,1,0,5,4,3};
	QuickSort(a,0,5);//第二个参数表示第一个元素的下标。第三个参数表示最后一个元素的下标
	for(int i = 0;i < 6;i++){
		printf("%d  ",a[i]);
	}
	printf("\n");
	return 0;
}
void QuickSort(int * a,int low,int high){
	int pos;
	if(low < high){
		pos = FindPos(a,low,high);
		QuickSort(a,low,pos - 1);
		QuickSort(a,pos + 1,high);
	}
}
int FindPos(int * a,int low,int high){
	int val = a[low];
	while(low < high){
		while(high > low && a[high] >= val){
			high--;
		}
		a[low] = a[high];
		while(low < high && a[low] <= val){
			low++;
		}
		a[high] = a[low];
	}
	a[low] = val;
	return low;
}