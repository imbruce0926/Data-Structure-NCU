#include <iostream>
#include <string>

using namespace std;

    struct infix {
        char symbol;
        struct infix *nextPtr;
    };
    typedef struct infix Infix;
    typedef infix* InfixPtr;

    void push(InfixPtr *, char);
    char pop(InfixPtr *);
    int isp(char);
    int icp(char);

int main()
{
    int num = 0;
    InfixPtr top = new Infix();
    string str;

    cin >> num;
    getline(cin, str);
    for(int i=0; i<num; i++){
        top->symbol = ' ';
        top->nextPtr = NULL;
        getline(cin, str);
        for(int i = 0; i < str.length(); i++){
            if(str[i] != ' ') {
                switch (str[i]) {
                    case '+': case '-': case '*': case '/':case '(':
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
    }

}

int isp (char symbol) {
    switch(symbol){
        case ' ': return -1;
        case '(': return 0;
        case '+': return 12;
        case '-': return 12;
        case '*': return 13;
        case '/': return 13;
    }
    return -1;
}
int icp (char symbol) {
    switch(symbol){
        case '(': return 20;
        case '+': return 12;
        case '-': return 12;
        case '*': return 13;
        case '/': return 13;
    }
    return -1;
}

void push(InfixPtr *top, char symbol) {
    InfixPtr temp = new Infix();
    temp->symbol = symbol;
    temp->nextPtr = (*top);
    (*top) = temp;
}

char pop(InfixPtr *top) {
    char symbol;
    InfixPtr temp;
    temp = (*top);
    symbol = (*top)->symbol;
    (*top) = (*top)->nextPtr;
    delete(temp);
    return symbol;
}

