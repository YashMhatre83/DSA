#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
typedef struct {
  int count;
  
  struct node *rear;
  struct node *back;
  struct node *fore;
}HEAD;
typedef struct node
{
   int data;
   struct node *back;
   struct node *fore;
}NODE;
class dll
{
HEAD *pNew;
public:
HEAD *createHead()
{
	HEAD *pNew;
	pNew = new HEAD;
	if(pNew)
	{
		pNew->count = 0;
		pNew->rear=NULL;
		pNew->back=NULL;
		pNew->fore=NULL;
		cout<<"Memory allocated"<<"\n";
	}
	else
		pNew = NULL;
	return pNew;
}
void insertNode(HEAD *,int);
int searchNode(HEAD *,int);
void traverse(HEAD *);
void deleteNode(HEAD *);

void reverseList(HEAD *);
};
void dll::insertNode(HEAD *pList, int element)
{
	int loc,i;
	NODE *pNew,*pPre,*temp,*pSucc;
	pPre =pList->fore;
	pNew = new NODE;
	if(pNew == NULL)
		cout<<"Memory overflow.\n";
	else
	{
		pNew->data = element;
	}
	//to locate a position according to ascending order
	//To insert into empty list or at first position
	if(pPre==NULL)
	{
		//pPre->back=pNew;
		pNew->fore=pList->fore;
		pNew->back=NULL;
		pList->fore=pNew;
		if (pPre==NULL)
			pList->rear=pNew;
	}
	else if (element<pPre->data) // To insert first position
	{
		pNew->fore= pList->fore;
		pNew->back=NULL;
		pPre->back = pNew; 
		pList->fore= pNew;
	}

	//to insert at last position
	//temp=pList->rear;
	else if (element>pList->rear->data)
	{
		pPre=pList->rear;
		pNew->fore=NULL;
		pNew->back=pPre;
		pPre->fore=pNew;
		pList->rear=pNew;
	}
	//to insert at middle position
	else
	{
		temp=pPre=pList->fore;
		while (element>temp->data)
		{
			pPre=temp;
			temp=temp->fore;
		}
		pSucc=pPre->fore;
		pNew->fore=pSucc;
		pSucc->back=pNew;
		pPre->fore=pNew;
		pNew->back=pPre;
	 }

	pList->count= pList->count+1;
	cout<<"Data is inserted\n";

	cout<<"Number of elements in the list is "<<pList->count;

}
void dll::deleteNode(HEAD *pList)
{
	NODE *pDlt,*pSucc,*pPre;
	int num,i;
	cout<<"Enter the element to be deleted:\n";
	cin>>num;
	pDlt=pList->fore;
	i=1;
	while(i<=pList->count)
	{
		if(pDlt->data==num)
			break;
		else
			pDlt=pDlt->fore;
		i++;
	}
	pPre=pDlt->back;
	pSucc=pDlt->fore;
	if(pSucc==NULL)    //To delete last node
	{
		pPre->fore=NULL;
		pList->rear=pPre;
	}
	else  //To delete middle or first node
	{
		pPre->fore=pSucc;
		pSucc->back=pPre;
	}
	free(pDlt);
	if(i==1)   //To delete first node
		pList->fore=pSucc;
	pList->count=pList->count-1;
	cout<<"Node is deleted\n";
	cout<<"Nodes remaining are: \n"<<pList->count;

}
void dll::traverse(HEAD *pList)
{
	NODE *pWalk;
	int i;
	if(pList->count==0)
		cout<<"List is empty\n";
	else
	{
		pWalk= pList->fore;
		i=1;
		while(i<=pList->count)
		{
			cout<<pWalk->data<<"\t";
			pWalk=pWalk->fore;
			i++;
		}
		cout<<"\n";
	}
}
int dll::searchNode(HEAD *pList,int data)
{
	NODE *pS,*p1;
	int flag=0;
	pS=pList->fore;
	if (pS->data==data) //To check at first position
		flag=1;
	else
	{
		p1=pList->rear;      //To check at last position
		if(p1->data==data)
			flag=1;
	}
	if(flag==0)
	while(pS!=NULL)
	{
		if(pS->data==data)
		{
			flag=1;
			p1=pS;
			break;
		}
		else
			pS=pS->fore;
	}
	if(pS==NULL)
		flag=0;
	return flag;
}
void dll::reverseList(HEAD *pList)
{
	NODE *pWalk,*pPre;
	pWalk=pList->rear;
	while(pWalk!=NULL)
	{
		cout<<pWalk->data<<"\t";
		pWalk=pWalk->back;
	}
	cout<<endl;

}
int main()
{
	HEAD *pList;
	int ch,datain,flag;
	
	dll d;
	pList = d.createHead();
	while(1)
	{
		cout<<"1. Insert node\n";
		cout<<"2.Display List\n";
		cout<<"3. Delete Node\n";
		cout<<"4.Search Node\n";
		//printf("5.Copy List\n");
		cout<<"6.Reverse List\n";
		cout<<"7.Exit\n";
		cout<<"Enter choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the element to be inserted\n";
				cin>>datain;
				d.insertNode(pList,datain);
			break;
			case 2:
				d.traverse(pList);
			break;
			case 3:
				d.deleteNode(pList);
			break;
			case 4:
				cout<<"\nEnter the element to be searched\n";
				cin>>datain;
				flag=d.searchNode(pList,datain);
				if(flag==1)
					cout<<"Data is present\n";
				else
					cout<<"Data is not present\n";
			break;
			/*case 5:
				copyList(pList);
			break;*/
			case 6:
			       d.reverseList(pList);
			break;
			case 7:
				exit(1);
			break;
		}
	}
	return 0;
}



/*void copyList(HEAD *pList1)
{
	int i;
	HEAD *pList2;
	NODE *pNew,*pWalk,*pPre;
	pList2 = createHead();
	pWalk=pList1->fore;
	i=1;
	pNew = (NODE *)malloc(sizeof(NODE));
	if(pNew == NULL)
		printf("Memory overflow.\n");
	else
	{
		pNew->data = pWalk->data;
		pPre = pNew;
	}
	if(i==1)
	{
		pList2->fore=pNew;
	}
	i++;
	while(i<=pList1->count)
	{
		pWalk=pWalk->fore;
		pNew = (NODE *)malloc(sizeof(NODE));
		pNew->data=pWalk->data;
		pNew->back = pPre;
		pPre->fore = pNew;
		pPre=pNew;
		i++;

	}
	if(i==pList1->count)
		pList1->rear=pNew;
	pList2->count=pList1->count;
	printf("Number of nodes copied are: %d\n", pList2->count);
	traverse(pList2);

} */
