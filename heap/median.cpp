


void addNum(int n)
{
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;

    maxheap.push(num);
    minheap.push(maxheap.top());
    maxheap.pop();

    if(maxheap.size()<minheap.size())
    {
        maxheap.push(minheap.top());
        minheap.pop();
    }
}
double findMedian() {
        // If odd number of elements, median is the top of the Left Heap
        if (leftMaxHeap.size() > rightMinHeap.size()) {
            return leftMaxHeap.top();
        }
        // If even, average the tops of both heaps
        // Divide by 2.0 to force float division
        return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
    }