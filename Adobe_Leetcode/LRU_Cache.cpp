#include<iostream>
#include<unordered_map>
using namespace std;

// In this program to run each get and put function in O(1) time complexity we create two nodes initially which are the start and end point of the doubly linked list 
// I have used unordered_map to check is the element is new or already present in list and if it  present then access it fastly
class Node
{
    public:
    int key, val;
    Node *next, *prev;
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        prev = next = NULL;
    }
};
class LRUCache {
    unordered_map<int, Node*> umap;
    int size;
    Node *head, *end;
public:
    LRUCache(int capacity)
    {
        size = capacity;
        head = new Node(0, 0);
        end = new Node(0, 0);
        head->next = end;
        end->prev = head;
    }
    int get(int key)
    {
        if(umap.find(key) != umap.end())
        {
            Node *temp = umap[key];
            remove(temp);
            insert(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        if(umap.find(key) != umap.end())
        {
            remove(umap[key]);
        }
        Node *newNode = new Node(key, value);
        umap[key] = newNode;
        insert(newNode);
        if(umap.size() > size)
        {
            Node *temp = head->next;
            umap.erase(temp->key);
            remove(temp);
            delete temp;
        }
    }

    void remove(Node *temp)
    {
        Node *prev = temp->prev;
        Node *next = temp->next;
        prev->next = next;
        next->prev = prev;
    }
    void insert(Node *newNode)
    {
        Node *prev = end->prev;;
        Node *next = end;
        prev->next = newNode;
        newNode->next = end;
        end->prev = newNode;
        newNode->prev = prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */