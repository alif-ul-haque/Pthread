#include<bits/stdc++.h>
using namespace std;
int mails = 0;
void *count_mail(void* args)
{
    for(int i=0;i<1000000000;i++)
    {
        mails++;
    }
    return nullptr;
}
int main()
{
    pthread_t thread1,thread2;
    pthread_create(&thread1,nullptr,count_mail,nullptr);
    pthread_create(&thread2,nullptr,count_mail,nullptr);
    pthread_join(thread1,nullptr);
    pthread_join(thread2,nullptr);
    cout<<mails<<endl;
}
