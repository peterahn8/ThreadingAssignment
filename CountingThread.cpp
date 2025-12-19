#include <iostream>
#include "CountingThread.h"

CountingThread::CountingThread(GlobalState& globalState, int index)
    : _globalState(globalState), _index(index) {
}

void CountingThread::doWork() {

    while (!stopRequested) {
        int step = 1;

        pthread_mutex_lock(&_globalState.mutex);

        int remaining = 100 - _globalState.total;
        if (remaining == 0) {
            pthread_mutex_unlock(&_globalState.mutex);
            stop();
            break;
        }

        _count += step;
        _globalState.total += step;

        pthread_mutex_unlock(&_globalState.mutex);
    }
}

void CountingThread::done() {
    pthread_mutex_lock(&_globalState.mutex);

    _globalState.contributions[_index] = _count;

    std::cout << "CountingThread " << id() << " finished counting: " << _count << std::endl;

    pthread_mutex_unlock(&_globalState.mutex);
}