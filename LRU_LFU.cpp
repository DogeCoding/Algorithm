#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <list>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* creatList(int *list, int length) {
	ListNode *head = new ListNode(0);
	ListNode *ans = head;
	for (int i = 0; i < length; i++) {
		head->next = new ListNode(list[i]);
		head = head->next;
	}
	return ans->next;
}

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 用一个双向链表记录访问时间，因为链表插入删除高效，时间新的在前面，旧的在后面。
// 用一个哈希表记录缓存(key, value)，哈希查找近似O(1)，发生哈希冲突时最坏O(n)，同时哈希表中得记录 (key, (value, key_ptr))，key_ptr 是key在链表中的地址，为了能在O(1)时间内找到该节点，并把节点提升到表头。
// 链表中的key，能快速找到hash中的value，并删除。
class LRUCache {
public:
    LRUCache(int capacity) {
    	maxCapacity = capacity;
    }
    
    int get(int key) {
    	auto it = pmap.find(key);
    	if (it == pmap.end()) return -1;
    	plist.splice(plist.begin(), plist, it->second);
    	return plist.begin()->second;
    }
    
    void put(int key, int value) {
    	if (maxCapacity == 0) return;
    	auto it = pmap.find(key);
    	if (it == pmap.end()) {
			if (plist.size() >= maxCapacity) {
    			pmap.erase(plist.back().first);
    			plist.pop_back();
    		}
			plist.emplace_front(key, value);
    		pmap[key] = plist.begin();    		 		
    	} else {
    		it->second->second = value;
    		plist.splice(plist.begin(), plist, it->second);
    	}
    }

private:
	int maxCapacity;
	list<pair<int, int>> plist;
	unordered_map<int, list<pair<int, int>>::iterator> pmap;
};


class LFUCache {
public:
    LFUCache(int capacity) {
    	maxCap = capacity;
    	curCap = 0;
    }
    
    int get(int key) {
    	auto it = pmap.find(key);
    	if (it == pmap.end()) return -1;
    	LFUData *data = &(it->second);
    	countIncrease(data);
    	return data->value;
    }
    
    void put(int key, int value) {
    	if (maxCap == 0) return;
    	auto it = pmap.find(key);
    	if (it == pmap.end()) {
    		list<int> *firstList = &(plist.front().second);
    		if (curCap >= maxCap) {
    			if (firstList->size()) {
					pmap.erase(firstList->back());
	    			firstList->pop_back();
	    			curCap--;	    				
    			}		
    		}
			
			if (plist.front().first != 1) {
				plist.emplace_front(pair<int, list<int>>(1, list<int>()));
				firstList = &(plist.front().second);
			}
			firstList->emplace_front(key);
			LFUData data;
			data.value = value;
			data.mainList = plist.begin();
			data.subList = firstList->begin();
			pmap[key] = data;
			curCap++;
    	} else {
    		it->second.value = value;
    		countIncrease(&(it->second));
    	}
    }

private:
	struct LFUData {
		int value;
		list<pair<int, list<int>>>::iterator mainList;
		list<int>::iterator subList;
	};
	int maxCap;
	int curCap;
	list<pair<int, list<int>>> plist;
	unordered_map<int, LFUData> pmap;

	void countIncrease(LFUData *data) {
		auto cur = data->mainList;
		auto next = data->mainList;
		auto sub = data->subList;
		next++;

		if (next != plist.end()) {
			if (cur->first + 1 != next->first) {
				if (cur->second.size() == 1) {
					cur->first++;
				} else {
					auto it = plist.emplace(next, pair<int, list<int>>(cur->first + 1, list<int>()));
					it->second.splice(it->second.begin(), cur->second, sub);
					data->mainList = it;
					data->subList = it->second.begin();
				}
			} else {
				next->second.splice(next->second.begin(), cur->second, sub);
				data->mainList = next;
				data->subList = next->second.begin();
				if (!cur->second.size()) {
					plist.erase(cur);
				}
			}
		} else {
			if (cur->second.size() == 1) {
				cur->first++;
			} else {
				list<int> tempList;
				tempList.splice(tempList.begin(), cur->second, sub);
				plist.emplace_back(cur->first + 1, tempList);
				data->mainList = plist.end();
				(data->mainList)--;
				data->subList = data->mainList->second.begin();
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	
	return 0;
}