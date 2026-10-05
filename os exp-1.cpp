#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    cout << "Current Process ID: " << GetCurrentProcessId() << endl;
    cout << "Parent Process ID: " << GetCurrentProcessId() << endl;

    return 0;
}