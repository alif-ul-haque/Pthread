#include<stdio.h>
#include<pthread.h>
//void cal_val(int a)
//{
//    int sum = 0;
//    for(int i=0;i<1000000000;i++)
//    {
//        sum+=a;
//    }
//    printf("%d\n",sum);
//}
void* cal_val(void* a)
{
    int sum = 0;
    int* add = (int*)a;
    for(int i=0;i<1000000000;i++)
    {
        sum+=*add;
    }
    printf("%d\n",sum);
    return NULL;
}
int main()
{
    pthread_t thread1,thread2;
    int val1 = 1;
    int val2 = 2;
    pthread_create(&thread1,NULL,cal_val,(void*)&val1);
    pthread_create(&thread2,NULL,cal_val,(void*)&val2);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    return 0;
}
