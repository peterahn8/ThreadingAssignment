#ifndef THREADINGASSIGNMENT_THREAD_H
#define THREADINGASSIGNMENT_THREAD_H

#include <pthread.h>
#include <atomic>

class Thread {
public:
    // spec 1: "begins the work associated w/ the thread"
    void start();

    // spec 2: "stops the work associated w/ the thread"
    void stop();

    void join(); // not explicitly stated in assignment specs, but was necessary to complete the abstraction
    
    // spec 3: "called when the work associated w/ the thread is complete"
    virtual void done();

    // spec 4: "returns the unique id of that thread"
    pthread_t id();

protected:
    virtual void doWork() = 0;

    std::atomic<bool> stopRequested = false; // https://stackoverflow.com/questions/62830569/boolean-stop-signal-between-threads

private:
    pthread_t thread;

    static void* startRoutine(void* arg);
};

#endif //THREADINGASSIGNMENT_THREAD_H