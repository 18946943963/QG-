#include <sort.h>

void InsertSort(int* arr, int n)
{
	int i; 
	for (i = 0; i < n - 1; ++i)
	{
		//��¼�����������һ��Ԫ�ص��±�
		int end = i;
		//�������Ԫ��
		int tem = arr[end + 1];
		//������
		while (end >= 0)
		{
			//�Ȳ��������������
			if (tem < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			//�Ȳ������С������ѭ��
			else
			{
				break;
			}
		}
		//tem�ŵ��Ȳ������С�����ĺ���
		arr[end  + 1] = tem;
		//����ִ�е���λ�����������:
		//1.������Ԫ���ҵ�Ӧ����λ�ã�break����ѭ�����ˣ�
		//2.������Ԫ�رȵ�ǰ���������е�����Ԫ�ض�С��whileѭ�������󵽴ˣ�
	}
}


void merge(int arr[], int start, int mid, int end)
{
	int result[100];
	int k = 0;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end) {		//С������ֵ�������� 
		if (arr[i] < arr[j]){
			result[k++] = arr[i++];
        }
		else{
			result[k++] = arr[j++];
        }
	}
	if (i == mid + 1) {					//����ʣ������ 
		while(j <= end)
			result[k++] = arr[j++];
	}
	if (j == end + 1) {
		while (i <= mid)
			result[k++] = arr[i++];
	}
	for (j = 0, i = start ; j < k; i++, j++) {	//����ԭ���� 
		arr[i] = result[j];
	}
}
void MergeSort(int arr[], int start, int end)
{	 
	if (start >= end)
		return;
	int mid = ( start + end ) / 2;
	MergeSort(arr, start, mid);				//�ݹ� 
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
    while(i != j){							//��һ��� 
        while(arr[j] >= tmp && j > i)
            j--;
        while(arr[i] <= tmp && j > i)
            i++;
        if(j > i){							//���� 
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    arr[begin] = arr[i];					//��������������м� 
    arr[i] = tmp;
    Quick_Sort(arr, begin, i-1);			//�ݹ� 
    Quick_Sort(arr, i+1, end);
}

void CountSort(int* arr, int n)
{
	//�ҵ������е����ֵ����Сֵ
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

	int range = max - min + 1;							//���ٿռ������
	int* countArr = (int*)malloc(sizeof(int)*range);	//���ٿռ�
	//��ʼ������ȫ��Ϊ0
	memset(countArr, 0, sizeof(int)*range);
	//��ʼ����
	for (i = 0; i < n; i++)
	{
		countArr[arr[i]-min]++;
	}

	//��ʼ����
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
	//����Щ��������n��Ԫ�ص����ֵ 
	int maxData = data[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(maxData<data[i])
			maxData=data[i];
	}
	
	//��Щ�����������ֵ��λ���Ƕ��� 
	int d=1;    //d�����������ֵ��λ������Ϊ��Ȼ��һ�������϶�������1λ������d��ʼ��Ϊ1 
	while(maxData>=10)  //�����ֵ����/10������λ�� 
	{
		maxData/=10;
		d++;
	}
	return d;
} 
void radixsort(int data[],int n)  //�������� 
{
	int d = maxBit(data,n);  //������λ��
	int i,j,k;
	int radix = 1;
	for(i=1;i<=d;i++)   //����d������
	{
	    for(j=0;j<10;j++)   //ÿ�η���ǰ��ռ�����
		{
			bucket[j]=0;
		}
		for(j=0;j<n;j++)    //ͳ��ÿ��Ͱ��Ԫ�ظ��� 
		{
			k=(data[j]/radix)%10;
			bucket[k]++;
		}
		
		//����Ͱ��ֵ���ö�Ӧ���±�Ϊdata�����λ�� 
	    for(j = 1; j < 10; j++)
            bucket[j] = bucket[j - 1] + bucket[j]; 
       
       //����õ���д��ȥ 
		for(j = n-1; j>=0; j--) 
        {
            k = (data[j] / radix) % 10;
            temp[bucket[k] - 1] = data[j];
            bucket[k]--;
        }
        for(j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
            data[j] = temp[j];
            
        radix = radix * 10;  //��λ  -�� ʮλ  -����λ -������ 
	} 
}
