class FrequencyTracker {
public:
    unordered_map<int,int> mapp;
    unordered_map<int,int> freq;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(mapp.count(number)==1){
            freq[mapp[number]]--;
            if(freq[mapp[number]]==0) freq.erase(mapp[number]);
        }
        mapp[number]++;
        freq[mapp[number]]++;
    }
    
    void deleteOne(int number) {
        if(mapp.count(number)==1){
            freq[mapp[number]]--;
            if(freq[mapp[number]]==0) freq.erase(mapp[number]);
            mapp[number]--;
            freq[mapp[number]]++;
            if(mapp[number]==0) mapp.erase(number);
        }
        
    }
    
    bool hasFrequency(int frequency) {
        if(freq.count(frequency)==1) return true;
        else return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */