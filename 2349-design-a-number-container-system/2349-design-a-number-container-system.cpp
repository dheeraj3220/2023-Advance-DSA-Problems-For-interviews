class NumberContainers {
public:
    unordered_map<int,int> mapIndex;
    unordered_map<int,set<int>> mapNums;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        mapNums[mapIndex[index]].erase(index);
        mapIndex[index]=number;
        mapNums[number].insert(index);
    }
    
    int find(int number) {
        if(mapNums[number].size()==0) return -1;
        else return (*mapNums[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */