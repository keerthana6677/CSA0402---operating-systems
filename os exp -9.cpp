#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
using namespace std;

int main()
{
    int shmid;
    char *str;

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, 1024, 0666 | IPC_CREAT);

    if(shmid == -1)
    {
        cout << "Shared memory creation failed";
        return 1;
    }

    // Attach shared memory
    str = (char*)shmat(shmid, NULL, 0);

    if(str == (char*)-1)
    {
        cout << "Shared memory attachment failed";
        shmctl(shmid, IPC_RMID, NULL);
        return 1;
    }

    // Write message
    cout << "Enter a message: ";
    cin.getline(str, 100);

    // Read message
    cout << "Message from shared memory: " << str << endl;

    // Detach shared memory
    shmdt(str);

    // Delete shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}