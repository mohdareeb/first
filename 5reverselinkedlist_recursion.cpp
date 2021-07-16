#include<bits/stdc++.h>
using namespace std;
class linkedlist{
public:
	int data;
	linkedlist* next;
	linkedlist(){
		this->next=NULL;
	}
	linkedlist(int data){
		this->data=data;
		this->next=NULL;
	}
	linkedlist* add(int data,linkedlist* head){
		if(head==NULL){
			linkedlist* temp=new linkedlist(data);
			head=temp;
		}
		else{
		linkedlist* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new linkedlist(data);
	}
		return head;
	}
	void display(linkedlist* head){
		if(head==NULL){
			cout<<"\n Linked List is empty\n";
		}
		else{
			linkedlist* temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
	}
	void print_reverse(linkedlist* head){
		if(head==NULL){
			return;
		}
		print_reverse(head->next);
		cout<<head->data<<" ";
	}

};
int main(){
	linkedlist* head=NULL;
	head=head->add(1,head);
	head=head->add(2,head);
	head=head->add(3,head);
	head=head->add(4,head);
	head=head->add(5,head);
	head->display(head);
	cout<<"\nReverse of the linked list \n";
	head->print_reverse(head);
	return 0;
}