#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	 int l=0,r=n-1;
    while(l<r)
    {
        if(knows(l,r))l++;
        else r--;
    }
    
    int person=l;
    bool known=1,knowsany=0;
    
    for(int i=0;i<n;i++)
    {
        if(i!=person and !knows(i,person))
        {
            known=0; break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(knows(person,i))
        {
            knowsany=1;break;
        }
    }
       if(!known or knowsany)return -1;
    
    return person;
}
