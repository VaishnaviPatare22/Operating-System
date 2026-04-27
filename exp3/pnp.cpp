#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter number of processes : ";
	cin>>n;
	
	int at[n];
	int bt[n];
	int pr[n];
	int rt[n];
	int ct[n];
	int tat[n];
	int wt[n];
	
	for(int i=0; i<n; i++){
		cout<<"Enter Arrival time, Burst time and Priority for P"<<i+1<<":";
		cin>>at[i]>>bt[i]>>pr[i];
		
		rt[i]=bt[i];
	}
	
	int time=0;
	int completed=0;
	
	while(completed<n){
		int index=-1;
		int highest_priority=9999;
		
		for(int i=0; i<n; i++){
			if(at[i]<=time && rt[i]>0){
				if(pr[i]<highest_priority){
					highest_priority = pr[i];
					index = i;
				}
			}
		}
		if(index!=-1){
			rt[index]--;
			time++;
			
			if(rt[index]==0){
				completed++;
				ct[index]=time;
				tat[index]=ct[index]-at[index];
				wt[index]=tat[index]-bt[index];
			}
		}
		else{
			time++;
		}
	
	}
	cout<<"\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
	
	for(int i=0; i<n; i++){
		cout<<"P"<<i+1<<"\t";
		cout<<at[i]<<"\t";
		cout<<bt[i]<<"\t";
		cout<<pr[i]<<"\t";
		cout<<ct[i]<<"\t";
		cout<<tat[i]<<"\t";
		cout<<wt[i]<<"\n";
	}
	
	return 0;
}