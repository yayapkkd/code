/*演算法
KRUSKAL處理邏輯 

begin
	begin T包含少於n-1個邊&&E非空  loop
	 	從E中選成本最小的邊 
	  	if 放入T中不會形成迴路 then
	 		 將邊加入
	 	else 
			捨棄
	end
end
 	
*完成 union find 兩個函式
*將quickSort改寫成heapSort
下次上課會簡略說明 可以先從排序改寫開始 
*/

#include<stdio.h>
#include<stdlib.h>
#define SWAP(x, y, t) { (t) = (x) ; (x) = (y) ; (y) = (t);}

typedef struct {
	int	start;
	int	end;
	int	cost;
}mst;

int parent[1000];
void quickSort(mst *e, int left, int right);//哥是快速排序 
void heapSort(mst *e, int n);//n為邊數 
void heapify(mst *e, int n, int i);//n為起始點 i為終點 
void makeSet(int size);
int find(int v);//路徑壓縮
int unionSet(int v, int u);//合併集合

int main(int argc, char *argv[]) 
{
	int i, n, m, sum = 0, count = 0, set_num = 0;
	mst *e;
	mst *ptr;
	FILE* fin;
	
	if (argc < 1) {
		fin = stdin;
	}
	else {
		fin = fopen("g1.txt", "rt");
		if (!fin) {
			fprintf(stderr, "file %s not found\n", argv[1]);
			exit(1);
		}
	}
	fscanf(fin, "%d, %d", &n, &m);
	printf("nodes = %3d, edges = %3d\n", n, m);
	
	e = (mst *)malloc(sizeof(mst)*(m+1));
	for (i = 0; i < m; i++) {
		ptr = &(e[i]);
		fscanf(fin, "%d, %d, %d", &ptr->start, &ptr->end, &ptr->cost);
		printf("edge[%3d]: start = %3d, end = %3d, cost = %3d\n", i, ptr->start, ptr->end, ptr->cost);
	}
	fclose(fin);
	
	makeSet(n);//呼叫function初始化 
	
	heapSort(e, m);
	puts("");
	puts("MST...成長中");
	
	for (i = 0; i < m; i++) {
		
		if (unionSet(e[i].start, e[i].end)) { 
			count++;
		
			sum=sum+e[i].cost;//成本加總 
			
			printf("edge[%3d]: start = %3d, end = %3d, cost = %3d\n",i, e[i].start, e[i].end, e[i].cost);//完成印出 
		}
		
		if (count == n - 1) {        
			break;            //如果邊達到n-1則跳出演算法
		}
	}
	
	for (i = 0; i < n; i++) {
		if (parent[i] == i) {
			set_num++;
		}
	} 
	
	if (n-1!=count) {//完成此判斷條件 
		puts("");
		puts("找不到生成樹");
	}
	else {
		printf("總成本:%d\n", sum);
	} 
	
	free(e);
	return 0;
}


void makeSet(int size){    //初始化
	int i;
	for(i = 0; i < size; i++) {
		parent[i] = i;
	}
}
//heap
void heapify(mst *e, int n, int i)
{   
    mst t;
    int largest = i;  // Initialize largest as root
    int l = 2*i ;  // left = 2*i
    int r = 2*i + 1;  // right = 2*i + 1 
 
    // If left child is larger than root
    if (l < n && e[l].cost > e[largest].cost)
        largest = l;//左大於父 
 
    // If right child is larger than largest so far
    if (r < n && e[r].cost > e[largest].cost)
        largest = r;//右大於父 
 
    // If largest is not root
    if (largest != i)
    {
        SWAP(e[i], e[largest], t);//互換位置 
 
        // Recursively heapify the affected sub-tree
        heapify(e, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(mst *e, int n)
{
	mst t;
    // 建立堆疊 (rearrange array)
    for (int i = n / 2; i >= 0; i--)//i為最小節點的父節點 
        heapify(e, n, i);
 
    // 從堆疊中提取數字
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        SWAP(e[0], e[i], t);
 
        // call max heapify on the reduced heap
        heapify(e, i, 0);
    }
}
 
//將此排序法改寫成heap
void quickSort(mst *e, int left, int right) {
	int i, j, pivot;
	mst t;
	if (left < right) {
		i = left;
		j = right + 1;
		pivot = e[left].cost;

		do {
			do { i++; } while (e[i].cost < pivot);
			do { j--; } while (e[j].cost > pivot);
			if (i < j) {
				SWAP(e[i], e[j], t);
			}
		} while (i < j);

		SWAP(e[left], e[j], t);
		quickSort(e, left, j - 1);
		quickSort(e, j + 1, right);
	}
}

int find(int v) {
	if (v != parent[v])
	{
		parent[v] = find(parent[v]);
	}
	return parent[v];
//完成此函數 
}

int unionSet(int v, int vv) {   //合併
	int r1 = find(v);//找v的paarent  
    int r2 = find(vv); //找vv的paarent
    if(r1==r2){
    	return 0;
	}
	else if(r1>r2){   //小的到大的身上
	    parent[r1] = r2;	
	}
	else{
		parent[r2] = r1;
	}
      
	}
//完成此函數 
