#ifndef THREAD_HPP
#define THREAD_HPP

#include "MessageQueue.h"
#include <cstddef>
#include <iostream>
#include <string>

class Thread {
    public:
        Thread() = default;
    virtual void registerThread() {}
    virtual bool run() {return false;}
};


template <typename Ty, std::size_t sz>
class UI : public Thread {
    MessageQueue<Ty, sz> *queue;
    int i = 0;
    public:
        UI(MessageQueue<Ty, sz> &queue_) {queue = &queue_;}
        bool run() override {
            queue->send(i++);
            if (i >= 7)
                return true;
            else 
                return false;
        }
};

template <typename Ty, std::size_t sz>
class Display : public Thread {
    MessageQueue<Ty, sz> *queue;
    public:
        Display(MessageQueue<Ty, sz> &queue_) { queue = &queue_;}
        bool run() override {
            auto [b, a] =  queue->receive();
            std::cout << b << std::endl;
            if (b == 5)
                return true;
            else
                return false;
        }

};
#endif /* THREAD_HPP */
