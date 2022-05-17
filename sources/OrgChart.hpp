#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <string>
using namespace std;

namespace ariel {
    
    class OrgChart {
        string position;
        vector<OrgChart> subs;
        public:
            string get_position();
            OrgChart& add_root(string root);
            OrgChart& add_sub(string sup, string sub);
            size_t size();

            class level_order_iterator {
                vector<OrgChart*> iter;
                size_t pos;
                public:
                    level_order_iterator(OrgChart* ptr = nullptr, size_t i = 0) {
                        pos = i;
                        queue<OrgChart*> que;
                        que.push(ptr);
                        while(!que.empty()) {
                            iter.push_back(que.front());
                            for(auto &sub : que.front()->subs) {
                                que.push(&sub);
                            }
                            que.pop();
                        }
                    }
                    bool operator==(const level_order_iterator &it) const;
                    bool operator!=(const level_order_iterator &it) const;
                    OrgChart& operator*() const;
                    level_order_iterator& operator++();
                    const level_order_iterator operator++(int postfix_flag);
                    string* operator->();
            };

            class reverse_order_iterator {
                vector<OrgChart*> iter;
                size_t pos;
                public:
                    reverse_order_iterator(OrgChart* ptr = nullptr, size_t i = 0) {
                        pos = i;
                        queue<OrgChart*> que;
                        que.push(ptr);
                        while(!que.empty()) {
                            iter.push_back(que.front());
                            for(auto &sub : que.front()->subs) {
                                que.push(&sub);
                            }
                            que.pop();
                        }
                    }
                    bool operator==(const reverse_order_iterator &it) const;
                    bool operator!=(const reverse_order_iterator &it) const;
                    OrgChart& operator*() const;
                    reverse_order_iterator& operator++();
                    const reverse_order_iterator operator++(int postfix_flag);
                    string* operator->();
            };

            class preorder_iterator {
                vector<OrgChart*> iter;
                size_t pos;
                public:
                    preorder_iterator(OrgChart* ptr = nullptr, size_t i = 0) {
                        pos = i;
                        queue<OrgChart*> que;
                        que.push(ptr);
                        while(!que.empty()) {
                            iter.push_back(que.front());
                            for(auto &sub : que.front()->subs) {
                                que.push(&sub);
                            }
                            que.pop();
                        }
                    }
                    bool operator==(const preorder_iterator &it) const;
                    bool operator!=(const preorder_iterator &it) const;
                    OrgChart& operator*() const;
                    preorder_iterator& operator++();
                    const preorder_iterator operator++(int postfix_flag);
                    string* operator->();
            };

            level_order_iterator begin();
            level_order_iterator end();
            level_order_iterator begin_level_order();
            level_order_iterator end_level_order();
            reverse_order_iterator begin_reverse_order();
            reverse_order_iterator reverse_order();
            preorder_iterator begin_preorder();
            preorder_iterator end_preorder();

            friend ostream& operator<<(ostream& os, const OrgChart &orgch);
            bool operator==(const OrgChart &w) const;
            bool operator!=(const OrgChart &w) const;
            string operator*();
    };
}