#include<iostream>
using namespace std;
class Node {
	public :
	int data;
	Node *next;

	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};
void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}
	cout << endl;
}
Node* takeInput() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data != -1) {
		Node *newNode = new Node(data);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = tail -> next;
			// OR
			// tail = newNode;
		}

		cin >> data;
	}
	return head;
}
Node* insertNode(Node *head, int i, int data) {
	Node *newNode = new Node(data);
	int count = 0;
	Node *temp = head;

	if(i == 0) {
		newNode -> next = head;
		head = newNode;
		return head;
	}

	while(temp != NULL && count < i - 1) {
		temp = temp -> next;
		count++;
	}
	if(temp != NULL) {
		Node *a = temp -> next;
		temp -> next = newNode;
		newNode -> next = a;
	}
	return head;
}
Node* deleteNode(Node *head, int i) {
    
  int c=0;
  Node *temp=head;
  if(i==0){
   Node *a=head->next;
    delete head;
    head= a;  
    return head;
  } 
  while(temp!=NULL && c<i-1){
    temp=temp->next;
    c++;
  }
  
  if(temp!=NULL){
  Node *a=temp->next;
    if(a==NULL)
      return head;
  temp->next=a->next;
  delete a;}
    return head;
}
int main(){
	cout<<"Enter the initial linked list\n";
Node *head = takeInput();
    cout<<"Choose from the given menu :\n1. Insert a node at i'th position\n2. Delete the i'th node\n";
	
	int i;
	int a;
	cin>>a;
	cout<<"Enter the value of i\n";
	cin >> i ;
	if(a==1){
	int data;
	cout<<"Enter the data to be inserted\n";
	cin>> data;
	head = insertNode(head, i, data);
	cout<<"Now the list becomes :";
	print(head);
}
else if(a==2){
	head=deleteNode(head,i);
	cout<<"Now the list becomes :";
	print(head);
}
	else{
		cout<<"Invalid Operation";
	}
}
