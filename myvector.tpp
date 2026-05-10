#include <iostream>

// Constructor
template<typename T>
myvector<T>::myvector() : capacity{1}, size{0} {
    arr = new T[capacity];
}

// Copy Constructor
template<typename T>
myvector<T>::myvector(const myvector &other) : capacity{other.capacity}, size{other.size} {
    arr = new T[capacity];
    for (std::size_t i{0}; i<size; i++) 
        arr[i] = other.arr[i];
}

// Copy assignment
template<typename T>
myvector<T> &myvector<T>::operator=(const myvector &rhs) {
    if (this == &rhs)
        return *this;

    size = rhs.size;
    capacity = rhs.capacity;
    arr = new T[capacity];
    for (std::size_t i; i<size; i++)
        arr[i] = rhs.arr[i];
    return *this;
}

// Move Constructor
template<typename T>
myvector<T>::myvector(myvector &&other) : capacity{other.capacity}, size{other.size}, arr{other.arr} {
    other.arr = nullptr;
    other.capacity = 0;
    other.size = 0;
}

// Move assignment
template<typename T>
myvector<T> &myvector<T>::operator=(myvector &&rhs) {
    if (this==&rhs)
        return *this;
    
    delete [] arr;
    size = rhs.size;
    capacity = rhs.capacity;
    arr = rhs.arr;

    rhs.arr = nullptr;
    rhs.size = 0;
    rhs.capacity = 0;
}

// Destructor
template<typename T>
myvector<T>::~myvector() {
    delete [] arr;
}

// Functions
template<typename T>
void myvector<T>::resize() {
    capacity *= 2;
    T *new_arr = new T[capacity];
    for (std::size_t i{0}; i<size; i++)
        new_arr[i] = arr[i];
    delete [] arr;
    arr = new_arr;
}

template<typename T>
void myvector<T>::push_back(const T &element) {
    if (size==capacity) 
        resize();
    arr[size] = element;
    ++size;
}

template<typename T>
void myvector<T>::pop_back() {
    if (size > 0)
        --size;
}

template<typename T>
T myvector<T>::at(const std::size_t index) {
    if (index<=size-1)
        return arr[index];
}

template<typename T>
std::size_t myvector<T>::len() {
    return size;
}