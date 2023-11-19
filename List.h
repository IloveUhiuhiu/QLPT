#pragma once
#ifndef LIST_H
#define LIST_H
template <class T>
class node
{
public:
    T data;// phần dữ liệu của một node
    node<T> *prev;// con trỏ trỏ tới node trước nó
    node<T> *next;// con trỏ trỏ tới node kế tiếp nó
    node(T data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template <class T>
class List
{
private:
    int _size;
    node<T> *head;// con trỏ trỏ tới node đầu tiên
    node<T> *tail;// con trỏ trỏ tới node cuối cùng
public:
    List(); // hàm dựng constructor
    ~List();// hàm hủy destructor
    void push_back(T);// hàm thêm một node vào cuối danh sách
    void add(int, T);// hàm thêm một node vào vị trí bất kì
    void erase(int);// xóa một node bất kì
    void clear();// xóa toàn bộ dư liệu và xóa bộ nhớ
    void erase(int, int);// xóa dữ liệu theo khoảng
    int getSize();// trả về kích thước của danh sách
    T &operator[](int);// đa năng hóa toán tử []
};

#endif