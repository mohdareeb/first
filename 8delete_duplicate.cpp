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
		linkedlist* temp=head;
		if(head==NULL){
			cout<<"\nSorry List is empty\n";
		}
		else{
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<"\n";
		}
	}
	linkedlist* removeduplicate(linkedlist* head){
		linkedlist* temp=head;
		while(temp->next!=NULL){
			if(temp->data==temp->next->data){
				linkedlist* temp2=temp->next;
				temp->next=temp2->next;
				delete temp2;
				// temp=temp->next;
			}
			else{
			temp=temp->next;
			}
		}
		return head;
	}
};
int main(){

	linkedlist* head=NULL;
	head=head->add(1,head);
	head=head->add(2,head);
	head=head->add(2,head);
	head=head->add(2,head);
	head=head->add(3,head);
	head->display(head);
	head=head->removeduplicate(head);
	head->display(head);
	return 0;

}