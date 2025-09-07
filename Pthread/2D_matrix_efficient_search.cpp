#include<bits/stdc++.h>
using namespace std;
int arr[4][4] ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
void* cal_add(void* a)
{
    auto *q = (pair<int,int>*)a;
    int idx = q->first;
    int s = q->second;
    for(int i=0;i<4;i++)
    {
        if(s==arr[idx][i])
        {
            auto *p = new pair<int,int>(idx,i);
            return (void*)p;
        }
    }
    return nullptr;
}
int main()
{
    pthread_t th[4];
    for(int i=0;i<4;i++)
    {
        auto *s = new pair<int,int>(i,12);
        pthread_create(&th[i],nullptr,cal_add,(void*)s);
    }
    for(int i=0;i<4;i++)
    {
        void* ret;
        pthread_join(th[i],&ret);
        auto *p = (pair<int,int>*)ret;
        if(p!=nullptr)
        {
             cout<<p->first<<" "<<p->second;
             break;
        }
    }

}
