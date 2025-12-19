#include <iostream>
#include <random>
#include <thread>
#include "CountingThread.h"

CountingThread::CountingThread(GlobalState& globalState, int index)
    : _globalState(globalState), _index(index) {
}

void CountingThread::doWork() {
    // https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine.html
    std::mt19937 rng(std::random_device{}() + _index);
    std::uniform_int_distribution<int> dist(1, 10);

    while (!stopRequested) {
        int increment = dist(rng);

        pthread_mutex_lock(&_globalState.mutex);

        int remaining = 100 - _globalState.total;
        if (remaining <= 0) {
            pthread_mutex_unlock(&_globalState.mutex);
            stop();
            break;
        }

        _count += increment;
        _globalState.total += increment;

        pthread_mutex_unlock(&_globalState.mutex);

        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // the work is so fast/cheap that if I don't manually sleep the thread, then the same thread hogs the cpu
    }
}

void CountingThread::done() {
    pthread_mutex_lock(&_globalState.mutex);

    _globalState.contributions[_index] = _count;

    std::cout << "CountingThread " << id() << " finished counting: " << _count << std::endl;

    pthread_mutex_unlock(&_globalState.mutex);
}