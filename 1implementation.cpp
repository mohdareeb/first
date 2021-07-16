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
};
int main(){
	linkedlist* head=NULL;
	head=head->add(1,head);
	head=head->add(2,head);
	head=head->add(3,head);
	head=head->add(4,head);
	head=head->add(5,head);

	head->display(head);
	return 0;
}