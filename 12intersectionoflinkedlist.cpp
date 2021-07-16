
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
	int length(linkedlist* head){
		int count=0;
		linkedlist* temp=head;
		while(temp!=NULL){
			temp=temp->next;
			count++;
		}
		return count;
	}
	int intersectionpoint(linkedlist* head1,linkedlist* head2,int diff){
		linkedlist* pointer1=head1;
		linkedlist* pointer2=head2;
		while(diff>0){
			pointer1=pointer1->next;
			diff--;
		}
		while(pointer1 != pointer2){
			pointer1=pointer1->next;
			pointer2=pointer2->next;
		}
		return pointer1->data;

	}
	int intersection(linkedlist* head1,linkedlist* head2){
		int len1 = length(head1);
		int len2 = length(head2);
		int result;
		if(len1>len2){
			 result=intersectionpoint(head1,head2,len1-len2);
		}
		else{
			 result=intersectionpoint(head2,head1,len2-len1);
		}
		return result;
	}
};
int main(){

	linkedlist* head1=NULL;
	head1=head1->add(1,head1);
	head1=head1->add(2,head1);
	head1=head1->add(3,head1);
	head1=head1->add(4,head1);
	head1=head1->add(5,head1);

	linkedlist* head2=NULL;
	head2=head2->add(6,head2);
	head2=head2->add(7,head2);

	linkedlist* temp=head1;
	while(temp->data!=4){
		temp=temp->next;
	}
	head2->next->next=temp;
	cout<<"Intersection Point "<<head1->intersection(head1,head2);
	
	return 0;

}