class MinStack {
    stack<int> s;
    stack<int> mins;
    int m=INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (mins.size()>0)
        m=min(val,mins.top());
        else m=val;
        mins.push(m);
        //print("push");
    }
    
    void pop() {
        
        s.pop();
        mins.pop();
        //print("pop");
    }
    
    int top() {
        //print("top");
        return s.top();
    }
    
    int getMin() {
        //print("getMin");
        return mins.top();
    }
    void print(string c){
        cout << "---------"<<c<<endl;
        stack<int> temps=s;
        while (!temps.empty()){ cout << temps.top()<<" ";temps.pop();}
        cout <<endl;
        stack<int> tempmins=mins;
        while (!tempmins.empty()) {cout << tempmins.top()<<" ";tempmins.pop();}
        cout <<endl;
    }
};
