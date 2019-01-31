#include<iostream>
using namespace std;
template<class T>
class node{
	public:
		node(T d=0,node *n=NULL)
		{
			data=d;
			next=n;
		}
		T data;
		node *next;
};
template<class T>
class linkedlist{
	public:
		linkedlist(node <T>*h=NULL,node<T> *t=NULL)
		{
			head=h;
			tail=t;
		}
		void insert_at_end(T x);
		linkedlist<T> operator +(linkedlist l2);
		void display();
		protected:
			node<T> *head,*tail;
};
template<class T>
void linkedlist<T>::insert_at_end(T x)
{
	node<T> *p=new node<T>(x);
	if(head==NULL)
	{
		head=tail=p;
	}
	else
	{
		tail->next=p;
		tail=tail->next;
	}
}
template<class T>
linkedlist<T> linkedlist<T>::operator +(linkedlist l2)
{
	node <T>*temp=l2.head;
	node <T>*p3=head;
	
	linkedlist <T>l3;

	while(p3!=NULL)
	{
		l3.insert_at_end(p3->data);
		p3=p3->next;
	}

	while(temp!=NULL)
	{ 
			l3.insert_at_end(temp->data);
	    	temp=temp->next;
	    }
	   	return l3; 	
}

template<class T>
void linkedlist<T>::display()
{
	node<T> *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
	linkedlist <int>l1,l2,l3;
	l1.insert_at_end(1);
	l1.insert_at_end(2);
	l2.insert_at_end(3);
	l1.display();
	cout<<endl;
	l2.display();
	cout<<endl;
	l3=l1+l2;
	l3.display();
	cout<<endl;
	return 0;
}

