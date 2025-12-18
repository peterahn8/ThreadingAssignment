#ifndef THREADINGASSIGNMENT_COUNTINGTHREAD_H
#define THREADINGASSIGNMENT_COUNTINGTHREAD_H

#include "Thread.h"
#include "GlobalState.h"

class CountingThread : public Thread {
public:
    CountingThread(GlobalState& globalState, int index);

    void doWork() override;
private:
    GlobalState& _globalState;
    int _index;

    int _count = 0;
};

#endif //THREADINGASSIGNMENT_COUNTINGTHREAD_H