/*�t��k
KRUSKAL�B�z�޿� 

begin
	begin T�]�t�֩�n-1����&&E�D��  loop
	 	�qE���令���̤p���� 
	  	if ��JT�����|�Φ��j�� then
	 		 �N��[�J
	 	else 
			�˱�
	end
end
 	
*���� union find ��Ө禡
*�NquickSort��g��heapSort
�U���W�ҷ|²������ �i�H���q�Ƨǧ�g�}�l 
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
void quickSort(mst *e, int left, int right);//���O�ֳt�Ƨ� 
void heapSort(mst *e, int n);//n����� 
void heapify(mst *e, int n, int i);//n���_�l�I i�����I 
void makeSet(int size);
int find(int v);//���|���Y
int unionSet(int v, int u);//�X�ֶ��X

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
	
	makeSet(n);//�I�sfunction��l�� 
	
	heapSort(e, m);
	puts("");
	puts("MST...������");
	
	for (i = 0; i < m; i++) {
		
		if (unionSet(e[i].start, e[i].end)) { 
			count++;
		
			sum=sum+e[i].cost;//�����[�` 
			
			printf("edge[%3d]: start = %3d, end = %3d, cost = %3d\n",i, e[i].start, e[i].end, e[i].cost);//�����L�X 
		}
		
		if (count == n - 1) {        
			break;            //�p�G��F��n-1�h���X�t��k
		}
	}
	
	for (i = 0; i < n; i++) {
		if (parent[i] == i) {
			set_num++;
		}
	} 
	
	if (n-1!=count) {//�������P�_���� 
		puts("");
		puts("�䤣��ͦ���");
	}
	else {
		printf("�`����:%d\n", sum);
	} 
	
	free(e);
	return 0;
}


void makeSet(int size){    //��l��
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
        largest = l;//���j��� 
 
    // If right child is larger than largest so far
    if (r < n && e[r].cost > e[largest].cost)
        largest = r;//�k�j��� 
 
    // If largest is not root
    if (largest != i)
    {
        SWAP(e[i], e[largest], t);//������m 
 
        // Recursively heapify the affected sub-tree
        heapify(e, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(mst *e, int n)
{
	mst t;
    // �إ߰��| (rearrange array)
    for (int i = n / 2; i >= 0; i--)//i���̤p�`�I�����`�I 
        heapify(e, n, i);
 
    // �q���|�������Ʀr
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        SWAP(e[0], e[i], t);
 
        // call max heapify on the reduced heap
        heapify(e, i, 0);
    }
}
 
//�N���ƧǪk��g��heap
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
//��������� 
}

int unionSet(int v, int vv) {   //�X��
	int r1 = find(v);//��v��paarent  
    int r2 = find(vv); //��vv��paarent
    if(r1==r2){
    	return 0;
	}
	else if(r1>r2){   //�p����j�����W
	    parent[r1] = r2;	
	}
	else{
		parent[r2] = r1;
	}
      
	}
//��������� 
