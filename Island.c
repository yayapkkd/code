#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	int	start;
	int	end;
}land;

int parent[10000];		 
int Node[10000]={-1};	

void makeSet(int s);
int find(int a);
int unionSet(int i, int ii);
int exist(int node,int cur_size); 
int sum = 0;

int main(int argc, char *argv[])
{
	FILE* fp1;
	land *arr;
	land *ptr;
	
	fp1 = fopen("tinyG.txt","r");
	int a,s;
	
	fscanf(fp1, "%d", &s);
	printf("地圖中有 %d 個節點\n",s);
	
	arr = (land *)malloc(sizeof(land)*(s+1));
	for(a=0;a<s;a++)
	{
		ptr = &(arr[a]);
		fscanf(fp1,"%d %d",&ptr->start, &ptr->end);
	}
	
	
	fclose(fp1);
	for(a= 0 ; a< s ; a++)
	{
		if(exist(arr[a].start,sum) == 0){
			Node[sum] = arr[a].start;
			sum++;
		}
		if(exist(arr[a].end,sum) == 0){
			Node[sum] = arr[a].end;
			sum++;
		}
	}
	makeSet(sum); 
	int island = 0;
	
	for(a = 0 ; a < s ; a++)
	{
		if(unionSet(arr[a].start, arr[a].end)!=0)
		{
			printf("Node[%d] = %d\n",a,Node[a],parent[Node[a]]);	
		}
	}
	
	for (a = 0; a < s; a++)
	{
		if (parent[Node[a]] == Node[a]) 
		{
			island++;
		}
	} 
	printf("\n地圖中有 %d 座小島\n",island);	
}

void makeSet(int s)
{
	int a;
	for(a = 0 ; a< s ; a++){
		parent[Node[a]] = Node[a];
	}
}

int exist(int node, int sum)
{
	int a;
	for(a = 0 ; a< sum + 1 ; a++){
		if(node == Node[a]){
			return 1;
		}	
	}
	return 0;
}

int find(int i)
{
	if (i != parent[i])
	{
		parent[i] = find(parent[i]);
	}
	return parent[i]; 
}

int unionSet(int i, int ii)
{
	int i1, i2;
	i1 = find(i);
	i2 = find(ii);
	if(i1 == i2)
	{
    	return 0;
	}
	else if(i1 > i2)
	{
	    parent[i1] = i2;	
	}
	else
	{
		parent[i2] = i1;
	}
}
