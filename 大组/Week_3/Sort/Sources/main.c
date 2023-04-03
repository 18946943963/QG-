#include <sort.h> 

int temp[100];
int bucket[10];

void test1(void)
{
	FILE *fp;
	int a, i;
	int num[100] = {0};
	printf("请输入范围：\n1、10000\n2、50000\n3、200000\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			a = 10000;
			break;
		case 2:
			a = 50000;
			break;
		case 3:
			a = 200000;
			break;
		default:
			printf("输入错误！\n");
	}
	if((fp = fopen("./test.txt", "w+"))==NULL)
		printf("创建文件失败!\n");
	for(i=0;i<100;i++)							//创建100个随机数 
		fprintf(fp, "%d ", rand()%a+a);
	rewind(fp);
	for(i=0;i<100;i++)							//读取100个随机数 
		fscanf(fp, "%d", &num[i]);
	fclose(fp);
	for(i=0;i<100;i++)							//输出排好的100个随机数 
		printf("%d ", num[i]);
	putchar('\n');
	
	puts("请输入函数：\n1、插入\n2、归并\n3、快排\n4、计数\n5、基数计数\n");
	scanf("%d",&a);
	
	clock_t start, end;
	start = clock();
	
	switch(a)
	{
		case 1:
			InsertSort(num, 100);
			break;
		case 2:
			MergeSort(num, 0, 99);
			break;
		case 3:
			Quick_Sort(num, 0, 99);
			break;
		case 4:
			CountSort(num, 100);
			break;
		case 5:
			radixsort(num,100);
			break;
		default:
			printf("输入错误！\n");
	}
	end = clock();
	int time = end-start;
	printf("start = %d ms\nend = %d ms\ntime = %d\n",start, end, time);
	for(i=0;i<100;i++)							//输出排好的100个随机数 
		printf("%d ", num[i]);
}

void test2(void)
{
	FILE *fp;
	int num[100] = {0};
	int i, j, a;
		
	puts("请输入函数：\n1、插入\n2、归并\n3、快排\n4、计数\n5、基数计数\n");
	scanf("%d",&a);
	
	if((fp = fopen("./test.txt", "w+"))==NULL)
		printf("创建文件失败!\n");
	
	for(j=1;j<=100*1000;j++)
	{
		for(i=0;i<100;i++)							//创建100*100k个随机数 
		fprintf(fp, "%d ", rand()%100+1);
	}
	clock_t start, end;
	start = clock();
	rewind(fp);
	for(j=1;j<=100*1000;j++)
	{
		for(i=0;i<100;i++)							//读取100个随机数 
		fscanf(fp, "%d", &num[i]);
		
		switch(a)
	{
		case 1:
			InsertSort(num, 100);
			break;
		case 2:
			MergeSort(num, 0, 99);
			break;
		case 3:
			Quick_Sort(num, 0, 99);
			break;
		case 4:
			CountSort(num, 100);
			break;
		case 5:
			radixsort(num,100);
			break;
		default:
			printf("输入错误！\n");
			return;
	}
	}
	end = clock();
	int time = end-start;
	printf("start = %d ms\nend = %d ms\ntime = %d\n",start, end, time);
}

int main()
{
	char a;
	do
	{
	fflush(stdin);
	puts("请输入排序方式：(输入'#'结束)\n1、不同的大数据100*100k\n2、大量小数据\n");
	a = getchar();
	fflush(stdin);
	switch(a)
	{
		case '1':
			test1();
			break;
		case '2':
			test2();
			break;
		case '#':
			break; 
		default:
			puts("输入错误重新输入！");
			
	}
	system("pause");
	system("cls");
	if(a == '#')break;
	}while(1);
	return 0;
 } 
