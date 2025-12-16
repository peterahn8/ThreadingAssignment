//
// Created by Peter Ahn on 12/14/25.
//

#include <iostream>
#include <chrono>
#include <thread>

#include "Thread.h"
#include "GlobalState.h"

class TestThread : public Thread {
public:
    GlobalState globalState; // currently per thread. Fix this later
    void doWork() override {
        std::cout << "Hello from TestThread.\n";
        globalState.total += 1;

        std::cout << globalState.total;
    }
};

int main() {
    TestThread testThread;

    testThread.start();

    // std::this_thread::sleep_for(std::chrono::seconds(1));

    testThread.join();

    return 0;
}