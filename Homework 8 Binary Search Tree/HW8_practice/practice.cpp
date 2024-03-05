#include <iostream>
#include <queue>
#include <stack>
using namespace std;

    struct node {
        int data;
        struct node *left, *right;
    };
    typedef struct node Node;
    typedef Node *NodePtr;

    void insertion(NodePtr *, int);
    NodePtr creat_node(int);
    void deletion(NodePtr *, int);
    NodePtr deleting(NodePtr, int);
    int find_max(NodePtr);
    NodePtr modified_search(NodePtr, int);
    int height(NodePtr);
    int search_node(NodePtr, int);
    void traversal(NodePtr);


int main()
{
    char judge[10];
    int data;
    NodePtr root = NULL;

    cin >> judge;

    while(judge[0] != 't') {
        switch(judge[0]) {
            case 'i':
                cin >> data;
                insertion(&root, data);
                break;
            case 'd':
                cin >> data;
                deletion(&root, data);
                break;
            case 's':
                cin >> data;
                cout << search_node(root, data) << endl;
                break;
            case 'h':
                cout << height(root) << endl;
                break;
        }
        cin >> judge;
    }

    traversal(root);

    return 0;
}

void insertion(NodePtr *ptr, int data) {

    if(!(*ptr)) {
        (*ptr) = creat_node(data);
        return;
    }

    NodePtr temp = modified_search((*ptr), data);

    if(temp) {
        if(data > temp->data)
            temp->right = creat_node(data);
        else
            temp->left = creat_node(data);
    }

}

NodePtr creat_node(int data) {
    NodePtr new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;

    return new_node;
}

void deletion(NodePtr *ptr, int data) {

    NodePtr temp = modified_search((*ptr), data);

    if(!(*ptr) || temp) {
        cout << "cannot delete" << endl;
        return;
    }

    (*ptr) = deleting((*ptr), data);
}

NodePtr deleting(NodePtr ptr, int data) {

    if(!ptr)
        return ptr;

    if(data > ptr->data)
        ptr->right = deleting(ptr->right, data);
    else if(data < ptr->data)
        ptr->left = deleting(ptr->left, data);
    else {
        if(!ptr->left && !ptr->right) {
            NodePtr temp = ptr;
            ptr = NULL;
            delete temp;
        }
        else if(!ptr->left && ptr->right) {
            NodePtr temp = ptr;
            ptr = ptr->right;
            delete temp;
        }
        else if(ptr->left && !ptr->right) {
            NodePtr temp = ptr;
            ptr = ptr->left;
            delete temp;
        }
        else {
            ptr->data = find_max(ptr->left);
            ptr->left = deleting(ptr->left, ptr->data);
        }
    }
    return ptr;
}

int find_max(NodePtr ptr) {

    for(; ptr->right; ptr = ptr->right);

    return ptr->data;
}

NodePtr modified_search(NodePtr ptr, int data) {

    if(!ptr)
        return ptr;

    while(true) {
        if(data > ptr->data) {
            if(!ptr->right)
                return ptr;
            ptr = ptr->right;
        }
        else if(data < ptr->data) {
            if(!ptr->left)
                return ptr;
            ptr = ptr->left;
        }
        else
            return NULL;
    }
}

int height(NodePtr ptr) {
    int left_h, right_h;

    if(!ptr)
        return 0;

    left_h = height(ptr->left);
    right_h = height(ptr->right);

    if(left_h > right_h)
        return left_h + 1;
    else
        return right_h + 1;
}

int search_node(NodePtr ptr, int i_smallest) {

    if(!ptr)
        return 0;

    stack<NodePtr> s;

    while(true) {
        for(; ptr; ptr = ptr->left)
            s.push(ptr);

        if(s.empty())
            break;

        ptr = s.top();
        s.pop();

        if(--i_smallest == 0)
            return ptr->data;

        ptr = ptr->right;
    }

    return 0;
}

void traversal(NodePtr ptr) {

    if(!ptr)
        return;

    queue<NodePtr> q;

    NodePtr temp = ptr;

    q.push(temp);

    while(!q.empty()) {
        temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}
