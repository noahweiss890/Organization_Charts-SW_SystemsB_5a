#include "OrgChart.hpp"
using namespace ariel;

namespace ariel {
    OrgChart OrgChart::add_root(string root) {
        OrgChart bla;
        return bla;
    }

    OrgChart OrgChart::add_sub(string sup, string sub) {
        OrgChart bla;
        return bla;
    }

    size_t OrgChart::size() {
        return 0;
    }

    bool OrgChart::level_order_iterator::operator==(const level_order_iterator &it) const {
        return true;
    }

    bool OrgChart::level_order_iterator::operator!=(const level_order_iterator &it) const {
        return true;
    }

    string OrgChart::level_order_iterator::operator*() {
        return "BLA";
    }

    OrgChart::level_order_iterator OrgChart::level_order_iterator::operator++() {
        OrgChart::level_order_iterator bla;
        return bla;
    }

    OrgChart::level_order_iterator OrgChart::level_order_iterator::operator++(int postfix_flag) {
        OrgChart::level_order_iterator bla;
        return bla;
    }

    OrgChart* OrgChart::level_order_iterator::operator->() {
        OrgChart* bla;
        return bla;
    }

    bool OrgChart::reverse_order_iterator::operator==(const reverse_order_iterator &it) const {
        return true;
    }

    bool OrgChart::reverse_order_iterator::operator!=(const reverse_order_iterator &it) const {
        return true;
    }

    string OrgChart::reverse_order_iterator::operator*() {
        return "BLA";
    }

    OrgChart::reverse_order_iterator OrgChart::reverse_order_iterator::operator++() {
        OrgChart::reverse_order_iterator bla;
        return bla;
    }

    OrgChart::reverse_order_iterator OrgChart::reverse_order_iterator::operator++(int postfix_flag) {
        OrgChart::reverse_order_iterator bla;
        return bla;
    }

    OrgChart* OrgChart::reverse_order_iterator::operator->() {
        OrgChart* bla;
        return bla;
    }

    bool OrgChart::preorder_iterator::operator==(const preorder_iterator &it) const {
        return true;
    }

    bool OrgChart::preorder_iterator::operator!=(const preorder_iterator &it) const {
        return true;
    }

    string OrgChart::preorder_iterator::operator*() {
        return "BLA";
    }

    OrgChart::preorder_iterator OrgChart::preorder_iterator::operator++() {
        OrgChart::preorder_iterator bla;
        return bla;
    }

    OrgChart::preorder_iterator OrgChart::preorder_iterator::operator++(int postfix_flag) {
        OrgChart::preorder_iterator bla;
        return bla;
    }

    OrgChart* OrgChart::preorder_iterator::operator->() {
        OrgChart* bla;
        return bla;
    }

    OrgChart::level_order_iterator OrgChart::begin() {
        OrgChart::level_order_iterator bla;
        return bla;
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