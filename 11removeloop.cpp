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
	linkedlist* removeduplicate_unsorted(linkedlist* head){
		set<int> s;
		linkedlist* temp=head;
		temp=head;
		linkedlist* prev;
		while(temp->next!=NULL){
			if(s.count(temp->data)){
				prev->next=temp->next;
				temp=prev;
			}
			else{
				s.insert(temp->data);
				prev=temp;
			}
			temp=temp->next;
		}
		return head;
	}
	bool detect(linkedlist* head){
		linkedlist* fast=head;
		linkedlist* slow=head;
		while(fast!=NULL && fast->next !=NULL){
			fast=fast->next->next;
			slow=slow->next;
			if(fast==slow){
				return true;
			}
		}
		return false;
	}
	linkedlist* remove(linkedlist* head){
		linkedlist* slow=head;
		linkedlist* fast=head;
		while(fast!=NULL && fast->next!=NULL){
			fast=fast->next->next;
			slow=slow->next;
			if(fast==slow){
				break;
			}
		}
		slow=head;
		while(slow->next!=fast->next){
			slow=slow->next;
			fast=fast->next;
		}
		fast->next=NULL;
		return head;
	}
};
int main(){

	linkedlist* head=NULL;
	head=head->add(1,head);
	head=head->add(5,head);
	head=head->add(2,head);
	head=head->add(5,head);
	head=head->add(3,head);
	head->display(head);
	linkedlist* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=head->next;
	if(head->detect(head)){
		cout<<"Yes loop is present";
		cout<<"\nNow we are going to remove the loop\n";
		head=head->remove(head);
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		cout<<temp->data;		
	}
	else{
		cout<<"Loop is not present";
	}
	return 0;

}