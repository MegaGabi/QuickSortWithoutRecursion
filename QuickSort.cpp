vector<int> quickSort(const vector<int>& lst)
{
    vector<int> result(lst);
    
    stack<int> pivots;
    pivots.push(0);
    pivots.push(result.size() - 1);
    
    while(!pivots.empty())
    {
        int h = pivots.top();
        pivots.pop();
        int l = pivots.top();
        pivots.pop();
        
        int pivot = h;
        
        if(h <= l)
        {
            continue;
        }
        
        for (int i = l; i <= pivot;)
        {
            if(result[i] > result[pivot])
            {
                result.insert(result.begin() + pivot + 1, result[i]);
                result.erase(result.begin() + i);
                --pivot;
            }
            else
            {
                ++i;
            }
        }
        pivots.push(l);
        pivots.push(pivot - 1);
        pivots.push(pivot + 1);
        pivots.push(h);
    }
    

    return result;
}