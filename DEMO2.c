 /*演算法
KRUSKAL流程 

begin
	begin T包含少於n-1個邊&&E非空  loop
	 	從E中選成本最小的邊 
	  	if 放入T中不會形成迴路 then
	 		 加入 
	 	else 
			捨棄
	end
end	
 	
*完成 union find 兩個函式
*將heapSort改寫成quick sort 
*/

#include<stdio.h>
#include<stdlib.h>
#define SWAP(x, y, t) { (t) = (x) ; (x) = (y) ; (y) = (t);}


typedef struct
{
	int	start;
	int	end;
	int	cost;
}mst;

int parent[1000];// 初始化
void makeSet(int size);
int find(int v);
int unionSet(int v, int u);
void heapSort(mst *e, int n);
void adjust(mst *e, int root, int n);
void quickSort(mst *e, int left, int right);//快速排序 

int main(int argc, char *argv[])
{
	int i, n, m, sum = 0, count = 0, set_num = 0;
	mst *e;
	mst *ptr;
	FILE* fin;
	
	if (argc < 1)
	{
		fin = stdin;
	}
	int data;
	printf("Enter the data number you want to do：");
	scanf("%d",&data);
	if(data == 1)
	{
		fin = fopen("g1.txt", "rt");
		if (fin == NULL) 
		{
			printf("file %s is not found\n", argv[1]);
			return 1;
		}
	}
	else if(data == 2)
	{
		fin = fopen("g2.txt","rt");
		if (fin == NULL) 
		{
			printf("file %s is not found\n", argv[1]);
			return 1;
		}
	}
	else if(data == 3)
	{ 
		fin = fopen("g3.txt","rt");
		if (fin == NULL) 
		{
			printf("file %s is not found\n", argv[1]);
			return 1;
		}
	}
	else
	{
		printf("file %d is not found\n", data);
		return 0;
	}
	fscanf(fin, "%d, %d", &n, &m);
	printf("nodes = %3d, edges = %3d\n", n, m);
	
	e = (mst *)malloc(sizeof(mst)*m);
	for (i = 0; i < m; i++)
	{
		ptr = &(e[i]);
		fscanf(fin, "%d, %d, %d", &ptr->start, &ptr->end, &ptr->cost);//完成輸入start end cost
		printf("edge[%3d]: start = %3d, end = %3d, cost = %3d\n", i+1, ptr->start, ptr->end, ptr->cost);//完成印出start end cost
	}
	
	fclose(fin);
	makeSet(n);
	quickSort(e,0,m); 
	puts("排序後");
	
	for (i = 0; i < m; i++)
	{
		printf("edge[%3d]: start = %3d, end = %3d, cost = %3d\n", i+1, e[i].start, e[i].end, e[i].cost);
	}
	
	puts("");
	puts("MST...成長中");
	
	for (i = m-1; i >= 0; i--)
	{
		
		if (count == n - 1)
		{
			break;
		}
	
		if (unionSet(e[i].start, e[i].end))
		{//完成此判斷 (檢查是否為迴路) 
			count++; 
			sum = sum + e[i].cost;
			printf("[%3d] start = %3d, end = %3d, cost = %3d\n", i+1, e[i].start, e[i].end, e[i].cost);
		}
	}
 
	for (i = 0; i < n; i++)
	{
		if (parent[i] == i)
		{
			set_num++;
		}
	}
	
	if (set_num > 1)
	{
		puts("");
		puts("沒有生成樹");
	}
	else
	{
		puts("");
		printf("總成本:%d\n", sum);
	} 
	
	free(e);
	return 0;
}


void makeSet(int size)//初始化集合 
{ 
	int i;
	for(i = 0; i < size; i++) 
	{
		parent[i] = i;
	}
}


//將此排序改寫成快速排序
void heapSort(mst *e, int n)
{
    mst temp;
    int i;

    for(i = n/2 ; i >= 1 ; i--)
    {
        adjust(e, i, n);
    }
        
    for(i = n-1 ; i > 0 ; i--)
    {
       SWAP(e[1], e[i+1], temp);
       adjust(e, 1, i);
    }
}
void adjust(mst *e, int root, int n)
{

   int s;
   s = 2 * root;
   mst temp;
   while(s <= n)
   {  
     if(s < n && e[s+1].cost < e[s].cost)
        s++;
        
     if(e[root].cost <= e[s].cost)
        break;
        
     SWAP(e[root], e[s], temp);
     
     root = s;
     s = 2 * root;
   }
}

void quickSort(mst *e, int left, int right) //left 0 right m
{
	int i, j, pivot;
	mst t;
	if (left < right) 
	{
		i = left;
		j = right;
		pivot = e[left].cost;
		do 
		{
			do { i++; } while (e[i].cost > pivot);
			do { j--; } while (e[j].cost < pivot);
			if (i < j) 
			{
				SWAP(e[i], e[j], t);
			}
		} while (i < j);

		SWAP(e[left], e[j], t);
		quickSort(e, left, j - 1);
		quickSort(e, j + 1, right);
	}
}

int find(int v)
{
	if (v != parent[v])
	{
		parent[v] = find(parent[v]);
	}
	return parent[v];
//完成此函數 
}
int unionSet(int v, int vv) 
{
	//完成此函數 
	int v1 = find(v);
	int v2 = find(vv);
	
	if(v1==v2)
	{
    	return 0;
	}
	else if(v1>v2)
	{
	    parent[v1] = v2;	
	}
	else
	{
		parent[v2] = v1;
	}
}
