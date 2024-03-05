#include <iostream>
#include <queue>
#include <stack>
using namespace std;

    struct node {
        int data;
        struct node *left, *right;
    };
    typedef node Node;
    typedef Node *NodePtr;

    void insertion(NodePtr *, int);
    NodePtr creat_node(int);
    NodePtr modified_search(NodePtr, int);
    void deletion(NodePtr *, int);
    NodePtr deleting(NodePtr, int);
    int find_max(NodePtr);
    int search_node(NodePtr, int);
    int height(NodePtr);
    void traversal(NodePtr);

int main() {
    NodePtr root = NULL;
    char judge[10];
    int data;

    cin >> judge;
    while(judge[0] != 't') {

        if(judge[0] == 'i') {
            cin >> data;
            insertion(&root, data);
        }
        else if(judge[0] == 'd') {
            cin >> data;
            deletion(&root, data);
        }
        else if(judge[0] == 's') {
            cin >>data;
            cout << search_node(root, data) << endl;
        }
        else if(judge[0] == 'h') {
            cout << height(root) << endl;
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
    NodePtr temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
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

void deletion(NodePtr *ptr, int data) {

    NodePtr temp = modified_search((*ptr), data);

    if(!(*ptr) || temp){
        cout << "cannot delete" << endl;
        return;
    }

    (*ptr) = deleting((*ptr), data);
}

NodePtr deleting(NodePtr ptr, int data) {

    if(!ptr)
        return NULL;

    if(data > ptr->data)
        ptr->right = deleting(ptr->right, data);
    else if(data < ptr->data)
        ptr->left = deleting(ptr->left, data);
    else {
        if(!ptr->left && !ptr->right) {
            delete ptr;
            ptr = NULL;
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

int height(NodePtr ptr) {

    if(!ptr)
        return 0;

    int l_h, r_h;
    l_h = height(ptr->left);
    r_h = height(ptr->right);

    if(l_h > r_h)
        return l_h +1;
    else
        return r_h +1;
}

void traversal(NodePtr ptr) {

    if(!ptr)
        return;

    NodePtr temp = ptr;;
    queue<NodePtr> q;

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
