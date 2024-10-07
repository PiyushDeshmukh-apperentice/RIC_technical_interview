#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    vector<Node*> children; 
};


void DFS(Node* node) {
    if (node == nullptr) {
        return;  
    }

    cout << node->data << " ";

    for (Node* child : node->children) {
        DFS(child);
    }
}

int main() {
    
    Node* root = new Node{1};
    Node* child1 = new Node{2};
    Node* child2 = new Node{3};
    Node* child3 = new Node{4};
    Node* grandchild1 = new Node{5};
    Node* grandchild2 = new Node{6};

   
    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);
    child1->children.push_back(grandchild1);
    child2->children.push_back(grandchild2);

    
    cout << "DFS Traversal: ";
    DFS(root);
    cout << endl;


    return 0;
}
