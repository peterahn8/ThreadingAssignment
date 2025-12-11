//
// Created by Peter Ahn on 12/11/25.
//

#ifndef THREADINGASSIGNMENT_THREAD_H
#define THREADINGASSIGNMENT_THREAD_H

class Thread {
    /* "begins the work associated w/ the thread" */
    void start();

    /* "stops the work associated w/ the thread" */
    void stop();

    /* "called when the work associated w/ the thread is complete"
     * It is not clear if this should return a value. Leaving it as void for now
     */
    void done();

    /* "returns the unique id of that thread"
     * I don't know what type the ID could be yet. Returning an int for now
     */
    int id();
};

#endif //THREADINGASSIGNMENT_THREAD_H