#include <iostream>
#include <queue>
using namespace std;

    struct node {
        int data;
        struct node *left, *right;
    };
    typedef node Node;
    typedef Node *NodePtr;

    void get_tree(NodePtr *);
    void insertion();
    NodePtr creat_node(int);
    void preorder(NodePtr);
    void inorder(NodePtr);
    void postorder(NodePtr);


int main() {
    int case_num;
    NodePtr root = NULL;

    cin >> case_num;
    for(int i = 0; i < case_num; i++){
        root = NULL;
        get_tree(&root);
        preorder(root);
        cout << endl;
        inorder(root);
        cout << endl;
        postorder(root);
        cout << endl;
    }

}

void get_tree(NodePtr *ptr) {
    int node_num, data;
    cin >> node_num;

    queue<NodePtr> q;

    NodePtr temp;

    for(int i = 0; i < node_num; i++){
        cin >> data;
        if(!(*ptr)){
            (*ptr) = creat_node(data);
            temp = (*ptr);
            continue;
        }

        if(temp->left && temp->right){
            temp = q.front();
            q.pop();
        }

        if(!temp->left) {
            temp->left = creat_node(data);
            q.push(temp->left);
            continue;
        }
        if(!temp->right) {
            temp->right = creat_node(data);
            q.push(temp->right);
            continue;
        }

    }
}

NodePtr creat_node(int data) {
    NodePtr new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;

    return new_node;
}

void preorder(NodePtr ptr) {
    if(ptr) {
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(NodePtr ptr) {
    if(ptr) {
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}

void postorder(NodePtr ptr) {
    if(ptr) {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " ";
    }
}


