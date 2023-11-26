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
        deque() : queue<T>() {}

        deque(const deque<T> &other) : queue<T>(other) {}

        void pop_back() {
            this->erase(--this->end());
        }

        void push_front(const T &val) {
            this->insert(this->front(), val);
        }

        typename queue<T>::iterator back() {
            return this->iterator(this->head->prev);
        }

        typename queue<T>::const_iterator cback() const {
            return const_iterator(this->head->prev);
        }
    };
}


#endif //DATASTRUCTURE_DEQUE_H
