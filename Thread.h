#ifndef THREADINGASSIGNMENT_THREAD_H
#define THREADINGASSIGNMENT_THREAD_H

#include <pthread.h>
#include <atomic>

class Thread {
public:
    /* "begins the work associated w/ the thread" */
    void start();

    /* "stops the work associated w/ the thread" */
    void stop();

    /* "called when the work associated w/ the thread is complete"
     * It is not clear if this should return a value. Leaving it as void for now
     */
    void done();

    /* "returns the unique id of that thread" */
    pthread_t id();

    void join();

    virtual void doWork() = 0; // TODO: override downstream

    static void* startRoutine(void* arg);

    std::atomic<bool> stopRequested = false; // https://stackoverflow.com/questions/62830569/boolean-stop-signal-between-threads
private:
    pthread_t thread;
};

#endif //THREADINGASSIGNMENT_THREAD_H