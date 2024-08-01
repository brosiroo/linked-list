#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    struct node* link;
    struct node* prev;
};

node* first = NULL;
node* last = NULL;
node* newnode = NULL;

void print_node() {
    node* p = first;
    while (p != NULL) {
        cout << p->data << endl;
        p = p->link;
    }
}

void insert_first() {
    if (first == NULL) {
        first = newnode;
        last = newnode;
        newnode->prev = NULL;
        newnode->link = NULL;
    } else {
        int x;
        cout << "Enter num to insert: ";
        cin >> x;
        newnode = new node;
        newnode->prev = NULL;
        newnode->link = first;
        newnode->data = x;
        if (first != NULL) {
            first->prev = newnode;
        }
        first = newnode;
        if (last == NULL) {
            last = newnode;
        }
    }
}

void insert_last() {
    if (first == NULL) {
        first = newnode;
        last = newnode;
        newnode->prev = NULL;
        newnode->link = NULL;
    } else {
        int x;
        cout << "Enter num to insert: ";
        cin >> x;
        newnode = new node;
        newnode->prev = last;
        newnode->data = x;
        newnode->link = NULL;
        last->link = newnode;
        last = newnode;
    }
}

void insert_node(int c) {
    int b = c;
    if (first == NULL) {
        first = newnode;
        last = newnode;
        newnode->prev = NULL;
        newnode->link = NULL;
    } else {
        int n, x, v = 0;
        cout << "Enter num to insert and its index: ";
        cin >> n >> x;
        node* q = first;
        while (q != NULL) {
            if (v == n && v != b) {
                newnode = new node;
                newnode->data = x;
                newnode->prev = q;
                newnode->link = q->link;
                q->link = newnode;
                break;
            } else {
                q = q->link;
            }
            v++;
        }
        b++;
    }
}
void delete_last() {
    if (last == NULL) {
        cout << "The list is empty" << endl;
    } else {
        node* del = last;
        if (last->prev != NULL) {
            last = last->prev;
            last->link = NULL;
        } else {
            first = last = NULL;
        }
        delete del;
    }
}

void delete_first(){
    if(first == NULL){
     cout << "The list is empty" << endl; 
    }else{
        node *p = first;
        node *del = p;
        first = p->link;
        p->link->prev = NULL;
        delete del;
        }
}
void delete_node(int c){
    int n, v =0;
    cout << "Which element you want to delete :";
    cin >> n;
    node *p = first;
    node *current_prev= p->prev;
    if(first == NULL){
        cout << "The list is empty" << endl;
    }else {
        while(p != NULL){
            if(n == 0){
                delete_first();
                 break;
            }else if(n == c){
               delete_last(); break;
            }else if (n == v) {
                node* del = p;
                if (del->prev != NULL) {
                    del->prev->link = del->link;
                }
                if (del->link != NULL) {
                    del->link->prev = del->prev;
                }
                delete del;
                break; 
                      
            }
            p = p->link;
            v++;
        }
    }

}

int main() {
    int num, c = 0;
    cin >> num;
    while (num != -999) {
        if (first == NULL) {
            newnode = new node;
            first = newnode;
            last = newnode;
            newnode->prev = NULL;
            newnode->data = num;
            newnode->link = NULL;
        } else {
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
    cout << "Number of nodes is: " << c << endl;
    print_node();
    int n;
    cout << "for insert first(0) last(1) else (2): ";
    cin >> n;
    if (n == 2) {
        insert_node(c);
        c++;
    } else if (n == 0) {
        insert_first();
        c++;
    } else if (n == 1) {
        insert_last();
        c++;
    }
    cout << "Number of nodes is: " << c << endl;
    bool flag;
    cout << "Do you want to delele an element ?  (1 for YES) or (0 for NO) : ";
    cin >> flag;
    if(flag){delete_node(c); c--;}
    
    print_node();
    cout << "Number of nodes is: " << c << endl;
}
