class LRUCache{
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(map.count(key)){
            int val=map[key]->second;
            values.erase(map[key]);
            values.push_front(make_pair(key,val));
            map[key]=begin(values);
            return val;
        }else
            return -1;
    }
    
    void set(int key, int value) {
        if(map.count(key))
            values.erase(map[key]);
        else if(map.size()==cap){
            map.erase(values.back().first);
            values.pop_back();
        }
        values.push_front(make_pair(key,value));
        map[key]=begin(values);
    }
private:
    int cap;
    list<pair<int,int>> values;
    unordered_map<int, list<pair<int,int>>::iterator> map;
};
