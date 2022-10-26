#include <iostream>
#include <queue>

using namespace std;

class Stack
{
    private:
        queue <int> q1;
        queue <int> q2;

    public:
        void push(int x);
        int pop();
        int top();
    
};

void Stack:: push(int x)
{
    q1.push(x);
}

int Stack:: pop()
{
    if(q1.empty())
        throw underflow_error("The stack is empty");

    //pass all the elements to the second queue but the last one
    while (q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }

    //value we are returning
    int value = q1.front();
    q1.pop();

    //swap the queues so we can repeat the process:
    queue <int> temp = q1;
    q1 = q2;
    q2 = temp;

    return value;

}

int Stack:: top()
{
    //pass all the elements to the second queue but the last one
    while (q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }

    //value we are returning
    int value = q1.front();

    //since we are only returning the value we leave it in the queue
    q2.push(value);
    q1.pop();

    //swap the queues so we can repeat the process:
    queue <int> temp = q1;
    q1 = q2;
    q2 = temp;

    return value;

}