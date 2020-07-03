#include<iostream>
using namespace std;
class node
{
	public:
	int info;
	node *left,*right;
		node(int val,node *p=0,node *q=0)
		{
			info=val;
			left=p;
			right=q;
		}
};
class queue{
	node *head;
	public:
		queue()
		{
			head=NULL;
		}
		void enqueue(node *ptr)
		{
			ptr->right=NULL;
			if(head==NULL)
			{
				head=ptr;
			}
			else
			{
				node *p=head;
				while(p->right)
				{
					p=p->right;	
				}	
				p->right=ptr;
			}	
		}
		int isempty()
		{
			if(!head)
			return 1;
			else
			return 0;
		}
		node* dequeue()
		{
			node *tmp=head;
			head=head->right;
			return tmp;
		}
};


class bst
{
	
	public:
		node *root;
		bst()
		{
			root=0;
		}
		void insert(int val)
		{
			node *prev=0,*curr=root;
			while(curr)
			{
				prev=curr;
				if(val<=curr->info)
				curr=curr->left;
				else
				curr=curr->right;
			}
			if(prev)
			{
				if(val<=prev->info)
				prev->left=new node(val);
				else
				prev->right=new node(val);
			}
			else
			root=new node(val);
		}
		int search(int val)
		{
			node *curr=root;
			while(curr)
			{
				if(curr->info==val)
				return 1;
				else if(val<curr->info)
				curr=curr->left;
				else
				curr=curr->right;
			}
			return 0;
		}
			void breadthwise()
		{
			queue q;
			node *p=root;
			if(p)
			{
				q.enqueue(p);
				while(!q.isempty())
				{
					p=q.dequeue();
					cout<<(p->info);
					if(p->left)
					q.enqueue(p->left);
					if(p->right)
					q.enqueue(p->right);
				}
			}
		}
		void preorder(node *x) //VLR
		{
			if (x)
			{
				cout<<x->info;
				preorder(x->left);
				preorder(x->right);
			}
		}
		void inorder(node *x) //LVR
		{
			if (x)
			{
				inorder(x->left);
				cout<<x->info;
				inorder(x->right);
			}
		}
		void postorder(node *x) 
		{
			if (x)
			{
				postorder(x->left);
				postorder(x->right);
				cout<<x->info;
			}
		}
		int leaves(node *ptr)
		{
			if(ptr)
			{
				if(ptr->left==0&&ptr->right==0)
				return 1;
				else
				return(leaves(ptr->left)+leaves(ptr->right));
			}
			else
			return 0;
		}
		int internal(node *ptr)
		{
			if(ptr)
			{
				if(ptr->left==0&&ptr->right==0)
				return 0;
				else
				return(1+internal(ptr->left)+internal(ptr->right));
			}
			else
			return 0;
		}
		int height(node *ptr)
		{
			if(ptr)
			{
				int l=height(ptr->left);
				int r=height(ptr->right);
				if(l>r)
				return l+1;
				else
				return r+1;
			}
			else
			return 0;
		}
		void mirror(node *ptr)
		{
			if(ptr)
			{
				mirror(ptr->left);
				mirror(ptr->right);
				node *temp=ptr->left;
				ptr->left=ptr->right;
				ptr->right=temp;
				
			}
			else
			return;
		}
		void findndelbycopy(int el)
		{
			node *ptr=root;
			while(ptr)
			{
				if(ptr->info==el)
				break;
				if(el<ptr->info)
				ptr=ptr->left;
				else
				ptr=ptr->right;
			}
			if(ptr!=0&&ptr->info==el)
			{
				deletebycopy(ptr);
			}
		}
		void deletebycopy(node *&ptr)
		{
			node *temp=ptr,*prev;
			if(ptr)
			{
				if(ptr->right==0)
				ptr=ptr->left;
				else if(ptr->left==0)
				ptr=ptr->right;
				else
				{
					temp=ptr->left;
					prev=ptr;
					while(temp->right!=0)
					{
						prev=temp;
						temp=temp->right;
					}
					ptr->info=temp->info;
					if(prev==ptr)
					prev->left=temp->left;
					else
					prev->right=temp->right;
				}
				delete temp;
			}
		}
		void findndelbymerge(int val)
		{
			node *ptr=root,*prev=0;
			while(ptr)
			{
				if(ptr->info==val)
				break;
				prev=ptr;
				if(val<ptr->info)
				ptr=ptr->left;
				else
				ptr=ptr->right;
				
			}
			if(ptr!=0&&ptr->info==val)
			{
				if(ptr==root)
				deletebymerge(root);
				else if(prev->left==ptr)
				deletebymerge(prev->left);
				else
				deletebymerge(prev->right);
			}
		}
		void deletebymerge(node *&ptr)
		{
			node *temp=ptr;
			if(ptr)
			{
				if(ptr->right==0)
				ptr=ptr->left;
				else if(ptr->left==0)
				ptr=ptr->right;
				else
				{
					temp=ptr->left;
					for(;temp->right!=0;temp=temp->right);
					temp->right=ptr->right;
					temp=ptr;
					ptr=ptr->left;
				}
				delete temp;
			}
		}
		node* delchild(node *ptr)
		{
			if(ptr)
			{
				if((ptr->left==0&&ptr->right==0))
				{
					delete ptr;
					return 0;
				}
				else
				{
					ptr->left=delchild(ptr->left);
					ptr->right=delchild(ptr->right);
				}
			}
		}
		
	};
	int main()
{
	char ch = 'y';
	bst ob;
	int count=0;
	int n, val, b, c = 1;
	do
	{
		cout << "1. Insert\n";
		cout << "2. Search\n";
		cout << "3. Preorder\n";
		cout << "4. Postorder\n";
		cout << "5. Inorder\n";
		cout << "6. Height\n";
		cout << "7. Number Of Leaves\n";
		cout << "8. Number of internal nodes\n";
		cout << "9. Display\n";
		cout << "10. Breadth Wise traversal\n";
		cout << "11. Mirror\n";
		cout << "12. Delete By copy\n";
		cout << "13. Delete By merge\n";
		cout << "Enter your choice:";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "\nEnter the number:";
			cin >> val;
			ob.insert(val);
			break;
		case 2:
			cout << "\nEnter the number:";
			cin >> val;
			b = ob.search(val);
			if (b == 1)
				cout << "Element found";
			else
				cout << "NO Element found";
			break;
		case 3:
			ob.preorder(ob.root);
			break;
		case 4:
			ob.postorder(ob.root);
			break;
		case 5:
			ob.inorder(ob.root);
			break;
		case 6:
			val = ob.height(ob.root);
			cout << "Height of the tree is:" << val;
			break;
		case 7:
			count=ob.leaves(ob.root);
			cout << "No.of leaves:" << count;
			break;
		case 8:
			count=ob.internal(ob.root);
			cout << "No.of Internal nodes:" << count;
			break;
			
		case 9:

		case 10:
			ob.breadthwise();
			break;
		case 11:
			
		case 12:
			cout << "\nEnter the number:";
			cin >> val;
			ob.findndelbycopy(val);
			break;
		case 13:
			cout << "\nEnter the number:";
			cin >> val;
			ob.findndelbymerge(val);
			break;
		case 14:
			ob.delchild(ob.root);
			break;
		default:
			cout << "\nWrong choice";
			break;
		}
		cout << "\nDp you want to continue  (y/n)";
		cin >> ch;
	} while (ch == 'y' || ch == '1');
	return 0;
}
