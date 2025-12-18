#include <array>
#include <memory>
#include "GlobalState.h"
#include "CountingThread.h"

int main() {
    GlobalState globalState;

    pthread_mutex_init(&globalState.mutex, nullptr); // initialize mutex

    // https://stackoverflow.com/questions/34989245/c-making-and-destroying-unique-ptr-pointer
    std::array<std::unique_ptr<CountingThread>, 5> threads;

    for (int i = 0; i < 5; ++i) { threads[i] = std::make_unique<CountingThread>(globalState, i); }
    for (int i = 0; i < 5; ++i) { threads[i]->start(); }
    for (int i = 0; i < 5; ++i) { threads[i]->join(); }

    pthread_mutex_destroy(&globalState.mutex); // destroy mutex

    return 0;
}
