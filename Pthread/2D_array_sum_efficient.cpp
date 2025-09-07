#include<bits/stdc++.h>
using namespace std;
int arr[4][4] ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
void* cal_sum(void* a)
{
    int idx = *((int*)a);
    int* sum = new int();
    *sum = 0;
    for(int i=0;i<4;i++)
    {
        *sum+=arr[idx][i];
    }
    return (void*)sum;
}
int main()
{
    pthread_t th[4];
    for(int i=0;i<4;i++)
    {
        int* n = new int();
        *n = i;
        pthread_create(&th[i],nullptr,cal_sum,(void*)n);
    }
    int sum = 0;
    for(int i=0;i<4;i++)
    {
        void* ret1;
        pthread_join(th[i],&ret1);
        sum+=*((int*)ret1);
    }
    cout<<sum<<endl;

}
