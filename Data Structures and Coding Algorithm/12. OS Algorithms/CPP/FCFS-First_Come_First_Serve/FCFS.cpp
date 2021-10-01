#include<bits/stdc++.h>

using namespace std;

struct process{
    string name;
    int pid;
    int arrival_time;
    int burst_time;
    int start_time = -1;
    int completion_time = -1;
    int turn_around_time = -1;
    int response_time = -1;
    int waiting_time = -1;

    process(string name, int pid, int arrival_time, int burst_time)
    {
        this->name = name;
        this->pid = pid;
        this->arrival_time = arrival_time;
        this->burst_time = burst_time;
    }
};

bool FCFS_comparator(process &p1, process &p2)
{
    if(p1.arrival_time == p2.arrival_time)
        return p1.pid < p2.pid;
    return p1.arrival_time < p2.arrival_time;
}


void FCFS_scheduling(vector<process> &P)
{
    int n = P.size();
    // first process stars instantly
    P[0].waiting_time = 0;
    P[0].start_time = P[0].arrival_time + P[0].waiting_time;
    P[0].completion_time = P[0].start_time + P[0].burst_time;

    int cur_time = P[0].completion_time;
    for(int i=1;i<n;i++)
    {
        int wt = max(0, cur_time - P[i].arrival_time);
        P[i].waiting_time = wt;
        P[i].start_time = P[i].arrival_time + P[i].waiting_time;
        P[i].completion_time = P[i].start_time + P[i].burst_time;
        cur_time = P[i].completion_time;
    }
    
    for(int i=0;i<n;i++)
    {
        P[i].response_time = P[i].start_time - P[i].arrival_time;
        P[i].turn_around_time = P[i].completion_time - P[i].arrival_time;
    }

    float TAT = 0, WT = 0;
    cout<<"========== FCFS Scheduling ==========\n\n";
    cout<<"PID\tProcess\tAT\tST\tBT\tCT\tRT\tTAT\tWT\n";
    for(auto it :  P)
    {
        cout<<it.pid<<"\t"<<it.name<<"\t\t"<<it.arrival_time<<"\t";
        cout<<it.start_time<<"\t"<<it.burst_time<<"\t"<<it.completion_time<<"\t"<<it.response_time<<"\t";
        cout<<it.turn_around_time<<"\t"<<it.waiting_time<<"\t\t"<<"\n";

        WT += it.waiting_time;
        TAT += it.turn_around_time;
    }

    printf("\n====================================\n");
    printf("Avg. Waiting Time : %2f \n",WT/n);
    printf("Avg. Turn Around Time Time :  %2f \n",TAT/n);
    printf("\n\n**\nAT = Arrival Time\nST = Start Time\nCT = Completion Time\nRT = Response  Time\n");
    printf("TAT = Turn Around Time\nWT = Waiting Time\nBT = Burst Time\n");

}

int main()
{
    vector<process> P;
    ifstream fin;
    fin.open("FCFS_Input.txt");
    int temp_pid = 1;
    string data;
    while( getline(fin,data) )
    {
        stringstream str(data);
        string name;
        int arrival_time;
        int burst_time;
        str>>name;
        str>>arrival_time;
        str>>burst_time;

        process cur(name,temp_pid,arrival_time,burst_time);
        P.push_back(cur);

        temp_pid++;
    }

    sort(P.begin(), P.end(), FCFS_comparator);

    FCFS_scheduling(P);
}

