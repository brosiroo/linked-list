#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node *link;
};
node *first=NULL,*last=NULL,*newnode=NULL;
void print_node(node *first){
    node *p = first;
if(first == NULL){
    cout << "The list is empty" << endl;
}else{
while(p != NULL){
    cout << p->data << endl;
    p = p->link;
}
}
}
void insert_node(node *first){
   
int x,y,c=-1;
cout << "Now we will add a new element choose one(give me index and data) :";
cin >> x >> y;

node *q = first;
if(first == NULL){
    newnode = new node;
        first = newnode;
        last = newnode;
        newnode->data = y;
        newnode->link = NULL;
   }else{
while(q != NULL){
   
    if(c == x){
     newnode = new node;
     newnode->link = q->link;
     q->link = newnode;
     newnode->data = y;
    }
    
 
   q = q->link;
    c++;

} 
}
}
void delete_node(node *first){
if(first == NULL){
    cout << "Cant delete from empty list" << endl;
}else {
    int n,c=1;
    cout << "Enter index to delete : ";
    cin >> n;
    node *q = first;

    while(q != NULL){
        if(c == n){
         node *del = q->link;
         q->link = del->link;
         delete del;
        c++;
           break;
        }else {
            q = q->link;
             c++;
        }
       

    }

}
}
int main(){

int num;cin >> num;

while(num != -999){
    if(first == NULL){
        newnode = new node;
        first = newnode;
        last = newnode;
        newnode->data = num;
        newnode->link = NULL;
    }else{
        newnode = new node;
        newnode->data = num;
        newnode->link = NULL;
        last->link = newnode;
        last = newnode;
    }
    cin >> num;
}
int n;
print_node(first);
cout << "You want to insert enter 1 for delete enter 0 : ";
cin >> n;
if(n)
insert_node(first);
else 
delete_node(first);

print_node(first);

}