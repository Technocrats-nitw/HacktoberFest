#include<bits/stdc++.h>

using namespace std;

struct process{
    string name;
    int pid;
    int arrival_time;
    int burst_time;
    int priority;   // priority of process
    int remaining_burst_time;
    int start_time = -1;
    int completion_time = -1;
    int turn_around_time = -1;
    int response_time = -1;
    int waiting_time = -1;

    process(string name, int pid, int arrival_time, int burst_time,int priority)
    {
        this->name = name;
        this->pid = pid;
        this->arrival_time = arrival_time;
        this->burst_time = burst_time;
        this->priority = priority;
        this->remaining_burst_time = burst_time;
    }
};

bool Priority_comparator(process &p1, process &p2)
{
    if(p1.arrival_time == p2.arrival_time)
    {
        if(p1.priority == p2.priority)
            return p1.pid < p2.pid;
        return p1.priority < p2.priority;
    }
    return p1.arrival_time < p2.arrival_time;
}

struct Priority_comp {
    constexpr bool operator()(process const& a,process const& b)const noexcept
    {
        if(a.priority == b.priority)
            return a.arrival_time > b.arrival_time;
        return a.priority > b.priority;
    }
};

bool sortPID(process &p1, process &p2)
{
    return p1.pid < p2.pid;
}

void Priority_scheduling(vector<process> &P)
{
    int n = P.size();
    priority_queue<process, vector<process>, Priority_comp>pq;
    vector<process> table;
    vector<string> gantt;
    int cur_time = P[0].arrival_time;
    pq.push(P[0]);
    int it=1;
    for(int i=0;i<cur_time;i++)
        gantt.push_back("idle");
    while(!pq.empty())
    {
        process cur_process = pq.top();
        pq.pop();
        if( cur_process.start_time == -1 )
            cur_process.start_time = cur_time; 
        cur_process.remaining_burst_time--;

        cur_time++;
        if( cur_process.remaining_burst_time != 0)
            pq.push(cur_process);
        else{
            cur_process.completion_time = cur_time;
            cur_process.response_time = cur_process.start_time - cur_process.arrival_time;
            cur_process.turn_around_time = cur_process.completion_time - cur_process.arrival_time;
            cur_process.waiting_time = cur_process.turn_around_time - cur_process.burst_time;
            table.push_back(cur_process);
        }
        gantt.push_back(cur_process.name);
        while(it < n && P[it].arrival_time <= cur_time)
        {
            pq.push(P[it]);
            it++;
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
    cout<<"========== Priority Scheduling - II ==========\n\n";
    cout<<"GANTT CHART\nTime Stamp  | Process\n";
    for(int i=0;i<gantt.size();)
    {
        string cur_pname = gantt[i];
        cout<<i<<" - ";
        while(i<gantt.size() && gantt[i]==cur_pname)
            i++;
        cout<<i<<"\t    | "<<cur_pname<<"\n";
    }
    cout<<"\nPID\tProcess\tAT\tST\tBT\tCT\tRT\tTAT\tWT\n";
    sort(table.begin(), table.end(),sortPID);
    for(auto it :  table)
    {
        cout<<it.pid<<"\t"<<it.name<<"\t\t"<<it.arrival_time<<"\t";
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
    fin.open("Priority_Input.txt");
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
        str>>priority;
        process cur(name,temp_pid,arrival_time,burst_time,priority);
        P.push_back(cur);

        temp_pid++;
    }

    sort(P.begin(), P.end(), Priority_comparator);
    Priority_scheduling(P);
}

