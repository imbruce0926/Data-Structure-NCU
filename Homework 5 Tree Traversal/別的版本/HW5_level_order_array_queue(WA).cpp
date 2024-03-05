#include <iostream>
using namespace std;

    struct node{
        struct node *left_child;
        int data;
        struct node *right_child;
    };
    typedef struct node Node;
    typedef Node *Tree_Ptr;

    void gettree(Tree_Ptr *);
    void insert(Tree_Ptr *, int);
    void enqueue(int , int *, Tree_Ptr);
    Tree_Ptr dequeue(int *, int); 
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
        gettree(&root_Ptr);

        preorder(root_Ptr);
        cout << endl;
        inorder(root_Ptr);
        cout << endl;
        postorder(root_Ptr);
        cout << endl;
    } 
}
void gettree(Tree_Ptr *ptr) {
    int data_num, data;
    cin >> data_num;

    for(int i = 0; i < data_num; i++) {
        cin >> data;
        //cout << "do insert!!!!!!!!!" << endl;
        insert(&(*ptr), data);
        
    }
}

const int MAX_SIZE = 10000;
Tree_Ptr queue[MAX_SIZE];
int front = 0, rear = 0;

void insert(Tree_Ptr *ptr, int data){
    
    Tree_Ptr temp;
    if((*ptr) == NULL) {
        (*ptr) = CreateNode(data);
    }
    else {
        //cout << "enqueue the root" << endl;
        enqueue(front, &rear, *ptr);
        while(front != rear) {
            //cout << "do dequeue" << endl;
            temp = dequeue(&front, rear);
            if(temp->left_child == NULL) {
                temp->left_child = CreateNode(data);
                //cout << "left_child is inserted!!!!!!!!!!!!!!!!!!!" << endl; 
                front = 0, rear = 0;       
                break;
            }
            else {
                //cout << temp->left_child << endl;
                //cout << "do left enqueue" << endl;
                enqueue(front, &rear, temp->left_child);
            }
            if(temp->right_child == NULL) {
                temp->right_child = CreateNode(data);
                //cout << "right_child is inserted!!!!!!!!!!!!!!!!!!!" << endl; 
                front = 0, rear = 0;
                break;
            }
            else {
                //cout << temp->right_child << endl;
                //cout << "do right enqueue" << endl;
                enqueue(front, &rear, temp->right_child);
            }
            
            // cout << "front is : " << front << endl;
            // cout << "reat is : " << rear << endl;
        }
    }
}
void enqueue(int front, int *rear, Tree_Ptr ptr) {
    (*rear) = ((*rear) + 1) % MAX_SIZE;
    queue[(*rear)] = ptr;
    // cout << "enqueue to  " << (*rear)  << endl;
    // cout << "front is : " << front << endl;
    // cout << "reat is : " << *rear << endl;
}
Tree_Ptr dequeue(int *front, int rear) {
    (*front) = ((*front) + 1) % MAX_SIZE;
    // cout << "the " << (*front) << " is deququed" << endl;
    // cout << "front is : " << *front << endl;
    // cout << "reat is : " << rear << endl;
    return queue[(*front)];
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
