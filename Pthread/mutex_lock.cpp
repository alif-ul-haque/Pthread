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
    pthread_t thread1,thread2,thread3,thread4;
    pthread_create(&thread1,nullptr,count_mail,nullptr);
    pthread_create(&thread2,nullptr,count_mail,nullptr);
    pthread_create(&thread3,nullptr,count_mail,nullptr);
    pthread_create(&thread4,nullptr,count_mail,nullptr);
    pthread_join(thread1,nullptr);
    pthread_join(thread2,nullptr);
    pthread_join(thread3,nullptr);
    pthread_join(thread4,nullptr);
    pthread_mutex_destroy(&mut);
    cout<<mails<<endl;
}
