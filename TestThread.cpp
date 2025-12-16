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
    GlobalState sharedState;
    void doWork() override {
        std::cout << "Hello from TestThread.\n";
        sharedState.currentTotal += 1;

        std::cout << sharedState.currentTotal;
    }
};

int main() {
    TestThread testThread;

    testThread.start();

    // std::this_thread::sleep_for(std::chrono::seconds(1));

    testThread.join();

    return 0;
}