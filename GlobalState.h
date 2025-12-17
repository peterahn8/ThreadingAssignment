//
// Created by Peter Ahn on 12/15/25.
//

#ifndef THREADINGASSIGNMENT_GLOBALSTATE_H
#define THREADINGASSIGNMENT_GLOBALSTATE_H

#include <pthread.h>

struct GlobalState {
    int total = 0;
    pthread_mutex_t mutex; // TODO: initialize mutex.. lock/unlock in doWork()
    int contributions[5] = {0, 0, 0, 0, 0};
};

#endif //THREADINGASSIGNMENT_GLOBALSTATE_H