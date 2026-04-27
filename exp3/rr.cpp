#include<iostream>
using namespace std;

int main(){
	int n,tq;//time quantum
	cout<<"Enter number of processes : ";
	cin>>n;
	
	int at[n],bt[n],rt[n],ct[n],tat[n],wt[n];
	
	for(int i=i; i<n; i++){
		cout<<"Enter Arrival Time and Burst Time for P"<<i+1<<":";
		cin>>at[i]>>bt[i];
		
		rt[i]=bt[i];
	}
	
	cout<<"Enter Time Quantum : ";
	cin>>tq;
	
	int time=0;
	int completed=0;
	
	cout<<"\nGantt Chart:\n";
	cout<<time;
	
	while(completed<n){
		bool executed = false;
		
		for(int i=0; i<n; i++){
			executed = true;
			
			cout<<"  | P"<<i+1;
			
			if(rt[i]>tq){
				time+=tq;
				rt[i]-=tq;
			}
			else{
				time+=rt[i];
				rt[i]=0;
				
				completed++;
				ct[i]=time;
				tat[i]=ct[i]-at[i];
				wt[i]=tat[i]-bt[i];
			}
			
			cout<<" | "<<time;
		}
		
		if(executed==false){
		time++;
		}
	}

	cout<<"\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
		
	for(int i=0; i<n; i++){
		cout<<"P"<<i+1<<"\t";
		cout<<at[i]<<"\t";
		cout<<bt[i]<<"\t";
		cout<<ct[i]<<"\t";
		cout<<tat[i]<<"\t";
		cout<<wt[i]<<"\n";
	}
	return 0;
	
	
}