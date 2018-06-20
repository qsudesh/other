


/**--------------------------------------------------------------------------------------------------------------------

Compilation step

$ g++ -g --std=c++11 -pthread sasken01.cpp -o sasken01

After generating executable we can debug binary using gdb

$ gdb sasken01

Before executing we need some break point otherwise program will start and exist.

$ break thread_function01

Get all threads information what are executing for this program

$ info threads

For stack information of particular threads, first switch to thread using thread command and then use bt command 

$ thread thread_id
$ bt

To display all bt traces belonged to all threads 

$ thread apply all bt


*--------------------------------------------------------------------------------------------------------------------/



/******************************************************************************************
    InterviewX
    
    sasken01.cpp
    
    Purpose: How to debug multithread programming using gdb
    
    @author Jay Kant Kumar
    @version 1.0 20/06/2019

*******************************************************************************************/


#include <iostream>
#include <thread>

using namespace std;


void thread_function01(void)
{
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
