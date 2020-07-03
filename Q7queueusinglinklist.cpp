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
	int delhead()
	{
		if(head&&head!=tail)
		{
			int x=head->data;
			node *temp=head;
			head=head->next;
			delete temp;
			return x;
		}
		else if(head&&head==tail)
			{
				int y=head->data;
				node *temp=head;
				head=tail=NULL;
				delete temp;
				return y;
			}
		else
			return -1;
			
		
	}
	int deltail()
	{
			
			if(tail&&tail!=head)
			{
			int x=tail->data;
			node *temp=head;
			for(;temp->next!=tail;temp=temp->next);
			tail=temp;
			temp=temp->next;
			delete temp;
			tail->next=NULL;	
			return x;
			}
			else if(head==tail&&tail)
			{
				int y=tail->data;
				node* tmp=tail;
				tail=head=NULL;
				delete tmp;
				return y;
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
class queue{
	int front;
	int rear;
	SLL list;
	public:
		queue()
		{
			front=-1;
			rear=-1;
		}
		void enqueue(int n)
		{
			if(rear==front&&rear==-1)
			{
				++rear;
				++front;
				list.addtohead(n);
			}
			else
			{
				++rear;
				list.addtotail(n);
			}
		}
		void dequeue()
		{
				int y=list.delhead();
				if(y==-1)
				{
					cout<<"QUEUE IS EMPTY!!!";
					++front;
				}
				else
				{
					cout<<" "<<y<<" DEQUEUED!!!!";
					++front;
				}
		}
		
		void display()
		{
			list.display();
		}
};
int main()
{
	queue q;
	int c=0;
	while(c<4)
	{
		cout<<"\nMENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\nENTER CHOICE: ";
		cin>>c;
		switch(c)
		{
			case 1:int val;
					cout<<"ENTER VALUE: ";
					cin>>val;
					q.enqueue(val);
									break;
			case 2:q.dequeue();
									break;
			case 3: q.display();
									break;
		}
	}
}

