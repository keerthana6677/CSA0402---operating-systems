#include <iostream>
using namespace std;

int main()
{
    int n, bt[10], rt[10], wt[10], tat[10];
    int tq, time = 0, done;

    cout << "Enter number of processes: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter burst time: ";
        cin >> bt[i];
        rt[i] = bt[i];
    }

    cout << "Enter time quantum: ";
    cin >> tq;

    do
    {
        done = 1;

        for(int i = 0; i < n; i++)
        {
            if(rt[i] > 0)
            {
                done = 0;

                if(rt[i] > tq)
                {
                    time += tq;
                    rt[i] -= tq;
                }
                else
                {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while(done == 0);

    cout << "\nProcess\tWT\tTAT\n";

    for(int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];

        cout << "P" << i+1 << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;
}