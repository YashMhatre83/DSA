#include<stdlib.h>
#include<iostream>
#include<conio.h>
using namespace std;
// This program creates unsorted linked list.
typedef struct node 
{
   int data;
   struct node *link;
}NODE;


typedef struct {
  int count;
 
   NODE *head;
}HEAD;
class linklist
{
	HEAD *pNew;
	public:
	HEAD *createHead()
	{
		pNew = new HEAD;
		if(pNew)
		{
			pNew->head = NULL;
			pNew->count = 0;
			cout<<"Memory allocated\n";
		}
		else
			pNew = NULL;
		return pNew;
	}
	void insertNode(HEAD *pList,int dain)
	{

	int loc,i;
	NODE *pNew,*pPre,*temp;
	pPre =pList->head;

	pNew = new NODE;
	if(pNew == NULL)
		cout<<"\nMemory overflow.\n";
	else
	{
		pNew->data = dain;

	}
	temp = pList->head;
	while (temp!=NULL)
	{
		pPre=temp;
		temp=temp->link;

	}
	if(pPre==NULL) //adding before first node or to empty list
	{
		pNew->link = pList->head;
		pList->head =pNew;
		pList->count = pList->count+1;
		cout<<"\ndata is inserted.\n";
	}
	else
	{
			pNew->link = pPre->link;
			pPre->link = pNew;
			pList->count = pList->count+1;
			cout<<"\ndata is inserted.\n";
	 }

}
void traverse(HEAD *pList)
{
	NODE *pWalk;
	int i;
	if(pList->head==NULL)
		cout<<"List is empty\n";
	else
	{
		pWalk = pList->head;
		//while(pWalk!=NULL)
		i=0;
		while (i<pList->count)
		{
			cout<<pWalk->data<<"\t";
			pWalk=pWalk->link;
			i++;
		}
		cout<<"\n";
		cout<<"Num ber of elements in linked list is \n"<<pList->count;
	}
}
void deleteNode(HEAD *pList)
{
	NODE *pWalk,*pPre;
	int num,i;

	cout<<"Enter the element to be deleted:\n";
	cin>>num;
	pWalk=pList->head;
	while(pWalk!=NULL)
	{
		if(pWalk->data==num)
			break;
		else
		{
			pPre= pWalk;
			//There should be some initialization for pPre.
			//So pPre=pWalk
			pWalk=pWalk->link;
		}

	}
	if(pWalk==pList->head) //To delete first node
	{
		pList->head = pWalk->link;
		free(pWalk);
		pList->count = pList->count-1;
		cout<<"Number is deleted\n";
	}
	else if(pWalk==NULL)
		cout<<"Number not found in list\n";
	else
	{
		pPre->link = pWalk->link;
		free(pWalk);
		pList->count = pList->count-1;
		cout<<"Number is deleted\n";
	}
	}
void searchList(HEAD *pList,int data)
{
	NODE *pWalk;
	int i,flag;
	pWalk=pList->head;
	i=1;
	while(pWalk!=NULL)
	{
		if(pWalk->data==data)
		{
			cout<<"Data is present at "<<i<<"th location\n ";
			flag=1;
			break;
		}
		else
			pWalk=pWalk->link;
		i++;


	}
	if(pWalk==NULL)
	{
		cout<<"Data is not present\n";
		flag=0;
	}
}
void retrieveNode(HEAD *pList, int locn)
{
	NODE *pWalk;
	int i,flag;
	pWalk=pList->head;
	for(i=1;i<=locn-1;i++)
	{
		pWalk =pWalk->link;
	}
	cout<<"Data at"<<locn<< "is\t"<<pWalk->data;
}
void emptyList(HEAD *pList)
{
	if(pList->count==0)
		cout<<"List is empty\n";
	else
		cout<<"List is not empty\n";
}
void reverseList(HEAD *pList)
{
	NODE *pWalk;
	int i;
	int *arr;
	arr = new int[pList->count];
	pWalk=pList->head;
	i=-1;
	while(pWalk!=NULL) //To store linked list into array
	{
		i++;
		arr[i]=pWalk->data;
		pWalk=pWalk->link;

	}
	cout<<"\n";
	for(;i>=0;i--) // print the array in reverse
		cout<<arr[i]<<"\t";

}
void sortList(HEAD *pList)
{
	NODE *pWalk,*pCur,*pCur1;
	int current,small,i;
	pWalk=pList->head;
	//pCur1=pCur=NULL;
	while(pWalk!=NULL)
	{
		pCur=pWalk->link;
		small=pWalk->data;
		while(pCur!=NULL)
		{
			if(small>pCur->data)
			{
				small = pCur->data;
				pCur1=pCur;
			}
			pCur=pCur->link;
		}
		if(pCur1!=pCur)
		{
			current = pWalk->data;
			pWalk->data=small;
			pCur1->data=current;
		}
		pWalk=pWalk->link;
		pCur=pCur1=NULL;
	}
	traverse(pList);




}
void destroyList(HEAD *pList)
{
	NODE *pWalk;
	while (pList->count!=0)
	{
		pWalk=pList->head;
		pList->head = pWalk->link;
		pList->count = pList->count-1;
		free(pWalk);
	}
	free(pList);
	cout<<"Linked list destroyed\n";
}
};
int flag;

int main()
{

	int choice,datain;
	HEAD *pList;
	linklist l;
	pList=l.createHead();
	while(1)
	{
		cout<<"1. Insert linked list node\n";
		cout<<"2. Traverse list\n";
		cout<<"3.Delete Node\n";
		cout<<"4.Search Element\n";
		cout<<"5. Retrieve Node\n";
		cout<<"6. Check empty List\n";
		cout<<"7. Reverse the list\n";
		cout<<"8. Sort the list\n";
		cout<<"9. Exit\n";
		cout<<"\nEnter choice:";
		cin>>choice;
		switch(choice)
		{


			case 1:
				cout<<"\nEnter the element to be inserted\n";
				cin>>datain;
				l.insertNode(pList,datain);
			break;
			case 2:
				l.traverse(pList);
			break;
			case 3:
				l.deleteNode(pList);
			break;
			case 4:
				cout<<"\nEnter the element to be searched:\n";
				cin>>datain;
				l.searchList(pList,datain);



			break;
			case 5:

				cout<<"\nEnter the location to be retrieved:\n";
				cin>>datain;
				l.retrieveNode(pList,datain);
			break;
			case 6:
				l.emptyList(pList);
			break;
			case 7:
				l.reverseList(pList);
			break;
			case 8:
				l.sortList(pList);
			break;
			case 9:
				//l.destroyList(pList);
				exit(1);
				break;
			default: cout<<"Illegal option\n";
		}
	}
	return 0;
}




