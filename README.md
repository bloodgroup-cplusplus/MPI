# MPI
Refer the website for installation:
  https://ireneli.eu/2016/02/15/installation/
  
  sudo apt-get install mpic++ // even this installed for ubuntu
 Parallel machine is computer system having more than one processor like cluster of computers etc.
 Program a parallel machines using message passing idea and not the idea of shared memory
 
 Need of Message Passing
  1) Mechanism to create processes to execute on different processors
  2) Mechansim to send/recieve messages
  
 Must Specify the identity of the communicating process
 
 Example
 P1:send(&x, P2)  P2: receive(&y,P1)
 explicit sending from sending and receiving on different os on different operating systems.
 Message Passing libraries
 
 PVM(1980s)
 MPI(1990s){Message Passing Interface}(MPI)
 MPI has the library functions for message passing programmer for computers
 
 Standard API
 HIdes softwawre/hardware details
 Portable, flexible
 It is implemented as a library
 
 Key MPI functions and Constants
 MPI_Init(int *argc, char **argv) 
 MPI_FINALIZE(void)
 MPI_Comm_rank(MPI_COMM comm, int *rank)
 MPI_Comm_size(MPI_COMM comm, int* size)
 MPI_Send(void *buf, int count, MPI_Datatype datatype,int dest, int tag, MPI_Comm comm)
 MPI_Recv(void *buf, int count, MPI_Datatype datatype,int source, int tag, MPI_Comm comm, MPI_Status *status)
 MPI_CHAR,MPI_INT,MPI_LONG,MPI_BYTE,MPI_ANY_SOURCE,MPI_ANY_TAG
 
 
MAKING MPI PROGRAMS
mpi has to be cmopiled before executed on a parallel computer
*)Executable must be built by compiling program and linking with MPI library
*)Header files( mpi.h) provide definitions and declarations.
*) MPI is commonly used in SPMD mode (SIMD and MIMD) single program multiple data is the simd model 
*) a single program is written and an executable file is run on each of the nodes of parallel computer
*) It is similar to writing on concurrent programming
*) one would write a c program and program could run multiple processes.
*) write a single program which could run as many processes=concurrency.
*)popular modes of writing mpi program SPMD mode
*) advantages:1)one executable file
              2) multiple instance of it executed in parallel
              
*) Implementations provide a command to initialte execution of MPI process(mpirun) doing this would initialtion of 10000 processers to run the executable.
*) we can run on the selected number of computers options:number of processes, which processors they are yto ru on.(these are the two additional parameters).
*) mpi program on network of computers having it's own ip address in the paralle computers.
*) we could run mpi as n processes. 

MPI Communicators
*)Defines communication deomain of a communication operation:set of processes that are allowed to communicate among themselves.
*) suppose we write parallel program with 4 processes in which p1 p2 have to communicate with each other and p3 p4 has to communicate and towards the end p4 and p1
*) to achieve this we can define the communicators for each processes. communicator is the construct wihin the mpi
*) Initially all processes are int the communicator MPI_COMM_WORLD
*) default is the mpi program is run as single communicators
*) p2 p1 p3 p4 would all be the part of MPI_COMM_WORLD
*) within a communicator the processes have unique ranks associated with communicator, numbered from 0 to n-1
*) there is need to identify to track the number of processes 
*) notion of rank abstracts process id beyond process communicator
*) differnet process
