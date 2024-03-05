#include <iostream>
using namespace std;

    struct poly {
        int coef;
        int exp;
        struct poly *nextPtr;
    };
    typedef struct poly Poly;
    typedef Poly *PolyPtr;

    void getpoly(PolyPtr *);
    void attach(PolyPtr *, PolyPtr*, int, int);
    int COMPARE(int, int);

int main() {
    PolyPtr a, b, afirstPtr, bfirstPtr, dfirstPtr, dlastPtr;
    afirstPtr = NULL;
    bfirstPtr = NULL;
    dfirstPtr = NULL;
    dlastPtr = NULL;
    getpoly(&afirstPtr);
    getpoly(&bfirstPtr);
    a = afirstPtr;
    b = bfirstPtr;

    while(a != NULL && b != NULL) {
        switch(COMPARE(a->exp, b->exp)){
            case 1:
                if(b->coef != 0)
                    attach(&dfirstPtr, &dlastPtr, b->coef, b->exp);
                b = b->nextPtr;
                break;
            case 0:
                if(a->coef + b->coef != 0)
                    attach(&dfirstPtr, &dlastPtr, a->coef + b->coef, b->exp);
                a = a->nextPtr; b = b->nextPtr;
                break;
            case -1:
                if(a->coef != 0)
                    attach(&dfirstPtr, &dlastPtr, a->coef, a->exp);
                a = a->nextPtr;
                break;

        }
    }
    while(a!=NULL){
        if(a->coef != 0)
            attach(&dfirstPtr, &dlastPtr, a->coef, a->exp);
        a = a->nextPtr;
    }
    while(b!=NULL){
        if(b->coef != 0)
            attach(&dfirstPtr, &dlastPtr, b->coef, b->exp);
        b = b->nextPtr;
    }
    for(; dfirstPtr!=NULL; dfirstPtr=dfirstPtr->nextPtr){
        cout << dfirstPtr->coef << " " << dfirstPtr->exp << " ";
    }
}
void getpoly(PolyPtr *front) {
    int num, coef, exp;
    cin >> num;
    PolyPtr rear = NULL;
    for(int i=0;i<num;i++){
        cin >> coef >> exp;
        attach(&(*front), &rear, coef, exp);
    }
}
void attach(PolyPtr *front, PolyPtr *rear, int coef, int exp) {
    PolyPtr temp = new poly();
    temp->coef = coef;
    temp->exp = exp;
    temp->nextPtr = NULL;
    if((*front) == NULL)
        (*front) = temp;
    else
        (*rear)->nextPtr = temp;
    (*rear) = temp;
}
int COMPARE(int a, int b) {
    if(a<b) return 1;
    else if (a==b) return 0;
    else return -1;
}