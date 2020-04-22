
/*

Authors .....

Sai Jyoti
(Silicon Institute of technology)

Debesh Mohanty
(Amazon Inc)

.............

*/

#include<stdio.h>
#include<stdlib.h>
#define n 30
struct Node
{
	int data;
	struct Node* next;
};
int stack[n],Arr[10],top=-1,visited_array[30],b=0,j=0;
int graph(int edge1)
{
	return edge1%10;
}
void Visited_add(int node)
{
	visited_array[b]=node;
	b++;
}
int IsVisited(int node)
{
	int i;
	if(b==0)
	{
		return 0;
	}
	else
	{
		for(i=0;i!=b;i++)
		{
			if(visited_array[i]==node)
			{
				return 1;
			}
		}
	}
	return 0;
}
void push(int x)
{
//	printf("top=%d\n",top);
	if(top==n-1)
	{
		printf("Stack is full\n");
	}
	else
	{
		stack[++top]=x;
	}
}
int pop()
{
	if(top==-1)
	{
		//printf("Stack is empty\n");
		return -1;
	}
	else
	{
		return stack[top--];
	}
}
int * get_neighbours(struct Node* A[10],int node)
{
	int i;
	i=graph(node);
	if(i<10 && A[i]!=NULL)
	{
		struct Node* temp=A[i];
		temp=temp->next;		
		while(temp!=NULL)
		{
			Arr[j]=temp->data;
			temp=temp->next;
			j++;
		}
		return Arr;
	}
	else
	{
		return NULL;
	}
}
void DFS(struct Node* A[10],int node)
{
	int k=0,a=0;
	int* Arr;
	push(node);
	while(top!=-1)
	{
		node=pop();
		if(IsVisited(node)==0)
		{
			printf("%d\t",node);
			Arr=get_neighbours(A,node);
			while(k!=j)
			{
				push(Arr[k]);
				k++;
			}
			j=0;
			k=0;
		}
		Visited_add(node);
	}
}

void creategraph(struct Node* A[],int no_of_nodes)
{	
	int edge1,edge2,i;
	printf("Enter the edges\n");
	scanf("%d%d",&edge1,&edge2);
	i=graph(edge1);
	if(i<10)
	{
		struct Node* new1=(struct Node*)malloc(sizeof(struct Node));
		struct Node* new2=(struct Node*)malloc(sizeof(struct Node));
		if(A[i]==NULL)
		{
			A[i]=new1;
			new1->data=edge1;
			new1->next=new2;
			new2->data=edge2;
			new2->next=NULL;
		}
		else		
		{
			struct Node* temp=A[i];
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=new2;
			new2->data=edge2;
			new2->next=NULL;
		}
	}
	else
	{
		printf("Not enough space\n");
	}

}

int main()
{
	int i,no_of_nodes,edge1,edge2,option=0,node,k=0;
	int* Arr;
	printf("Enter the no of nodes\n");
	scanf("%d",&no_of_nodes);
	struct Node* A[no_of_nodes];
	for(i=0;i<10;i++)
	{
		A[i]=NULL;
	}
	while(option!=4)
	{
		printf("\nChoose option\n1.create graph\n2.Get neighbours\n3.DFS\n4.exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Create graph\n");
				creategraph(A,no_of_nodes);
				break;
			case 2:
				printf("Get the neighbours\n");
				printf("Enter the node to get it's neighbours\n");
				scanf("%d",&node);
				Arr=get_neighbours(A,node);
				if(Arr==NULL)
				{
					printf("No elements found\n");
				}
				else 
				{
					for(k=0;k<j;k++)
					{
						printf("%d\t",Arr[k]);
					}
					j=0;
				}
				break;
			case 3:
	                	printf("Depth first search\nEnter the node\n");
				scanf("%d",&node);
				DFS(A,node);
				break;
			case 4:
				break;
			default:
				printf("Invalid input\n");
				break;
		}
	}
	return 0;
}

