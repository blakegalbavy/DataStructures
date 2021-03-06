#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;

Node::Node()
{
	//initializing values
	val = (-1);
	next = NULL;
}

void
Node::Print()
{
	std::cout << val;
}

List::List()
{
	count = 0;
	first = NULL;
}

void
List::Insert(NodePtr n)
{
	if (first == NULL)   //if condition for when the list is EMPTY
	{
		first = n;  
		// our list is now pointing to the first node.
		count++;
	}
	else                  //if condition for when the list is NOT EMPTY
	{
		NodePtr temp;

		temp = first;
		while (temp->next != NULL)
		{
			temp = temp->next;		
		}
		// connecting the temp->next to our initial node
		temp->next = n;
		count++;
	}
	return;
}

NodePtr
List::Find(int val)
{
	// we have to re-initialize it
	NodePtr temp = first;

	while (temp->val != val)
	{	
		temp = temp->next;	
	}
	//return the value found
	return temp;
}

void
List::Remove(NodePtr n)
{

	NodePtr temp = first;
	NodePtr current = first;

	while (current != NULL && current != n)
	{
		temp = current;
		current= current->next;
	}
	if (current != n )
	{
		cout<<"Node was not in the list.\n";
	}	
	else
	{
	      
		//now skip over the node that will be deleted
		current = current->next;
		//now connect temp to current
		temp->next = current;
		//if first is the one that needs to be deleted. Just make the first pointer the next node. 
		if (first == n)
		{
			first = first->next;
		}
	}

	return;
}

void
List::Print()
{
	NodePtr p;

	std::cout << "[";
	for (p = first; p != NULL; p = p->next) {
		p->Print();
		if (p->next != NULL)
			std::cout << ",";

	}
	std::cout << "]";
}
