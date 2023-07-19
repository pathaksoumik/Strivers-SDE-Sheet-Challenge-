#include <bits/stdc++.h> 
struct SumCombination 
{
    int sum;
    int indexA;
    int indexB;

    SumCombination(int s, int ia, int ib) : sum(s), indexA(ia), indexB(ib) {}

    bool operator<(const SumCombination& other) const 
	{
        return sum < other.sum;
    }
};

   vector<int> kMaxSumCombination(vector<int>& a, vector<int>& b, int n, int k) {
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    priority_queue<SumCombination> pq;

    pq.push(SumCombination(a[0] + b[0], 0, 0));

   vector<int> result;

    while (k > 0 && !pq.empty())
	{
        SumCombination curr = pq.top();
        pq.pop();

        result.push_back(curr.sum);

        if (curr.indexA + 1 < n) 
            pq.push(SumCombination(a[curr.indexA + 1] + b[curr.indexB], curr.indexA + 1, curr.indexB));
        
        if (curr.indexA == 0 && curr.indexB + 1 < n) 
            pq.push(SumCombination(a[curr.indexA] + b[curr.indexB + 1], curr.indexA, curr.indexB + 1));

        k--;
    }

    return result;
}
