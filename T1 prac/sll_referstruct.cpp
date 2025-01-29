#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) : data(data1), next(next1) {} // Constructor with default parameter
};

// Convert an array to a linked list
Node* convertArr2LL(vector<int>& arr) {
    if (arr.empty()) return nullptr; // Handle empty array case
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

// Display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Delete a specific node in the linked list
Node* deleteNode(Node* head, Node* target) {
    if (head == target) { // If the target node is the head
        Node* newHead = head->next;
        delete head;
        return newHead;
    }

    Node* temp = head;
    while (temp && temp->next != target) {
        temp = temp->next;
    }

    if (temp && temp->next == target) {
        temp->next = target->next;
        delete target;
    }
    return head;
}

// Delete nodes with values greater than k
Node* deletion_greater(Node* head, int k) {
    Node* temp = head;
    while (temp && temp->data > k) { // Delete head nodes greater than k
        Node* next = temp->next;
        delete temp;
        temp = next;
        head = temp;
    }

    Node* current = head;
    while (current && current->next) {
        if (current->next->data > k) {
            Node* target = current->next;
            current->next = target->next;
            delete target;
        } else {
            current = current->next;
        }
    }
    return head;
}

int main() {
    vector<int> arr = {1, 5, 2, 3, 4};
    Node* head = convertArr2LL(arr);

    cout << "Original List: ";
    display(head);

    // Delete nodes with values greater than 2
    head = deletion_greater(head, 2);

    cout << "List after deleting elements greater than 2: ";
    display(head);

    return 0;
}
