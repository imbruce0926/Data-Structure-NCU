#include <iostream>
#include <queue>

using namespace std;

    struct node {
        int data;
        struct node *left, *right;
    };
    typedef struct node Node;
    typedef Node *NodePtr;

    void get_tree(NodePtr *);
    NodePtr creat_node(int);
    void preorder(NodePtr);
    void inorder(NodePtr);
    void postorder(NodePtr);

int main () {
    NodePtr root = NULL;
    int case_num;
    cin >> case_num;

    for(int i=0; i<case_num; i++) {
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
    NodePtr temp;
    queue<NodePtr> q;

    cin >> node_num;

    for(int i=0; i<node_num; i++) {
        cin >> data;

        if(!(*ptr)) {
            (*ptr) = creat_node(data);
            temp = (*ptr);
            continue;
        }

        if(temp->left && temp->right) {
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
    NodePtr temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
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
