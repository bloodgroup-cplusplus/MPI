//both threads are racing for the common resource here it is "cout"
//race condition is not good for our program
// mutex can be used to synchronize acess of common resource
// acess of common resource is synchronized by using the mutex lock and mutex unlock
// suppose the immediate line after the mutex throws an exception.Then what happens is that the thread gets locked forever
// so it is recommended to not to used lock and unlock function directly
// so it is good to use the std::lock_guard<std::mutex> guard(mu); //RAII
// when guard goes out of resource the mutex will always be unlocked with or without exception
//there is another problem with problem i.e., cout is not direcly assecible by just using a single thread
// in order to protect a resource completely, a mutex must be bundled with the resource it is protecting
//never retrun f to the outside world
// i.e. we shouldn't have a function this way
//ofstream & getStream(){return f;}
//this way f is accessed without going through the mutex.
// Never pass f as an argument to user provided function
//say we have a function void processf(void fun(ofstream &)){
	//fun(f);
//}
// once we do that the user defined function fun can do all misinterpretations to the f
// it can close f so that nobody else can write to f anymore
// so the resource f is out of control
// this example deals mainly with prevention of datarace
// the important things to keep in mind is
//Use mutex to synchronize data access
//never leak a handle of data to user functions
//design interface appropriately

#include<iostream>
#include<fstream>
#include<thread>
#include<mutex>

class LogFile
{
	std::mutex m_mutex;
	std::ofstream _f;
	
	public:
		LogFile()
		{
			_f.open("log.txt");//do create a logfile at the location of program
		}
	
		void shared_print(std::string id,int value)
		{
			std::lock_guard<std::mutex> locker(m_mutex);
			_f<<"From"<<id<<":"<<value<<std::endl;
		}
	
};

void function_1(LogFile & log)
{
	for(int i=0;i<=100;++i)
	{
		log.shared_print(string("From t1:"),i);
	}
}


int main()
{
	LogFile log;
	std::thread t1(function_1,std::ref(log));
	return 0;
}
//include flag -lpthread while compiling
