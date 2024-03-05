#include<iostream>
#include <queue>
using namespace std;

    struct node {
        struct node *left, *right;
        int val;
    };
    typedef struct node Node;
    typedef Node *NodePtr;

    void insertNode(NodePtr *, int);
    void deleteNode(NodePtr *, int);
    int searchNode(NodePtr, int);
    int height(NodePtr);
    void traversal(NodePtr);
    NodePtr modified_search(NodePtr, int);
    void push(int *, NodePtr [], NodePtr);
    NodePtr pop(int *, NodePtr []);
    NodePtr deleting(NodePtr, int);
    NodePtr find_max(NodePtr);

int main() {
    char oper[10];
    int temp_int;
    NodePtr tree = NULL;

    cin >> oper;

    while(oper[0] != 't') {
        if(oper[0] == 'i') {
            cin >> temp_int;
            insertNode(&tree, temp_int);
        }
        if(oper[0] == 'd') {
            cin >> temp_int;
            deleteNode(&tree, temp_int);
        }
        if(oper[0] == 's') {
            cin >> temp_int;
            cout << searchNode(tree, temp_int) << endl;
        }
        if(oper[0] == 'h') {
            cout << height(tree) << endl;
        }

        cin >> oper;
    }

    traversal(tree);

    return 0;
}

void insertNode(NodePtr *ptr, int val) {

    NodePtr node, temp = modified_search((*ptr), val);

    if(temp || !(*ptr)) {
        node = new Node();
        node->val = val;
        node->left = NULL;
        node->right = NULL;

        if(*ptr) {
            if(val < temp->val)
                temp->left = node;
            else    
                temp->right = node;
        }
        else {
            (*ptr) = node;
        }
    }

}

void deleteNode(NodePtr *ptr, int val) {

    NodePtr target = modified_search((*ptr), val);

    if((*ptr) == NULL){
        cout << "cannot delete" << endl;
        return;
    }

    if(target){
        cout << "cannot delete" << endl;
        return;
    }
    else 
        (*ptr) = deleting((*ptr), val);
}

NodePtr deleting(NodePtr ptr, int val) {

    if(ptr == NULL)
        return ptr;
        
    if(val < ptr->val)
        ptr->left = deleting(ptr->left, val);

    else if(val > ptr->val)
        ptr->right = deleting(ptr->right, val);

    else {
        if(ptr->left == NULL && ptr->right == NULL) {
            delete ptr;
            ptr = NULL;
        }
        else if(ptr->left == NULL) {
            NodePtr temp = ptr;
            ptr = ptr->right;
            delete temp;
        }
        else if(ptr->right == NULL) {
            NodePtr temp = ptr;
            ptr = ptr->left;
            delete temp;
        }
        else {
            NodePtr temp = find_max(ptr->left);
            ptr->val = temp->val;
            ptr->left = deleting(ptr->left, temp->val);
        }
    }
    return ptr;
}

NodePtr find_max(NodePtr ptr) {
    for(; ptr->right != NULL; ptr = ptr->right);

    return ptr;
}

int searchNode(NodePtr ptr, int i_smallest) {

    int top = -1;
    NodePtr stack[1000];

    while(true) {

        for(; ptr; ptr = ptr->left)
            push(&top, stack, ptr);
        
        ptr = pop(&top, stack);
        if(ptr == NULL)
            break;
        if(--i_smallest == 0)
            return ptr->val;

        ptr = ptr->right;

    }

    return 0;
}

void push(int *top, NodePtr stack[], NodePtr ptr) {
    stack[++(*top)] = ptr;
}

NodePtr pop(int *top, NodePtr stack[]) {
    return stack[(*top)--];
}

int height(NodePtr ptr) {
    int left_height, right_height;

    if(ptr == NULL)
        return 0;
    else {
        left_height = height(ptr->left);
        right_height = height(ptr->right);
        
        if(left_height > right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

void traversal(NodePtr ptr) {

    queue<NodePtr> q;

    if(ptr == NULL) 
        return;

    q.push(ptr);

    while(true){
        if(!q.empty()){
            ptr = q.front();
            q.pop();
        }
        else    
            return;

        if(ptr) {
            cout << ptr->val << " ";
            if(ptr->left)
                q.push(ptr->left);
            if(ptr->right)
                q.push(ptr->right);
        }
        else 
            return;
        
    }
    return;
    
}

NodePtr modified_search(NodePtr ptr, int val) {

    while(ptr) {
        if(ptr->val == val)
            return NULL;

        if(val < ptr->val) {
            if(ptr->left == NULL)
                return ptr;
            ptr = ptr->left;
        }
        else {
            if(ptr->right == NULL)
                return ptr;
            ptr = ptr->right;
        }
    }

    return NULL;
}