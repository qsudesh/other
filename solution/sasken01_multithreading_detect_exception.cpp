
/******************************************************************************************
    InterviewX
    
    sasken01.cpp
    
    Purpose: How to detect exception in multithreaded program using GDB
    
    @author Jay Kant Kumar
    @version 1.0 20/06/2019

*******************************************************************************************/

#include <iostream>
#include <thread>

using namespace std;

void thread_function01(void)
{
    cout << 1 / 0 << endl; // Exception code. 
    cout << "Thread function 1 is called." << endl;
}

void thread_function02(void)
{
    cout << "Thread function 2 is called." << endl;
}

/* Client program to test  */

/*******************************************************************************************
    learn how a multithread program can be debuged using ddb in case of segmentation fault

    @param  void 
    @return void

*******************************************************************************************/

int main()
{
    // Create two threads and start
    thread thread1(thread_function01);
    thread thread2(thread_function02);
    
    thread1.join();
    thread2.join();
    
    return 0;
    
}
