
#include<future>
#include<iostream>
//we first write the code using the mutex only
//std::mutex mu;
//std::conditional_variable cond;
//now our code becomes more complicated as we need to call the mutex 
//we also need to call our conditional variable
//and we also have two global variables which need to be taken care of
//our structre code becomes messy
//the standard library provides easier way 
//instead of using thread object 
//we use std::async(factorial,4);
//thread is a class
//async is a function
//async returns the future variable
//future is a channel where i can get the result from child therad
//std::future<int> fu=std::async(factorail,4)
//x=fu.get();
//now we can get rid of our global variables 
//fu.get function will wait until the child thread finishes and then return the return value from the child thread
//future class represents an object where you can get something in the future
//future object can call the get only if we 
//async function may or may not create another thread
//if we call the async function using the function call
//std::future<int> fu=std::async(std::launch::deferred, factorial,4);
//the async function will not create the thread
//it will actually differ the exectuion of the function 
//when the get function is called the factorail function is executed in the same thread
//we also can call the async function using the code
//std::future<int> fu=std::async(std::launch::async | std::launch::deferred, factorial, 4);
//and that is the default value for the parameters
// we can also use future fto pass value from parent ot child and vice versa not at time at creation but at futrure
// that required something called a promise and a future
// std::promise<int> p;
// std::future<int> f=p.get_future();
// std::future<int> fu=std::async(std::launch::async,factorial, std::ref(f));
// x=fu.get();
// by doing the above line we are telling the child thread i will send you a value but i don't have the value yet
// so i willl send it over the future and that is my promise
// sometime later 
// std::this_thread::sleep_for(chrono::milliseconds(20));
// p.set_value(4)
// x=fu.get();
// std::cout<<"Get from child"<<x<<std::endl;
// promise and future are template classes with type of integer
// future is also template class of integer
// if we break the promise
// i.e., we comment the line p.set_value(4);
// we get the exception: std::future_errc::broken_promise
// p.set_exception(std::make_exception_ptr(std::runtime_error("To err is human"))
// and now when the child thread calls the get function it will get an exception
// promise and future cannot be copied they can only be moved
// std::promise<int> p2=std::move(p);
// std::future<int> f=p.get_future();
// eacch future can call the future only once so if we have 10 threads
// they'll call the get function 10 times which is not a good idea
// i create 10 promises and future
// each thread will get it is future and thread but that idea is clumsy
// the std:: library provides shared_future<int> sf=f.share();
// and unlike a regular future the shared future is copied
// so we can pass the shared_future by value 
//  so shared value is vary helpful for broadcast kind of communicattion model

int factorial(std::shared_future<int> f)
{
        int res=1;
        int N=f.get();
        for(int i=N; i>1;i--)
        {
                res*=i;
        }

        std::cout<<"Result is : "<< res<<std::endl;
        return res;
}


int main()
{
        int x;
        std::promise<int> p;
        std::future<int> f=p.get_future();
        std::shared_future<int> sf=f.share();
        std::future<int> fu=std::async(std::launch::async,factorial,sf);
        std::future<int> fu2=std::async(std::launch::async,factorial,sf);
        std::future<int> fu3=std::async(std::launch::async,factorial,sf);
        p.set_value(4);
        return 0;
}

