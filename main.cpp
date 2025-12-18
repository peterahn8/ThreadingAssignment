#include <iostream>
#include "GlobalState.h"
#include "CountingThread.h"

int main()
{
    GlobalState globalState;

    // std::cout << "Hello, World!" << std::endl;

    CountingThread thread0(globalState, 0);
    thread0.start();
    thread0.join();

    return 0;
}