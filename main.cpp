#include <iostream>
#include "GlobalState.h"
#include "CountingThread.h"

int main() {
    GlobalState globalState;

    pthread_mutex_init(&globalState.mutex, nullptr); // initialize mutex

    CountingThread thread0(globalState, 0);
    thread0.start();
    thread0.join();

    pthread_mutex_destroy(&globalState.mutex); // destroy mutex.. Not necessary with this short lifecycle, but docs recommended it

    return 0;
}
