class Solution {
public:
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        for(int i=0;i<nums2.size();i++)
        {
            insert(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++)
        {
            insert(nums1[i]);
        }

        return get();
    }

    void insert(int data)
    {
        if(maxHeap.size() == 0)
        {
            maxHeap.push(data);
            return;
        }

        if(maxHeap.size() < minHeap.size())
        {
            if(data > get())
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

        if(data < get())
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

    double get()
    {
        if(maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top())/2.f;
        }

        if(maxHeap.size() < minHeap.size())
        {
            return minHeap.top();
        }

        return maxHeap.top();
    }
};