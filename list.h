//
// Created by 22976 on 2023/11/23.
//

#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H
namespace jack {
    typedef unsigned long long size_t;

    template<typename T>
    struct list_node {
        T Val;
        list_node<T> *Next;
        list_node<T> *Prev;

        list_node(const T &_Val = T()) {
            Val = _Val;
            Next = nullptr;
            Prev = nullptr;
        }
    };

    template<typename T, typename Ref, typename Ptr>
    struct list_iterater {
        typedef list_node<T> node;
        typedef list_iterater<T, Ref, Ptr> self;

        node *pnode;

        list_iterater(node *pnode) : pnode(pnode) {}

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
        typedef list_node<T> node;
    public:
        typedef list_iterater<T, T &, T *> iterator;
        typedef list_iterater<T, const T &, const T *> const_iterator;

        list() {
            head = new node();
            head->Next = head;
            head->Prev = head;
        }

        list(const list<T> &other) {
            head = new node();
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

        iterator begin() {
            return iterator(head->Next);
        }

        iterator end() {
            return iterator(head);
        }

        const_iterator cbegin() const {
            return const_iterator(head->Next);
        }

        const_iterator cend() const {
            return const_iterator(head);
        }

        void insert(iterator pos, const T &val) {

            node *newnode = new node(val);

            newnode->Next = pos.pnode->Next;
            pos.pnode->Next = newnode;

            newnode->Prev = pos.pnode;
            newnode->Next->Prev = newnode;

        }

        iterator erase(iterator pos) {
            if (pos.pnode == head) {
                return pos;
            }
            node *next = pos.pnode->Next;
            node *prev = pos.pnode->Prev;
            delete pos.pnode;
            prev->Next = next;
            next->Prev = prev;
            return iterator(next);
        }

        void clear() {
            iterator it = begin();
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
        node *head;
    };

}


#endif //DATASTRUCTURE_LIST_H
