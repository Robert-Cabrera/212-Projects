#include <iostream>
#include <stack>

using namespace std;

class Queue
{
    private:
        stack <int> s1;
        stack <int> s2;

    public:
        void enqueue(int x);
        int dequeue();
        int front();
};

void Queue:: enqueue(int x)
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    s1.push(x);

    //swapping
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

int Queue:: dequeue()
{
    if(s1.empty())
        throw underflow_error("The queue is empty");

    int value = s1.top();
    s1.pop();

    return value;
}

int Queue:: front()
{
    if(s1.empty())
        throw underflow_error("The queue is empty");

    int value = s1.top();
    s1.pop();

    return value;

}