#include <pthread.h>
#include "Thread.h"

void Thread::start() {
    pthread_create(&thread, nullptr, startRoutine, this);
}

void Thread::stop() {
    stopRequested = true;
}

void Thread::done() {

}

pthread_t Thread::id() {
    return thread;
}

void* Thread::startRoutine(void* arg) {
    Thread* self = static_cast<Thread*>(arg);
    self->doWork();
    self->done();

    return nullptr;
}

void Thread::join() {
    pthread_join(thread, nullptr);
}
