#include <stdio.h> 
#include <stdlib.h> 


struct node{ 
	char data; 
	struct node* left; 
	struct node* right; 
}; 

struct node* newNode(char data);
struct node* buildTree(char in[], char pre[], int inStrt, int inEnd);
int search(char arr[], int strt, int end, char value); 
void printPostorder(struct node* node);

int main () 
{ 
	int  i, n;
	
	printf("請輸入節點數: ");
	scanf("%d",&n);
	
	int arr_n = n+1;
	char in[arr_n];
	char pre[arr_n];
	
	printf("\n請輸入前序走訪： (值只能為A-Z,0-9)");
	for (i = 0; i <= n; i++)
	{
		scanf("%c",&pre[i]);
	}
	printf("\n請輸入中序走訪：(值只能為A-Z,0-9)");
	for (i = 0; i <= n; i++)
	{
		scanf("%c",&in[i]);
	}
	
	printf("前序走訪結果為：");
	printf("%s\n",pre);
	
	printf("中序走訪結果為：");
	printf("%s\n",in);
	
	struct node* root = buildTree(in, pre, 0, n); 

	printf("後序走訪結果為:\n"); 
	printPostorder(root); 
	return 0;
} 

struct node* newNode (char data) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
}

struct node* buildTree (char in[], char pre[], int inStrt, int inEnd) 
{ 
	static int preIndex = 0; 

	if (inStrt > inEnd)
	{ 
		return NULL;
	} 

	struct node* tNode = newNode(pre[preIndex++]); 

	if (inStrt == inEnd)
	{ 
		return tNode;
	} 

	int inIndex = search(in, inStrt, inEnd, tNode->data); 

	tNode->left = buildTree(in, pre, inStrt, inIndex - 1); 
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
} 

int search (char arr[], int strt, int end, char value) 
{ 
	int i; 
	for (i = strt; i <= end; i++)
	{ 
		if (arr[i] == value)
		{ 
			return i;
		} 
	} 
} 
 

void printPostorder (struct node* node) 
{ 
	if (node == NULL)
	{
		return; 
	}
	printPostorder(node->left);
	printPostorder(node->right);
	printf("%c ", node->data);
}
