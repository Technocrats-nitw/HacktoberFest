#include<bits/stdc++.h>
#define QUANT 2
using namespace std;

struct process{
    string name;
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_burst_time;
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
        this->remaining_burst_time = burst_time;
    }
};

bool RR_comparator(process &p1, process &p2)
{
    if(p1.arrival_time == p2.arrival_time)
    {
        return p1.pid < p2.pid;
    }
    return p1.arrival_time < p2.arrival_time;
}

bool sortPID(process &p1, process &p2)
{
    return p1.pid < p2.pid;
}

void RR_scheduling(vector<process> &P)
{
    int n = P.size();
    queue<process>pq;
    vector<process> table;
    vector<string> gantt;
    int cur_time = P[0].arrival_time;
    pq.push(P[0]);
    int it=1;
    for(int i=0;i<cur_time;i++)
        gantt.push_back("idle");
    while(!pq.empty())
    {
        process cur_process = pq.front();
        pq.pop();
        if( cur_process.start_time == -1 )
            cur_process.start_time = cur_time; 

        if( cur_process.remaining_burst_time > QUANT )
        {
            cur_process.remaining_burst_time -= QUANT;
            cur_time += QUANT;
            for(int i=0;i<QUANT;i++)
                gantt.push_back(cur_process.name);
        }
        else{
            cur_time += QUANT - cur_process.response_time;
            for(int i=0;i<QUANT - cur_process.response_time;i++)
                gantt.push_back(cur_process.name);
            cur_process.remaining_burst_time = 0;
        }

        while(it < n && P[it].arrival_time <= cur_time)
        {
            pq.push(P[it]);
            it++;
        }
        
        if( cur_process.remaining_burst_time != 0)
            pq.push(cur_process);
        else{
            cur_process.completion_time = cur_time;
            cur_process.response_time = cur_process.start_time - cur_process.arrival_time;
            cur_process.turn_around_time = cur_process.completion_time - cur_process.arrival_time;
            cur_process.waiting_time = cur_process.turn_around_time - cur_process.burst_time;
            table.push_back(cur_process);
        }
        
        
        if(pq.empty() && it < n)
        {
            pq.push(P[it]);
            for(int i=0;i<P[it].arrival_time - cur_time; i++)
                gantt.push_back("idle");
            cur_time = P[it].arrival_time;
            it++;
        }
    }
    
    float TAT = 0, WT = 0;
    cout<<"========== RR Scheduling ==========\n\n";

    cout<<"GANTT CHART - [Start Time] Process [End Time]\n";
    for(int i=0;i<gantt.size();)
    {
        string cur_pname = gantt[i];
        cout<<" ["<<i<<"] ";
        while(i<gantt.size() && gantt[i]==cur_pname)
            i++;
        cout<<cur_pname;
    }

    cout<<" ["<<gantt.size()<<"] ";
    cout<<"\n\n\nPID\tProcess\tAT\tST\tBT\tCT\tRT\tTAT\tWT\n";
    sort(table.begin(), table.end(),sortPID);
    for(auto it :  table)
    {
        cout<<it.pid<<"\t"<<it.name<<"\t"<<it.arrival_time<<"\t";
        cout<<it.start_time<<"\t"<<it.burst_time<<"\t"<<it.completion_time<<"\t"<<it.response_time<<"\t";
        cout<<it.turn_around_time<<"\t"<<it.waiting_time<<"\t\t"<<"\n";

        WT += it.waiting_time;
        TAT += it.turn_around_time;
    }

    cout<<"\n====================================\n";
    cout<<"Avg. Waiting Time : "<<WT/n<<"\n";
    cout<<"Avg. Turn Around Time Time : "<<TAT/n<<"\n";
    cout<<"\n\n**\n";
    cout<<"AT = Arrival Time\nST = Start Time\nCT = Completion Time\nRT = Response  Time\n";
    cout<<"TAT = Turn Around Time\nWT = Waiting Time\nBT = Burst Time\n\n";

    
}

int main()
{
    vector<process> P;
    ifstream fin;
    fin.open("RR_Input.txt");
    int temp_pid = 1;
    string data;
    while( getline(fin,data) )
    {
        stringstream str(data);
        string name;
        int arrival_time;
        int burst_time;
        int priority;
        str>>name;
        str>>arrival_time;
        str>>burst_time;
        process cur(name,temp_pid,arrival_time,burst_time);
        P.push_back(cur);

        temp_pid++;
    }

    sort(P.begin(), P.end(), RR_comparator);
    RR_scheduling(P);
}

