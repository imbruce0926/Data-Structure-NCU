#include <iostream>
#include <string>
using namespace std;

    struct element{
        string str;
        int priority;
    };
    typedef struct element Element;

    void gettree(Element *, int);
    void insert(Element *, Element, int *);
    void printtree(Element *, int);

main (){
    const int MAX_SIZE = 100000;
    Element item[MAX_SIZE];

    int case_num;
    cin >> case_num;

    gettree(item, case_num);
    cout << "First three things to do:" << endl;
    cout << item[1].str << endl;
    if(item[2].priority > item[3].priority){
        cout << item[2].str << endl;
        cout << item[3].str << endl;
    }
    else {
        cout << item[3].str << endl;
        cout << item[2].str << endl;
    }
}

void gettree(Element *item, int case_num) {
    int node_num = 0;
    Element new_item;
    for(int i = 1; i <= case_num; i++) {
        cin >> new_item.str >> new_item.priority; 
        insert(item, new_item, &node_num);
    }
}

void insert(Element *item, Element new_item, int *n) {
    int i = ++(*n);
    while((i != 1) && (new_item.priority > item[i/2].priority)) {
        item[i] = item[i/2];
        i /= 2;
    }
    item[i] = new_item;
}

void printtree(Element *item, int case_num) {
    for(int i = 1; i <= case_num; i++) 
        cout << item[i].str << " " << item[i].priority << endl; 
}