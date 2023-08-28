class MyStack {
    queue<int> que1,que2;
    int size;
public:
    MyStack() {
        size=0;
    }
    
    void push(int x) {
        if(que1.size()==0)
        {
            que1.push(x);
            while(que2.size()!=0)
            {
                que1.push(que2.front());
                que2.pop();
            }
        }
        else
        {
            que2.push(x);
            while(que1.size()!=0)
            {
                que2.push(que1.front());
                que1.pop();
            }
        }
        size++;
    }
    
    int pop() {
        int a;
        if(!que1.empty())
        {
            a=que1.front();
            que1.pop();
        }
        else if(!que2.empty())
        {
            a=que2.front();
            que2.pop();
        }
        size--;
        return a;
    }
    
    int top() {
        int frnt;
        if(que1.size()!=0) frnt= que1.front();
        else if(que2.size()!=0) frnt= que2.front();
        return frnt;
    }
    
    bool empty() {
        if(size>0) return false;
        else return true;
        
    }
};