#include "OrgChart.hpp"
using namespace ariel;

namespace ariel {

    string OrgChart::get_position() {
        return this->position;
    }

    OrgChart OrgChart::add_root(string root) {
        this->position = root;
        return *this;
    }

    OrgChart OrgChart::add_sub(string sup, string sub) {
        OrgChart oc;
        // return oc;
        oc.position = sub;
        for(auto worker : *this) {
            if(worker.position == sup) {
                worker.subs.push_back(oc);
                return *this;
            }
        }
        throw invalid_argument(sup + " does not exist on the chart!");
    }

    bool OrgChart::level_order_iterator::operator==(const level_order_iterator &it) const {
        return this->que.front() == it.que.front();
    }

    bool OrgChart::level_order_iterator::operator!=(const level_order_iterator &it) const {
        return !(*this == it);
    }

    OrgChart OrgChart::level_order_iterator::operator*() const {
        return this->que.front();
    }

    OrgChart::level_order_iterator& OrgChart::level_order_iterator::operator++() {
        for(auto sub : this->que.front().subs) {
            this->que.push(sub);
        }
        this->que.pop();
        return *this;
    }

    const OrgChart::level_order_iterator OrgChart::level_order_iterator::operator++(int postfix_flag) {
        OrgChart::level_order_iterator temp = *this;
        for(auto sub : this->que.front().subs) {
            this->que.push(sub);
        }
        this->que.pop();
        return temp;
    }

    string* OrgChart::level_order_iterator::operator->() {
        return &(this->que.front().position);
    }

    bool OrgChart::reverse_order_iterator::operator==(const reverse_order_iterator &it) const {
        return this->que.front() == it.que.front();
    }

    bool OrgChart::reverse_order_iterator::operator!=(const reverse_order_iterator &it) const {
        return !(*this == it);
    }

    OrgChart OrgChart::reverse_order_iterator::operator*() const {
        return this->que.front();
    }

    OrgChart::reverse_order_iterator& OrgChart::reverse_order_iterator::operator++() {
        return *this;
    }

    const OrgChart::reverse_order_iterator OrgChart::reverse_order_iterator::operator++(int postfix_flag) {
        return *this;
    }

    string* OrgChart::reverse_order_iterator::operator->() {
        return &(this->que.front().position);
    }

    bool OrgChart::preorder_iterator::operator==(const preorder_iterator &it) const {
        return this->que.front() == it.que.front();
    }

    bool OrgChart::preorder_iterator::operator!=(const preorder_iterator &it) const {
        return !(*this == it);
    }

    OrgChart OrgChart::preorder_iterator::operator*() const {
        return this->que.front();
    }

    OrgChart::preorder_iterator& OrgChart::preorder_iterator::operator++() {
        return *this;
    }

    const OrgChart::preorder_iterator OrgChart::preorder_iterator::operator++(int postfix_flag) {
        return *this;
    }

    string* OrgChart::preorder_iterator::operator->() {
        return &(this->que.front().position);
    }

    OrgChart::level_order_iterator OrgChart::begin() {
        return OrgChart::level_order_iterator(this);
    }

    OrgChart::level_order_iterator OrgChart::end() {
        return OrgChart::level_order_iterator();
    }

    OrgChart::level_order_iterator OrgChart::begin_level_order() {
        return OrgChart::level_order_iterator(this);
    }

    OrgChart::level_order_iterator OrgChart::end_level_order() {
        return OrgChart::level_order_iterator();
    }

    OrgChart::reverse_order_iterator OrgChart::begin_reverse_order() {
        return OrgChart::reverse_order_iterator(this);
    }

    OrgChart::reverse_order_iterator OrgChart::reverse_order() {
        return OrgChart::reverse_order_iterator();
    }

    OrgChart::preorder_iterator OrgChart::begin_preorder() {
        return OrgChart::preorder_iterator(this);
    }

    OrgChart::preorder_iterator OrgChart::end_preorder() {
        return OrgChart::preorder_iterator();
    }

    ostream& operator<<(ostream& os, const OrgChart &orgch) {
        os << orgch.position;
        return os;
    }

    bool OrgChart::operator==(const OrgChart &w) const {
        return this == &w;
    }

    bool OrgChart::operator!=(const OrgChart &w) const {
        return !(*this == w);
    }

    string OrgChart::operator*() {
        return this->position;
    }
}
