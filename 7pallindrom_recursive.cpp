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
	linkedlist* reverse(linkedlist* head){
		linkedlist* prev=NULL;
		linkedlist* pres=head;
		linkedlist* futr;
		while(pres!=NULL){
			futr=pres->next;
			pres->next=prev;
			prev=pres;
			pres=futr;
		}
		head=prev;
		return head;
	}
	bool is_pallindrom(linkedlist* &left,linkedlist* right){
		if(right==NULL){
			return true;
		}
		bool first=is_pallindrom(left,right->next);
		if(first==false){
			return false;
		}
		bool second=left->data == right->data;
	  	left=left->next;
	  	return second;
	}

};
int main(){
	linkedlist* head=NULL;
	head=head->add(1,head);
	head=head->add(2,head);
	head=head->add(3,head);
	head=head->add(2,head);
	head=head->add(1,head);
	head->display(head);
	cout<<"\nPallindrom Linked List : \n";
	cout<<head->is_pallindrom(head,head);

	return 0;
}