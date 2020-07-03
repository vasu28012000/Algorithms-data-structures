#include<iostream>
using namespace std;
class cirqueue{
	int *ar;
	int front;
	int rear;
	int size;
	public:cirqueue(int n=20)
			{
				front=rear=-1;
				ar=new int(n);
				size=n-1;
			}
		void enqueue(int val)	
		 {
   				if ((front == 0 && rear == size) || (front == rear+1)) {
      			cout<<"Queue Overflow \n";
      			return;
   				}
 			  if (front == -1) {
      			front = 0;
      			rear = 0;
   			} else {
    			  if (rear ==size)
      				rear = 0;
      				else
      				rear = rear + 1;
   				}
   				ar[rear] = val ;
		}
			int dequeue()
			{
				if(rear==front&&rear==-1)
				{
					cout<<"QUEUE IS EMPTY!!!";
					return -1;
				}
				else if(front==size)
				{
					int x=ar[front];
					front=0;
					return x;
				}
				else if(front==rear)
				{
					int x=ar[front];
					front=rear=-1;	
					return x;
				}
				else 
				{
					return ar[front++];
				}
			}
			void display()
			{
				if(front==rear&&rear==-1)
				{
					cout<<"LIST IS EMPTY!!!";
				}
				else if(front==0)
				{
					for(int i=front;i<rear+1;++i)
					{
						cout<<ar[i]<<", ";
					}
				}
				else if(rear<front)
				{
					for(int j=front;j<size+1;++j)
					{
						cout<<ar[j]<<", ";
					}
					for(int y=0;y<rear+1;++y)
					{
						cout<<ar[y]<<", ";
					}
				}
				else if(front==rear)
				{
					cout<<ar[front];
				}
				
				}	
};
int main()
{
		cout<<"ENTER THE SIZE OF QUEUE: ";
	int c;
	cin>>c;
	cirqueue q(c);
	c=0;
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
			case 2:cout<<" ELEMENT "<<q.dequeue()<<" DEQUEUED!!";
									break;
			case 3: q.display();
									break;
		}
	}
}
