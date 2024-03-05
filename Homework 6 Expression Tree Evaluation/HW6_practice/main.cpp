#include <iostream>
#include <string>
#include <queue>

using namespace std;

    struct node {
        long int val;
        char data;
        struct node *left, *right;
    };
    typedef struct node Node;
    typedef Node *NodePtr;
    void get_expression(NodePtr *);
    NodePtr creat_node(char);
    void postorder(NodePtr);

void print_tree(NodePtr root) {
    NodePtr temp = root;
    queue<NodePtr> q;

    q.push(temp);

    while(!q.empty()) {
        temp = q.front();
        q.pop();

        cout << temp->val;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

int main()
{
    NodePtr root = NULL;
    get_expression(&root);
    postorder(root);
    //print_tree(root);
    cout << root->val;

    return 0;
}

void get_expression(NodePtr *ptr) {

    long int level_num;
    NodePtr temp;
    string str;

    queue<NodePtr> q;

    cin >> level_num;

    getline(cin, str);
    for(long int j = 0; j < level_num; j++) {
        getline(cin, str);
        for(long int i = 0; i < str.length(); i++) {
            if(str[i] == ' ') continue;

            if((*ptr) == NULL){
                if(str[i] == '-' && str[i + 1] == '1'){
                    (*ptr) = creat_node(' ');
                    i++;
                }
                else
                    (*ptr) = creat_node(str[i]);
                temp = (*ptr);
                continue;
            }

            if(temp->left != NULL && temp->right != NULL) {
                temp = q.front();
                q.pop();
            }

            if(temp->left == NULL) {
                if(str[i] == '-' && str[i + 1] == '1'){
                    temp->left = creat_node(' ');
                    i++;
                }
                else
                    temp->left = creat_node(str[i]);
                q.push(temp->left);
                continue;
            }

            if(temp->right == NULL) {
                if(str[i] == '-' && str[i + 1] == '1'){
                    temp->right = creat_node(' ');
                    i++;
                }
                else
                    temp->right = creat_node(str[i]);
                q.push(temp->right);
                continue;
            }
        }
    }

}
NodePtr creat_node(char data) {
    NodePtr newnode = new Node();

    newnode->data = data;

    if(data >= '0' && data <= '9')
        newnode->val = data - '0';

    newnode->left = newnode->right = NULL;

    return newnode;
}
void postorder(NodePtr ptr) {

    if(ptr) {
        postorder(ptr->left);
        postorder(ptr->right);

        switch(ptr->data) {
            case '+':
                ptr->val = ptr->left->val + ptr->right->val;
                break;
            case '-':
                ptr->val = ptr->left->val - ptr->right->val;
                break;
            case '*':
                ptr->val = ptr->left->val * ptr->right->val;
                break;
            case '/':
                ptr->val = ptr->left->val / ptr->right->val;
                break;
        }
    }
}
