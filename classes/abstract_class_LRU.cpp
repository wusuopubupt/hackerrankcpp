#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cassert>
using namespace std;

struct Node {
	int key;
	int value;
	Node* next;
	Node* prev;
	Node(Node* p, Node* n, int k, int v): key(k), value(v), next(n), prev(p) {}
	Node(int k, int v): key(k), value(v), next(NULL), prev(NULL) {}
};

class Cache {
protected:
	map<int, Node*> mp; // map the key to the node in the linked list
	int cp;
	Node* head;
	Node* tail;
	virtual void set(int, int) = 0;
	virtual int get(int) = 0;
};

class LRUCache : public Cache {
private:
	static int counter;
public:
	LRUCache(int capacity) {
		cp = capacity;
		head = NULL;
		tail = NULL;
	}

	void print_LRU_cache() {
		Node* n = head;
		while(n) {
			cout << n->key << "->" << n->value << " ";	
			n = n->next;
		}			
		cout << endl;
	}

	void update_tail() {
		Node *n = head;
		while(n->next) {
			n = n->next;	
		} 	
		tail = n;
	}

	void set(int key, int value) {
		// if map contains key
		if(mp.count(key) == 1) {
			//cout << "key founed!" << endl;
			Node* finded_node = mp.find(key)->second;			
			finded_node->value = value;
			if(head != finded_node) {
				// remove from old place
				if(finded_node->prev != NULL) {
					finded_node->prev->next = finded_node->next;
				}
				if(finded_node->next != NULL) {
					finded_node->next->prev = finded_node->prev;	
				}
			    head->prev = finded_node;
			    finded_node->next= head;
			    head = finded_node;
				// update tail	
				update_tail();
			}
		} else {
			//cout << "key not founed!" << endl;
			Node* new_node = new Node(key, value);				
			// insert <key, Node> to map
			mp.insert(std::pair<int, Node*>(key, new_node));
			new_node->next = head;
			if(head != NULL) {
				head->prev = new_node;
			}
			head = new_node;
			// update tail
			update_tail();
			counter++;
			if(counter > cp) {
				std::map<int, Node*>::iterator it = mp.find(tail->key);
				mp.erase (it); 
				counter--;
				tail = tail->prev;
				tail->next = NULL;	
			}
		}
		// debug
		//print_LRU_cache();
	}

	int get(int key) {
		if(mp.count(key) == 1) {
			return mp.find(key)->second->value;
		}	
		return -1;
	}

};


int LRUCache::counter = 0;

int main() {
	int n, capacity, i;
	cin >> n >> capacity;
	LRUCache cache(capacity);
	for(int i = 0; i < n; i++) {
		string command;	
		cin >> command;
		if("get" == command) {
			int key;
			cin >> key;	
			cout << cache.get(key) << endl;
		} else if ("set" == command){
			int key, value;	
			cin >> key >> value;
			cache.set(key, value);
		}
	}
	return 0;
}
