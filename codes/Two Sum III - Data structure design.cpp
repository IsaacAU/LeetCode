class TwoSum{
public:
    void add(int x){
        ++um[x];
    }
    bool find(int target){
        for(auto p:um){
            --p.second;
            if(um.count(target-p.first) && um[target-p.first]>0)
                return true;
            ++p.second;
        }
        return false;
    }
private:
    unordered_map<int,int> um;
};
