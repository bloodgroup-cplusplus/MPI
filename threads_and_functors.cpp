//multithreading
//t1.join(); main thread waits for t1 to finish
//main and t1 thread
//t1.deatch(); t1 will freely run on its own -- it becomes a daemon process
// c++ resource library recailm the resources of deamon
//if there are two threads running simultaneously it is not deterministic about which thread
//runs faster unless there is synchronization mechanism
// thread is lightweight than process
// main thread will always finish faster than the child thread
// if two threads are sharing certian resource then the thread that owns the resoucre should
//live as long as the other threads accessing the resource
// we can join and detached a thread only once
//t1.join() cannot follow t1.detach();
//what if the thread is destroyed before it is joined or detached
//then your program will terminate
// so decide if you want to join the thread or detach a thread
//  here we use an altreanative method of using thread by using RAII
// we create a wrapper class it will automatically join the thread
// thread object can be joined by any callable object like a functor or a lambda function
// here we accomplish that by creating a functor
#include<iostream>
#include<thread>

class Fctor
{
    public:
        void operator ()()
        {
            for(int i=0;i<=100;++i)
            {
                std::cout<<"from functor and thread number"<<i<<std::endl;
            }
        }
};

int main()
{
    Fctor fct;
    std::thread t1(fct);
    t1.join();
    // or by using the functor name itself and pass it as a parameter
    std::thread t2((Fctor()));//t2 starts running
    t2.join();
    // run a simple main thread as well inside a try catch block
    try
    {
        for(int i=0;i<100;++i)
        {
            std::cout<<"from main"<<i<<std::endl;
        }
    }
    catch(...)
    {
            t1.join();
            throw;
    }
    
    return 0;
}
