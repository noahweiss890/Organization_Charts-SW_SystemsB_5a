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
            size_t size();

            class level_order_iterator {
                OrgChart* current;
                // queue<OrgChart> que;
                public:
                    bool operator==(const level_order_iterator &it) const;
                    bool operator!=(const level_order_iterator &it) const;
                    OrgChart operator*();
                    level_order_iterator operator++();
                    level_order_iterator operator++(int postfix_flag);
                    OrgChart* operator->();
            };

            class reverse_order_iterator {
                OrgChart* current;
                // queue<OrgChart> que;
                public:
                    bool operator==(const reverse_order_iterator &it) const;
                    bool operator!=(const reverse_order_iterator &it) const;
                    OrgChart operator*();
                    reverse_order_iterator operator++();
                    reverse_order_iterator operator++(int postfix_flag);
                    OrgChart* operator->();
            };

            class preorder_iterator {
                OrgChart* current;
                // queue<OrgChart> que;
                public:
                    bool operator==(const preorder_iterator &it) const;
                    bool operator!=(const preorder_iterator &it) const;
                    OrgChart operator*();
                    preorder_iterator operator++();
                    preorder_iterator operator++(int postfix_flag);
                    OrgChart* operator->();
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