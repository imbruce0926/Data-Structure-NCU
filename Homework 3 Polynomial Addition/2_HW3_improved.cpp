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
    void printpoly(PolyPtr );
    int COMPARE(int, int);
    void attach(int, int, PolyPtr *, PolyPtr *);


int main(){

    int sum = 0;
    PolyPtr afirstPtr, bfirstPtr, dfirstPtr, a, b, dlastPtr;
    afirstPtr = NULL;
    bfirstPtr = NULL;
    dfirstPtr = NULL;
    getpoly(&afirstPtr); // get poly A
    getpoly(&bfirstPtr); // get poly B
    a = afirstPtr; 
    b = bfirstPtr;
    
    
    while (a != NULL && b != NULL){
        switch (COMPARE(a->exp, b->exp)){
            case -1:
                if(b->coef != 0)
                    attach(b->coef, b->exp, &dfirstPtr, &dlastPtr);
                b = b->nextPtr;
                break;
            case 0:
                sum = a->coef + b->coef;
                if (sum != 0)
                    attach(sum, a->exp, &dfirstPtr, &dlastPtr);
                a = a->nextPtr; b = b->nextPtr;
                break;
            case 1:
                if(a->coef != 0)
                    attach(a->coef, a->exp, &dfirstPtr, &dlastPtr);
                a = a->nextPtr;
                break;
        }
    }

    while (a != NULL) {
        if(a->coef != 0)
            attach(a->coef, a->exp, &dfirstPtr, &dlastPtr);
        a = a->nextPtr;
    }
    
    while (b != NULL) {
        if(b->coef != 0)
            attach(b->coef, b->exp, &dfirstPtr, &dlastPtr);
        b = b->nextPtr;
    }
    
    printpoly(dfirstPtr);
}

int COMPARE(int aexp, int bexp){
    if (aexp < bexp)
        return -1;
    else if (aexp == bexp)
        return 0;
    else    
        return 1;
}

void attach(int coef, int exp, PolyPtr *front, PolyPtr *rear){
    PolyPtr temp = new Poly();
    temp->coef = coef;
    temp->exp = exp;
    if ((*front) == NULL) {
        (*front) = temp;
        (*front)->nextPtr = NULL;
    }
    else {
        (*rear)->nextPtr = temp;
    }
    (*rear) = temp;
}

void getpoly(PolyPtr *front){
    int items_sum = 0, coef = 0, exp = 0;
    cin >> items_sum;
    PolyPtr rear = NULL;
    for (int i = 0; i < items_sum; i++){
        cin >> coef >> exp;
        attach(coef, exp, &(*front), &rear);
    }
}

void printpoly(PolyPtr ptr){
    while(ptr != NULL){
        cout << ptr->coef << " " << ptr->exp << " ";
        ptr = ptr->nextPtr;
    }
}