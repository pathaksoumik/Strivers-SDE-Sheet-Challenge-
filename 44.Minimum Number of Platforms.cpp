int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    sort(at, at + n);
    sort(dt, dt + n);

    int curNumOfPlatforms = 0, minNumOfPlatforms = 0;

    int i = 0, j = 0;

    while (i < n && j < n) 
    {
        if (at[i] <= dt[j])
        {
            curNumOfPlatforms++;
            i++;
        }

        else 
        {
            curNumOfPlatforms--;
            j++;
        }
        minNumOfPlatforms = max(minNumOfPlatforms, curNumOfPlatforms);
    }
    return minNumOfPlatforms;
}
