#include <iostream>
#include <string>
using namespace std;

    struct element {
        string name;
        int grade;
    };
    typedef element element;

    const int MAX_STD = 1000;
    void get_list(element *, int);
    void quick_sort(element *, int, int, int *);
    bool is_equal(element, element);
    bool is_alphabat_greater(element, element);
    bool is_alphabat_smaller(element, element);
    void SWAP(element *, int, int);
    void print_list(element *, int);

int main() {
    element list[MAX_STD];
    int std_num, index = 0;

    cin >> std_num;
    get_list(list, std_num);
    quick_sort(list, 0, std_num - 1, &index);
    print_list(list, std_num);
}

void get_list(element *list, int std_num) {
    for(int i = 0; i < std_num; i++) 
        cin >> list[i].name >> list[i].grade;
}

void quick_sort(element *list, int left, int right, int *index) {
    int i, j;
    element pivot;

    if(left < right) {
        i = left;
        j = right + 1; // for do...while symmetry
        pivot = list[left];

        do {
            do
                i++;
            while(list[i].grade < pivot.grade || (list[i].grade == pivot.grade && is_alphabat_greater(list[i], pivot)));

            do
                j--;
            while(list[j].grade > pivot.grade || (list[j].grade == pivot.grade && is_alphabat_smaller(list[j], pivot)));

            if(i < j || is_equal(list[i], list[j]))
                SWAP(list, i, j);
        }
        while(i < j);

        SWAP(list, left, j);
        cout << "The index of the " << ++(*index) << "-th pivot is " << j << "." << endl;
        quick_sort(list, left, j-1, &(*index));
        quick_sort(list, j+1, right, &(*index));

    }
}

bool is_equal(element a, element b) {
    if(a.name == b.name && a.grade == b.grade)
        return true;
    else    
        return false;
}

bool is_alphabat_greater(element a, element b) {
    
    if(is_equal(a, b))
        return false;
    
    int length;
    if(a.name.length() > b.name.length())
        length = b.name.length();
    else
        length = a.name.length();


    for(int i = 0; i < length; i++){
        if(a.name[i] == b.name[i])
            continue;
        else if(a.name[i] > b.name[i])
            return true;
        else
            return false;
    }
    return true;

}

bool is_alphabat_smaller(element a, element b) {
    
    if(is_equal(a, b))
        return false;
    
    int length;
    if(a.name.length() > b.name.length())
        length = b.name.length();
    else
        length = a.name.length();


    for(int i = 0; i < length; i++){
        if(a.name[i] == b.name[i])
            continue;
        else if(a.name[i] < b.name[i])
            return true;
        else
            return false;
    }
    return true;

}

void SWAP(element *list, int i, int j) {
    element temp;
    temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

void print_list(element *list, int std_num) {
    for(int i = 0; i < std_num; i++) 
        cout << list[i].name << " " << list[i].grade << endl;
}