#include<bits/stdc++.h>
using namespace std;
int mails = 0;
pthread_mutex_t mut;
void *count_mail(void* args)
{
    for(int i=0;i<10000000;i++)
    {
        pthread_mutex_lock(&mut);
        mails++;
        pthread_mutex_unlock(&mut);
    }
    return nullptr;
}
int main()
{
    pthread_t thread[4];
    for(int i=0;i<4;i++)
    {
        pthread_create(&thread[i],nullptr,count_mail,nullptr);
        cout<<"Thread start "<<i<<endl;
    }
    for(int i=0;i<4;i++)
    {
        pthread_join(thread[i],nullptr);
        cout<<"Thread end "<<i<<endl;
    }
    pthread_mutex_destroy(&mut);
    cout<<mails<<endl;
}
