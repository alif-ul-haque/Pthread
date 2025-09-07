#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>at(n),bt(n),ct(n),tat(n),wt(n),completed(n),prt(n);
    for(int i=0;i<n;i++)
    {
         cin>>at[i]>>bt[i]>>prt[i];
    }
    int temp = n;
    int cur = 0;
    while(temp!=0)
    {
        int mn = 9999;
        int idx = -1;
        for(int i=0;i<n;i++)
        {
            if(cur>=at[i] && completed[i]!=1)
        {
            if(bt[i] < mn) {
                mn = bt[i];
                idx = i;
            }
            else if(bt[i] == mn) {
                if(prt[i] < prt[idx]) idx = i; // priority tie-breaker
                else if(prt[i] == prt[idx] && at[i] < at[idx]) idx = i; // arrival tie-breaker
            }
        }
        }
        
        if(idx==-1)
        {
            cur++;
            continue;
        }
        ct[idx] = cur+bt[idx];
        tat[idx] = ct[idx]-at[idx];
        wt[idx] = tat[idx]-bt[idx];
        cur = ct[idx];
        completed[idx] = 1;
        temp--;
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