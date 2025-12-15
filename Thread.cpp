//
// Created by Peter Ahn on 12/11/25.
//

#include "Thread.h"
#include "pthread.h"

void Thread::start() {
    pthread_create(&thread, nullptr, startRoutine, this);
}

void Thread::stop() {

}

void Thread::done() {

}

int Thread::id() {
    // TODO: whichever type gets returned by pthreads api
    return 0;
}

void* Thread::startRoutine(void* arg) {
    Thread* self = static_cast<Thread*>(arg);
    self->doWork();
    self->done();

    return nullptr;
}
