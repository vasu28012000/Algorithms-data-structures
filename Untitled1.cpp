#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next;
		node()
		{
			next=NULL;
		}
};
class cirlink
{
	node *head;
	public:
	cirlink()
	{
		head=NULL;
	}
		void addtohead(int val)
	{
		node* temp=new node;
		temp->data=val;
		if(head)
		{
			temp->next=head;
			head=temp;
		}
		else
		{
			temp->next=NULL;
			head=temp;
		}
	}
	void addtoend(int val)
	{
		node *ptr=new node;
		ptr->data=val;
		for(node *tmp=head;tmp->next!=NULL;tmp=tmp->next);
		ptr->next=head;
		tmp->next=ptr;
		
	}
	void search(int val)
	{
		node *ptr=head;
		for(;ptr!=NULL;ptr=ptr->next)
		{
			if(ptr->data==val)
			{
				cout<<"ELEMENT FOUND!!!!!";
				return;
			}
			else
			{
				cout<<"ELEMENT NOT FOUND!!!!";
				return;
			}
		}
	}
	void reverse()
	{
		
	}
};
int main()
{
	cirlink c;
	int choice=0,v;
	while(choice<3)
	{
		cout<<"1.ADD TO HEAD\n2.ADD TO END\nENTER CHOICE: ";
		cin>>choice;
		switch(choice)
		{
			case 1:cout<<"ENTER NUM: ";
					cin>>v;
					c.addtohead(v);
								break;
			case 2:cout<<"ENTER NUM: ";
					cin>>v;
					c.addtoend(v);
								break;
		}
	}
}

