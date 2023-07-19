string kthPermutation(int n, int k) 
{
    int j, factorial = 1;
    string s;

    for (int i = 1; i <= n; i++) 
    {

        factorial *= i;
      
        s += to_string(i);
    }

    k--;

    for (int i = 0; i < n; i++) 
    {
        factorial /= n - i;

        // Calculate index of char to put at index i on 's'.
        j = i + k / factorial;
        char c = s[j];

        // Remove c by shifting to cover up (adjust the right part).
        while (j > i) 
        {
            s[j] = s[j - 1];
            j--;
        }

        k %= factorial;
        s[i] = c;
    }
    return s;
}
