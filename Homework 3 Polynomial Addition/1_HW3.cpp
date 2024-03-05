#include <iostream>
using namespace std;

    struct poly{
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

int main() {

    int sum = 0;
    PolyPtr afirstPtr, bfirstPtr, dfirstPtr, a, b, dlastPtr;
    getpoly(&afirstPtr); // get poly A
    getpoly(&bfirstPtr); // get poly B
    a = afirstPtr; 
    b = bfirstPtr;
    dfirstPtr = NULL;
    
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

void attach(int coef, int exp, PolyPtr *ptr, PolyPtr *rear){
        if ((*ptr) == NULL) {
            (*ptr) = new Poly();
            (*rear) = (*ptr);
        }
        else {
            (*rear)->nextPtr = new Poly();
            (*rear) = (*rear)->nextPtr;
        }
        (*rear)->nextPtr = NULL;
        (*rear)->coef = coef;
        (*rear)->exp = exp;
}

void getpoly(PolyPtr *ptr){
    int items_sum = 0;
    cin >> items_sum;

    PolyPtr currentPtr = NULL;
    for (int i = 0; i < items_sum; i++){
        if (currentPtr) {
            currentPtr->nextPtr = new Poly();
            currentPtr = currentPtr->nextPtr;
            cin >> currentPtr->coef >> currentPtr->exp;
            currentPtr->nextPtr = NULL;
        } // normal operation
        else {
            currentPtr = new Poly();
            (*ptr) = currentPtr;
            cin >> currentPtr->coef >> currentPtr->exp;
            currentPtr->nextPtr = NULL;
        } // add first item into poly
    }
}

void printpoly(PolyPtr ptr){
    while(ptr != NULL){
        cout << ptr->coef << " " << ptr->exp << " ";
        ptr = ptr->nextPtr;
    }
}