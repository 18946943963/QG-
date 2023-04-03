#include <sort.h> 

int temp[100];
int bucket[10];

void test1(void)
{
	FILE *fp;
	int a, i;
	int num[100] = {0};
	printf("�����뷶Χ��\n1��10000\n2��50000\n3��200000\n");
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
			printf("�������\n");
	}
	if((fp = fopen("./test.txt", "w+"))==NULL)
		printf("�����ļ�ʧ��!\n");
	for(i=0;i<100;i++)							//����100������� 
		fprintf(fp, "%d ", rand()%a+a);
	rewind(fp);
	for(i=0;i<100;i++)							//��ȡ100������� 
		fscanf(fp, "%d", &num[i]);
	fclose(fp);
	for(i=0;i<100;i++)							//����źõ�100������� 
		printf("%d ", num[i]);
	putchar('\n');
	
	puts("�����뺯����\n1������\n2���鲢\n3������\n4������\n5����������\n");
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
			printf("�������\n");
	}
	end = clock();
	int time = end-start;
	printf("start = %d ms\nend = %d ms\ntime = %d\n",start, end, time);
	for(i=0;i<100;i++)							//����źõ�100������� 
		printf("%d ", num[i]);
}

void test2(void)
{
	FILE *fp;
	int num[100] = {0};
	int i, j, a;
		
	puts("�����뺯����\n1������\n2���鲢\n3������\n4������\n5����������\n");
	scanf("%d",&a);
	
	if((fp = fopen("./test.txt", "w+"))==NULL)
		printf("�����ļ�ʧ��!\n");
	
	for(j=1;j<=100*1000;j++)
	{
		for(i=0;i<100;i++)							//����100*100k������� 
		fprintf(fp, "%d ", rand()%100+1);
	}
	clock_t start, end;
	start = clock();
	rewind(fp);
	for(j=1;j<=100*1000;j++)
	{
		for(i=0;i<100;i++)							//��ȡ100������� 
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
			printf("�������\n");
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
	puts("����������ʽ��(����'#'����)\n1����ͬ�Ĵ�����100*100k\n2������С����\n");
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
			puts("��������������룡");
			
	}
	system("pause");
	system("cls");
	if(a == '#')break;
	}while(1);
	return 0;
 } 
