#ifndef SINGLY_H
#define SINGLY_H

namespace singly
{
template<class T>
class list 
{
public:
    list();
    ~list();
    int is_empty();
    void add_to_head(T);
    void add_to_tail(T);
    T pop_front();
    T pop_back();
    void delete_node(T);
    bool find(T) const;
private:
    struct node
    {
        node() 
            : next{nullptr}{}
        node(T _data, node* p=nullptr)
            : data{_data}, next{p}{}
        T data;
        node* next;
    };

    node* head;
    node* tail;
};

template<typename T>
list<T>::list()
    : head{nullptr}, tail{nullptr}
{
}

template<typename T>
list<T>::~list()
{
    for(node* p; !is_empty();) {
        p = head->next;
        delete head;
        head = p;
    }
}

template<typename T>
int list<T>::is_empty()
{
    return head == 0;
}

template<typename T>
void list<T>::add_to_head(T _data)
{
    head = new node(_data, head);
    if(tail == nullptr) {
        tail = head;
    }
}

template<typename T>
void list<T>::add_to_tail(T _data)
{
    if(tail != nullptr) { // list is not empty
        tail->next = new node(_data);
    }
    else {
        tail = tail->next;
    }
}

template<typename T>
T list<T>::pop_front()
{
    T _data = head->data;
    node* tmp = head;
    if(head == tail) { // only one entry in list
        head = nullptr;
        tail = nullptr;
    }
    else {
        head = head->next;
    }
    delete tmp;
    return _data;
}

template<typename T>
T list<T>::pop_back()
{
    T _data = tail->data;
    if(head == tail) { // only one entry in list
        delete head;
        head == nullptr;
        tail == nullptr;
    }
    else { // if more than one entry in the list
        node* tmp; // find what was before tail
        for(tmp = head; tmp->next != tail; tmp->next); // go to end of list
        delete tail;
        tail = tmp; // this was before the tail and becomes tail
        tail->next = nullptr;
    }
    return _data;
}

template<typename T>
bool list<T>::find (T _data) const
{
    node* tmp;
    for(tmp = head; tmp != nullptr &&
        !(tmp->data == _data); tmp = tmp->next);
    return tmp != 0;
}
} // namespace
#endif
