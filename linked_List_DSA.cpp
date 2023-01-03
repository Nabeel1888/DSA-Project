#include <iostream>
using namespace std;

struct node {                  //a node implemented using struct having a data part and pointer
	int data;
	node* next;
};

int main() {

	node* headpointer=NULL;     //a head pointer is created having address of the first node

	int option=1,noNodes=0;

	while (option != -1) {

		cout << " enter a value from the menu given below " << endl;

		cout << " 1) Insert value at start of list " << endl;

		cout << " 2) Traverse through the linked list " << endl;

		cout << " 3) Insert value at end of link list " << endl;

		cout << " 4) Insert after a specified number of nodes " << endl;

		cout << " 5) Delete Node from list front " << endl;

		cout << " 6) Delete Node from list back " << endl;

		cout << " 7) Sort Nodes " << endl;

		cout << " 8) Inserting new node between existing nodes " << endl;  //an extra case I did


		cin >> option;

		switch (option) {

		case 1: {

			int value;

			cout << " kindly enter a value " << endl;

			cin >> value;

			node* pointer = new node;    //a new node is created 

			noNodes++;					//number of nodes is incremented

			pointer->data = value;       //value taken from user transffered to new node

			pointer->next = headpointer; //pointer in the new node gets value of headpointer

			headpointer = pointer;		//head pointer value updated to addres of new node


			break;
		}

		case 2: {
			
			node* temp = headpointer;	//temporary pointer is made with address of head ptr

			while (temp!=NULL) {		//a loop is run untill we reach the end of the list

				cout << temp->data << endl;		//data of each node is dispalyed
				
				temp = temp->next;				//address of the temp pointer is changed
				
			}

			break;
		}

		case 3: {

			node* pointer = new node;		//new node is created

			noNodes++;

			int value;

			cout << " kindly enter a value" << endl;

			cin >> value;

			pointer->data = value;		//value from user placed in the node

			pointer->next = NULL;		//pointer in node has value of null since last node

			node* temp = headpointer;	//temporary pointer with address of head pointer

			while (temp->next != NULL) {	//when node with pointer=NULL we break
				
				temp = temp->next;			//address of temp pointer is changed
			}

			temp->next = pointer;	//pointer in second last node has the address of new node

			break;
		}

		case 4: {

			node* pointer = new node;		//new node to insert is created
			
			noNodes++;						//number of nodes is incremented

			node* temp=headpointer;			//a pointer created with address of headpointer

			int target=0,value=0,counter = 1;

			cout << " kindly enter the value that you want to insert" << endl;

			cin >> value;

			cout <<" kindly enter the number of nodes after which you want to insert value" << endl;

			cin >> target;

			if (target == 0) {		//if target is 0 it means node to be placed at front of list

				pointer->next = headpointer;	//head nodes pointer gets a value

				pointer->data = value;			//head nodes data gets a value taken from user

				headpointer = pointer;			//headpointer value is updated with new node 
			}

			else if(target<=noNodes) {

				while (counter != target) {

					temp = temp->next;

					counter++;
				}

				pointer->next = temp->next;

				temp->next = pointer;

				pointer->data = value;
			}

			else if (target<0 || target>noNodes) {

				cout << " entered number of nodes dosent exist " << endl;
			}

			break;
		}

		case 5: {

			if (headpointer==NULL) {

				cout << " list is empty " << endl;

			}
			else {

				headpointer = headpointer->next;

				noNodes--;

			}

			break;
		}

		case 6: {

			node* currentptr = headpointer;		//two pointers are made 

			node* previousptr=NULL;					

			if (currentptr == NULL) {

				cout << " the linked list does not exist " << endl;

			}
			else {

				while (currentptr->next != NULL) {

					previousptr = currentptr;

					currentptr = currentptr->next;
				}

				previousptr->next = NULL;

				noNodes--;
			}

			break;
		}

		case 7: {

			if (headpointer == NULL || headpointer->next == NULL) {

				cout << " not enough nodes to preform sorting " << endl;

			}

			else {

				node* temp = headpointer;

				int* array = new int[noNodes];

				for (int i = 0; i < noNodes; i++) {

					array[i] = temp->data;

					temp = temp->next;
				}

				for (int i = 0; i < noNodes - 1; i++) {

					for (int x = 0; x < (noNodes - 1) - i; x++) {

						if (array[x] > array[x + 1]) {

							int tempdata = array[x + 1];

							array[x + 1] = array[x];

							array[x] = tempdata;
						}
					}
				}

				temp = headpointer;

				for (int i = 0; i < noNodes; i++) {

					temp->data = array[i];

					temp = temp->next;
				}

			}

			break;	
		}

		case 8: {

			node* pointer = new node;		    //new node is made

			node* forwardptr=NULL;				//a pointer is made for the forward node

			node* backwardptr=NULL;			    //a pointer is made for the backward node

			int value, keyForward, keyBackward;		//keys, which are the data vales, stored

			cout << " kindly enter the value you want to store" << endl;

			cin >> value;

			cout << " kindly enter the key of the two nodes that you want to place the value between " << endl;

			cin >> keyForward;

			cin >> keyBackward;

			forwardptr = headpointer;

			while (forwardptr->data != keyForward && forwardptr!=NULL) {

				backwardptr = forwardptr;

				forwardptr = forwardptr->next;
			
			}
			if (forwardptr == NULL) {

				cout << " the node between you want to palce the value does not exist " << endl;

			}
			else if (backwardptr == NULL) {

				cout << " the node between you want to place the value does not exist " << endl;

			}
			else {

				backwardptr->next = pointer;

				pointer->next = forwardptr;

				pointer->data = value;

			}
		}
			  break;
		}
	}
}