#include<iostream>
#include<omp.h>


int main()
{
        #pragma omp parallel for
        for(int i=0;i<4*omp_get_num_threads();++i)
        {
                std::cout<<"Thread  "<< i <<"   "<<  omp_get_thread_num()<<std::endl;
        }

        return 0;
}

