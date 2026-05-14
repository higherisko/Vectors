#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <initializer_list>

template<typename T>
class myvector {
private:
    T *arr{nullptr};
    std::size_t capacity;
    std::size_t size;
public:
    myvector(); // Constructor
    myvector(std::initializer_list<T> init); // Overloaded constructor
    myvector(const myvector &other); // Copy constructor
    myvector &operator=(const myvector &rhs); // Copy assignment
    myvector(myvector &&other); // Move construcor
    myvector &operator=(myvector &&rhs); // Move assignment
    ~myvector(); // Destructor

    void resize();
    void push_back(const T &element);
    void pop_back();
    T at(const std::size_t index);
    std::size_t len();
};

#endif

#include "myvector.tpp"