#include<bits/stdc++.h>
using namespace std;

struct process{
    string name;
    int pid, arrival_time, burst_time;
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

bool SJF_comparator(process &p1, process &p2)
{
    if(p1.arrival_time == p2.arrival_time)
    {
        if(p1.burst_time == p2.burst_time)   return p1.pid < p2.pid;
        return p1.burst_time < p2.burst_time;
    }
    return p1.arrival_time < p2.arrival_time;
}
struct SJF_comp {
    constexpr bool operator()(process const& a,process const& b)const noexcept
    {
        if(a.burst_time == b.burst_time)
            return a.arrival_time > b.arrival_time;
        return a.burst_time > b.burst_time;
    }
};

void SJF_scheduling(vector<process> &P){
    int n = P.size();
    priority_queue<process, vector<process>, SJF_comp>pq;
    vector<process>gantt;
    int cur_time = 0;
    pq.push(P[0]);
    int it=1;
    while(!pq.empty())
    {
        process cur_process = pq.top();
        pq.pop();

        int wt = max(0, cur_time - cur_process.arrival_time);
        cur_process.waiting_time = wt;
        cur_process.start_time = cur_process.arrival_time + cur_process.waiting_time;
        cur_process.completion_time = cur_process.start_time + cur_process.burst_time;
        cur_time = cur_process.completion_time;
        gantt.push_back(cur_process);
        while(it < n && P[it].arrival_time <= cur_time)
        {
            pq.push(P[it]);
            it++;
        }
        if(pq.empty() && it<n)
        {
            pq.push(P[it]);
            cur_time = P[it].arrival_time;
            it++;
        }
    }
    for(int i=0;i<n;i++)
    {
        gantt[i].response_time = gantt[i].start_time - gantt[i].arrival_time;
        gantt[i].turn_around_time = gantt[i].completion_time - gantt[i].arrival_time;
    }

    float TAT = 0, WT = 0;
    cout<<"========== SJF Scheduling ==========\n\n";
    cout<<"PID\tProcess\tAT\tST\tBT\tCT\tRT\tTAT\tWT\n";
    for(auto it :  gantt)
    {
        cout<<it.pid<<"\t"<<it.name<<"\t\t"<<it.arrival_time<<"\t";        cout<<it.start_time<<"\t"<<it.burst_time<<"\t"<<it.completion_time<<"\t"<<it.response_time<<"\t";
        cout<<it.turn_around_time<<"\t"<<it.waiting_time<<"\t\t"<<"\n";

        WT += it.waiting_time;
        TAT += it.turn_around_time;
    }

    cout<<"\n====================================\n";
    cout<<"Avg. Waiting Time : "<<WT/n<<"\n";
    cout<<"Avg. Turn Around Time Time : "<<TAT/n<<"\n";
    cout<<"\n\n**\n";
    cout<<"AT = Arrival Time\nST = Start Time\nCT = Completion Time\nRT = Response  Time\n";
    cout<<"TAT = Turn Around Time\nWT = Waiting Time\nBT = Burst Time\n";

}

int main()
{
    vector<process> P;
    ifstream fin;
    fin.open("ShortestJob_Input.txt");
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

    sort(P.begin(), P.end(), SJF_comparator);

    SJF_scheduling(P);
}
