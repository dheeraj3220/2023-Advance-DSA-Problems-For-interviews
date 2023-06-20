class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    set<int> mset;
    SmallestInfiniteSet() {
        for(int i=1;i<1001;i++){
            pq.push(i);
            mset.insert(i);
        }
    }
    
    int popSmallest() {
        int ans=pq.top();
        pq.pop();
        mset.erase(ans);
        return ans;
    }
    
    void addBack(int num) {
        if(mset.count(num)==0){
            pq.push(num);
            mset.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */