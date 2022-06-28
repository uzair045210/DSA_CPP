//
// Created by uzair on 6/28/22.
//

#ifndef DSA_CPP_ARRAY_H
#define DSA_CPP_ARRAY_H

#include <iostream>

template<class T>
class Array {
public:
    // Methods //
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    int maxSize() const;
    bool equals(int index, const T& item) const;
    void insertAt(int index, const T& item);
    void insertItem(const T& item);
    void insertEnd(const T& item);
    void removeItem(const T& item);
    void removeAt(int index);
    void removeEnd();
    int get() const;
    int getAt(int index) const;
    int indexOf(const T& item) const;
    void replaceAt(int index, const T& item);
    void replace(T& c_item, const T& r_item);
    void clear();
    void print() const;
    // Overload Assignment Operator
    const Array<T> &operator=(const Array<T>& rhs);
    // Overload at-position operator
    const T &operator[](int index);
    // Search - Sequence
    int seqSearch(const T& item) const;
    // Constructors
    Array(int size = 100);
    Array(const Array<T>& rhs);
    ~Array();

protected:
    T *list;
    int length;
    int max_size;
};


#endif //DSA_CPP_ARRAY_H
