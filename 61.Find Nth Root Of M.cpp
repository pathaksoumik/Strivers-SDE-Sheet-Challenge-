int NthRoot(int n, int m) {
  // Write your code here.
  int low=1,high=m;

  while(low<=high)
  {
    int mid=low+(high-low)/2;

    long long check=1;
    for(int i=1;i<=n;i++)
    {
      check*=mid;
      if(check>m)
      {
        high=mid-1;
        break;
      }
    }

    if(check==m) return mid;
    
     if(check < m) low=mid+1;
    //else high=mid-1;
  }
  return -1;
}
