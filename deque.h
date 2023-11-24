//
// Created by 22976 on 2023/11/24.
//

#ifndef DATASTRUCTURE_DEQUE_H
#define DATASTRUCTURE_DEQUE_H

#include "queue.h"

namespace jack {
    using namespace jack;

    template<typename T>
    class deque : public queue<T> {
    public:
        typedef queue_iterator<T, T &, T *> iterator;
        typedef queue_iterator<T, const T &, const T *> const_iterator;

        deque() : queue<T>() {}

        deque(const deque<T> &other) : queue<T>(other) {}

        void pop_back() {
            queue<T>::erase(--queue<T>::end());
        }

        void push_front(const T &val) {
            queue<T>::insert(queue<T>::front(), val);
        }

        iterator back() {
            return iterator(queue<T>::head->prev);
        }

        const_iterator cback() const {
            return const_iterator(queue<T>::head->prev);
        }

    protected:
        typedef queue_node<T> node;
    };
}


#endif //DATASTRUCTURE_DEQUE_H
