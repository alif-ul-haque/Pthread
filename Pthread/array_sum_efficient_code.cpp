#include<bits/stdc++.h>
using namespace std;
int arr[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

void* cal_sum(void* a)
{
    int idx = *((int*)a);
    int *sum = new int();
    *sum = 0;
    for(int i=idx;i<idx+5;i++)
    {
        *sum+=arr[i];
        cout<<"Summing index : "<<i<<endl;
    }
    return (void*)sum;
}
int main()
{
     pthread_t th[3];
     for(int i=0;i<3;i++)
     {
         int* n = new int();
         *n = i*5;
         pthread_create(&th[i],nullptr,cal_sum,(void*)n);
     }
     void* val;
     int sum = 0;
     for(int i=0;i<3;i++)
     {

         pthread_join(th[i],&val);
         int* val1 = (int*)val;
         sum+=*val1;
     }
     cout<<sum<<endl;
}
