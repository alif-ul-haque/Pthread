#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int a;
int b;
pthread_mutex_t mu_a,mu_b;
void* all_1(void* args)
{
    pthread_mutex_lock(&mu_a);
    cout<<"ACC a by p1\n";
    cout<<"Wait for b by p1\n";
    Sleep(5);
    pthread_mutex_lock(&mu_b);
    cout<<"ACC b by p1\n";
}
void* all_2(void* args)
{
    pthread_mutex_lock(&mu_b);
    cout<<"ACC b by p2\n"<<endl;
    cout<<"Wait for a by p2\n"<<endl;
    Sleep(5);
    pthread_mutex_lock(&mu_a);
    cout<<"ACC a by p2\n"<<endl;
}
int main()
{
    pthread_t th1,th2;
    pthread_create(&th1,nullptr,all_1,nullptr);
    pthread_create(&th2,nullptr,all_2,nullptr);
    pthread_join(th1,nullptr);
    pthread_join(th2,nullptr);
    pthread_mutex_destroy(&mu_a);
    pthread_mutex_destroy(&mu_b);
}
