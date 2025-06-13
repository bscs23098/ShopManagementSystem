#ifndef DYNAMIC_H
#define DYNAMIC_H
#include<iostream>
using namespace std;

template <class T>
class Dynamic_array {
private:
  T *arr;
  int len;
  int cap;

  // Doubles the current capacity when needed
  void double_capacity(){
    T * temp_array = new T[len];
    for (int i = 0; i < len; i++) {
        temp_array[i] = arr[i];
    }
    cap *= 2;
    delete[] arr;
    arr = new T[cap];
    for (int i=0;i < len;i++) {
        arr[i] = temp_array[i];
    }
    delete[] temp_array;
  }

public:
  // Constructors & Destructor
  Dynamic_array(){ 
    len = 0;
    cap = 1;
    arr = new T [cap];}                           // Default constructor
  Dynamic_array(int count, int value){
    len = count;
    if (count > 0) {
        cap = count;
    }
    else {
        cap = 1;
    }
    arr = new T[cap];
    for (int i = 0; i < count; i++) {
        arr[i] = value;
    }
  }      // Fill constructor
  Dynamic_array(const Dynamic_array &other){
    len = other.len;
    cap = other.cap;
    arr = new T[cap];
    for (int i = 0;i < len;i++) {
        arr[i] = other.arr[i];
    }
  } // Copy constructor
  ~Dynamic_array(){
    delete[]  arr;

  }                     // Destructor

  // Operators
  Dynamic_array &operator=(const Dynamic_array &other){
    delete[] arr; // Free old memory

    len = other.len;
    cap = other.cap;
    arr = new T[cap];
    for (int i = 0; i < len; i++) {
        arr[i] = other.arr[i];
    }

    return *this;
  } // Copy assignment
  T &operator[](int index){
    if (index < 0 || index >= len) {
        throw out_of_range("Invalid index");
    }
    return arr[index];
  }                           // Subscript operator
  const T &operator[](int index) const{
    if (index < 0 || index >= len) {
        throw out_of_range("Invalid index");
    }
    return arr[index];
  }            // Const subscript operator
  bool operator==(const Dynamic_array &other) const{
    if (len != other.len) {
        return false;
    }
    for (int i = 0;i < len;i++) {
        if (arr[i] != other.arr[i]) {
            return false;
        }
    }
    return true;
  } // Equality comparison
  bool operator!=(const Dynamic_array &other) const{
    if (len != other.len) {
        return true;
    }
    for (int i = 0;i < len;i++) {
        if (arr[i] != other.arr[i]) {
            return true;
        }
    }
    return false;
  } // Inequality comparison
  Dynamic_array operator+(const Dynamic_array &other) const{
    Dynamic_array result;
    result.len = len + other.len;
    result.cap = result.len;
    result.arr = new T[result.cap];

    for (int i = 0; i < len; i++) {
        result.arr[i] = arr[i];
    }
    for (int i = 0; i < other.len; i++) {
        result.arr[len + i] = other.arr[i];
    }

    return result;
  } // Concatenation
  Dynamic_array &operator+=(const Dynamic_array &other){
    int temp_len = len + other.len;
    int temp_cap = cap + other.cap;
    T* temp_array = new T[temp_cap];
    for (int i = 0;i < len;i++) {
        temp_array[i] = arr[i];
    }
    for (int i = 0;i < other.len;i++) {
        temp_array[i + len] = other.arr[i];
    }
    delete[] arr;
    len = temp_len;
    cap = temp_cap;
    arr = new T[temp_cap];
        for (int i = 0;i < temp_len;i++) {
            arr[i] = temp_array[i];
        }
    delete[] temp_array;
    return *this;
  }     // Append

  // Modifiers
  void push(T value){
    if (len==cap){ double_capacity(); }
    arr[len] = value;
    len += 1;
  }                // Adds an element to the end
  void pop(){
    T* temp_array = new T[len - 1];
    for (int i = 0;i < len - 1;i++) {
        temp_array[i] = arr[i];
    }
    delete[] arr;
    len -= 1;
    arr = new T[cap];
    for (int i = 0;i < len;i++) {
        arr[i] = temp_array[i];
    }
    delete[]  temp_array;
  }                           // Removes the last element
  void insert_at(int index, T value){
    arr[index] = value;
  } // Inserts value at index
void delete_at(int index){
    if (index < 0 || index >= len) {
        throw out_of_range("Invalid index");
    }
    T* temp_array = new T[len - 1];
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (i == index) continue;
        temp_array[j++] = arr[i];
    }
    delete[] arr;
    len -= 1;
    arr = new T[cap];
    for (int i = 0; i < len; i++) {
        arr[i] = temp_array[i];
    }
    delete[] temp_array;
}           // Deletes value at index
  void reserve(int new_capacity){
    if (new_capacity <= cap) return;

    T* new_arr = new T[new_capacity];
    for (int i = 0; i < len; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
    cap = new_capacity;
  }      // Reserves a new capacity
  void clear(){
    delete[]  arr;
    arr = new T[cap];
    len = 0;
  }                         // Clears all elements
  void swap(Dynamic_array &other){
    int temp_len = len;
    int temp_cap = cap;
    T* temp_array = new T[cap];
    for (int i = 0;i < len;i++) {
        temp_array[i] = arr[i];
    }
    delete[] arr;
    len = other.len;
    cap = other.cap;
    arr = new T[cap];
        for (int i = 0;i < len;i++) {
            arr[i] = other.arr[i];
        }
    delete[] other.arr;
    other.len = temp_len;
    other.cap = temp_cap;
    other.arr= new T[other.cap];
    for (int i = 0;i < len;i++) {
        other.arr[i] = temp_array[i];
    }
    delete[] temp_array;
  }      // Swaps with another array
  void shrink_to_fit(){
    if (len < cap) {
        T* new_arr = new T[len];
        for (int i = 0; i < len; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        cap = len;
    }
  }                 // Reduces capacity to match size
  void reverse(){
    T* temp_array = new T[len];
    int j = 0;
    for (int i = len - 1;i >= 0;i--) {
        temp_array[j++] = arr[i];
    }
    delete[]arr;
    arr = new T[cap];
    for (int i = 0;i < len;i++) {
        arr[i] = temp_array[i];
    }
    delete[] temp_array;
  }                      // Reverses the array elements

  // Accessors
  bool empty() const{
    return len == 0;
  } // Checks if array is empty
  int size() const{
    return len;
  }   // Returns current size

  T &at(int index){
    if (index < 0 || len <= index) {
        throw out_of_range("Invalid index");
    }
    return arr[index];
  } // Bounds-checked element access
  const T &at(int index) const{
    if (index < 0  ||  len <= index) {
        return -1;
    }
    return arr[index];
  }

  T &front(){
    if (empty()) {
        throw out_of_range("Invalid index");
    }
    return arr[0];
}// Returns first element
  const int &front() const{
    if (empty()) {
        throw out_of_range("Invalid index");
    }
    return arr[0];
  }

  T &back(){
    if (empty()) {
        throw out_of_range("Invalid index");
    }
    return arr[len - 1];
  } // Returns last element
  const int &back() const{
    if (empty()) {
        throw out_of_range("Invalid index");
    }
    return arr[len - 1];
  }

  int find(T value) const{
    for (int i = 0;i < len;i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
  } // Return index of first instance, or -1 if non-existent
};

#endif // DYNAMIC_H