//few keypoints before executing the codes
// using standard thread that is part of c++ 11
// why do we want parallelism?
// cpu isn't getting better in past decade
// problems with making transistor smaller
// we can start exploiting differnt level instructions.
// data level parallelism.differnt data that are independent over each other
// task level parallelism. Completly different processes on completly different thread
//multithreaded applications.ways of keeping the performance going in absence of transistors
// there are some applications which are not parallelizable due to data/ operations dependency
// synchronization overhead. 
//very small tasks. overhead from creating threads cause more overhead than actually solving the problem
// it is important to know which task to parallize and which not to

//This program is a multi-threaded "call from" program in C++
//pthread mpi and open p and also mapreduce
//shoutout to coffeebeforearch for teaching me the concepts
//youtubelink:https://www.youtube.com/watch?v=diEAEFly9ak&list=PLxNPSjHT5qvugVNYwtQwnvSQyvlbzAML3

#include<iostream>
#include<thread>
//Initial function for each thread
void call_from (int tid)
{
	std::cout<<"Launched by thread"<<tid<<std::endl;
}

int main()
{
	//we create an array of 10 thread opjects
	std::thread t[10];

	//we launch 10 threads with inital function "call_from(...)"
	// a thread needs an initial function so we initialize the call_from as that function
	//first parameter is the initial function,the second param is the tid or the index of the thread array
	for(int i=0;i<10;++i)
	{
		t[i]=std::thread(call_from,i);
	}
	
	//Print from main function
	//main also has the thread
	std::cout<<"Launched from main"<<std::endl;
	
	//then we wait for all threads to complete
	//if we do not do so, the main function may also complete before anyone else
	//that ends up killing all other threads which may not have even run yet.
	// so we join for finishing
	for(int i=0;i<10;++i)
	{
		t[i].join();
	}
	
	return 0;
}
//cout is not thread safe
//multiple threads are going to write to cout object at the same time
//every time you run the program you get the different output . It totally depends on how the threads are
//scheduled by the cpu.
//so this makes debugging nightmare so for that we use the mutex.
//concurrency=multiple things executing at the same time however they could or couldn't be running at the same time
//whereas in case of parallelism we are mainly concerned with "RUNNING AT THE SAME TIME"

//use the required flags for compilation i.e.,(g++ progname.cpp -lpthread)

