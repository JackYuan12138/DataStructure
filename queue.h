//
// Created by 22976 on 2023/11/24.
//

#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H
namespace jack {
    template<typename T>
    struct queue_node {
        T val;
        queue_node<T> *next;
        queue_node<T> *prev;

        queue_node(const T &_val = T()) {
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    template<typename T, typename Ref, typename Ptr>
    struct queue_iterator {
        typedef queue_node<T> node;
        typedef queue_iterator<T, Ref, Ptr> self;

        node *pnode;

        queue_iterator(node *_pnode) : pnode(_pnode) {}

        Ref operator*() {
            return pnode->val;
        }

        Ptr operator->() {
            return &pnode->val;
        }

        bool operator==(const self &other) const {
            return this->pnode == other.pnode;
        }

        bool operator!=(const self &other) const {
            return pnode != other.pnode;
        }

        self &operator++() {
            pnode = pnode->next;
            return *this;
        }

        self operator++(int) {
            self tmp = *this;
            pnode = pnode->next;
            return tmp;
        }

        self &operator--() {
            pnode = pnode->prev;
            return *this;
        }

        self operator--(int) {
            self tmp = *this;
            pnode = pnode->prev;
            return tmp;
        }

    };

    template<typename T>
    class queue {
    public:
        typedef queue_iterator<T, T &, T *> iterator;
        typedef queue_iterator<T, const T &, const T *> const_iterator;
        typedef unsigned long long size_t;

        queue() {
            head = new node();
            head->prev = head;
            head->next = head;
        }

        queue(const queue<T> &other) {
            head = new node();
            head->prev = head;
            head->next = head;
            for (auto it = other.begin(); it != it.end(); it++) {
                push_back(*it);
            }
        }

        ~queue() {
            clear();
            delete head;
            head = nullptr;
        }

        queue<T> &operator=(const queue<T> &other) {
            clear();
            for (auto it = other.begin(); it != it.end(); it++) {
                push_back(*it);
            }
            return *this;
        }

        const_iterator cfront() const {
            return const_iterator(head->next);
        }

        iterator front() {
            return iterator(head->next);
        }

        void clear() {
            iterator it = front();
            while (it != end()) {
                erase(it++);
            }
        }

        size_t size() const {
            size_t count = 0;
            for (iterator it = front(); it != end(); it++) {
                count++;
            }
            return count;
        }

        bool empty() const {
            return head->next == head;
        }

        void push_back(const T &val) {
            insert(--end(), val);
        }

        void pop_front() {
            erase(front());
        }

    protected:
        typedef queue_node<T> node;
        node *head;
        iterator erase(iterator pos) {
            if (pos.pnode == head) {
                return pos;
            }
            node *prev = pos.pnode->prev;
            node *next = pos.pnode->next;

            delete pos.pnode;

            prev->next = next;
            next->prev = prev;
            return iterator(next);
        }

        iterator insert(iterator pos, const T &val) {
            node *newnode = new node(val);

            pos.pnode->next->prev = newnode;
            newnode->next = pos.pnode->next;

            pos.pnode->next = newnode;
            newnode->prev = pos.pnode;

            return iterator(newnode);
        }

        const_iterator cend() const {
            return const_iterator(head);
        }

        iterator end() {
            return iterator(head);
        }
    };


}

#endif //DATASTRUCTURE_QUEUE_H
