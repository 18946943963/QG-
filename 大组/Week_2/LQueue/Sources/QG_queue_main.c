#include"LQueue.h"

void get_type();
void get_int(void **data);
void get_float(void **data);
void get_char(void **data);
void show();

int main()
{
	get_type();
	show();
	return 0;
}

void LPrint(void *q);
void get_type()
{
	while(1)
	{
		type = '\0';
		printf("Please give me what kind of the data you want to keep:\n");
		printf("'i' means int, 'f' means float while 'c' means char!\n");
		scanf("%c", &type);													//��Ҫ�õ��������͸���type 
		while(getchar() != '\n');
		if(type=='i' || type=='f' || type=='c')
			break;
		else
		{
			system("cls");
			printf("Please don't give me others!\n");
		}
	}
}
void get_data(void **data)
{
	if(type == 'i')
		get_int(data);
	else if(type == 'f')
		get_float(data);
	else if(type == 'c')
		get_char(data);
}

void get_int(void **data)
{
	printf("Please give me a int number:\n");
	int *p = (int*)malloc(sizeof(int));			//�����ڴ� 
	char s[50] = {'\0'};
	while(1)
	{
		int flag=1;
		gets(s);								//���û���������ݷŽ��ַ����� 
		if(s[0] == '\n') 
		{
			printf("���������ݣ�\n");
			break;
		}
		if(*s == '-')							//�����һ���ַ���-����Ϊ���� 
		{
			if(strlen(s) < 6)					//int���Ϊ��λ�������������ַ������Ȳ��ܳ���6 
			{
				int i;
				for(i=1; i<6 && s[i]!='\0'; i++)
					if(s[i]<'0' || s[i]>'9');	//����ַ����ǲ���Ȩ������ 
					{
						flag = 0;
						break;
					}
				if(flag == 1)
				{
					*p = 0;
					for(i=1; i<6 && s[i]!='\0'; i++)	//������������Ӧ��λ�� 
						*p = (*p)*10 + s[i] - '0';
					(*p) *= -1;							//���ϸ��� 
					*data = (void*)p;
					return;
				}
			}
		}
		else if(strlen(s) < 5)					//int���Ϊ��λ�������������ַ������Ȳ��ܳ���5 
		{
			int i;
			for(i=0; i<5 && s[i]!='\0'; i++)
				if(s[i]<'0' || s[i]>'9')
				{
					flag = 0;
					break;
				}
			if(flag == 1)
			{
				*p = 0;
				for(i=0; i<5 && s[i]!='\0'; i++)
					*p = (*p)*10 + s[i] - '0';
				*data = (void*)p;
				return;
			}
		}
		printf("Please give me a right int number which is bigger than -10000 and smaller than 10000;\n");
	}	
}

void get_float(void **data)
{
	printf("Please give me a float number:\n");
	float *p = (float*)malloc(sizeof(float));	//�����ڴ�
	*p = 0.0;									//ָ��һ���ط� 
	/* �˴�����������������Ǹ������ͼ��������Ǹ�д������̫���ˣ�����......���û���ʵ  */ 
	scanf("%f", p);								//��ȡ����  
	*data = (void*)p;							//תΪ������ָ�븳����
	while(getchar() != '\n');
}

void get_char(void **data)
{
	printf("Please give me a char:\n");
	char *p = (char*)malloc(sizeof(char));	//�����ڴ� 
	*p = '0';								//ָ��һ���ط� 
	scanf("%c", p);
	while(getchar() != '\n');				//��ȡ���� 
	*data = (void*)(p);						//תΪ������ָ�븳���� 
}
void show()
{
	LQueue* Q=(LQueue*)malloc(sizeof(LQueue));
	void *data;
	if(type == 'i')								//�����û���Ҫ�����洢���������� 
		data = (void*)malloc(sizeof(int));
	else if(type == 'f')
		data = (void*)malloc(sizeof(float));
	else if(type == 'c')
		data = (void*)malloc(sizeof(char));
	void *add_data;
	int flag;									//�����ĸ����� 
	int length;
	InitLQueue(Q);
	while(1)
	{
		while(1)
		{
			printf("���س��Լ���");
			fflush(stdin);
			getchar();
			system("cls");
			flag = 0;
			printf("You can do these function:\n");
			printf("1.Check whether the queue is empty or not;\n");
			printf("2.Get the number of the queue head;\n");
			printf("3.Add a number into the queue;\n");
			printf("4.Get a number out of the queue;\n");
			printf("5.Read all the node of the queue;\n");
			printf("6.Get the length of the queue;\n");
			printf("7.Delete the queue and quit;\n");
			printf("Now please give me the number to finish the function:\n");
			scanf("%d", &flag);
			while(getchar() != '\n');
			if(flag<1 || flag>7)							//������Χ 
			{
				system("cls");
				printf("Please give me the right number!");
			}
			else
				break;
		}
		switch(flag)
		{
			case(1)://�ж��Ƿ�Ϊ�� 
				if(IsEmptyLQueue(Q) == TRUE)
					printf("The queue is empty now!You should add something!\n");
				else
					printf("The queue is not empty now.\n");
				break;
			case(2)://��ȡջ��Ԫ�� 
				if(GetHeadLQueue(Q, data) == TRUE);
				else
					printf("The queue is empty now!You should add something!\n");
				break;
			case(3)://��ջ 
				if(type == 'i')				//�鿴������������ͣ�ѡ���Ӧ���������� 
					get_int(&add_data);
				else if(type == 'f')
					get_float(&add_data);
				else
					get_char(&add_data);
				if(EnLQueue(Q, add_data) == TRUE)	//��ջ 
					printf("Printf we have add it into the queue!\n");
				else
				{
					printf("The room is full!!!\n");
					exit(-1);
				}
				break;
			case(4)://��ջ 
				if(DeLQueue(Q) == TRUE)
					printf("We have get the node out of the queue.\n");
				else
					printf("The queue is empty now!\n");
			case(5)://���� 
				if(TraverseLQueue(Q, LPrint) == FALSE)
					printf("�����ǿյģ�\n");
				break;
			case(6)://�鿴��ջ���� 
				if((length = LengthLQueue(Q)) != 0)
					printf("The length of the queue is %d.\n", length);
				else
				{
					printf("The queue is empty!!!\n");
				}
				break;
			case(7)://��ջ 
				DestoryLQueue(Q);
				free(Q);
				return;
		}
	}
	
}
