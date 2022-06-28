#include <iostream>
#include <string>
#include "linear/Array.h"

using namespace std;

int main() {
    Array<int> numbers(100);
    Array<string> names;

    int n;
    cout << "List 10: Enter 10 integers: ";
    for (int i = 0; i < 10; i++) {
        cin >> n;
        numbers.insertItem(n);
    }
    cout << "List = ";
    numbers.print();

    cout << "Remove element from end = ";
    numbers.removeEnd();
    numbers.print();

    cout << "Remove element at 1 index = ";
    numbers.removeAt(1);
    numbers.print();

    cout << "Remove element by number = ";
    numbers.removeItem(30);
    numbers.print();

    cout << "Replace numbers[2] with element numbers[5] = ";
    numbers.replace(numbers[2], numbers[5]);
    numbers.print();

    cout << "Insert End = ";
    numbers.insertEnd(1000);
    cout << "Insert At = ";
    numbers.insertAt(5, 10);
    cout << "get() = ";
    numbers.get();
    cout << "getAt() = ";
    numbers.getAt(7);
    cout << "Max Size = ";
    numbers.maxSize();
    cout << "Size = ";
    numbers.size();
    cout << "isFull = ";
    numbers.isFull();
    cout << "isEmpty = ";
    numbers.isEmpty();
    cout << "Index Of 1000";
    numbers.indexOf(1000);
    cout << "Clear = ";
    numbers.clear();
    numbers.print();
    return 0;
}
