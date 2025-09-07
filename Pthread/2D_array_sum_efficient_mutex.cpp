#include<bits/stdc++.h>
using namespace std;
int sum = 0;
int arr[4][4] ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
pthread_mutex_t mut;
void* cal_sum(void* a)
{
    int idx = *((int*)a);
    for(int i=0;i<4;i++)
    {
        pthread_mutex_lock(&mut);
        sum+=arr[idx][i];
        pthread_mutex_unlock(&mut);
    }
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
    for(int i=0;i<4;i++)
    {
        pthread_join(th[i],nullptr);
    }
    cout<<sum<<endl;

}
