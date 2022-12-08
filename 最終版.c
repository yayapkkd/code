#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define MAX_LINE_SIZE 30

typedef struct
{
 	char *id[MAX];   
	char *password[MAX];   
 	int  money;
}dataset;

int a[MAX],count=0,i=0; 
char *b[MAX]; 
char *c[3]={"存款","提款","轉帳"};  
int n,s,v[100],z[100]; 

int password(dataset *list,int len);  
void datadelete(void);
void user_function(dataset *list,int len,int z[]);
void manager_function(dataset *list,int len);
void password_change(dataset *list,int len);
void printfile(dataset *list);
void deletedata(dataset *list);
void addid(dataset *list);
void salarymanage(dataset *list,int len,int z[]);
char* code();   
char* code1();  

dataset list[MAX];  
int len; 
int function; 

int ii;  
int j;   

int main(int argc, const char * argv[]) 
{
	char file_name[] = "atm_data.csv"; 
    dataset list[MAX];  
	len = 0;  
    
    FILE *fp;
    fp = fopen(file_name, "r");
    
    if (!fp)
	{
        fprintf(stderr, "failed to open file for reading\n"); 
        return 1;
    }
    
    char line[MAX_LINE_SIZE];
    char *result = NULL;
    
    while(fgets(line, MAX_LINE_SIZE, fp) != NULL)   
	{
        result = strtok(line, ",");
        int i = 0;
        while( result != NULL ) 
		{
            if(i==0)
			{
            	strcpy(list[len].id,result);
            	printf("ID：%-30s", result);
                i++;
            }
            else if(i==1)
			{
            	strcpy(list[len].password,result);
				printf("password：%-30s", result);
				i++;
            }
            else if(i==2) 
			{
            	list[len].money=atoi(result);
            	printf("money：%-30d", atoi(result)); 
			}
            result = strtok(NULL, ","); 
        }
        len++;  
        printf("\n");
    }
    fclose (fp);
    
	char user[10]; 
    
    char manager[10]="admin"; 
	
    printf("請輸入帳號:");
    fflush(stdin);
    gets(user);
    
    for(ii=0;ii<len;ii++)
	{
		if (strcmp(user,list[ii].id) == 0)
		{
			if(strcmp(user, manager) == 0) 
			{		
				int temp = password(list,ii); 
				if(temp == 1) 
				{
					printf("Successfully logged in as administrator...\n"); 
                	printf("將進入帳號管理模式\n");
                	manager_function(list,len);  
				}
				else 
				break;
            }
			else 
			{	
				int temp = password(list,ii);
				if(temp == 1)
				{
					user_function(list,ii,z);
				}
				else
				break;
			}
		}
	}
	FILE *fptr;   
	fptr=fopen("atm_data.csv","w+");  
	for(i=0;i<len;i++) 
	{
		fprintf(fptr,"%s,%s,%d\n",list[i].id,list[i].password,list[i].money);
	}
	fclose(fptr);
}

int password(dataset *list,int len)
{
	int i;
	int len1 = len; 
	int count=3; 
	char password[10]; 
	
	for(i=0;i<count;i++)   
	{
		printf("請輸入密碼:");
		fflush(stdin); 
		gets(password); 
		if(strcmp(password,list[len1].password) == 0) 
		{
			printf("%s你好,帳戶餘額%-10d\n",list[len1].id,list[len1].money);  
			z[0]=list[len].money;  
			return 1; 
			break; 
		}
		if(i==2)   
		{
			printf("密碼連續輸入錯誤 3 次\n");
			return 2;  
			break; 
		}
	}
}

void manager_function(dataset *list,int len) 
{
	int a1 =0;  
	int len3 = len;
	char user[10];
	
	do{
		printf("請選擇你要使用的帳戶管理: 1修改密碼  2隨機新增或註銷帳戶  3退出程式\n");
		fflush(stdin);
		scanf("%d",&function);
		switch(function)
		{
			case 1:
				if(a1==0) 
				{
					printf("輸入欲修改密碼之帳戶\n");
					fflush(stdin);
    				gets(user);
    			
    				for(ii=0;ii<len3;ii++)
					{
						if (strcmp(user,list[ii].id ) == 0)
						{
							a1=1;
						}		
    				}
					if(a1==1)
					{
						password_change(list,ii-1);  
					}
					else  
    					printf("沒有這個%s使用者，請重新輸入\n",user);
				}
				break;
			case 2:
				printf("請選擇你要使用的帳戶管理: 1隨機新增帳戶  2註銷帳戶  3回上一頁\n");
				fflush(stdin);
				scanf("%d",&function);
				switch(function)
				{
					case 1: 
						addid(list);
						break;
					case 2: 
						deletedata(list);
						break;
					case 3: 
					    break; 
				}
			case 3:  
				break;
		} 
	}while(function != 3); 
}

void user_function(dataset *list,int len,int z[])
{	
	while(function != 3)
	{			
		printf("請選擇: 1款項管理  2修改密碼  3退出程式\n");	
		fflush(stdin);
		scanf("%d",&function);
		switch(function)
		{
			case 1:  
				salarymanage(list,len,z);
				break; 	
			case 2:  
				password_change(list,ii);
				break;
			case 3: 
				break;			
		} 
	}
}

void password_change(dataset *list,int len)
{
	int len2=len;
	
	char new_password_1[MAX]={"1"},new_password_2[MAX]={"0"};

	while(strcmp(new_password_1,new_password_2) != 0)
	{	
		printf("請輸入新密碼\n");
		fflush(stdin);
		gets(new_password_1);
		int temp_len = strlen(new_password_1);  
		if(temp_len > 5 && temp_len < 13)
		{
			fflush(stdin);
			printf("請再次輸入新密碼\n");
			gets(new_password_2);
		
			if(strcmp(new_password_1,new_password_2) == 0)  
			{ 
				strcpy(list[len2].password,new_password_1); 
				printf("修改密碼完成:");
				printf("%s\n",list[len2].password);
				break;
			}
			else
			printf("兩次輸入密碼不同，請重新輸入\n");
		}
		else
		{
			printf("新密碼長度需介於6到12碼間\n");
		}
		
	}
	printf("修改後:\n");
	printf("ID：%-30spassword：%-30smoney：%-30d\n",list[len2].id,list[len2].password,list[len2].money);
	return 0;
}

void salarymanage(dataset *list,int len,int z[])
{
	a[0]=z[0];
	int i=1,m;   
	printf("存款1,提款2,轉帳3,結束4:\n");
	while(s!=-1)  
	{
		printf("請選擇輸入方式及金額(以空格分開),若輸入3則須在下一行輸入轉帳帳號位址:\n");
		scanf("%d",&n);

		if(n==3) 
		{
			scanf("%d",&s);  
			scanf("%d",&m); 
		}
		else if(n==4)
		{
			s=-1;  
			break;
		}
		else 
		{
			scanf("%d",&s); 
		}
		v[i]=s; 
		switch(n)
		{
			case 1: 
				a[i]=a[i-1]+s;  
				b[i]=c[0];  
				break;
			case 2: 
				a[i]=a[i-1]-s;
				b[i]=c[1];
				break;   
			case 3:
				a[i]=a[i-1]-s;
				list[m].money+=v[i]; 
				b[i]=c[2];
				break;
			case 4:  
				break;
		}
		i++;  
		count++;  
	}
	list[len].money=a[count]; 

	for(i=1;i<count+1;i++) 
	{
		printf("%s金額:%d\n",b[i],v[i]);
		printf("%s後餘額:%d\n",b[i],a[i]);
	}
}

void addid(dataset *list)
{
	int ii;
	int addid = 0;
	int a = 0;
	
	for(ii=0;ii<len;ii++)
	{
		if (strcmp(list[ii].id,code()) == 0 ) 
		{
			
			addid = 1;
		}
	}
		if(addid == 0)
		{
			strcpy(list[len].id,code());
   			strcpy(list[len].password,code1());
   			list[len].money = 0;
			len++; 
			a = 1;
			printf("帳號無重複，新增成功\n");
			printf("新增的帳號:\n");
			printf("ID：%-30spassword：%-30smoney：%-30d\n",list[len-1].id,list[len-1].password,list[len-1].money);
        }
        else 
	    {
       		printf("帳號已重複\n");
		} 
}

char* code()
{
	int i;   
	int mark;
	int count = 0;
	char code[20]={};
	int eng; 

	eng=(rand()%25)+65;  
	code[0]=eng;   
	
	srand(time(NULL));  
	for(i=1;i<7;i++)  
    {
		mark=rand()%9;   
		code[i]=mark+48;   
	}
	char* co = code;
	return co;
}

char* code1()
{
	int i;
	int mark;
	int count = 0;
	char code[20]={};  
	int num1;
	int eng;
	int length;

	srand(time(NULL));
	length = rand() % (12 - 6 + 1) + 6; 
	
	for(i=0;i<length;i++)
	{
		mark=rand()%36;
		if(mark>=0&&mark<=9)
		{
			code[i]=mark+48; 
		}
		else
		{
			code[i]=mark+87; 
		}
	}
	char* co = code; 
	return co;
}

void deletedata(dataset *list)
{
	char user2[10];
	char manager[10]="admin";     

	int ii;
	int aa=0;
	
	printf("請輸入帳號:");
    fflush(stdin);
    gets(user2);
	for(ii=0;ii<len;ii++)  
	{
		if (strcmp(user2,list[ii].id ) == 0)
		{
			int j;
			for(j=0;j<len;j++)
			{
				if (strcmp(manager,list[j].id ) == 0) 
				{
					list[j].money += list[ii].money;
				}
			}
			int i;
			for(i=ii;i<=len-2;i++)   
			{
  				strcpy(list[i].id,list[i+1].id);  
            	strcpy(list[i].password,list[i+1].password);
            	list[i].money = list[i+1].money;
			}
			aa=1;
			len--;	
			printfile(list);
			printf("刪除完成。\n");
		}		
	}
	if(aa!=1)
	{
		printf("查無此帳號，請重新開始\n");
	}
}

void printfile(dataset *list)
{
	int i;
	for(i=0;i<len;i++)
	{
    	printf("ID：%-30spassword：%-30smoney：%-30d\n",list[i].id,list[i].password,list[i].money);
	}
}
