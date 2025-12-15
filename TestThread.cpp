//
// Created by Peter Ahn on 12/14/25.
//

#include <iostream>

#include "Thread.h"

class TestThread : public Thread {
public:
    void doWork() override {
        std::cout << "Hello from TestThread.\n";
    }
};

int main() {
    TestThread testThread;

    testThread.start();
    return 0;
}