#include <bits/stdc++.h>

using namespace std;
struct node {
int data; 
struct node *link;  
struct node *prev;  
};
node *first = NULL ,*last = NULL,*newnode=NULL;
void print_node(){
node *p =first;

while(p != NULL){
    cout << p->data << endl;
    p = p->link;
}
}
void insert_first(){

if(first == NULL){
first = newnode;
last = newnode;
newnode->prev = NULL;
newnode->link = NULL;
}else {
 int x; 
 cout << "Enter num to insert : ";
cin >> x;

         newnode = new node;
      
          newnode->prev = NULL;
          newnode->link = first;
          newnode->data = x;
          if (first != NULL) {
        first->prev = newnode;
    }
    first = newnode;
          
            if(last == NULL){
                last == newnode;
            }
      
}
}

void insert_last(){
    if(first == NULL){
first = newnode;
last = newnode;
newnode->prev = NULL;
newnode->link = NULL;
}else {
     int x; 
 cout << "Enter num to insert : ";
cin >> x;
        
            newnode = new node;
           newnode->prev = last;
          newnode->data = x;
          newnode->link = NULL;
          last->link = newnode;
          last = newnode;
              
        
}
}

void insert_node(int c){
    int b;
    b = c;
if(first == NULL){
first = newnode;
last = newnode;
newnode->prev = NULL;
newnode->link = NULL;
}else{
    int n ,x , v=0;
     cout << "Enter num to insert  and it index : ";
      cin >> n >> x;
    node *q = first;
    while(q != NULL){
     if(v == n && v != b){
            newnode = new node;
            newnode->data = x;
            newnode->prev = q;
            newnode->link = q->link;
            q->link = newnode;
            break;
        }
        else {
        q = q->link;
        }
        v++;
    }    
 b++;
}
}
int main() {

int num,c=0;
cin >> num;
while(num != -999){
    if(first  ==  NULL){
      newnode = new node;
        first = newnode;
        last = newnode;
        newnode->prev = NULL;
        newnode->data = num;
        newnode->link = NULL;
        
    }else{
       newnode = new node;
       newnode->prev = last;
       newnode->data = num;
       newnode->link = NULL;
       last->link = newnode;
       last = newnode;
    }
    c++;
cin >> num;
}
cout << "Number of nodes is : " << c << endl;
print_node();
int n;
cout << "for insert first(0) last(1) else (2) : "; cin >> n;
if(n==2)
{insert_node(c);c++;}
else if(n==0)
{insert_first();c++;}
else if(n==1)
{insert_last();c++;}

print_node();
cout << "Number of nodes is : " << c << endl;

}