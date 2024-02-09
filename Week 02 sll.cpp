#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int data) : data(data) {}
};

class LinkedList {
private:
    node* head = nullptr;
    node* tail;
    int len;

public:
    // problem 01 --> Destructor .. free all the created nodes.

    ~LinkedList() {
        node* current;
        while (head != NULL) {
            current = head->next;
            delete head;
            head = current;
        }
    }

    //********************************************************************************************************

    // problem 02 --> Insert front.

    void addAtfront(int value) {
        node* newNode = new node(value);
        newNode->next = head;
        head = newNode;
        len++;
    }

    //********************************************************************************************************

    // problem 03 --> Delete front

    void deleteAtfront() {
        if (head == NULL)
            cout << "Linked list is empty.";
        else if (head->next == NULL)
            head = NULL;
        else {
            head = head->next;
        }
        len--;
    }

    //********************************************************************************************************

    // problem 04 --> Get nth from back

    int get_nth_back(int n) {
        int idx = 0;
        for (node* current = head; current; current = current->next, idx++) {
            if (idx == len - n)
                return current->data;
        }
        return -1; // index isn't found.
    }

    //********************************************************************************************************

    // problem 05 --> Is Same list’s data?

    bool is_same1(const LinkedList &l2) { // Length is known.
        if (len != l2.len)
            return false;

        node* cur1 = head, * cur2 = l2.head;
        while (cur1 && cur2) {
            if (cur1->data != cur2->data)
                return false;
            cur1 = cur1->next, cur2 = cur2->next;
        }
        return true;
    }

    bool is_same2(const LinkedList& l2) { // Length unknown.
        node* cur1 = head, *cur2 = l2.head;
        while (cur1 && cur2) {
            if (cur1->data != cur2->data)
                return false;
            cur1 = cur1->next, cur2 = cur2->next;
        }
        return !cur1 && !cur2;
    }

    //********************************************************************************************************

    // problem 06 --> Linked List without tail/length {print, add_element, get_tail}.

    void print() {
        node* current = head;
        while (current != nullptr) {
            cout << current->data << ' ';
            current = current->next;
        }
        cout << endl;
    }

    void addElement(int value) {
        node* newNode = new node(value);
        newNode->next = head;
        head = newNode;
    }

    node* get_tail() {
        if (!head)
            return NULL;

        node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        return current;
    }
};

int main()
{
    
    return 0;
}
