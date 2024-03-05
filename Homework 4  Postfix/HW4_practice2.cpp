#include <iostream>
#include <string>
using namespace std;

    struct infix {
        char symbol;
        struct infix * nextPtr;
    };
    typedef struct infix Infix;
    typedef Infix *InfixPtr;

    void push(InfixPtr *, char);
    char pop(InfixPtr *);
    int isp(char);
    int icp(char);
int main(){
    int num;
    cin >> num;
    string str;
    InfixPtr top;
    getline(cin, str);
    for(int j=0; j<num; j++){
        getline(cin, str);
        top = new Infix();
        top->symbol = ' ';
        top->nextPtr = NULL;
        for(int i=0; i<str.length(); i++){

            if(str[i]==' ') continue;
            switch(str[i]){
                case '+':case '-':case '*':case '/':case '(':
                    while(isp(top->symbol)>=icp(str[i])){
                        cout << pop(&top) << " ";
                    }
                    push(&top, str[i]);
                    break;
                case ')':
                    while(top->symbol!='('){
                        cout << pop(&top) << " ";
                    }
                    pop(&top);
                    break;
                default:
                    cout << str[i] << " ";
                    break;
            }
            
        }
        while(top->symbol!=' '){
            cout << pop(&top) << " ";
        }
        cout << endl;
        delete(top);
    }

}
void push(InfixPtr *top, char symbol){
    InfixPtr temp = new Infix();
    temp->symbol = symbol;
    temp->nextPtr = (*top);
    (*top) = temp;
}
char pop(InfixPtr *top){
    char symbol;
    InfixPtr temp = (*top);
    symbol = (*top)->symbol;
    (*top) = (*top)->nextPtr;
    delete(temp);
    return symbol;
}
int isp(char symbol){
    switch(symbol){
        case '+': return 12;
        case '-': return 12;
        case '*': return 13;
        case '/': return 13;
        case '(': return 0;
        default: return -1;
    }
}
int icp(char symbol){
    switch(symbol){
        case '+': return 12;
        case '-': return 12;
        case '*': return 13;
        case '/': return 13;
        case '(': return 20;
        default: return -1;
    }
}