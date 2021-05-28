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
// A parameter to a thread is always passed by value,even if we try to pass reference to it
//However in order to pass by refrence itself we need to explicitly mention it with a std::ref before passing it as a parameter
// we can also modify the operator function inside the functor to accept parameters
// the syntax than changes to 
// return_type operator()(datatype variable name)
//{
  //  .......
    //}
//threads cannot be copied
//i.e., std::thread t2=t1 is an invalid operation
// so to transfer  ownership we can use the move function
// std::thread t2=std::move(t1);
// get the identification number of each thread we can use the command
// std::cout<<std::this_thread::get_id()<<std::endl;(this is for parent id thread)
//std::cout<<t1.get_id()<<std::endl;(for child thread)
//inside the main we can call this by using std::thread t1((Fctor()),the parameter to pass);
// here we accomplish that by creating a functor
//oversubscription=bad (more thread running than required).too much context switching which degrads 
//the performance
// so the thread module provides a hardware concurrency
// std::thread::hardware_concurrency();
//this will give an indiciation of how many thread can be truly running 


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
