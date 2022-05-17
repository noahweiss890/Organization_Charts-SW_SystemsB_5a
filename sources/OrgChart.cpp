#include "OrgChart.hpp"
using namespace ariel;

namespace ariel {

    string OrgChart::get_position() {
        return this->position;
    }

    OrgChart& OrgChart::add_root(string root) {
        this->position = root;
        return *this;
    }

    OrgChart& OrgChart::add_sub(string sup, string sub) {        
        OrgChart oc;
        oc.add_root(sub);
        for(auto &worker : *this) {
            if(worker.position == sup) {
                OrgChart oc;
                oc.add_root(sub);
                worker.subs.push_back(oc);
                return *this;
            }
        }
        throw invalid_argument(sup + " does not exist on the chart!");
    }

    size_t OrgChart::size() {
        size_t count = 1;
        for(auto w : this->subs) {
            count += w.size();
        }
        return count;
    }


    // level_order_iterator:

    bool OrgChart::level_order_iterator::operator==(const level_order_iterator &it) const {
        return this->pos == it.pos;
    }

    bool OrgChart::level_order_iterator::operator!=(const level_order_iterator &it) const {
        return !(*this == it);
    }

    OrgChart& OrgChart::level_order_iterator::operator*() const {
        return *(this->iter.at(this->pos));
    }

    OrgChart::level_order_iterator& OrgChart::level_order_iterator::operator++() {
        (this->pos)++;
        return *this;
    }

    const OrgChart::level_order_iterator OrgChart::level_order_iterator::operator++(int postfix_flag) {
        OrgChart::level_order_iterator temp = *this;
        ++(*this);
        return temp;
    }

    string* OrgChart::level_order_iterator::operator->() {
        return &(this->iter.at(this->pos)->position);
    }

    
    // reverse_order_iterator:

    bool OrgChart::reverse_order_iterator::operator==(const reverse_order_iterator &it) const {
        return this->pos == it.pos;
    }

    bool OrgChart::reverse_order_iterator::operator!=(const reverse_order_iterator &it) const {
        return !(*this == it);
    }

    OrgChart& OrgChart::reverse_order_iterator::operator*() const {
        return *(this->iter.at(this->pos));
    }

    OrgChart::reverse_order_iterator& OrgChart::reverse_order_iterator::operator++() {
        (this->pos)++;
        return *this;
    }

    const OrgChart::reverse_order_iterator OrgChart::reverse_order_iterator::operator++(int postfix_flag) {
        OrgChart::reverse_order_iterator temp = *this;
        ++(*this);
        return temp;
    }

    string* OrgChart::reverse_order_iterator::operator->() {
        return &(this->iter.at(this->pos)->position);
    }


    // preorder_iterator:

    bool OrgChart::preorder_iterator::operator==(const preorder_iterator &it) const {
        return this->pos == it.pos;
    }

    bool OrgChart::preorder_iterator::operator!=(const preorder_iterator &it) const {
        return !(*this == it);
    }

    OrgChart& OrgChart::preorder_iterator::operator*() const {
        return *(this->iter.at(this->pos));
    }

    OrgChart::preorder_iterator& OrgChart::preorder_iterator::operator++() {
        (this->pos)++;
        return *this;
    }

    const OrgChart::preorder_iterator OrgChart::preorder_iterator::operator++(int postfix_flag) {
        OrgChart::preorder_iterator temp = *this;
        ++(*this);
        return temp;
    }

    string* OrgChart::preorder_iterator::operator->() {
        return &(this->iter.at(this->pos)->position);
    }


    // OrgChart function:

    OrgChart::level_order_iterator OrgChart::begin() {
        return this->begin_level_order();
    }

    OrgChart::level_order_iterator OrgChart::end() {
        return this->end_level_order();
    }

    OrgChart::level_order_iterator OrgChart::begin_level_order() {
        return OrgChart::level_order_iterator(this);
    }

    OrgChart::level_order_iterator OrgChart::end_level_order() {
        return OrgChart::level_order_iterator(this, this->size());
    }

    OrgChart::reverse_order_iterator OrgChart::begin_reverse_order() {
        return OrgChart::reverse_order_iterator(this);
    }

    OrgChart::reverse_order_iterator OrgChart::reverse_order() {
        return OrgChart::reverse_order_iterator(this, this->size());
    }

    OrgChart::preorder_iterator OrgChart::begin_preorder() {
        return OrgChart::preorder_iterator(this);
    }

    OrgChart::preorder_iterator OrgChart::end_preorder() {
        return OrgChart::preorder_iterator(this, this->size());
    }

    ostream& operator<<(ostream& os, const OrgChart &orgch) {
        os << orgch.position;
        os << " ->  printing kids:";
        for(auto sub : orgch.subs) {
            os << sub.position << " ";
        }
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
