//This program shows off the basics of using MPI with C++
// I learnt how to write this program from the youtube tutorials https://www.youtube.com/watch?v=a0V8KpLu7EY
// Check out his youtube channel for more of MPI

#include<iostream>
#include<mpi.h>

int main( int argc, char *argv[])
{
	//Unique rank is assigned to each process in a communicator
	int rank;
	
	//Total number of ranks;
	int size;
	
	//The machine we are on
	char name[90];
	
	//Length of the machine name
	
	int length;
	
	//Initializes the MPI execution environment
	
	MPI_Init(&argc,&argv);
	
	//Get this process rank(  process within a communicator)
	//MPI_COMM_WORLD is the default communicator
	
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	
	// Get the total number of ranks in this communicator
	MPI_Comm_size(MPI_COMM_WORLD, & size);
	
	//Gets the name of the processor
	//Implementation specific(may be gethostname, uname, or sysinfo)
	MPI_Get_processor_name(name,&length);
	//Print out for each rank
	std::cout<<"Hello, MPI Rank:"<<rank<<"  size  "<<size<<std::endl;
	//Terminate the MPI execution environment
	MPI_Finalize();
	return 0;
}
	//install
	//compile the program using the command mpic++ -o programname programname.cpp
	// ./programname
	//before compiling make sure you have installed mpic++ using the command 
	// sudo apt-get install mpic++ on your bash shell
