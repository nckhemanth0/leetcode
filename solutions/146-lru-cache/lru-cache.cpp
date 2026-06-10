class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int val): key(key), val(val), next(nullptr), prev(nullptr){}
};
class DLL{ // front......back
public:
    Node* front;
    Node* back;

    DLL(){
        front=new Node(-1,-1);
        back=new Node(-1,-1);  
        front->next=back;
        back->prev=front;
    }

    void remove(Node* node){
        Node* prev=node->prev;
        Node* next=node->next;
        prev->next=next;
        next->prev=prev;
    }

    void push(Node* node){
        Node* prev2=back->prev;
        prev2->next=node;
        node->next=back;
        node->prev=prev2;
        back->prev=node;
    }
};


class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity), dll(new DLL()) {
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end() && mp[key]!=nullptr){
            dll->remove(mp[key]);
            dll->push(mp[key]);
            return mp[key]->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            dll->remove(mp[key]);
            dll->push(mp[key]);
            mp[key]->val=value;
        }else{
            if(distinct>=cap){
                evictLRU();
            }
            Node* newnode=new Node(key,value);
            mp[key]=newnode;
            dll->push(newnode);
            distinct++;
        }
    }

    ~LRUCache(){
        delete dll;
    }

private:
    int cap;
    int distinct=0;
    unordered_map<int, Node*> mp;
    DLL *dll;

    void evictLRU(){
        Node* nodeToRemove=dll->front->next;
        dll->remove(nodeToRemove);
        mp.erase(nodeToRemove->key);
        delete nodeToRemove;
        distinct--;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */