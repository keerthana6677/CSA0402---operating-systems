#include <iostream>
using namespace std;

int main()
{
    int n, at[10], bt[10], rt[10], pr[10];
    int ct[10], wt[10], tat[10];
    int time = 0, completed = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter arrival, burst and priority: ";
        cin >> at[i] >> bt[i] >> pr[i];
        rt[i] = bt[i];
    }

    while(completed < n)
    {
        int pos = -1, best = 999;

        for(int i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0 && pr[i] < best)
            {
                best = pr[i];
                pos = i;
            }
        }

        if(pos == -1)
        {
            time++;
            continue;
        }

        rt[pos]--;
        time++;

        if(rt[pos] == 0)
        {
            ct[pos] = time;
            completed++;
        }
    }

    cout << "\nProcess\tWT\tTAT\n";

    for(int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        cout << "P" << i+1 << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;
}