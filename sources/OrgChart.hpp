#pragma once

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace ariel {
    
    class OrgChart {
        string position;
        vector<OrgChart> subs;
        public:
            string get_position();
            OrgChart add_root(string root);
            OrgChart add_sub(string sup, string sub);

            class level_order_iterator {
                queue<OrgChart> que;
                public:
                    level_order_iterator(OrgChart* ptr) {
                        que.push(*ptr);
                    }
                    bool operator==(const level_order_iterator &it) const;
                    bool operator!=(const level_order_iterator &it) const;
                    string& operator*() const;
                    level_order_iterator& operator++();
                    const level_order_iterator operator++(int postfix_flag);
                    string* operator->() const;
            };

            class reverse_order_iterator {
                queue<OrgChart> que;
                public:
                    reverse_order_iterator(OrgChart* ptr) {
                        que.push(*ptr);
                    }
                    bool operator==(const reverse_order_iterator &it) const;
                    bool operator!=(const reverse_order_iterator &it) const;
                    string& operator*() const;
                    reverse_order_iterator& operator++();
                    const reverse_order_iterator operator++(int postfix_flag);
                    string* operator->() const;
            };

            class preorder_iterator {
                queue<OrgChart> que;
                public:
                    preorder_iterator(OrgChart* ptr) {
                        que.push(*ptr);
                    }
                    bool operator==(const preorder_iterator &it) const;
                    bool operator!=(const preorder_iterator &it) const;
                    string& operator*() const;
                    preorder_iterator& operator++();
                    const preorder_iterator operator++(int postfix_flag);
                    string* operator->() const;
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
            bool operator!=(const OrgChart &w) const;
            string operator*();
            OrgChart operator++();
    };
}