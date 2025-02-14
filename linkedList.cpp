#include "util.h"

struct node {
    int data;
    node *next;
};

void printStack(node *head) {
    if (head != NULL) {
        cout << head->data << "\t|\t";
        printStack(head->next);
    }
}

void printQueue(node *head) {
    if (head != NULL) {
        printQueue(head->next);
        cout << head->data << "\t|\t";
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

int main() {
    cout << "Single Linked List Examples" << endl;
    cout << "=================================" << endl << endl;

    // create the single linked list for ADS List (Stack/Queue)
    node *list = NULL;

    cout << "Example of a 'List' ADS (Unsorted Stack/Queue)" << endl;
    cout << "-------------------------------------" << endl;
    // add nodes to the list at the head (like a stack)
    for (int i = 1; i < 5; i++) {
        node *newnode = new node;
        newnode -> data = rand() % 10 + 1;
        newnode -> next = list;
        list = newnode;
    }

    // traverse list using a loop (like a stack)
    cout << "Print using a standard loop (like a stack)" << endl;
    node *temp = list;
    while (temp != NULL) {
        cout << temp->data << "\t|\t";
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
    for (int i = 0; i < 5; i++) {
        node *newNode = new node;
        newNode -> data = rand() % 10 + 1;
        insertSorted(newNode, sortedList);        
    }

    // traverse list using a loop (since list is sorted)
    cout << "Print using a standard loop (sorted list)" << endl;
    node *tempSorted = sortedList;
    while (tempSorted != NULL) {
        cout << tempSorted->data << "\t|\t";
        tempSorted = tempSorted->next;
    }
    cout << endl;
    
    cout << "\nThanks for playing..." << endl;
    
    return 0;
}