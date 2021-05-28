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
//
