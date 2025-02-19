#include "util.h"

struct node {
    int data;
    node *next;
};

struct doubleNode {
    int data;
    doubleNode *next;
    doubleNode *prev;
    doubleNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void insertAtHead(int val, doubleNode * &head, doubleNode * &tail) {
    doubleNode* newNode = new doubleNode(val);
    if (!head) {
        head = newNode;
        tail = newNode;  //note set tail with first item and then it stays
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(int val, doubleNode * &head, doubleNode * &tail) {
    doubleNode* newNode = new doubleNode(val);
    if (!head) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void printDoublyLinkedListForward(doubleNode *head) {
    doubleNode* current = head;
    while(current) {
        cout << current->data << " | ";
        current = current->next;
    }
    cout << endl;
}

void printDoublyLinkedListBackward(doubleNode *tail) {
    doubleNode* current = tail;
    while(current) {
        cout << current->data << " | ";
        current = current->prev;
    }
}

void printStack(node *head) {
    if (head != NULL) {
        cout << head->data << " | ";
        printStack(head->next);
    }
}

void printQueue(node *head) {
    if (head != NULL) {
        printQueue(head->next);
        cout << head->data << " | ";
    }
}

void insertSorted(node *newNode, node * &head) {
    if (head == NULL || newNode->data < head->data) {
        newNode->next = head;
        head = newNode;
    } else {
        insertSorted(newNode, head->next);
    }
}

void singleLinkedList() {
    cout << "Single Linked List Examples" << endl;
    cout << "=================================" << endl << endl;

    // create the single linked list for ADS List (Stack/Queue)
    node *list = NULL;

    cout << "Example of a 'List' ADS (Unsorted Stack/Queue)" << endl;
    cout << "-------------------------------------" << endl;
    // add nodes to the list at the head (like a stack)
    for (int i = 1; i < 5; i++) {
        node *newnode = new node;
        newnode -> data = randInt(1, 10);
        newnode -> next = list;
        list = newnode;
    }

    // traverse list using a loop (like a stack)
    cout << "Print using a standard loop (like a stack)" << endl;
    node *temp = list;
    while (temp != NULL) {
        cout << temp->data << " | ";
        temp = temp->next;
    }
    cout << endl;

    // print out using LIFO recursion (like Stack)
    cout << "\nPrint using LIFO Recursion - Stack" << endl;
    printStack(list);
    cout << endl;

    // print out using FILO recursion (like Queue)
    cout << "\nPrint using FILO Recursion - Queue" << endl;
    printQueue(list);
    cout << endl;

    // create the single linked list for ADS Sorted List
    node *sortedList = NULL;

    cout << "\nExample of a 'List' ADS (Sorted)" << endl;
    cout << "-------------------------------------" << endl;
    // add nodes to the list in a sorted manner
    for (int i = 0; i < 9; i++) {
        node *newNode = new node;
        
        newNode -> data = randInt(1,100);
        insertSorted(newNode, sortedList);        
    }

    // traverse list using a loop (since list is sorted)
    cout << "Print using a standard loop (sorted list)" << endl;
    node *tempSorted = sortedList;
    while (tempSorted != NULL) {
        cout << tempSorted->data << " | ";
        tempSorted = tempSorted->next;
    }
    cout << endl;

}

void doubleLinkedList() {
    cout << "Doubly Linked List Examples" << endl;
    cout << "=================================" << endl << endl;

    // create the doubly linked list for ADS List
    doubleNode *dlistHead = NULL;
    doubleNode *dlistTail = NULL;

    // add nodes to the list at the head (like a stack)
    cout << "Insert 1 - 5 at head (like a stack)" << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 1; i < 6; i++) {
        insertAtHead(i, * &dlistHead, * &dlistTail);
    }

    // traverse list using a loop
    cout << "Print using a standard loop (head to tail)" << endl;
    printDoublyLinkedListForward(* &dlistHead);

    // add nodes to the list at the tail (like a queue)
    cout << "Insert 10 - 50 at tail (like a queue)" << endl;
    cout << "-----------------------------------" << endl;
    for (int i = 1; i < 6; i++) {
        insertAtTail((i * 10), * &dlistHead, * &dlistTail);
    }

    // traverse list using a loop
    cout << "Print using a standard loop (head to tail)" << endl;
    printDoublyLinkedListForward(* &dlistHead);

    // traverse from back to front using the tail
    cout << "Print using a standard loop (tail to head)" << endl;
    printDoublyLinkedListBackward(* &dlistTail);

}

int main() {
    singleLinkedList();
    doubleLinkedList();
    cout << "\nThanks for playing..." << endl;

    return 0;
}