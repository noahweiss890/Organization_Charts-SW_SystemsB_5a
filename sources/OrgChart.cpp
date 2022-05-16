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
        return oc;
        // oc.position = sub;
        // for(auto worker : *this) {
        //     if(worker.position == sup) {
        //         worker.subs.push_back(oc);
        //         return *this;
        //     }
        // }
        // throw invalid_argument(sup + " does not exist on the chart!");
    }

    bool OrgChart::level_order_iterator::operator==(const level_order_iterator &it) const {
        return true;
    }

    bool OrgChart::level_order_iterator::operator!=(const level_order_iterator &it) const {
        return true;
    }

    string& OrgChart::level_order_iterator::operator*() const {
        return this->current->position;
    }

    OrgChart::level_order_iterator& OrgChart::level_order_iterator::operator++() {
        OrgChart::level_order_iterator bla;
        return bla;
    }

    const OrgChart::level_order_iterator OrgChart::level_order_iterator::operator++(int postfix_flag) {
        OrgChart::level_order_iterator bla;
        return bla;
    }

    string* OrgChart::level_order_iterator::operator->() const {
        return &(this->current->position);
    }

    bool OrgChart::reverse_order_iterator::operator==(const reverse_order_iterator &it) const {
        return true;
    }

    bool OrgChart::reverse_order_iterator::operator!=(const reverse_order_iterator &it) const {
        return true;
    }

    string& OrgChart::reverse_order_iterator::operator*() const {
        return this->current->position;
    }

    OrgChart::reverse_order_iterator& OrgChart::reverse_order_iterator::operator++() {
        OrgChart::reverse_order_iterator bla;
        return bla;
    }

    const OrgChart::reverse_order_iterator OrgChart::reverse_order_iterator::operator++(int postfix_flag) {
        OrgChart::reverse_order_iterator bla;
        return bla;
    }

    string* OrgChart::reverse_order_iterator::operator->() const {
        return &(this->current->position);
    }

    bool OrgChart::preorder_iterator::operator==(const preorder_iterator &it) const {
        return true;
    }

    bool OrgChart::preorder_iterator::operator!=(const preorder_iterator &it) const {
        return true;
    }

    string& OrgChart::preorder_iterator::operator*() const {
        return this->current->position;
    }

    OrgChart::preorder_iterator& OrgChart::preorder_iterator::operator++() {
        OrgChart::preorder_iterator bla;
        return bla;
    }

    const OrgChart::preorder_iterator OrgChart::preorder_iterator::operator++(int postfix_flag) {
        OrgChart::preorder_iterator bla;
        return bla;
    }

    string* OrgChart::preorder_iterator::operator->() const {
        return &(this->current->position);
    }

    OrgChart::level_order_iterator OrgChart::begin() {
        return OrgChart::level_order_iterator(this);
    }

    OrgChart::level_order_iterator OrgChart::end() {
        OrgChart::level_order_iterator bla;
        return bla;
    }

    OrgChart::level_order_iterator OrgChart::begin_level_order() {
        OrgChart::level_order_iterator bla;
        return bla;
    }

    OrgChart::level_order_iterator OrgChart::end_level_order() {
        OrgChart::level_order_iterator bla;
        return bla;
    }

    OrgChart::reverse_order_iterator OrgChart::begin_reverse_order() {
        OrgChart::reverse_order_iterator bla;
        return bla;
    }

    OrgChart::reverse_order_iterator OrgChart::reverse_order() {
        OrgChart::reverse_order_iterator bla;
        return bla;
    }

    OrgChart::preorder_iterator OrgChart::begin_preorder() {
        OrgChart::preorder_iterator bla;
        return bla;
    }

    OrgChart::preorder_iterator OrgChart::end_preorder() {
        OrgChart::preorder_iterator bla;
        return bla;
    }

    ostream& operator<<(ostream& os, const OrgChart &orgch) {
        return os;
    }

    bool OrgChart::operator!=(const OrgChart &w) const {
        return true;
    }

    string OrgChart::operator*() {
        return "BLA";
    }

    OrgChart OrgChart::operator++() {
        OrgChart bla;
        return bla;
    }
}