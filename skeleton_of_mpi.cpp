// this program is just a skeleton so it is not in it's proper executable state
// It is only written for understanding purpose
#include<iostream>
int main(int argc, char *argv[])
{
	int myrank;
	MPI_Init(&argc, &agv);
	//how many process are there in the MPI function
	//the value of that myrank will be the value of the process within the MPI_COMM_WPR:LD
	myrank=MPI_Comm_rank(MPI_COMM_WORLD, &myrank); //communicator and the rank
	if(myrank==0)
	{
		// 0 is the master it contains the funcationality of master process
		master();
		MPI_Send(&x,1,MPI_INT, 1, msgtag,MPI_COMM_WORLD);
	}
	else
	{
		// is the functionality of slave process.
		slave();
	}
	
	// if i am running this instance on paralley computer
	//each process has own rank
	//each process is part of own communicator

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	MPI_Finalize();
	return 0;
}
