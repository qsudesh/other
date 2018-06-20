



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


/*------------------------------------ Debuggling log  ------------------------------------------
   
Reading symbols from /home/a.out...done.                                                                                                                                                                                                                                                            
(gdb) break thread_function01                                                                                                                                                                                                                                                                       
Breakpoint 1 at 0x400f6c: file main.cpp, line 56.                                                                                                                                                                                                                                                   
(gdb) info breakpoints                                                                                                                                                                                                                                                                              
Num     Type           Disp Enb Address            What                                                                                                                                                                                                                                             
1       breakpoint     keep y   0x0000000000400f6c in thread_function01()                                                                                                                                                                                                                           
                                                   at main.cpp:56                                                                                                                                                                                                                                   
(gdb) break thread_function02                                                                                                                                                                                                                                                                       
Breakpoint 2 at 0x400f8f: file main.cpp, line 61.                                                                                                                                                                                                                                                   
(gdb) info breakpoints                                                                                                                                                                                                                                                                              
Num     Type           Disp Enb Address            What                                                                                                                                                                                                                                             
1       breakpoint     keep y   0x0000000000400f6c in thread_function01()                                                                                                                                                                                                                           
                                                   at main.cpp:56                                                                                                                                                                                                                                   
2       breakpoint     keep y   0x0000000000400f8f in thread_function02()                                                                                                                                                                                                                           
                                                   at main.cpp:61                                                                                                                                                                                                                                   
(gdb) delete 2                                                                                                                                                                                                                                                                                      
(gdb) info breakpoints                                                                                                                                                                                                                                                                              
Num     Type           Disp Enb Address            What                                                                                                                                                                                                                                             
1       breakpoint     keep y   0x0000000000400f6c in thread_function01()                                                                                                                                                                                                                           
                                                   at main.cpp:56                                                                                                                                                                                                                                   
(gdb) r                                                                                                                                                                                                                                                                                             
Starting program: /home/a.out                                                                                                                                                                                                                                                                       
[Thread debugging using libthread_db enabled]                                                                                                                                                                                                                                                       
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".                                                                                                                                                                                                                          
[New Thread 0x7ffff6fc5700 (LWP 24316)]                                                                                                                                                                                                                                                             
[Switching to Thread 0x7ffff6fc5700 (LWP 24316)]                                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                                                    
Breakpoint 1, thread_function01 () at main.cpp:56                                                                                                                                                                                                                                                   
56          cout << "Thread function 1 is called." << endl;                                                                                                                                                                                                                                         
(gdb) info threads                                                                                                                                                                                                                                                                                  
[New Thread 0x7ffff67c4700 (LWP 24317)]                                                                                                                                                                                                                                                             
  Id   Target Id         Frame                                                                                                                                                                                                                                                                      
  3    Thread 0x7ffff67c4700 (LWP 24317) "a.out" clone ()                                                                                                                                                                                                                                           
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:81                                                                                                                                                                                                                                                 
* 2    Thread 0x7ffff6fc5700 (LWP 24316) "a.out" thread_function01 ()                                                                                                                                                                                                                               
    at main.cpp:56                                                                                                                                                                                                                                                                                  
  1    Thread 0x7ffff7fe8780 (LWP 24312) "a.out" clone ()                                                                                                                                                                                                                                           
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:81                                                                                                                                                                                                                                                 
(gdb) thread 3                                                                                                                                                                                                                                                                                      
[Switching to thread 3 (Thread 0x7ffff67c4700 (LWP 24317))]                                                                                                                                                                                                                                         
#0  clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:81                                                                                                                                                                                                                                        
81      ../sysdeps/unix/sysv/linux/x86_64/clone.S: No such file or directory.                                                                                                                                                                                                                       
(gdb) bt                                                                                                                                                                                                                                                                                            
#0  clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:81                                                                                                                                                                                                                                        
#1  0x00007ffff7bc40c0 in ?? () at pthread_create.c:174                                                                                                                                                                                                                                             
   from /lib/x86_64-linux-gnu/libpthread.so.0                                                                                                                                                                                                                                                       
#2  0x00007ffff67c4700 in ?? ()                                                                                                                                                                                                                                                                     
#3  0x0000000000000000 in ?? ()                                                                                                                                                                                                                                                                     
(gdb) threads apply all bt                                                                                                                                                                                                                                                                          
Undefined command: "threads".  Try "help".                                                                                                                                                                                                                                                          
(gdb) thread apply all bt                                                                                                                                                                                                                                                                           
                                                                                                                                                                                                                                                                                                    
Thread 3 (Thread 0x7ffff67c4700 (LWP 24317)):                                                                                                                                                                                                                                                       
#0  clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:81                                                                                                                                                                                                                                        
#1  0x00007ffff7bc40c0 in ?? () at pthread_create.c:174                                                                                                                                                                                                                                             
   from /lib/x86_64-linux-gnu/libpthread.so.0                                                                                                                                                                                                                                                       
#2  0x00007ffff67c4700 in ?? ()                                                                                                                                                                                                                                                                     
#3  0x0000000000000000 in ?? ()                                                                                                                                                                                                                                                                     
                                                                                                                                                                                                                                                                                                    
Thread 2 (Thread 0x7ffff6fc5700 (LWP 24316)):                                                                                                                                                                                                                                                       
#0  thread_function01 () at main.cpp:56                                                                                                                                                                                                                                                             
#1  0x0000000000402423 in std::_Bind_simple<void (*())()>::_M_invoke<>(std::_Index_tuple<>) (this=0x616c48) at /usr/include/c++/5/functional:                                                                                                                                                       
#2  0x000000000040238f in std::_Bind_simple<void (*())()>::operator()() (                                                                                                                                                                                                                           
    this=0x616c48) at /usr/include/c++/5/functional:1520                                                                                                                                                                                                                                            
#3  0x000000000040232e in std::thread::_Impl<std::_Bind_simple<void (*())()> >::_M_run() (this=0x616c30) at /usr/include/c++/5/thread:115                                                                                                                                                           
#4  0x00007ffff793a5b0 in ?? () from /usr/lib/x86_64-linux-gnu/libstdc++.so.6                                                                                                                                                                                                                       
#5  0x00007ffff7bc4182 in start_thread (arg=0x7ffff6fc5700)                                                                                                                                                                                                                                         
    at pthread_create.c:312                                                                                                                                                                                                                                                                         
#6  0x00007ffff73c730d in clone ()                                                                                                                                                                                                                                                                  
    at ../sysdeps/unix/sysv/linux/x86_64/clone.S:111                                                                                                                                                                                                                                                
                                                                                                                                                                                                                                                                                                    
Thread 1 (Thread 0x7ffff7fe8780 (LWP 24312)):                                                                                                                                                                                                                                                       
#0  clone () at ../sysdeps/unix/sysv/linux/x86_64/clone.S:81                                                                                                                                                                                                                                        
#1  0x00007ffff7bc319a in do_clone (pd=pd@entry=0x7ffff67c4700,                                                                                                                                                                                                                                     
    attr=attr@entry=0x7fffffffea10, stackaddr=<optimized out>,                                                                                                                                                                                                                                      
    stopped=stopped@entry=1, fct=0x7ffff7bc40c0 <start_thread>,                                                                                                                                                                                                                                     
    clone_flags=4001536) at ../nptl/sysdeps/pthread/createthread.c:75                                                                                                                                                                                                                               
#2  0x00007ffff7bc4a60 in create_thread (stackaddr=<optimized out>,                                                                                                                                                                                                                                 
---Type <return> to continue, or q <return> to quit---q                                                                                                                                                                                                                                             
attr=0x7ffffQuit                                                                                                                                                                                                                                                                                    
(gdb)                                                                                                                                                                                                                                                                                               
                                                                                                                                                                                                                                                                                                    
                                 

*/


