#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        CP::stack<T> tmp = s, tmp2;
        while (!empty()) {
            tmp2.push(top());
            pop();
        }
        while (!tmp2.empty()) {
            tmp.push(tmp2.top());
            tmp2.pop();
        }
        (*this) = tmp;
    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
        CP::stack<T> tmp, tmp2, tmp3;
        while (!q.empty()) {
            tmp.push(q.front());
            q.pop();
        }
        while (!tmp.empty()) {
            tmp2.push(tmp.top());
            tmp.pop();
        }
        while (!empty()) {
            tmp3.push(top());
            pop();
        }
        while (!tmp3.empty()) {
            tmp2.push(tmp3.top());
            tmp3.pop();
        }
        (*this) = tmp2;
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        while (!s.empty()) {
            push(s.top());
            s.pop();
        }
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        while (!q.empty()) {
            push(q.front());
            q.pop();
        }
    }
}
