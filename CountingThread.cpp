#include <iostream>
#include "CountingThread.h"

CountingThread::CountingThread(GlobalState& globalState, int index)
    : _globalState(globalState), _index(index) {
}

void CountingThread::doWork() {
    pthread_mutex_lock(&_globalState.mutex); // lock global state to prevent other threads from reading/writing it

    std::cout << "Hello from CountingThread " << _index << 
    " (pthread id: " << id() << ")" << std::endl;

    pthread_mutex_unlock(&_globalState.mutex); // unlock global state
}