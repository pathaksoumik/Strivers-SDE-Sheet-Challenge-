int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int low=0,high=arr.size()-1;

	while(low<high)
	{
		int mid=low+(high-low)/2;
		if(arr[mid]==arr[mid^1])low=mid+1;
		else high=mid;
	}
	return arr[low];
}
