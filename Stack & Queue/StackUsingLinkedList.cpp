#include<bits/stdc++.h>
using namespace std;

struct node {
    int value;
    node* next;
}*head;

void push(int value){
    node *newNode = new node;
    newNode->value = value;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->next=head;
        head = newNode;
    }
}
int pop(){
    int y = head->value;
    head = head->next;
    return y;
}
int peek(){
    return head->value;
}

void display(){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->value<<endl;
        temp = temp->next;
    }
}

int main(){

    head = NULL;
    while(1){
		cout<<"1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Display\n0. Exit"<<endl;
		int x;
		cin>>x;
		if(x==0) break;
		else if(x==1){
			cout<<"Enter a value: ";
			int y;
			cin>>y;
			push(y);
		}
		else if(x==2){
			int y = pop();
			cout<<y<<endl;
		}
		else if(x==3){
			int y = peek();
			cout<<y<<endl;
		}
		else if(x==5){
			display();
		}
	}

}