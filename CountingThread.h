#ifndef THREADINGASSIGNMENT_COUNTINGTHREAD_H
#define THREADINGASSIGNMENT_COUNTINGTHREAD_H

#include "Thread.h"

class CountingThread : public Thread {
public:
    int count = 0; // may need to be private field

    void doWork() override;
};

#endif //THREADINGASSIGNMENT_COUNTINGTHREAD_H