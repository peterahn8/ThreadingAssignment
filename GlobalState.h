#ifndef THREADINGASSIGNMENT_GLOBALSTATE_H
#define THREADINGASSIGNMENT_GLOBALSTATE_H

#include <pthread.h>

struct GlobalState {
    int total = 0;
    pthread_mutex_t mutex;
    int contributions[5] = {0, 0, 0, 0, 0};
};

#endif //THREADINGASSIGNMENT_GLOBALSTATE_H