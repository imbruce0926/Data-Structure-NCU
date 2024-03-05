#include <iostream>
#include <string>
#include <queue>
using namespace std;

    struct node{
        struct node *left;
        char data;
        long int value;
        struct node *right;
    };
    typedef struct node Node;
    typedef Node *Tree_Ptr;


    void getexpression(Tree_Ptr *);
    Tree_Ptr CreateNode(char);
    void postorder(Tree_Ptr);
    void printtree(Tree_Ptr);

int main() {
    Tree_Ptr root_Ptr = NULL;

    getexpression(&root_Ptr);

    postorder(root_Ptr);

    cout << root_Ptr->value;

    // printtree(root_Ptr);
}

void printtree(Tree_Ptr ptr) {

    queue<Tree_Ptr> q;

    if(!ptr) return;
    q.push(ptr);
    while(true){

        if(!q.empty()) {
            ptr = q.front();
            q.pop();
        }
        else 
            break;

        if(ptr) {
            cout << ptr->value << " ";
            if(ptr->left)
                q.push(ptr->left);
            if(ptr->right)
                q.push(ptr->right);
        }
        else 
            break;
    }
    
}

void getexpression(Tree_Ptr *root){
    long int level_num;
    string str;
    Tree_Ptr temp;
    queue<Tree_Ptr> q;

    cin >> level_num;
    getline(cin,str);

    for(long int j = 1; j <= level_num; j++){
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

            if(temp->left != NULL && temp->right != NULL) {
                temp = q.front();
                q.pop();
            }

            if (temp->left == NULL) {
                if (str[i] == '-' && str[i+1] == '1') {
                    temp->left = CreateNode(' ');
                    i++;
                }
                else
                    temp->left = CreateNode(str[i]);                
                
                q.push(temp->left);
                continue;
            }
            if (temp->right == NULL) {
                if (str[i] == '-' && str[i+1] == '1') {
                    temp->right = CreateNode(' ');
                    i++;
                }
                else
                    temp->right = CreateNode(str[i]);  

                q.push(temp->right);
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

