#include<bits/stdc++.h>
using namespace std;
int arr[4][4] ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
int arr1[4][4] ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
int ans[4][4]= {0};
void* cal_add(void* a)
{
    int idx = *((int*)a);
    for(int i=0;i<4;i++)
    {
        ans[idx][i] = arr[idx][i]+arr1[idx][i];
    }
}
int main()
{
    pthread_t th[4];
    for(int i=0;i<4;i++)
    {
        int *n = new int();
        *n = i;
        pthread_create(&th[i],nullptr,cal_add,(void*)n);
    }
    for(int i=0;i<4;i++)
    {
        pthread_join(th[i],nullptr);
    }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
