#include <iostream>
#include <unordered_map>
using namespace std;

// 设计和实现一个  LRU (最近最少使用) 缓存机制 。
// 实现 LRUCache 类：
// LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
//  
// 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
struct DLinkList{
    int key;
    int value;
    DLinkList* next;
    DLinkList* pre;
    DLinkList():key(0),value(0),next(nullptr),pre(nullptr){}
    DLinkList(int k,int v):key(k),value(v),next(nullptr),pre(nullptr){}
};


class LRUCache {
    DLinkList *head, *tail;
    unordered_map<int,DLinkList*> cache;
    int capacity;
    int size;
    void removeNode(DLinkList *node){
        node->pre->next=node->next;
        node->next->pre=node->pre;
    }
    void insertHead(DLinkList *node){
        node->next=head->next;
        head->next->pre=node;
        head->next=node;
        node->pre=head;
    }
public:
    LRUCache(int _capacity){
        head=new DLinkList();
        tail=new DLinkList();
        head->next = tail;
        tail->pre = head;
        capacity = _capacity;
        size = 0;
    }
    ~LRUCache(){
        DLinkList *p=head->next;
        while(p!=tail){
            DLinkList* tmp=p;
            p=p->next;
            removeNode(tmp);
            delete tmp;
        }
        delete head,tail;
    }
    int get(int key) {
        if(cache.count(key)==0){
            return -1;
        }
        DLinkList *node=cache[key];
        removeNode(node);
        insertHead(node);
        return node->value;
    }
    
    void put(int key, int value) {

        if(cache.count(key)==0){
            if(size==capacity){
                DLinkList* node = tail->pre;
                cache.erase(node->key);
                removeNode(node);
                delete node;
                size--;
            }
            DLinkList *node = new DLinkList(key,value);
            insertHead(node);
            cache[key]=node;
            size++;
        }else{
            DLinkList *node = cache[key];
            node->value=value;
            removeNode(node);
            insertHead(node);
        }

    }

    
};

int main()
{
	LRUCache lRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lRUCache.get(1) << endl;    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lRUCache.get(2)<< endl;    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout <<lRUCache.get(1) << endl;    // 返回 -1 (未找到)
    cout <<lRUCache.get(3) << endl;    // 返回 3
    cout <<lRUCache.get(4) << endl;    // 返回 4

	return 0;
}