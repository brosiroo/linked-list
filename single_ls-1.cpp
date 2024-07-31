#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *link;
};

node *first = NULL, *last = NULL, *newnode = NULL;

void print_node() {
    node *p = first;
    if (first == NULL) {
        cout << "The list is empty" << endl;
    } else {
        while (p != NULL) {
            cout << p->data << endl;
            p = p->link;
        }
    }
}

void insert_first() {
    int n;
    cout << "Enter num to insert: ";
    cin >> n;
    newnode = new node;
    newnode->data = n;
    if (first == NULL) {
        first = newnode;
        last = newnode;
        newnode->link = NULL;
    } else {
        newnode->link = first;
        first = newnode;
    }
}

void insert_last() {
    int n;
    cout << "Enter num to insert: ";
    cin >> n;
    newnode = new node;
    newnode->data = n;
    newnode->link = NULL;
    if (last == NULL) {
        first = newnode;
        last = newnode;
    } else {
        last->link = newnode;
        last = newnode;
    }
}

void insert_node(int c) {
    int x, y;
    cout << "Now we will add a new element. Choose one (give me index and data): ";
    cin >> x >> y;

    node *q = first;
    if (first == NULL) {
        newnode = new node;
        newnode->data = y;
        newnode->link = NULL;
        first = newnode;
        last = newnode;
    } else {
        int index = 0;
        while (q != NULL) {
            if (index == x) {
                newnode = new node;
                newnode->data = y;
                newnode->link = q->link;
                q->link = newnode;
                if (newnode->link == NULL) {
                    last = newnode;
                }
                break;
            }
            q = q->link;
            index++;
        }
    }
}

void delete_node() {
    if (first == NULL) {
        cout << "Can't delete from an empty list" << endl;
    } else {
        int n;
        cout << "Enter index to delete: ";
        cin >> n;
        node *q = first;
        node *prev = NULL;

        int index = 0;
        while (q != NULL) {
            if (index == n) {
                if (prev == NULL) {
                    first = q->link;
                } else {
                    prev->link = q->link;
                }
                if (q == last) {
                    last = prev;
                }
                delete q;
                break;
            }
            prev = q;
            q = q->link;
            index++;
        }
    }
}

int main() {
    int c = 0;
    int num;
    cin >> num;

    while (num != -999) {
        newnode = new node;
        newnode->data = num;
        newnode->link = NULL;
        if (first == NULL) {
            first = newnode;
            last = newnode;
        } else {
            last->link = newnode;
            last = newnode;
        }
        cin >> num;
        c++;
    }

    print_node();

    int n;
    cout << "For insert first(0), last(1), else (2): ";
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

    int l;
    cout << "If you want to delete any element press (0 for NO) or (1 for YES): ";
    cin >> l;
    if (l) {
        delete_node();
    }

    print_node();

    return 0;
}
