#include <iostream>
#include <string>
using namespace std;

    struct node{
        struct node *left;
        char data;
        long int value;
        struct node *right;
    };
    typedef struct node Node;
    typedef Node *Tree_Ptr;

    struct queue{
        Tree_Ptr ptr;
        struct queue *nextPtr;
    };
    typedef struct queue Queue;
    typedef Queue *Queue_Ptr;

    void getexpression(Tree_Ptr *);
    void enqueue(Queue_Ptr * , Queue_Ptr *, Tree_Ptr);
    Tree_Ptr dequeue(Queue_Ptr *, Queue_Ptr *); 
    Tree_Ptr CreateNode(char);
    void postorder(Tree_Ptr);
    void printtree(Tree_Ptr);

int main() {
    Tree_Ptr root_Ptr = NULL;
    getexpression(&root_Ptr);
    postorder(root_Ptr);
    cout << root_Ptr->value;

    
}

void printtree(Tree_Ptr ptr) {
    Queue_Ptr front = NULL, rear = NULL;

    if(!ptr) return;
    enqueue(&front, &rear, ptr);
    while(true){
        ptr = dequeue(&front, &rear);
        if(ptr) {
            cout << ptr->value << " ";
            if(ptr->left)
                enqueue(&front, &rear, ptr->left);
            if(ptr->right)
                enqueue(&front, &rear, ptr->right);
        }
        else 
            break;
    }
    
}

void getexpression(Tree_Ptr *root){
    long int level, level_num;
    string str;
    Tree_Ptr temp;
    Queue_Ptr front = NULL, rear = NULL;

    cin >> level;
    getline(cin,str);

    for(long int j = 1; j <= level; j++){
        getline(cin,str);
        for(long int i = 0; i < str.length(); i++){
            if(str[i] == ' ') continue;

            if ((*root) == NULL) {
                if (str[i] == '-' && str[i+1] == '1') {
                    (*root) = CreateNode(' ');
                    i++;
                }
                else
                    (*root) = CreateNode(str[i]);

                temp = (*root);
                continue;
            }

            if(temp->left != NULL && temp->right != NULL)
                temp = dequeue(&front, &rear);

            if (temp->left == NULL) {
                if (str[i] == '-' && str[i+1] == '1') {
                    temp->left = CreateNode(' ');
                    i++;
                }
                else
                    temp->left = CreateNode(str[i]);                
                
                enqueue(&front, &rear, temp->left);
                continue;
            }
            if (temp->right == NULL) {
                if (str[i] == '-' && str[i+1] == '1') {
                    temp->right = CreateNode(' ');
                    i++;
                }
                else
                    temp->right = CreateNode(str[i]);  

                enqueue(&front, &rear, temp->right);
                continue;
            }

        }
    }
}

void postorder(Tree_Ptr ptr){

    if(ptr) {
        postorder(ptr->left);
        postorder(ptr->right);

        if(ptr->left == NULL || ptr->right == NULL) 
            return;
        if(ptr->left->data == ' ' || ptr->right->data == ' ') 
            return;

        switch(ptr->data) {
            case '+':
                ptr->value = (ptr->left->value) + (ptr->right->value);
                break;
            case '-':
                ptr->value = (ptr->left->value) - (ptr->right->value);
                break;
            case '*':
                ptr->value = (ptr->left->value) * (ptr->right->value);
                break;
            case '/':
                ptr->value = (ptr->left->value) / (ptr->right->value);
                break;
        }
    }
}

Tree_Ptr CreateNode(char data){
    Tree_Ptr newNode = new Node();
    newNode->data = data;
    if(data >= 48 && data <= 57)
        newNode->value = data - 48;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void enqueue(Queue_Ptr *front, Queue_Ptr *rear, Tree_Ptr ptr) {
    Queue_Ptr temp = new Queue();
    temp->ptr = ptr;
    temp->nextPtr = NULL;
    if((*front) == NULL) 
        (*front) = temp;
    else    
        (*rear)->nextPtr = temp;
    (*rear) = temp;
}

Tree_Ptr dequeue(Queue_Ptr *front, Queue_Ptr *rear) {
    if((*front) == (*rear) || (*front) == NULL || (*rear) == NULL)
        return NULL;

    Queue_Ptr temp = (*front);
    Tree_Ptr ptr = (*front)->ptr;

    (*front) = (*front)->nextPtr;
    
    if ((*front) == NULL)
        (*rear) = NULL;
    delete(temp);
    return ptr;
}
