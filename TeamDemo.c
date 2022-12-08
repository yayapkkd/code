#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#define SWAP(x, y, t) { (t) = (x) ; (x) = (y) ; (y) = (t);}
#define Songlist_Max 1000

typedef struct
{
	char name[50];
	char singer[50];
	int time;
}songdata;
struct Song * head = NULL;

void random(songdata *s, int sum);
void showallsong(songdata *s, int sum);
void quicksort(songdata *s, int left, int right);
void printlist (songdata *s, int sum);
void readfile (void);
void add (void);
void update(void);

int main(int argc, char *argv[])
{
	FILE* fp;
	songdata songlist[Songlist_Max];
	if (argc < 1)
	{
		fp = stdin;
	}
	else 
	{
		fp = fopen("songlist15.csv", "rt");
		if (!fp) 
		{
			fprintf(stderr, "file %s not found\n", argv[1]);
			exit(1);
		}
	}
	
	char line[100];
    char *songdata = NULL;
    int i,n;
    int sum = 0;
    while(fgets(line,100, fp) != NULL) {
        
        songdata = strtok(line, ",");
        int i = 0;
        while( songdata != NULL ) {
            if(i==0){
            	strcpy(songlist[sum].name,songdata);
            	i++;
            }
            else if(i==1){
                	strcpy(songlist[sum].singer,songdata);
                i++;
            }
            else if(i==2){
				songlist[sum].time = atoi(songdata);
			}
            songdata = strtok(NULL, ",");
        }
        sum++;
        printf("\n");
    }

	for(i = 0 ; i < sum ; i++)
	{ 
    	printf("Song[%3d]: Name:%-30s,Singer:%-30s,Time:%-4d\n", i+1, songlist[i].name, songlist[i].singer, songlist[i].time);
	}
    fclose (fp);
    printf("\n\n"); 
    
    add();
    select_singer();
    //printlist(&songlist, sum);
	//showallsong(&songlist, sum);
	//random(&songlist, sum);
}

void random(songdata *s, int sum) //�H���L 
{
    srand(time(0));
	int i,j,randarr[sum];
	for(i = 0 ; i < sum ; i++)
	{
		do{
			randarr[i] = rand() % sum;
			for(j = 0 ; j < i ; j++)
			{
				if(randarr[i] == randarr[j])
				{
					break;
				}
			}
		} while(j != i);
		printf("Song[%3d]: Name:%-30s,Singer:%-30s,Time:%-4d\n", randarr[i]+1, s[randarr[i]].name, s[randarr[i]].singer, s[randarr[i]].time);	
	}	
}

void showallsong(songdata *s, int sum)
{
	quicksort(s, 0, sum);
	printlist(s, sum);
}

void quicksort(songdata *s, int left, int right)
{
	int i, j, pivot;
	songdata t;
	if (left < right) 
	{
		i = left;
		j = right + 1;
		pivot = s[left].time;
		do 
		{
			do { i++; } while (s[i].time > pivot);
			do { j--; } while (s[j].time < pivot);
			if (i < j) 
			{
				SWAP(s[i], s[j], t);
			}
		} while (i < j);

		SWAP(s[left], s[j], t);
		quicksort(s, left, j - 1);
		quicksort(s, j + 1, right);
	}
}

void readfile (void)
{
	FILE* fp;
	songdata songlist[Songlist_Max];

	fp = fopen("songlist15.csv", "r");
	if (!fp) 
	{
		fprintf(stderr, "file %s not found\n");
		exit(1);
	}
	
	char line[100];
    char *songdata = NULL;
    int i,n;
    int sum = 0;
    while(fgets(line,100, fp) != NULL) {
        
        songdata = strtok(line, ",");
        int i = 0;
        while( songdata != NULL ) {
            if(i==0){
            	strcpy(songlist[sum].name,songdata);
            	i++;
            }
            else if(i==1){
                	strcpy(songlist[sum].singer,songdata);
                i++;
            }
            else if(i==2){
				songlist[sum].time = atoi(songdata);
			}
            songdata = strtok(NULL, ",");
        }
        sum++;
        printf("\n");
    }

	for(i = 0 ; i < sum ; i++)
	{ 
    	printf("Song[%3d]: Name:%-30s,Singer:%-30s,Time:%-4d\n", i+1, songlist[i].name, songlist[i].singer, songlist[i].time);
	}
    fclose (fp);	
}

void printlist (songdata *s, int sum)
{
	int i; 
	for( i = 0 ; i < sum ; i++)
	{
		printf("Song[%3d]: Name:%-30s,Singer:%-30s,Time:%-4d\n", i+1, s[i].name, s[i].singer, s[i].time);
	}	
}

void add()
{
	char data[150];
	int sure;
	printf("�п�J�n�s�W���q����T(�q�W,�q��,�ɶ�����)\n");
    gets(data);
    printf("Are you sure ?? Yes = 1 ; No = 0\n");
    scanf("%d",&sure);
    if(sure != 1)
    {
    	return;
	}
    else
	{
		FILE *fp;
    	fp = fopen("songlist15.csv","a+");
    	if(fp != NULL)
	{
		fputs(data,fp);
	    fprintf(fp,"\n");	
	}       
    	else 
		{
	    	printf("�ɮ׵L�kŪ��");
		}
	fclose(fp);
	printf("Add Success�I\n");
	
	readfile();	
	}
}


void update() {

    printf("�ק�q��\n");
    struct Song * point = head;

    if(point != NULL) {
        printf("�п�J�q�W\n");
        char name [30];//�q�W
        scanf("%s", name);
        while(point != NULL) {
            if(strcmp(name, point) == 0) {
                break;
            }
            point=NULL;//��M�����������̫�@�Ӥ����ɡApoint���w�ܶq����=NULL
        }
        if(point != NULL) {
            printf("�п�J�s�q�W\n");
            scanf("%s", name);
            printf("�п�J�s�@��\n");
            scanf("%s", singer);
            printf("�п�J�s�q��\n");
            scanf("%s", (*point).content);
            printf("�ƾڭק令�\�I\n");
        } else {
            printf("�t�ΨS�����q�W%s���q���A�L�k�ק�I\n", name);
        }
    } else {
        printf("��e�t�ΨS���O�s�q���A�L�k�ק�I\n");
    }
}

	
