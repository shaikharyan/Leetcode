class MinStack {
public:
    vector<pair<int,int>> v;
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(v.empty()){
            pair<int,int> p = make_pair(val,val);
            v.push_back(p);

        }

        else{

            int temp = min(val,v.back().second);
            pair<int,int> p = make_pair(val,temp);
            v.push_back(p);

        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back().first;
    }
    
    int getMin() {
        return v.back().second;
    }
};
