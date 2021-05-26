//this lesson is compile from the video from the youtuber coffeebeforearch
//in the previous thread program we saw there was a problem of synchronization between the threads run time
// so we see how to run threads using synchronization when they run the critical section
//so mutex lock stands for mutual exclusion
// one thread acquires lock at a time
// a thread will get the lock and it will get it exclusively

#include<iostream>
#include<thread>
#include<mutex>

//mutex for critical section

std::mutex mtx;

//Initial function for each thread

void call_from(int tid)
{
	mtx.lock();
	std::cout<<"Launched by thread"<<tid<<std::endl;
	mtx.unlock();
}

int main()
{
	//create an array of 10 thread objects
	std::thread t[10];
	//launch 10 threads with initial function "call_from(...)"
	for(int i=0;i<10;++i)
	{
		t[i]=std::thread(call_from, i);
	}
	//wait for all threads to complete
	for(int i=0;i<10;++i)
	{
		t[i].join();
	}
	
	return 0;
}
//launch the program using the command g++ progname.cpp -lpthread


	
