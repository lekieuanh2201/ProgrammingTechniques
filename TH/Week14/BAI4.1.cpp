/*Bài tập 1: Đảo ngược một danh sách liên kết đơn*/

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    /*# YOUR CODE HERE #*/
    Node* d = new Node(data);
    d->next = head;
    return d;
    /*****************/
}

// print the list content on a line
void print(Node* head) {
    /*# YOUR CODE HERE #*/
    Node *d = head;
    while(d != NULL){
        cout<<d->data<<" ";
        d = d->next;
    }
    cout<<endl;
    /*****************/
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    /*# YOUR CODE HERE #*/
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
    /*****************/
}

int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    }

    cout << "Original list: ";
    print(head);

    head = reverse(head);

    cout << "Reversed list: ";
    print(head);

    return 0;
}
