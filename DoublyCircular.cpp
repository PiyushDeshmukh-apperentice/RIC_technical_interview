#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyCircularLinkedList {
private:
    Node* head;

public:
    // Constructor 
    DoublyCircularLinkedList() {
        head = nullptr;
    }

    
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            
            Node* tail = head->prev; // last node
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head; 
            head->prev = newNode;
        }
    }

    
    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    
    void deleteNode(int key) {
        if (head == nullptr) {
            cout << "The list is empty. Cannot delete." << endl;
            return;
        }

        Node* current = head;
        do {
            if (current->data == key) {
                if (current->next == current && current->prev == current) {
                    
                    delete current;
                    head = nullptr;
                } else {
                    Node* prevNode = current->prev;
                    Node* nextNode = current->next;

                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;

                    if (current == head) {
                        head = nextNode; 
                    }

                    delete current;
                }
                cout << "Node with value " << key << " deleted." << endl;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "Node with value " << key << " not found." << endl;
    }

    // Destructor
    ~DoublyCircularLinkedList() {
        if (head == nullptr) return;

        Node* current = head;
        do {
            Node* next = current->next;
            delete current;
            current = next;
        } while (current != head);
    }
};


int main() {
    DoublyCircularLinkedList list;

    
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    
    cout << "List (Head to Tail): ";
    list.display();
    
    list.deleteNode(20);
    cout << "After deletion: ";
    list.display();

    
    list.deleteNode(50);

    return 0;
}
