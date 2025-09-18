#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *back;
};

//Converting array to linked list
Node* convert2DDL(vector<int>&nums){
    Node* head=nullptr;
    Node*temp=nullptr;
    for(int i=0;i<nums.size();i++){
        Node* newnode=new Node();
        newnode->data=nums[i];
        newnode->next=nullptr;
        newnode->back=nullptr;
        if(head==nullptr){
        head=newnode;
        temp=head;
    }
    else{
        temp->next=newnode;
        newnode->back=temp;
        temp=temp->next;
    }
    }
    return head;
    
}


//Traversing linked list
void trav(Node* head){
    Node*temp=head;
    while(temp->next!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}

//Insertion at beginning
Node* insertionAtHead(Node* head){
    int x;
    cout<<"Enter the value of node you want insert at head:  ";
    cin>>x;
    Node* newnode=new Node();
    newnode->back=nullptr;
    newnode->next=nullptr;
    newnode->data=x;

    if(head==nullptr){
        head=newnode;
    }
    else{
        head->back=newnode;
        newnode->next=head;
        head=newnode;
    }
    return head;
}


//Insertion at tail
Node* insertionAtTail(Node* head){
    int x;
    cout<<"Enter the value of node you want insert at tail:  ";
    cin>>x;
    Node* newnode=new Node();
    newnode->back=nullptr;
    newnode->next=nullptr;
    newnode->data=x;

     if(head==nullptr){
        head=newnode;
    }

    else{
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->back=temp;
    }
    return head;

}

//Insertion at kth position
Node* insertionAtK(Node* head,int k){
  
    int x;
    cout<<"Enter the value of node you want insert at kth position:  ";
    cin>>x;
    Node* newnode=new Node();
    newnode->back=nullptr;
    newnode->next=nullptr;
    newnode->data=x;

     if(k==1){
        head=newnode;
    }
    else{
          int cnt=1;
        Node*temp=head;
        Node* prev=head;
        while(temp!=nullptr){
            
            if(cnt==k)break;
            prev=temp;
            temp=temp->next;
            cnt++;
        }
       prev->next=newnode;
       newnode->back=prev;
       newnode->next=temp;
       temp->back=newnode;
    }
    return head;
}


//Deletion at beginning
Node* deletionAtBeg(Node* head){
    if(head==nullptr){
        cout<<"Linked List is empty";
    }
    else{
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    return head;
}

//Deletion at Tail
Node* deletionAtTail(Node*head){
     if(head==nullptr){
        cout<<"Linked List is empty";
    }
    else{
        Node* temp=head;
        Node* prev=head;
        while(temp->next!=nullptr){
            prev=temp;
            temp=temp->next;
        }
        prev->next=nullptr;
        delete temp;
    }
    return head;
}


//deleteion after kth pos
Node* deletionAtK(Node* head,int k){
    if(head==nullptr){
        cout<<"Linked List is empty";
    }
    else{
        Node*temp=head;
    Node*prev=head;
    Node*front=head;
    int cnt=1;
    while(temp!=nullptr){
        if(cnt==k)break;
        temp=temp->next;
        cnt++;
    }
   front=temp->next;
   prev=temp->back;
   if(prev==nullptr&&front==nullptr){
    return nullptr;
   }
   else if(prev==nullptr){
    return deletionAtBeg(head);
   }
   else if(front==nullptr){
    return deletionAtTail(head);
   }
   else{
    prev->next=front;
   front->back=prev;
   delete temp;
   }
   
    }
    return head;


}

int main(){
    vector<int>nums={4,6,2,3};
     Node *head=convert2DDL(nums);
    // head= insertionAtHead(head);
    // head= insertionAtTail(head);
    trav(head);
    // head=insertionAtK(head,2);
    // head=deletionAtBeg(head);
    // head=deletionAtTail(head);
    head=deletionAtK(head,1);
    cout<<"After deletion"<<endl;
     trav(head);

}