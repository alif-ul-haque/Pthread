#include<bits/stdc++.h>
using namespace std;
void* cal_val(void* a)
{
    int* val = (int*)a;
    int *sum = new int();
    for(int i=0;i<1000000000;i++)
    {
        *sum+=*val;
    }
    return (void*)sum;
}
int main()
{
    pthread_t thread1,thread2;
    int val1=1,val2=2;
    void* ret1;
    void* ret2;
    pthread_create(&thread1,nullptr,cal_val,(void*)&val1);
    pthread_create(&thread2,nullptr,cal_val,(void*)&val2);
    pthread_join(thread1,&ret1);
    pthread_join(thread2,&ret2);
    int* sum1 = (int*)ret1;
    int* sum2 = (int*)ret2;
    cout<<*sum1<<" "<<*sum2<<endl;
    return 0;
}
