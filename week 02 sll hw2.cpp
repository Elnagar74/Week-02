#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int data) : data(data) { }
};

class linkedList {
private:
    node* head = nullptr;
    node* tail;
    int len = 0;
public:
    // problem 01 --> Delete with key.

    void delete_node_with_key(int key) {
        if (len == 0)
            cout << "Linked list is empty";
        if (head->data == key) {
            node* cur = head;
            head = head->next;
            delete cur;
        }
        else {
            node* cur = head, * pre = head;
            while (cur) {
                if (cur->data == key) {
                    pre->next = cur->next;
                    delete cur;
                    return;
                }
                pre = cur, cur = cur->next;
            }
            cout << "Not found." << endl;
        }
    }

    //******************************************************

    // problem 02 --> Swap each pair vales.

    void swap_pairs() {
        for (node* cur = head; cur; cur = cur->next) {
            if (cur->next != nullptr) {
                swap(cur->data, cur->next->data);
                cur = cur->next;
            }
        }
    }

    //******************************************************

    // problem 03 -->  Reverse list nodes.

    void reverse() {
        if (len <= 1)
            return;
        tail = head; // tail --> first node.
        node* pre = head;
        head = head->next;
        node* next;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        head = pre; // set head.
        tail->next = NULL; // set tail.
    }

    //******************************************************

    // problem 04 -->  Delete even positions.

    void delete_even_positions() {
        if (len < 2)
            return;
        node* current = head;
        if (len % 2 == 0) {
            while (current) {
                current->next = current->next->next;
                current = current->next;
            }

        }
        else {
            while (current->next) {
                current->next = current->next->next;
                current = current->next;
            }
        }
    }

    //******************************************************
};


int main() {

    return 0;
}
