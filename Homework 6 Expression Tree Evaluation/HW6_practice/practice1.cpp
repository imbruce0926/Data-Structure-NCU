#include <iostream>
#include <string>
#include <queue>

using namespace std;

    struct node {
        char data;
        long int val;
        struct node *left, *right;
    };
    typedef struct node Node;
    typedef Node *NodePtr;

    void get_expression(NodePtr *);
    NodePtr creat_node(char);
    void postorder(NodePtr);

int main() {
    NodePtr root = NULL;
    get_expression(&root);
    postorder(root);
    cout << root->val;
}

void get_expression(NodePtr *ptr) {
    NodePtr temp;
    string str;
    queue<NodePtr> q;
    int level_num;

    cin >> level_num;

    getline(cin, str);

    for(int j=0; j<level_num; j++) {
        getline(cin, str);

        for(long int i=0; i<str.length(); i++) {

            if(str[i] == ' ') continue;

            if(!(*ptr)) {
                if(str[i] == '-' && str[i+1] == '1') {
                    (*ptr) = creat_node(' ');
                    i++;
                }
                else
                    (*ptr) = creat_node(str[i]);

                temp = (*ptr);
                continue;
            }

            if(temp->left && temp->right) {
                temp = q.front();
                q.pop();
            }

            if(!temp->left) {
                if(str[i] == '-' && str[i+1] == '1') {
                    temp->left = creat_node(' ');
                    i++;
                }
                else
                    temp->left = creat_node(str[i]);

                q.push(temp->left);
                continue;
            }
            if(!temp->right) {
                if(str[i] == '-' && str[i+1] == '1') {
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
    NodePtr temp = new Node();
    temp->data = data;
    if(data >= '0' && data <= '9')
        temp->val = data - '0';
    temp->left = temp->right = NULL;
    return temp;
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
