#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next;
};
class SLL
{
	node *head;
	node *tail;
	public:
	SLL()
	{
		head=NULL;
		tail=NULL;
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
			head=tail=temp;
		}
	}
	void addtotail(int val)
	{
		node *temp=new node;
		temp->data=val;
		temp->next=NULL;
		if(tail)
		{
			tail->next=temp;
			tail=temp;
		}
		else
		{
			tail=head=temp;
		}
	}
	int count()
	{
		node *ptr=head;
		int cnt;
		for(cnt=0;ptr!=NULL;++cnt,ptr=ptr->next);
		return cnt;
	}
	void addafter(int val)
	{
		node *tmp=new node;
		cout<<"ENTER NUMBER TO BE INSERTED: ";
		cin>>tmp->data;
		node *cur=head;
		node *prev=head;
		if(cur->data==val)
		{
			if(head==tail)
			addtotail(tmp->data);
			else
			{
				tmp->next=head->next;
				head->next=tmp;
			}
		}
		else
		{
			cur=cur->next;
			for(;cur->data!=val&&cur!=NULL;cur=cur->next,prev=prev->next);
			if(!cur)
			{
				prev->next=tmp;
				tmp->next=cur;
			}
			else
			{
				cout<<"ELEMENT NOT FOUND!!!!!!!!!";
			}
		}
		
	}
	void display()
	{
		node *temp=head;
		for(;temp!=NULL;temp=temp->next)
		cout<<temp->data<<", ";
	}
	bool search(int val)
	{
		bool t=false;
		node *temp=head->next;
		if(head->data==val)
		t=true;
		else
		for(;temp!=NULL&&temp->data!=val;temp=temp->next);
		if(temp)
		t=true;
		return t;
	}
	void delhead()
	{
		if(head&&head!=tail)
		{
			node *temp=head;
			head=head->next;
			delete temp;
		}
		else if(head&&head==tail)
			{
				node *temp=head;
				head=tail=NULL;
				delete temp;
			}
		else
			cout<<"LIST EMPTY!!!!!";
			
		
	}
	void deltail()
	{
			if(tail&&tail!=head)
			{
			node *temp=head;
			for(;temp->next!=tail;temp=temp->next);
			tail=temp;
			temp=temp->next;
			delete temp;
			tail->next=NULL;	
			
			}
			else if(head==tail&&tail)
			{
				node* tmp=tail;
				tail=head=NULL;
				delete tmp;
			}
			else
			cout<<"LIST EMPTY!!!!!!";
	}
	void delelement(int val)
	{
		node *cur=head;
		node *prev=head;
		if(cur->data==val)
		delhead();
		else
		{
			cur=cur->next;
			for(;cur->data!=val&&cur!=NULL;cur=cur->next,prev=prev->next);
			if(cur)
			{
				prev->next=cur->next;
				delete cur;
			}
			else
			{
				cout<<"ELEMENT NOT FOUND!!!!!!!!!";
			}
		}
	}
	
	node * rethead()
	{
		node *ptr=head;
		return ptr;
	}
	void append(node *ptr)
	{
		tail->next=ptr;
	}
	void reverse()
	{
			node* temp=tail;
			node *prev;
			int x=count();
			for(;x!=1;--x)
			{	prev=head;
				for(;prev->next!=tail;prev=prev->next);
				prev->next->next=prev;
				tail=prev;
			}	
			tail->next=NULL;
			head=temp;
	}
	void deleven()
	{
		int c=2;
		node *prev=head;
		if(count()%2==0)
		deltail();
		for(node *tmp=head->next;tmp!=NULL;tmp=tmp->next)
		{
			if(c%2==0)
			{
					node *temp=tmp;
					prev->next=tmp->next;
					tmp=tmp->next;
					delete temp;
					
					
			}
			++c;
			prev=prev->next;
		}
	}
	void delallocc(int n)
	{
		if(head->data==n)
		delhead();
		if(tail->data==n)
		deltail();
		node *prev=head,*curr=head->next;
		for(;curr!=NULL;prev=prev->next,curr=curr->next)
		{
			if(curr->data==n)
			{
				prev->next=curr->next;
				curr=curr->next;
			}
		}
	}
	void sort()
	{
		for(node *ptr1=head;ptr1!=NULL;ptr1=ptr1->next)
		{
			int x=ptr1->data;
			node *ptr=ptr1;
			for(node *ptr2=ptr1->next;ptr2!=NULL;ptr2=ptr2->next)
			{
				if(ptr2->data<x)
				{
					x=ptr2->data;
					ptr=ptr2;
				}
			}
			int temp;
			temp=ptr1->data;
			ptr1->data=x;
			ptr->data=temp;
		}
	}
	node *merge(node *ptr1,node *ptr2)
	{
		if(!ptr1)
		{
			return ptr2;
		}
		else if(!ptr2)
		{
			return ptr1;
		}
		else if(ptr1->data<ptr2->data||ptr1->data==ptr2->data)
		{
			ptr1->next=merge(ptr1->next,ptr2);
			return ptr1;
		}
		else
		{
			ptr2->next=merge(ptr1,ptr2->next);
			return ptr2;
		}
	}
	void gethead(node * pt)
	{	
		head=pt;
	}
	SLL operator + (SLL s4)
	{

		SLL result;
		result.head=head;
		result.tail=tail;
		result.tail->next=s4.head;
		result.tail=s4.tail;
		return result;
	}
};

int main()
{
	SLL s;
	SLL s2;
	int choice=0;
	do
	{
		cout<<"\n\t\tMENU\n1.ADD TO HEAD\n2.ADD TO TAIL\n3.COUNT NUMBER OF ELEMENTS\n4.ADD AFTER AN ELEMENT\n5.DISPLAY LIST\n6.SEARCH AN ELEMENT\n7.DELETE HEAD\n8.DELETE TAIL\n9.DELETE AN ELEMENT\n10.MERGE\n11.SORT\n12.DELETE ALL OCCURENCE\n13.DELETE EVEN NODES\n14.REVERSE\n15.APPEND\n16.CONCATE(OPERATOR OVERLOADING)\nENTER CHOICE: ";
		cin>>choice;
		if(choice==10||choice==15||choice==16)
		{ cout<<"ENTER NUMBER OF ELEMENTS FOR SECOND LINK LIST: ";
						int u;
						cin>>u;
						cout<<"ENTER ELEMENTS: \n";
						int j;
						cin>>j;
						
						s2.addtohead(j);
						--u;
						while(u!=0)
						{
							cin>>j;
							s2.addtotail(j);
							--u;
						}
		}
		switch(choice)
		{
			case 1:cout<<"ENTER ELEMENT TO BE ADDED TO HEAD: ";
				cin>>choice;
				s.addtohead(choice);
				s.display();
								break;
			case 2:cout<<"ENTER ELEMENT TO BE ADDED TO TAIL: ";
				cin>>choice;
				s.addtotail(choice);
				s.display();
								break;
			case 3:cout<<"TOTAL ELEMENTS IN THE LIST: "<<s.count();
								break;
			case 4:cout<<"ENTER ELEMENT AFTER WHICH YOU WANT TO ADD: ";
				cin>>choice;
				s.addafter(choice);
				s.display();
								break;
			case 5: s.display();
								break;
			case 6:cout<<"ENTER ELEMENT TO BE SEARCHED: ";
				cin>>choice;
				if(s.search(choice))
				cout<<"ELEMENT FOUND!!!";
				else
				cout<<"ELEMENT NOT FOUND!!!";
								break;
			case 7: s.delhead();
				s.display();
									break;
			case 8: s.deltail();
				s.display();		
									break;
			case 9:cout<<"ENTER ELEMENT TO BE DELETE: ";
				cin>>choice;
				s.delelement(choice);
									break;
					case 10:s.gethead(s.merge(s.rethead(),s2.rethead()));
				break;
			case 11:s.sort();
					s.display();
									break;
			case 12: 	int h;
						cout<<"ENTER NUMER TO BE DELETED: ";
						cin>>h;
						s.delallocc(h);
									break;
			case 13: s.deleven();
									break;
			case 14: s.reverse();
									break;
			case 15:s.append(s2.rethead());
									break;
	
			case 16:SLL R=s+s2;
					cout<<"2";
					R.display();
									break;
									
				
		};
		
	}while(choice<17);
		
	return 0;
	
}
