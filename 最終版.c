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
char *c[3]={"�s��","����","��b"};  
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
            	printf("ID�G%-30s", result);
                i++;
            }
            else if(i==1)
			{
            	strcpy(list[len].password,result);
				printf("password�G%-30s", result);
				i++;
            }
            else if(i==2) 
			{
            	list[len].money=atoi(result);
            	printf("money�G%-30d", atoi(result)); 
			}
            result = strtok(NULL, ","); 
        }
        len++;  
        printf("\n");
    }
    fclose (fp);
    
	char user[10]; 
    
    char manager[10]="admin"; 
	
    printf("�п�J�b��:");
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
                	printf("�N�i�J�b���޲z�Ҧ�\n");
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
		printf("�п�J�K�X:");
		fflush(stdin); 
		gets(password); 
		if(strcmp(password,list[len1].password) == 0) 
		{
			printf("%s�A�n,�b��l�B%-10d\n",list[len1].id,list[len1].money);  
			z[0]=list[len].money;  
			return 1; 
			break; 
		}
		if(i==2)   
		{
			printf("�K�X�s���J���~ 3 ��\n");
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
		printf("�п�ܧA�n�ϥΪ��b��޲z: 1�ק�K�X  2�H���s�W�ε��P�b��  3�h�X�{��\n");
		fflush(stdin);
		scanf("%d",&function);
		switch(function)
		{
			case 1:
				if(a1==0) 
				{
					printf("��J���ק�K�X���b��\n");
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
    					printf("�S���o��%s�ϥΪ̡A�Э��s��J\n",user);
				}
				break;
			case 2:
				printf("�п�ܧA�n�ϥΪ��b��޲z: 1�H���s�W�b��  2���P�b��  3�^�W�@��\n");
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
		printf("�п��: 1�ڶ��޲z  2�ק�K�X  3�h�X�{��\n");	
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
		printf("�п�J�s�K�X\n");
		fflush(stdin);
		gets(new_password_1);
		int temp_len = strlen(new_password_1);  
		if(temp_len > 5 && temp_len < 13)
		{
			fflush(stdin);
			printf("�ЦA����J�s�K�X\n");
			gets(new_password_2);
		
			if(strcmp(new_password_1,new_password_2) == 0)  
			{ 
				strcpy(list[len2].password,new_password_1); 
				printf("�ק�K�X����:");
				printf("%s\n",list[len2].password);
				break;
			}
			else
			printf("�⦸��J�K�X���P�A�Э��s��J\n");
		}
		else
		{
			printf("�s�K�X���׻ݤ���6��12�X��\n");
		}
		
	}
	printf("�ק��:\n");
	printf("ID�G%-30spassword�G%-30smoney�G%-30d\n",list[len2].id,list[len2].password,list[len2].money);
	return 0;
}

void salarymanage(dataset *list,int len,int z[])
{
	a[0]=z[0];
	int i=1,m;   
	printf("�s��1,����2,��b3,����4:\n");
	while(s!=-1)  
	{
		printf("�п�ܿ�J�覡�Ϊ��B(�H�Ů���}),�Y��J3�h���b�U�@���J��b�b����}:\n");
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
		printf("%s���B:%d\n",b[i],v[i]);
		printf("%s��l�B:%d\n",b[i],a[i]);
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
			printf("�b���L���ơA�s�W���\\n");
			printf("�s�W���b��:\n");
			printf("ID�G%-30spassword�G%-30smoney�G%-30d\n",list[len-1].id,list[len-1].password,list[len-1].money);
        }
        else 
	    {
       		printf("�b���w����\n");
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
	
	printf("�п�J�b��:");
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
			printf("�R�������C\n");
		}		
	}
	if(aa!=1)
	{
		printf("�d�L���b���A�Э��s�}�l\n");
	}
}

void printfile(dataset *list)
{
	int i;
	for(i=0;i<len;i++)
	{
    	printf("ID�G%-30spassword�G%-30smoney�G%-30d\n",list[i].id,list[i].password,list[i].money);
	}
}
