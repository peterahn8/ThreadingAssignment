#ifndef THREADINGASSIGNMENT_COUNTINGTHREAD_H
#define THREADINGASSIGNMENT_COUNTINGTHREAD_H

#include "Thread.h"
#include "GlobalState.h"

class CountingThread : public Thread {
public:
    CountingThread(GlobalState& globalState, int index);

    int count = 0;

    void doWork() override;
private:
    GlobalState& _globalState;
    int _index;
};

#endif //THREADINGASSIGNMENT_COUNTINGTHREAD_H