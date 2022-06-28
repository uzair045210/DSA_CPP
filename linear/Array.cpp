//
// Created by uzair on 6/28/22.
//

#include "Array.h"

template<class T>
bool Array<T>::isEmpty() const {
    return (length == 0);
}

template<class T>
bool Array<T>::isFull() const {
    return (length == max_size);
}

template<class T>
int Array<T>::size() const {
    return length;
}

template<class T>
int Array<T>::maxSize() const {
    return max_size;
}

template<class T>
bool Array<T>::equals(int index, const T &item) const {
    return (list[index] == item);
}

template<class T>
void Array<T>::insertAt(int index, const T &item) {
    if (index < 0 || index >= max_size) {
        std::cerr << "The position of the item to be inserted is out of range" << std::endl;
        return;
    }
    if (length >= max_size)
        std::cerr << "Cannot insert in a full list!" << std::endl;
    else {
        for (int i = length; i > index; i--)
            list[i] = list[i - 1];
        list[index] = item;
        length++;
    }
}

template<class T>
void Array<T>::insertItem(const T &item) {
    if (length == 0) {
        std::cerr << "Cannot insert item to an empty list." << std::endl;
        return;
    }
    if (length >= max_size)
        std::cerr << "Cannot insert in a full list!" << std::endl;
    else
        insertEnd(item);
}

template<class T>
void Array<T>::insertEnd(const T &item) {
    if (length >= max_size) {
        std::cerr << "Cannot insert in a full list!" << std::endl;
        return;
    }
    list[length] = item;
    length++;
}

template<class T>
void Array<T>::removeAt(int index) {
    if (index < 0 || index >= max_size) {
        std::cerr << "The position of the item to be inserted is out of range" << std::endl;
        return;
    }
    for (int i = index; i < length - 1; i++) {
        list[i] = list[i+1];
        length--;
    }
}

template<class T>
void Array<T>::removeItem(const T &item) {
    int index;
    if (length == 0) {
        std::cerr << "Cannot delete from an empty list." << std::endl;
        return;
    }
    index = seqSearch(item);
    if (index != -1)
        removeAt(index);
    else
        std::cout << "The item to be deleted is not in the list." << std::endl;
}

template<class T>
void Array<T>::removeEnd() {
    if (length == 0) {
        std::cerr << "Cannot delete from an empty list." << std::endl;
        return;
    }
    removeAt(length - 1);
    length--;
}

template<class T>
int Array<T>::get() const {
    if (length == 0)
        std::cerr << "List is empty right now!" << std::endl;
    else
        return list[0];
}

template<class T>
int Array<T>::getAt(int index) const {
    if (index < 0 || index >= length)
        std::cerr << "The location of the item to be retrieved is out of range." << std::endl;
    else
        return list[index];
}

template<class T>
int Array<T>::indexOf(const T &item) const {
    int index;
    if (index < 0 || index >= max_size)
        std::cerr << "Index is going out of range." << std::endl;
    index = seqSearch(item);
    if (index != -1)
        return index;
    else
        std::cout << "The item to be searched is not in the list!" << std::endl;
}

template<class T>
void Array<T>::replaceAt(int index, const T &item) {
    if (index < 0 || index >= length)
        std::cerr << "The location of the item to be replaced is out of range." << std::endl;
    else
        list[index] = item;
}

template<class T>
void Array<T>::replace(T &c_item, const T &r_item) {
    int index;
    if (length == 0)
        std::cerr << "List is empty right now!" << std::endl;
    index = seqSearch(c_item);
    if (index != -1)
        this->list[index] = r_item;
    else
        std::cout << "The item to be replaced is not in the list." << std::endl;
}

template<class T>
void Array<T>::clear() {
    length = 0;
}

template<class T>
void Array<T>::print() const {
    std::cout << "[";
    int i = 0;
    while (i < length) {
        std::cout << list[i];
        i++;
        if (i != length)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

template<class T>
const Array<T> &Array<T>::operator=(const Array<T> &rhs) {
    if (this != &rhs) {
        delete [] list;
        max_size = rhs.max_size;
        length = max_size;
        list = new T[max_size];
        assert(list != NULL);
        for (int i = 0; i < length; i++)
            list[i] = rhs.list[i];
    }
    return *this;
}

template<class T>
const T &Array<T>::operator[](int index) {
    return list[index];
}

template<class T>
int Array<T>::seqSearch(const T &item) const {
    int index;
    bool found = false;
    for (index = 0; index < length; index++)
        if (list[index] == item) {
            found = true;
            break;
        }
}

template<class T>
Array<T>::Array(int size) {
    if (size < 0) {
        std::cerr << "The array size must be positive. Creating an array of size 100. " << std::endl;
        max_size = 100;
    } else
        max_size = size;
    length = 0;
    list = new T[max_size];
    assert(list != NULL);
}

template<class T>
Array<T>::Array(const Array<T> &rhs) {
    max_size = rhs.max_size;
    length = rhs.length;
    list = new T[max_size];
    assert(list != NULL);
    for (int i = 0; i < length; i++)
        list[i] = rhs.list[i];
}

template<class T>
Array<T>::~Array() {
    delete [] list;
}
