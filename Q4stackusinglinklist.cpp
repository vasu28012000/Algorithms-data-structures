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
	int deltail()
	{
			if(tail&&tail!=head)
			{
			node *temp=head;
			for(;temp->next!=tail;temp=temp->next);
			int j=tail->data;
			tail=temp;
			temp=temp->next;
			delete temp;
			tail->next=NULL;	
			return j;
			}
			else if(head==tail&&tail)
			{
				node* tmp=tail;
				int k=tail->data;
				tail=head=NULL;
				delete tmp;
				return k;
			}
			else
			{
				return -1;
			}
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

};
class stack{
	SLL s;
	int top;
	public:stack()
			{
				top=-1;
			}
			void push(int n)
			{
				if(top==-1)
				{
					s.addtohead(n);
					++top;
				}
				else
				{
					s.addtotail(n);
					++top;
				}
			}
			int pop()
			{
				--top;
				return s.deltail();
			}
			void clear()
			{
				while(s.deltail()+1);
			}
			void display()
			{
				s.display();
			}
};
int main()
{
	stack s;
	int choice=0;
	while(choice<5)
	{
		cout<<"MENU\n 1.PUSH\n2.POP\n3.CLEAR\n4.DISPLAY\nENTER CHOICE: ";
		cin>>choice;
		switch(choice)
		{
			case 1:cout<<"ENTER ELEMENT: ";
				int y;
				cin>>y;
				s.push(y);
								break;
			case 2:cout<<s.pop()<<"   DELETED";
								break;
			case 3:s.clear();
				cout<<"STACK CLEARED ";
								break;
			case 4:s.display();
								break;
		}
		cout<<'\n';
	}
}

