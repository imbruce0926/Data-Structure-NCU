#include <iostream>
#include <string>

using namespace std;

    struct infix {
        char symbol;
        struct infix *nextPtr;
    };
    typedef struct infix Infix;
    typedef Infix *InfixPtr;

    int isp(char);
    int icp(char);
    void push(InfixPtr *, char symbol);
    char pop(InfixPtr *);

int main() {
    int num;
    string str;
    InfixPtr top;
    cin >> num;

    getline(cin, str);
    for(int j = 0; j < num; j++) {
        getline(cin, str);
        top = new Infix();
        top->symbol = ' ';
        top->nextPtr = NULL;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] != ' ') {
                switch(str[i]) {
                    case '+':case '-':case '*':case '/':case '(':
                        while(isp(top->symbol) >= icp(str[i])) 
                            cout << pop(&top) << " ";
                        push(&top, str[i]);
                        break;
                    case ')':
                        while(top->symbol != '(') 
                            cout << pop(&top) << " ";
                        pop(&top);
                        break;
                    default:
                        cout << str[i] << " ";
                        break;
                }
            }
        }
        while(top->symbol != ' ') 
            cout << pop(&top) << " ";
        cout << endl;
        delete(top);
    }
}

int isp(char symbol) {
    switch (symbol) {
    case '+': return 12; break;
    case '-': return 12; break;
    case '*': return 13; break;
    case '/': return 13; break;
    case '(': return 0; break;
    default: return -1; break;
    }
}
int icp(char symbol) {
    switch (symbol) {
    case '+': return 12; break;
    case '-': return 12; break;
    case '*': return 13; break;
    case '/': return 13; break;
    case '(': return 20; break;
    default: return -1; break;
    }
}
void push(InfixPtr *top, char symbol) {
    InfixPtr temp = new Infix();
    temp->symbol = symbol;
    temp->nextPtr = (*top);
    (*top) = temp;
}
char pop(InfixPtr *top) {
    char symbol;
    InfixPtr temp = (*top);
    symbol = temp->symbol;
    (*top) = temp->nextPtr;
    delete(temp);
    return symbol;
}