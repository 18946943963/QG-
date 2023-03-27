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
		scanf("%c", &type);													//将要用的数据类型赋给type 
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
	int *p = (int*)malloc(sizeof(int));			//申请内存 
	char s[50] = {'\0'};
	while(1)
	{
		int flag=1;
		gets(s);								//将用户输入的数据放进字符串里 
		if(s[0] == '\n') 
		{
			printf("请输入数据！\n");
			break;
		}
		if(*s == '-')							//如果第一个字符是-表明为负数 
		{
			if(strlen(s) < 6)					//int最多为五位数，所以整个字符串长度不能超过6 
			{
				int i;
				for(i=1; i<6 && s[i]!='\0'; i++)
					if(s[i]<'0' || s[i]>'9');	//检查字符串是不是权威数字 
					{
						flag = 0;
						break;
					}
				if(flag == 1)
				{
					*p = 0;
					for(i=1; i<6 && s[i]!='\0'; i++)	//将各个数×对应的位数 
						*p = (*p)*10 + s[i] - '0';
					(*p) *= -1;							//带上负号 
					*data = (void*)p;
					return;
				}
			}
		}
		else if(strlen(s) < 5)					//int最多为五位数，所以整个字符串长度不能超过5 
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
	float *p = (float*)malloc(sizeof(float));	//申请内存
	*p = 0.0;									//指向一个地方 
	/* 此处可以用类比于上面那个函数和计算器中那个写，但是太长了，所以......靠用户诚实  */ 
	scanf("%f", p);								//获取数据  
	*data = (void*)p;							//转为无类型指针赋给它
	while(getchar() != '\n');
}

void get_char(void **data)
{
	printf("Please give me a char:\n");
	char *p = (char*)malloc(sizeof(char));	//申请内存 
	*p = '0';								//指向一个地方 
	scanf("%c", p);
	while(getchar() != '\n');				//获取数据 
	*data = (void*)(p);						//转为无类型指针赋给它 
}
void show()
{
	LQueue* Q=(LQueue*)malloc(sizeof(LQueue));
	void *data;
	if(type == 'i')								//根据用户需要决定存储的数据类型 
		data = (void*)malloc(sizeof(int));
	else if(type == 'f')
		data = (void*)malloc(sizeof(float));
	else if(type == 'c')
		data = (void*)malloc(sizeof(char));
	void *add_data;
	int flag;									//接收哪个功能 
	int length;
	InitLQueue(Q);
	while(1)
	{
		while(1)
		{
			printf("按回车以继续");
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
			if(flag<1 || flag>7)							//超出范围 
			{
				system("cls");
				printf("Please give me the right number!");
			}
			else
				break;
		}
		switch(flag)
		{
			case(1)://判断是否为空 
				if(IsEmptyLQueue(Q) == TRUE)
					printf("The queue is empty now!You should add something!\n");
				else
					printf("The queue is not empty now.\n");
				break;
			case(2)://获取栈顶元素 
				if(GetHeadLQueue(Q, data) == TRUE);
				else
					printf("The queue is empty now!You should add something!\n");
				break;
			case(3)://入栈 
				if(type == 'i')				//查看储存的数据类型，选择对应的数据类型 
					get_int(&add_data);
				else if(type == 'f')
					get_float(&add_data);
				else
					get_char(&add_data);
				if(EnLQueue(Q, add_data) == TRUE)	//入栈 
					printf("Printf we have add it into the queue!\n");
				else
				{
					printf("The room is full!!!\n");
					exit(-1);
				}
				break;
			case(4)://出栈 
				if(DeLQueue(Q) == TRUE)
					printf("We have get the node out of the queue.\n");
				else
					printf("The queue is empty now!\n");
			case(5)://遍历 
				if(TraverseLQueue(Q, LPrint) == FALSE)
					printf("队列是空的！\n");
				break;
			case(6)://查看链栈长度 
				if((length = LengthLQueue(Q)) != 0)
					printf("The length of the queue is %d.\n", length);
				else
				{
					printf("The queue is empty!!!\n");
				}
				break;
			case(7)://毁栈 
				DestoryLQueue(Q);
				free(Q);
				return;
		}
	}
	
}
