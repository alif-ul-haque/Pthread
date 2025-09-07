#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter the number of process : ";
    int n;
    cin>>n;
    vector<int>at(n),bt(n),ct(n),tat(n),wt(n),completed(n),remaining_bt(n);
    for(int i=0;i<n;i++)
    {
         cout<<"Enter the Arrival time and Burst time of P"<<i+1<<": ";
         cin>>at[i]>>bt[i];
         remaining_bt[i] = bt[i];
    }
    int temp = n;
    int cur = 0;
    while(temp!=0)
    {
        int mn = 9999;
        int idx = -1;
        for(int i=0;i<n;i++)
        {
            if(cur>=at[i] && remaining_bt[i]<mn && remaining_bt[i]>0 && completed[i]!=1)
            {
                  mn = remaining_bt[i];
                  idx = i;
            }
        }
        if(idx!=-1)
        remaining_bt[idx]--;
        cur++;
        if(idx!=-1 && remaining_bt[idx]==0)
        {
           ct[idx] = cur;
           tat[idx] = ct[idx]-at[idx];
           wt[idx] = tat[idx]-bt[idx];
           completed[idx] = 1;
           temp--;
        }
    }
    
    double avg_tat = 0;
    double avg_wt = 0;
    cout<<"PR\tAT\tBT\tCT\tTAT\tWT"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
         avg_tat+=tat[i];
         avg_wt+=wt[i];
    }
    avg_tat/=n;
    avg_wt/=n;
    cout<<"Average Turn Around Time : "<<avg_tat<<"s"<<endl;
    cout<<"Average Waiting Time : "<<avg_wt<<"s"<<endl;
}