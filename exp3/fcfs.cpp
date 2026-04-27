#include<iostream>
#include<algorithm>
using namespace std;

struct Process{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
};

int main(){
	int n;
	
	cout<<"Enter number of processes : ";
	cin>>n;
	
	Process p[n];
	
	for(int i=0; i<n; i++){
		p[i].pid=i+1;
		cout<<"Enter Arrival time and Burst Time for P "<<i+1<<" : ";
		cin>>p[i].at>>p[i].bt;
	}
	
	sort(p,p+n,[](Process a, Process b){
		return a.at<b.at;
	});
	
	int time=0;
	
	for(int i=0; i<n; i++){
		if(time<p[i].at){
			time=p[i].at;
		}
		time=time+p[i].bt;
		p[i].ct=time;
		
		p[i].tat=p[i].ct-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
	}
	
	cout<<"\nPID\tAT\tBT\tCT\tTAT\tWT\n";
	
	for(int i=0; i<n; i++){
		cout<<"P"<<p[i].pid<<"\t";
		cout<<p[i].at<<"\t";
		cout<<p[i].bt<<"\t";
		cout<<p[i].ct<<"\t";
		cout<<p[i].tat<<"\t";
		cout<<p[i].wt<<"\n";
	}
	
	return 0;
}