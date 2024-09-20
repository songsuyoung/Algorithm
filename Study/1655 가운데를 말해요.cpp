#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

double getVal()
{
    if (maxHeap.size() < minHeap.size())
    {
        return minHeap.top();
    }
    return maxHeap.top();
}

void insert(int data)
{
    if (maxHeap.size() == 0)
    {
        maxHeap.push(data);
        return;
    }
    if (maxHeap.size() < minHeap.size())
    {
        if (data > getVal())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(data);
        }
        else
        {
            maxHeap.push(data);
        }
        return;
    }
    if (data < getVal())
    {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        maxHeap.push(data);
    }
    else
    {
        minHeap.push(data);
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int value;
        cin >> value;
        insert(value);

        cout << getVal() << '\n';
    }
}