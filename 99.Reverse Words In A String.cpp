string reverseString(string &str){
	// Write your code here.
	string store,res;
    vector<string>v;
    for(char x:str)
    {
        if(isspace(x) && store.size()>0)v.push_back(store),store="";
        else if(!isspace(x)) store+=x;
    }
    if(store.size()>0)v.push_back(store);
    
    for(int i=v.size()-1;i>=0;i--)
    {
      res+=v[i]+" ";  
    }
   
    return res;	
}
