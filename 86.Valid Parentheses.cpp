bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>st;
        bool f=1;
        for(auto x:expression)
        {
            if(x=='(' || x=='{'|| x=='[')
                st.push(x);
            else if(!st.empty())
            {
              if((x==')' && st.top()=='(') || (x=='}' && st.top()=='{')|| (x==']' && st.top()=='['))
                  st.pop();
                else
                {
                    f=0; break;
                }
            }
            else if(st.empty())f=0;
        }
        if(!f || st.size()>0) return false;
        else return true; 
}
