#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream source("input.txt");
    ofstream destination("output.txt");

    char ch;

    while (source.get(ch))
    {
        destination.put(ch);
    }

    source.close();
    destination.close();

    cout << "File copied successfully";

    return 0;
}