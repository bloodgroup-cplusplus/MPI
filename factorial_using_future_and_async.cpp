#include<iostream>
#include<future>
int factorial(int N)
{
	int res=1;
	for(int i=N;i>1;--i)
	{
		res*=i;
	}
	
	std::cout<<"Result is "<<res<<std::endl;
	return res;
}


int main()
{
	int x;
	std::future<int> fu=std::async(factorial,4);
	x=fu.get();
	std::cout<<x<<std::endl;
	return 0;
}
