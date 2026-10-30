#include <iostream>
using namespace std;

int main()
{
    int n, bt[20], p[20], wt[20], tat[20], temp;

    cout << "Enter number of processes: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        p[i] = i+1;
        cout << "Enter burst time: ";
        cin >> bt[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(int i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    cout << "\nProcess\tBT\tWT\tTAT\n";

    for(int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];

        cout << "P" << p[i] << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;
}