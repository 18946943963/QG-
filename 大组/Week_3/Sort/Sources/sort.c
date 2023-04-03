#include <sort.h>

void InsertSort(int* arr, int n)
{
	int i; 
	for (i = 0; i < n - 1; ++i)
	{
		//记录有序序列最后一个元素的下标
		int end = i;
		//待插入的元素
		int tem = arr[end + 1];
		//单趟排
		while (end >= 0)
		{
			//比插入的数大就向后移
			if (tem < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			//比插入的数小，跳出循环
			else
			{
				break;
			}
		}
		//tem放到比插入的数小的数的后面
		arr[end  + 1] = tem;
		//代码执行到此位置有两种情况:
		//1.待插入元素找到应插入位置（break跳出循环到此）
		//2.待插入元素比当前有序序列中的所有元素都小（while循环结束后到此）
	}
}


void merge(int arr[], int start, int mid, int end)
{
	int result[100];
	int k = 0;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end) {		//小的数赋值到新数组 
		if (arr[i] < arr[j]){
			result[k++] = arr[i++];
        }
		else{
			result[k++] = arr[j++];
        }
	}
	if (i == mid + 1) {					//处理剩余数据 
		while(j <= end)
			result[k++] = arr[j++];
	}
	if (j == end + 1) {
		while (i <= mid)
			result[k++] = arr[i++];
	}
	for (j = 0, i = start ; j < k; i++, j++) {	//赋给原数组 
		arr[i] = result[j];
	}
}
void MergeSort(int arr[], int start, int end)
{	 
	if (start >= end)
		return;
	int mid = ( start + end ) / 2;
	MergeSort(arr, start, mid);				//递归 
	MergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}

void Quick_Sort(int *arr, int begin, int end)
{
    if(begin > end)
        return;
    int tmp = arr[begin];
    int i = begin;
    int j = end;
    while(i != j){							//逐一检查 
        while(arr[j] >= tmp && j > i)
            j--;
        while(arr[i] <= tmp && j > i)
            i++;
        if(j > i){							//调换 
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    arr[begin] = arr[i];					//将最初的数赋给中间 
    arr[i] = tmp;
    Quick_Sort(arr, begin, i-1);			//递归 
    Quick_Sort(arr, i+1, end);
}

void CountSort(int* arr, int n)
{
	//找到序列中的最大值和最小值
	int i;
	int max = arr[0];
	int min = arr[0];
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	int range = max - min + 1;							//开辟空间的数量
	int* countArr = (int*)malloc(sizeof(int)*range);	//开辟空间
	//初始化数组全部为0
	memset(countArr, 0, sizeof(int)*range);
	//开始计数
	for (i = 0; i < n; i++)
	{
		countArr[arr[i]-min]++;
	}

	//开始排序
	int j = 0;
	for (i = 0; i < range; i++)
	{
		while (countArr[i]--)
		{
			arr[j] = i + min;
			j++;
		}
	}
	free(countArr);
}

int maxBit(int data[],int n)
{
	//行这些代码在求n个元素的最大值 
	int maxData = data[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(maxData<data[i])
			maxData=data[i];
	}
	
	//这些代码在求最大值的位数是多少 
	int d=1;    //d用来计数最大值的位数，因为既然是一个数，肯定至少有1位，所以d初始化为1 
	while(maxData>=10)  //将最大值不断/10，计算位数 
	{
		maxData/=10;
		d++;
	}
	return d;
} 
void radixsort(int data[],int n)  //基数排序 
{
	int d = maxBit(data,n);  //求出最大位数
	int i,j,k;
	int radix = 1;
	for(i=1;i<=d;i++)   //进行d次排序
	{
	    for(j=0;j<10;j++)   //每次分配前清空计数器
		{
			bucket[j]=0;
		}
		for(j=0;j<n;j++)    //统计每个桶的元素个数 
		{
			k=(data[j]/radix)%10;
			bucket[k]++;
		}
		
		//重置桶的值，让对应的下标为data数组的位置 
	    for(j = 1; j < 10; j++)
            bucket[j] = bucket[j - 1] + bucket[j]; 
       
       //排序好的数写回去 
		for(j = n-1; j>=0; j--) 
        {
            k = (data[j] / radix) % 10;
            temp[bucket[k] - 1] = data[j];
            bucket[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = temp[j];
            
        radix = radix * 10;  //个位  -》 十位  -》百位 -》…… 
	} 
}
