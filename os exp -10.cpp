#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
using namespace std;

struct Message
{
    long type;
    char text[100];
};

int main()
{
    int msgid;
    Message msg;

    // Create message queue
    msgid = msgget(IPC_PRIVATE, 0666 | IPC_CREAT);

    if(msgid == -1)
    {
        cout << "Message queue creation failed";
        return 1;
    }

    // Enter message
    msg.type = 1;

    cout << "Enter a message: ";
    cin.getline(msg.text, 100);

    // Send message
    if(msgsnd(msgid, &msg, sizeof(msg.text), 0) == -1)
    {
        cout << "Message sending failed";
        msgctl(msgid, IPC_RMID, NULL);
        return 1;
    }

    cout << "Message sent successfully" << endl;

    // Receive message
    if(msgrcv(msgid, &msg, sizeof(msg.text), 1, 0) == -1)
    {
        cout << "Message receiving failed";
        msgctl(msgid, IPC_RMID, NULL);
        return 1;
    }

    cout << "Received message: " << msg.text << endl;

    // Delete message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}