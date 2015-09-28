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
        void add_to_head(const T&);
        void add_to_tail(const T&);
        T pop_front();
        T pop_back();
        void delete_node(T);
        bool find(T) const;
    private:
        struct node
        {
            node() 
                : next{nullptr}{}
            node(const T& _data, node* p=nullptr)
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
    void list<T>::add_to_head(const T& _data)
    {
        head = new node(_data, head);
        if(tail == nullptr) {
            tail = head;
        }
    }

    template<typename T>
    void list<T>::add_to_tail(const T& _data)
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
        if(is_empty()) { // make sure not an empty list
            throw("Empty list");
        }
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
        if(is_empty()) { // make sure list is not empty
            throw("List is empty");
        }
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
    void list<T>::delete_node(T _data)
    {
        if(head != nullptr) { // list is not empty
            if(head == tail && _data == head->data) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else if(_data == head->data) { // if more than one node in list
                node* tmp = head;
                head = head->next;
                delete tmp;
            }
            else {
                node *p, *tmp;
                for(p = head, tmp = head->next;
                    tmp != nullptr && (tmp->data == _data);
                    p = p->next, tmp = tmp->next);
                if(tmp != nullptr) {
                    p->next = tmp->next;
                    if(tmp == tail) {
                        tail = p;
                    }
                    delete tmp;
                }
            }
        }
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
