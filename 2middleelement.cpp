// implementation of linked list
#include<bits/stdc++.h>
using namespace std;
class linkedlist{
public:
	int data;
	linkedlist* next;
	linkedlist(){
		this->next=NULL;
	}
	linkedlist(int val){
		this->data=val;
		this->next=NULL;
	}
	linkedlist* add(int val,linkedlist* head){
		if(head==NULL){
			linkedlist* temp=new linkedlist(val);
			head=temp;
		}
		else{
		linkedlist* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new linkedlist(val);
		}
		return head;
	}
	void display(linkedlist* head){
		linkedlist* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	int middle(linkedlist* head){
		linkedlist* fast;
		linkedlist* slow;
		fast=head;
		slow=head;
		while( fast!=NULL && fast->next!=NULL ){
			slow=slow->next;
			fast=fast->next->next;
			
		}
		return slow->data;
	}
};
int main(){
	linkedlist* head=NULL;
	head=head->add(1,head);
	head=head->add(2,head);
	head=head->add(3,head);
	head=head->add(4,head);
	head=head->add(5,head);
	head=head->add(6,head);
	head=head->add(7,head);
	head->display(head);

	cout<<"\nFinding the middle element ";
	cout<<head->middle(head);
	return 0;
}