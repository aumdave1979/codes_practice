#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
class Queue
{
    int f;
    int r;
    int Q[MAX_SIZE];
public:
    Queue()
    {
        f = -1;
        r = -1;
    }
    void enqueue(int x)
    {
        if (f == -1)
            f++;
        if (r < MAX_SIZE - 1)
        {
            Q[++r] = x;
        }
        else
        {
            cout << "Queue is full" << endl;
        }
    }
    int dequeue()
    {
        if (f == -1)
        {
            cout << "Empty Queue" << endl;
            return -9999;
        }
        else
        {
            int x = Q[f++];
            if (f > r)
            {
                f = -1;
                r = -1;
            }
            return x;
        }
    }
    void printQueue()
    {
        cout << "Queue Elements: " << endl;
        for (int i = f; i <= r; i++)
        {
            cout << " " << Q[i];
        }
        cout << endl
             << "----f:" << f << "-----r:" << r << "-------------" << endl;
    }
};
int main()
{
    Queue q;
    q.enqueue(2);
    q.printQueue();
    q.enqueue(10);
    q.printQueue();
    cout << "from dequeue: " << q.dequeue() << endl;
    q.printQueue();
    q.enqueue(50);
    q.printQueue();

    return 0;
}