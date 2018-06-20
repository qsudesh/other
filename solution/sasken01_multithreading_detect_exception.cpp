
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


/*--------------------------------------- GDB debugging log ---------------------------------------------

Reading symbols from /home/a.out...done.                                                                                                                                            
(gdb) r                                                                                                                                                                             
Starting program: /home/a.out                                                                                                                                                       
[Thread debugging using libthread_db enabled]                                                                                                                                       
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".                                                                                                          
[New Thread 0x7ffff6fc5700 (LWP 4657)]                                                                                                                                              
                                                                                                                                                                                    
Program received signal SIGFPE, Arithmetic exception.                                                                                                                               
[Switching to Thread 0x7ffff6fc5700 (LWP 4657)]                                                                                                                                     
0x0000000000400fc7 in thread_function01 () at main.cpp:21                                                                                                                           
21          cout << 1 / 0 << endl; // Exception code.                                                                                                                               
(gdb) bt                                                                                                                                                                            
#0  0x0000000000400fc7 in thread_function01 () at main.cpp:21                                                                                                                       
#1  0x0000000000402499 in std::_Bind_simple<void (*())()>::_M_invoke<>(std::_Index_tuple<>) (this=0x616c48) at /usr/include/c++/5/functional:1531                                   
#2  0x0000000000402405 in std::_Bind_simple<void (*())()>::operator()() (                                                                                                           
    this=0x616c48) at /usr/include/c++/5/functional:1520                                                                                                                            
#3  0x00000000004023a4 in std::thread::_Impl<std::_Bind_simple<void (*())()> >::_M_run() (this=0x616c30) at /usr/include/c++/5/thread:115                                           
#4  0x00007ffff793a5b0 in ?? () from /usr/lib/x86_64-linux-gnu/libstdc++.so.6                                                                                                       
#5  0x00007ffff7bc4182 in start_thread (arg=0x7ffff6fc5700)                                                                                                                         
    at pthread_create.c:312                                                                                                                                                         
#6  0x00007ffff73c730d in clone ()                                                                                                                                                  
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:111                                                                                                                                
(gdb) info threads                                                                                                                                                                  
[New Thread 0x7ffff67c4700 (LWP 4659)]                                                                                                                                              
  Id   Target Id         Frame                                                                                                                                                      
  3    Thread 0x7ffff67c4700 (LWP 4659) "a.out" clone ()                                                                                                                            
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:81                                                                                                                                 
* 2    Thread 0x7ffff6fc5700 (LWP 4657) "a.out" 0x0000000000400fc7 in thread_function01 () at main.cpp:21                                                                           
  1    Thread 0x7ffff7fe8780 (LWP 4653) "a.out" clone ()                                                                                                                            
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:81                                                                                                                                 
(gdb)                                                                                                                                                                               
      


---------------------------------------------------------------------------------------------------------------*/
