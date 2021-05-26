// refer youtube channel coffeebeforearch for more
// targeting the window platform for thread
//this code is exclusive for windows only.
#include<Windows.h>
//for window specific functions
#include<strsafe.h>
 




















int main()
{
	//create an array of handles
	HANDLE array_of_handles[NUM_THREADS]={ 0 };
	//create an array of structs as arguments
	
	Package packages[NUM_THREADS];
	
	//Create threads
	for(int i=0;i< NUM_THREADS;++i)
	{
		packages[i].tid=i;
		packages[i].number=i*i;
		/*
			Arguements:
			0)Security Attributes(default)
			1)Stack size(default)
			2)Function
			3)Argument(converted to void pointer)
			4)Creation flag(0=run immediately after creation)
			5)Pointer to variable to receive thread id
			
		*/
		array_of_handles[i]=CreateThread(NULL,0,boring_thread_function,&packages[i],0,NULL);
		//Wait for a number of thread to be in a signaled state
		//Infinite states to wait forever
	}
		
		WaitForMultipleObjects(NUM_THREADS,array_of_handles,true,INFINITE);
		
		//clean up by closing the object handles
	
	for(int i=0;i<NUM_THREADS;++i)
	{
		
		WriteConsole(hscreen,message_buffer,cchStringSize,&dwChars,NULL);
		
		//Just put the thread to sleep for a little
		Sleep(1000);
	}
	
//WINAPI is a macro that speicifies the use of Windows calling
//convention
//LPVOID is a void pionter
	
DWORD WINAPI boring_thread
		
		
		
		
		
		
		
