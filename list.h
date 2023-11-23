//
// Created by 22976 on 2023/11/23.
//

#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H
namespace jack {
    typedef unsigned long long size_t;

    template<typename T>
    struct node {
        T Val;
        node<T> *Next;
        node<T> *Prev;

        node(const T &_Val = T()) {
            Val = _Val;
            Next = nullptr;
            Prev = nullptr;
        }
    };

    template<typename T, typename Ref, typename Ptr>
    struct iterator {
        typedef node<T> list_node;
        typedef iterator<T, Ref, Ptr> self;

        list_node *pnode;

        iterator(list_node *pnode) : pnode(pnode) {}

        Ref operator*() {
            return pnode->Val;
        }

        Ptr operator->() {
            return &pnode->Val;
        }

        bool operator!=(const self &it) const {
            return pnode != it.pnode;
        }

        bool operator==(const self &it) const {
            return pnode == it.pnode;
        }

        self &operator++() {
            pnode = pnode->Next;
            return *this;
        }

        self operator++(int) {
            self tmp = *this;
            pnode = pnode->Next;
            return tmp;
        }

        self &operator--() {
            pnode = pnode->Prev;
            return *this;
        }

        self operator--(int) {
            self tmp = *this;
            pnode = pnode->Prev;
            return tmp;
        }
    };

    template<typename T>
    class list {
        typedef node<T> list_node;
    public:
        typedef iterator<T, T &, T *> list_iterator;
        typedef iterator<T, const T &, const T *> const_list_iterator;

        list() {
            head = new list_node();
            head->Next = head;
            head->Prev = head;
        }

        list(const list<T> &other) {
            head = new list_node();
            head->Next = head;
            head->Prev = head;
            for (auto it = other.begin(); it != other.end(); it++) {
                push_back(*it);
            }
        }

        list<T> &operator=(const list<T> &other) {
            if (this != &other) {
                clear();
                for (auto it = other.begin(); it != other.end(); it++) {
                    push_back(*it);
                }
            }
            return *this;
        }

        ~list() {
            clear();
            delete head;
            head = nullptr;
        }

        list_iterator begin() {
            return list_iterator(head->Next);
        }

        list_iterator end() {
            return list_iterator(head);
        }

        const_list_iterator begin() const {
            return const_list_iterator(head->Next);
        }

        const_list_iterator end() const {
            return const_list_iterator(head);
        }

        void insert(list_iterator pos, const T &val) {

            list_node *newnode = new list_node(val);

            newnode->Next = pos.pnode->Next;
            pos.pnode->Next = newnode;

            newnode->Prev = pos.pnode;
            newnode->Prev = pos.pnode;

        }

        list_iterator erase(list_iterator pos) {
            if (pos.pnode == head) {
                return pos;
            }
            list_node *next = pos.pnode->Next;
            list_node *prev = pos.pnode->Prev;
            delete pos.pnode;
            prev->Next = next;
            next->Prev = prev;
            return list_iterator(next);
        }

        void clear() {
            list_iterator it = begin();
            while (it != end()) {
                erase(it++);
            }
        }

        void push_front(const T &val) {
            insert(begin(), val);
        }

        void push_back(const T &val) {
            insert(--end(), val);
        }

        void pop_front() {
            erase(begin());
        }

        void pop_back() {
            erase(--end());
        }

        bool empty() const {
            return head->Next == head;
        }

        size_t size() const {
            size_t count = 0;
            for (auto it = begin(); it != end(); it++) {
                count++;
            }
            return count;
        }

    private:
        list_node *head;
    };

}


#endif //DATASTRUCTURE_LIST_H
