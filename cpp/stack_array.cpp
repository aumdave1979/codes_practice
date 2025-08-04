#include <iostream>
using namespace std;
const int MAX_SIZE = 5;
class Stack
{
    char s[MAX_SIZE];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    void push(char d)
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "Stack is overflow/full";
            return;
        }
        s[++top] = d;
    }
    char pop()
    {
        if (top == -1)
        {
            cout << "Stack empty/underflow";
            return ' ';
        }
        return s[top--];
    }
    void display()
    {
        cout << "Stack elements" << endl;
        for (int i = top; i > -1; i--)
        {
            cout << s[i] << endl;
        }
    }
};
int main()
{
    Stack s1;
    s1.push('A');
    s1.display();
    s1.push('B');
    s1.display();
    cout << endl
         << s1.pop() << endl;
    s1.display();
    s1.push('X');
    s1.display();
    return 0;
}