//Searches an element in a given Linked List through iterative method

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class List
{
private:
	Node *head;				//head for the list
public:
	List() { head = NULL; }
	Node* create(int);
	void InsertBegin(int);
	void Display();
	void SearchElement( );

};


Node* List::create(int localData)			//for creating a node
{

	try {

		Node *node = new Node;
		if (node == NULL)
		{
			cout << "Allocation failure\n";
		}

		node->data = localData;
		node->next = NULL;
		return node;
	}
	catch (bad_alloc xa)
	{
		cout << "Allocation failure\n";
		return NULL;
	}

}

void List::InsertBegin(int dataItem)			//for inserting the node in the of Begining list
{
	Node *node = create(dataItem);
	if (node!=NULL)
	{
		if (head == NULL)
		{
			head = node;
			node->next = NULL;
		}
		else
		{
			node->next = head;
			head = node;
		}
	}
	else
	{
		cout << "Can't create node\n";
	}

}

void List::SearchElement()
{
    int element;
	cout<<"\nEnter Element to search\n";
    cin>>element;

	Node *temp=head;
	while(temp!=NULL)
	{
		if(temp->data==element)
		{
			cout<<"Element found!!\n";
			return;
		}
        temp=temp->next;
	}
	cout<<"Element not found!\n";
}

void List::Display()						//for displaying the list
{
	cout << "\nContents of List:\n";
	Node*temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int main()
{
	List list1;

	for (int i = 0; i <4; ++i)
	{
		list1.InsertBegin(i);

	}
    list1.Display();

    list1.SearchElement();
	return 0;
}
