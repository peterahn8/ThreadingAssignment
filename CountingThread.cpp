#include <iostream>
#include "CountingThread.h"

CountingThread::CountingThread(GlobalState& globalState, int index)
    : _globalState(globalState), _index(index) {
}

void CountingThread::doWork() {
    pthread_mutex_lock(&_globalState.mutex); // lock global state to prevent other threads from reading/writing it

    std::cout << "Hello from CountingThread " << id() << std::endl;

    pthread_mutex_unlock(&_globalState.mutex); // unlock global state
}

void CountingThread::done() {
    pthread_mutex_lock(&_globalState.mutex);

    _globalState.contributions[_index] = _count;

    std::cout << "CountingThread " << id() << " finished counting: " << _count << std::endl;

    pthread_mutex_unlock(&_globalState.mutex);
}