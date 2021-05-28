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
//  
