//code courtesy Nick from CoffeeBeforeArch
#inlcude<iostream>
#include<mpi.h>


int main(int argc, char * argv[])
{
	// unique rank is assigned to each process in a communicator
	int rank;
	//Total number of ranks
	int size;
	//The machine we are on
	char name[80];
	//Length of the machine name
	int length;
	//Initializes the MPI execution environment
	MPI_Init(&argc,&argv);

	//Get this proces rank(process within a communciator)
	//MPI_COMM_WORLD is the default communicator
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	//Get the total number ranks in this communicator
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	//Gets the name of the processor
	//Implementation specific (may be gethostname,uname, or sysinfo)
	MPI_Get_processor_name(name, &length);
	
	//Pack these values together into a string
	int buffer_len=150;
	char buffer[buffer_len];
	sprintf(buffer,"Hello,MPI: rank: %d Total: %d machine %s",rank,size,name);
	//Synchronize so we can remove interleaved output
	
	if (rank==0)
	{
		printf("%s\n",buffer);
		for(int i=1;i<size;++i)
		{
			MPI_Recv(buffer,buffer_len,MPI_CHAR,i,i,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			//Print our recieved message
			printf("%s\n",buffer);
		}
		
	}
	else
	{
		//If not rank zero, send your message to be printed
		MPI_Send(buffer,buffer_len, MPI_CHAR, 0, rank, MPI_COMM_WORLD);
		
	}
	
	// Then we terminate the MPI execution environment
	MPI_Finalize();

	return 0;
}

	
