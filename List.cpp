#include "List.h"
template <class T>
// hàm dựng constructor
List<T>::List()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0;// khởi tạo kích cỡ danh sách bằng 0
}

template <class T>
// hàm hủy destructor
List<T>::~List()
{
    while (this->head)
    {
        node<T> *p = this->head->next;
        delete this->head;
        this->_size--;
        this->head = p;
    }
}

template <class T>
// hàm thêm một node vào cuối danh sách
void List<T>::push_back(T data)
{
    node<T> *new_node = new node<T>(data);
    if (this->head == nullptr) // nếu danh sách đang rỗng
    {
        this->head = this->tail = new_node;
    }
    else
    {
        this->tail->next = new_node;
        new_node->prev = this->tail;
        this->tail = new_node;
    }
    this->_size++;
}

template <class T>
// hàm thêm một node vào vị trí bất kì
void List<T>::add(int index, T data)
{
    if (index < 0 || index >= this->_size) // nếu index nằm ngoài danh sách thì thoát
        return;
    node<T> *new_node = new node<T>(data);
    if (this->_size == 0) // nếu danh sách đang rỗng
    {
        this->head = this->tail = new_node;
    }
    else
    {
        if (index == 0)
        {
            new_node->next = this->head;
            this->head->prev = new_node;
            this->head = new_node;
        }
        else if (index == this->_size) // nếu index là _size thì ta sử dụng phương thức push_back
        {
            push_back(data);
        }
        else
        {
            node<T> *p = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            new_node->next = p->next;
            new_node->prev = p;
            p->next->prev = new_node;
            p->next = new_node;
        }
    }
    this->_size++;
}

template <class T>
// xóa một node bất kì
void List<T>::erase(int index)
{
    if (index < 0 || index >= this->_size)
        return;
    if (this->_size == 0)
    {
        return;
    }
    else if (this->_size == 1)
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        if (index == 0)
        {
            node<T> *p = this->head->next;
            p->prev = nullptr;
            delete this->head;
            this->head = p;
        }
        else if (index == this->_size - 1)
        {
            node<T> *p = this->tail->prev;
            p->next = nullptr;
            delete this->tail;
            this->tail = p;
        }
        else
        {
            node<T> *p = this->head;
            for (int i = 0; i < index; i++)
            {
                p = p->next;
            }
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
        }
    }
    this->_size--;
}
template <class T>
// xóa dữ liệu theo khoảng
void List<T>::erase(int begin, int end)
{
    if (begin >= 0 && begin <= end && end < this->_size)
    {
        int k = begin;
        for (int i = begin; i <= end; i++)
        {
            erase(k);
        }
    }
}
template <class T>
// xóa toàn bộ dư liệu và xóa bộ nhớ
void List<T>::clear()
{
    if (this->_size == 0)
    {
        return;
    }
    else if (this->_size == 1)
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        erase(0, this->_size - 1);
    }
    this->_size = 0;
}

template <class T>
// trả về kích thước của danh sách
int List<T>::getSize()
{
    return this->_size;
}

template <class T>
// đa năng hóa toán tử []
T &List<T>::operator[](int index)
{
    static T NGU;
    if (index >= 0 && index < this->_size)
    {
        node<T> *p = this->head;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        return p->data;
    }
    else
    {
        return NGU;
    }
}
