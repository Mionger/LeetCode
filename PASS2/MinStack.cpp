#include<iostream>
#include<stack>
using namespace std;

class MinStack 
{
private:
    stack<int> s;
    stack<int> m;
public:
    MinStack();
    void push(int x);
    void pop();
    int top();
    int getMin();
};

MinStack::MinStack()
{

}

void MinStack::push(int x)
{
    if (s.empty())
    {
        this->s.push(x);
        this->m.push(x);
    }
    else
    {
        this->s.push(x);
        this->m.push(min(this->m.top(), x));
    }
}

void MinStack::pop()
{
    if (!s.empty())
    {
        this->s.pop();
        this->m.pop();
    }
}

int MinStack::top()
{
    if (!s.empty())
        return s.top();
    else
        return 0;
}

int MinStack::getMin()
{
    if (!m.empty())
        return m.top();
    else
        return 0;
}