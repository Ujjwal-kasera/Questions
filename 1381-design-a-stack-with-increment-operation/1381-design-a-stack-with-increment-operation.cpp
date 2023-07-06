class CustomStack {
    vector<int> vec;
    int top;
    int size;
public:
    CustomStack(int maxSize) {
        vec.resize(maxSize,0);
        top=-1;
        size=maxSize;
    }
    
    void push(int x) {
        if(top<(size-1))
            vec[++top]=x;
    }
    
    int pop() {
        if(top!=-1){
            return vec[top--];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if((top+1)<=k){
            for(int i=0;i<=top;++i){
                vec[i]+=val;
            }
        }
        else
            for(int i=0;i<k;i++){
                vec[i]+=val;
            }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */