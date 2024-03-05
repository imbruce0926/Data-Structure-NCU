#include <iostream>
#include <queue>
using namespace std;

    struct node{
        struct node *left_child;
        int data;
        struct node *right_child;
    };
    typedef struct node Node;
    typedef Node *Tree_Ptr;

    void insert(Tree_Ptr *);
    Tree_Ptr CreateNode(int);
    void preorder(Tree_Ptr);
    void inorder(Tree_Ptr);
    void postorder(Tree_Ptr);

int main() {
    int case_num;
    cin >> case_num;

    Tree_Ptr root_Ptr = NULL;

    for(int i = 0; i < case_num; i++) {
        root_Ptr = NULL;
        insert(&root_Ptr);

        preorder(root_Ptr);
        cout << endl;
        inorder(root_Ptr);
        cout << endl;
        postorder(root_Ptr);
        cout << endl;
    } 
}




void insert(Tree_Ptr *root){
    int data_num, data;
    cin >> data_num;

    queue<Tree_Ptr> q;

    Tree_Ptr temp;

    for(int i = 0; i < data_num; i++) {
        cin >> data;
        if ((*root) == NULL) {
            (*root) = CreateNode(data);
            temp = (*root);
            continue;
        }

        if(temp->left_child != NULL && temp->right_child != NULL){
            temp = q.front();
            q.pop();
        }
        if (temp->left_child == NULL) {
            temp->left_child = CreateNode(data);
            q.push(temp->left_child);
            continue;
        }
        if (temp->right_child == NULL) {
            temp->right_child = CreateNode(data);
            q.push(temp->right_child);
            continue;
        }
    }
}

Tree_Ptr CreateNode(int data)
{
    Tree_Ptr newNode = new Node();
    newNode->data = data;
    newNode->left_child = newNode->right_child = NULL;
    return newNode;
}
void preorder(Tree_Ptr ptr){
    if(ptr) {
        cout << ptr->data << " ";
        preorder(ptr->left_child);
        preorder(ptr->right_child);
    }
}
void inorder(Tree_Ptr ptr){
    if(ptr) {
        inorder(ptr->left_child);
        cout << ptr->data << " ";
        inorder(ptr->right_child);
    }
}
void postorder(Tree_Ptr ptr){
    if(ptr) {
        postorder(ptr->left_child);
        postorder(ptr->right_child);
        cout << ptr->data << " ";
    }
}
