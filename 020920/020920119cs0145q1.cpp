//UTSAB OJHA
//119CS0145
//g++ compiler


#include <iostream>
using namespace std;

struct Node{
    char data;
    Node *link;
};
void PrintList(Node* head)
{
 Node *temp=head;
 while(temp!=NULL)
 {
  cout<<temp->data<<" ";
  temp=temp->link;
 }
 cout<<"\n";
}
Node* InsertAtBeginning(Node* head, char d)
{
 Node *ptr = new Node();
 ptr->data=d;
 ptr->link=head;
 head=ptr;
 return head;
}
Node* search(Node* head,char x)  
{  
    Node* current = head; 
    while (current != NULL)  
    {  
        if (current->data == x){
            return current;      
        }
        current = current->link;  
    } 
    return NULL;
    
} 

void insertAfterLOC(Node* head, Node* loc, int new_data) 
{ 
           
    Node* new_node =new Node();
    new_node->data  = new_data; 
    new_node->link= loc->link;  
    loc->link = new_node; 
} 

void Insert(Node* head,char item,char key){

    Node* LOC =search(head,key);
    if(LOC==NULL){
        head=InsertAtBeginning(head,item);
        PrintList(head);
    }
    else
    {
        insertAfterLOC(head,LOC,item);
        PrintList(head);
    }
}


bool DeleteFirstOccurrence(Node* head, char value) 
{ 
    Node* temp =head;
    Node* save;
    Node* LOC=search(head,value);
    if(LOC==NULL){
        return false;
    }
    if (temp != NULL && temp->data == value) 
    { 
        head = temp->link;           
        return true; 
    } 
  
    while (temp != NULL && temp->data != value) 
    { 
        save = temp; 
        temp = temp->link; 
    } 

    if (temp == NULL) return false; 
  
    save->link = temp->link;
     
    return true;
  
} 



int main()
{
    int k;
    int i;
    char v;
    char key;
    char s;
    int q;
    struct Node* head;


    cout<<"How many value you want to enter?\n";
    cin >> k;
    for(i=0;i<k;i++){

        cout << "Enter value to insert at Beginning.. \n";
        cin >> v;
        head= InsertAtBeginning(head,v);
    }
    cout<<"Success\n";
    cout<<"Result: ";
    PrintList(head);
    cout<<"Menu \n 1.Insert \n 2.Delete \n 3.DeleteAll \n 4.quit\n";
    cin>>q;
    if(q==1){
        cout<<"Insert a value: ";
        cin>>v;
        cout<<"Insert a key: ";
        cin>>key;
        Insert(head,v,key);
        
    }
    if(q==2){
        cout<<"Insert a value to delete: ";
        cin>>v;
        bool a=DeleteFirstOccurrence(head,v);
        PrintList(head);
    }
    if(q==3){
        cout<<"Insert a value to delete: ";
        cin>>v;
        while(DeleteFirstOccurrence(head,v)){
            DeleteFirstOccurrence(head,v);
        }; 
        PrintList(head); 
    }
}