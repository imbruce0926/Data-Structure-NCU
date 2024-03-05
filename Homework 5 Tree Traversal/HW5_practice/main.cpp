#include <iostream>
#include <queue>
using namespace std;

    struct node {
        int data;
        struct node *left, *right;
    };
    typedef struct node node;
    typedef struct node *nodePtr;

    void get_tree(nodePtr *);
    nodePtr creat_node(int);
    void preorder(nodePtr);
    void inorder(nodePtr);
    void postorder(nodePtr);

int main()
{
    int case_num;
    nodePtr root = NULL;

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
    return 0;
}

void get_tree(nodePtr *ptr) {
    int node_num, data;
    nodePtr newnode, temp;

    queue<nodePtr> q;

    cin >> node_num;

    for(int i = 0; i < node_num; i++) {
        cin >> data;
        newnode = creat_node(data);

        if((*ptr) == NULL) {
            (*ptr) = newnode;
            temp = (*ptr);
            continue;
        }

        if(temp->left != NULL && temp->right != NULL){
            temp = q.front();
            q.pop();
        }

        if(temp->left == NULL) {
            temp->left = newnode;
            q.push(temp->left);
            continue;
        }
        if(temp->right == NULL) {
            temp->right = newnode;
            q.push(temp->right);
            continue;
        }
    }
}

nodePtr creat_node(int data) {
    nodePtr new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;

    return new_node;
}

void preorder(nodePtr ptr){
    if(ptr){
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
void inorder(nodePtr ptr) {
    if(ptr){
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}

void postorder(nodePtr ptr) {
    if(ptr){
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " ";
    }
}
