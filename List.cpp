#include "List.h"
template <class T>
// hàm dựng constructor
List<T>::List()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->_size = 0; // khởi tạo kích cỡ danh sách bằng 0
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
List<T>::List(const List<T> &other)
{
    // Khởi tạo các con trỏ head, tail và kích thước danh sách mới
    head = nullptr;
    tail = nullptr;
    _size = 0;
    // Duyệt qua danh sách other và sao chép từng phần tử
    node<T> *temp = other.head;
    while (temp != nullptr)
    {
        push_back(temp->data); // Thêm phần tử từ other vào danh sách mới
        temp = temp->next;
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
            /* nếu node ở giữa danh sách bao gồm các bước:
            Bước 1: Gán con trỏ cho node đầu tiên của mảng và thực hiện vòng lặp lần lượt gán con trỏ kế tiếp cho đến vị trí node cần được thêm vào.
            Bước 2: Chuyển con trỏ next của node đứng ngay trước node cần thêm tới vị trí của node ngay sau node cần thêm đó.
            Bước 3: Chuyển con trỏ prev của node đứng ngay sau node cần thêm về vị trí của node ngay trước node cần thêm vào đó.
            Bước 4: Cung cấp giá trị cho node mới thêm vào*/

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
    if (index < 0 || index >= this->_size) // nếu index nằm ngoài danh sách thì thoát
        return;
    if (this->_size == 0) // nếu danh sách đang rỗng thì thoát
    {
        return;
    }
    else if (this->_size == 1) // nếu danh sách còn 1 phần tử thì xóa head, gán head và tail bằng null
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        if (index == 0) 
        {   
            /* Trường hợp node ở vị trí đầu, ta chỉ việc chuyển con trỏ head để trỏ vào vị trí kế tiếp của node đầu tiên
             và giải phóng bộ nhớ đã cấp cho node đầu tiên đó.*/
            node<T> *p = this->head->next;
            p->prev = nullptr;
            delete this->head;
            this->head = p;
        }
        else if (index == this->_size - 1)
        {   /* Trường hợp node ở vị trí cuối cùng của danh sách, ta duyệt đến vị trí của node đứng ngay trước node cuối cùng,
             sau đó gán cho con trỏ next của node đó trỏ tới NULL và giải phóng bộ nhớ đã cấp cho node cuối cùng.*/
            node<T> *p = this->tail->prev;
            p->next = nullptr;
            delete this->tail;
            this->tail = p;
        }
        else
        {   
            /* Trường hợp node ở giữa danh sách phức tạp hơn một chút bao gồm các bước:
            Bước 1: Gán con trỏ cho node đầu tiên của mảng và thực hiện vòng lặp lần lượt gán con trỏ kế tiếp cho đến vị trí node cần xóa.
            Bước 2: Chuyển con trỏ next của node đứng ngay trước node cần xóa tới vị trí của node ngay sau node cần xóa đó.
            Bước 3: Chuyển con trỏ prev của node đứng ngay sau node cần xóa về vị trí của node ngay trước node cần xóa đó.
            Bước 4: Giải phóng bộ nhớ đã cấp cho node vừa xóa.*/

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
    if (begin >= 0 && begin <= end && end < this->_size) // kiểm tra begin <= end và end < kích thước danh sách
    {
        int k = begin;
        for (int i = begin; i <= end; i++)
        {
            erase(k); // sử dụng xóa k vì sau mỗi lần xóa thì phần tử k+1 sẽ dịch chuyển sang trái va trở thành k
        }
    }
}
template <class T>
// xóa toàn bộ dư liệu và xóa bộ nhớ
void List<T>::clear()
{
    if (this->_size == 0) // nếu danh sách rỗng thì thoát
    {
        return;
    }
    else if (this->_size == 1) // nếu danh sách có 1 phần tử thì xóa head, sau đó gán head và taid bằng null
    {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {   // ngược lại sử dụng xóa đoạn để xóa toàn bộ danh sách
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
