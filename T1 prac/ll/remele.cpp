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

int maximum(Node* head) {
    Node* temp = head->next;
    int cur = temp->data;
    while(!temp) {
        if(temp->data > cur) {
            cur = temp->data;
        }
        temp = temp->next;
    }
    return cur;
}

Node* reverse(Node* head) {
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        Node* front = temp->next;
        prev = temp;
        temp = front;
    }
    return prev;
}

bool pali(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = new Node(*slow->next);
    Node* first = head;
    Node* second = newHead;

    while(second != NULL) {
        if(first->data != second->data) {
        reverse(newHead);
        return false;
        }   
        first = first->next;
        second = second->next;
    }
    return true;
}

void removeDuplicates(Node*& head) {
    if (!head) return;

    std::unordered_set<int> seen;  // Set to track seen values
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (seen.find(current->data) != seen.end()) {
            // Duplicate found, remove the node
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            // Not a duplicate, add to set and move to next
            seen.insert(current->data);
            prev = current;
            current = current->next;
        }
    }
}


int main() {
    vector<int> arr = {1, 5, 2, 5, 8};
    Node* head = convertArr2LL(arr);

    cout << "Original List: ";
    display(head);
    cout<<maximum(head);

    // Delete nodes with values greater than 2
    //deletion_greater(head, 2);
    

    cout << "List after deleting elements greater than 2: ";
    removeDuplicates(head);
    display(head);
    cout << pali(head);
    
    return 0;
}
