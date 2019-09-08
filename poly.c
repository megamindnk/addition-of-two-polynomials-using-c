#include<stdio.h>
#include<stdlib.h>
#define cap 100
struct poly
{
	int coeff,exp;
	struct  poly *next;
};
struct poly *temp,*newpoly;
struct poly *root[cap],*addroot;
int create(struct poly **root,int q)
{
	int n,i;
	*root=NULL;
	printf("\nenter how many node u want in %d:-\n",q+1);
	scanf("%d",&n);
for(i=0;i<n;i++)
{
	newpoly=(struct poly*)malloc(sizeof(struct poly));
	printf("\nenter coefficient and variable exponent\n");
	scanf("%d%d",&newpoly->coeff,&newpoly->exp);
	newpoly->next=NULL;
	if(*root==NULL)
	{
		*root=newpoly;
		//printf("first node created\n");
	}
	else
	{
		temp=*root;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newpoly;
	//	printf("node inserted after other node\n");
	}
}
printf("%d expression created",q+1);
return 0;
}
int display1(struct poly **root)
{

	struct poly *temp;
	temp=*root;
	while(temp->next!=NULL)
	{
		printf("[%d(x^%d)]",temp->coeff,temp->exp);
		temp=temp->next;
		if(temp->next!=NULL)
			printf("+");
	}printf("[%d(x^%d)]",temp->coeff,temp->exp);
	printf(" = 0");

return 0;
}
void add(struct poly **root1,struct poly **root2)
{
	struct poly *newnode,*temp1=*root1,*temp2=*root2,*temp3=addroot;
	addroot=NULL;
	while(temp1!=NULL && temp2!=NULL)
	{
	newnode=(struct poly *)malloc(sizeof(struct poly));
	newnode->next=NULL;
			if(temp1->exp>temp2->exp)
			{
			newnode->exp=temp1->exp;
			newnode->coeff=temp1->coeff;
			temp1=temp1->next;
			}
			else if (temp1->exp<temp2->exp)
			{
			newnode->exp=temp2->exp;
			newnode->coeff=temp2->coeff;
			temp2=temp2->next;
			}
			else
			{
			newnode->exp=temp1->exp;
			newnode->coeff=temp1->coeff+temp2->coeff;
			temp1=temp1->next;
			temp2=temp2->next;
			}
		if(addroot==NULL)
		{
		addroot=newnode;
		}
		else
		{
			temp3 = addroot; 
			while(temp3->next!=NULL)
			{
			temp3=temp3->next;
			}
			temp3->next=newnode;
		}
	}
	while(temp1)
	{
	newnode->exp=temp1->exp;
	newnode->coeff=temp1->coeff;
	temp1=temp1->next;
	temp3=temp3->next;
	}
	while(temp2)
	{
	newnode->exp=temp2->exp;
	newnode->coeff=temp2->coeff;
	temp2=temp2->next;
	temp3=temp3->next;
	}
	
}
void dispadd()
{
	printf("dislay add");
	struct poly *dis;
	dis=addroot;
	while(dis->next!=NULL)
	{
		printf("[%d(x^%d)]+",dis->coeff,dis->exp);
		dis=dis->next;
	}printf("[%d(x^%d)]",dis->coeff,dis->exp);
	printf(" = 0");
}	
void main()
{
	int ch,i,n;
	int exp1,exp2;
	while(1)
	{
		printf("\nenter choice:-");
		printf("\n1.create polynomial expresssions");
		printf("\n2.display");
		printf("\n3.add two expressions");
		printf("\n4.display additions");
		printf("\n5.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n how many expression you want");
				scanf("%d",&n);
				for(i=0;i<n;i++)
					create(&root[i],i);
				break;

			case 2: for(i=0;i<n;i++)
				{
				printf("\nExpression no. %d :-\n",i+1);
				display1(&root[i]);
				}
				break;

			case 3: printf("which expressions u want to add:-\n");
				scanf("%d%d",&exp1,&exp2);
				printf("adding expression %d and %d ",exp1,exp2);
				add(&root[exp1-1],&root[exp2-1]);			
				break;
			case 4: dispadd();
				break;
			case 5:exit(0);
		}
	}
}

