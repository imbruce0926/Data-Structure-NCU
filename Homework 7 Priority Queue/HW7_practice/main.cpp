#include <iostream>
#include <string>

using namespace std;

    struct element {
        string str;
        int prior;
    };
    typedef struct element element;
    const int MAX = 1000;

    void get_heap(element *);
    void insert_heap(element, element *, int *);

int main()
{
    element heap[MAX];

    get_heap(heap);

    cout << "First three things to do:" << endl;
    cout << heap[1].str<< endl;
    if(heap[2].prior > heap[3].prior){
        cout << heap[2].str << endl;
        cout << heap[3].str << endl;
    }
    else {
        cout << heap[3].str << endl;
        cout << heap[2].str << endl;
    }

    return 0;
}

void get_heap(element *heap) {
    int node_num, n = 0;
    element item;
    cin >> node_num;
    for(int i = 0; i < node_num; i++) {
        cin >> item.str >> item.prior;
        insert_heap(item, heap, &n);
    }
}

void insert_heap(element item, element *heap, int *n) {
    int i = ++(*n);
    while(i != 1 && item.prior > heap[i / 2].prior) {
        heap[i] = heap[i / 2];
        i = i / 2;
    }
    heap[i] = item;
}
