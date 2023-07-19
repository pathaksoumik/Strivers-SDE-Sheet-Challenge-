class Queue {
    // Define the data members(if any) here.
    
    public:
    stack<int>stack1,stack2;
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        stack1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(stack2.empty())
        {
            if(stack1.empty())
              return -1;
              
                while(!stack1.empty())
                {
                    stack2.push(stack1.top());
                    stack1.pop();
                } 
        }
        int item=stack2.top();
        stack2.pop();
        
        return item;
    }

    int peek() {
        // Implement the peek() function here.
        if(stack2.empty())
        {
            if(stack1.empty())
               return -1;
               
                while(!stack1.empty())
                {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            
        }
       
        return stack2.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return stack1.empty() and stack2.empty();
    }
};
