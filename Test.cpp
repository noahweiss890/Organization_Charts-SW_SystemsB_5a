#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/OrgChart.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("checking add_root and add_sub ") {
    OrgChart oc;
    oc.add_root("Rick");
    CHECK(oc.get_position() == "Rick");
    oc.add_root("Morty");
    CHECK(oc.get_position() == "Morty");

    oc.add_sub("Morty", "Jessica");
    auto it = oc.begin_level_order();
    CHECK(*it == "Morty");
    ++it;
    CHECK(*it == "Jessica");

    CHECK_THROWS(oc.add_sub("Steve", "Jobs"));
}

TEST_CASE("checking level order") {
    OrgChart oc;
    oc.add_root("Rick")
    .add_sub("Rick", "Beth")
    .add_sub("Rick", "Jerry")
    .add_sub("Beth", "Morty")
    .add_sub("Beth", "Summer")
    .add_sub("Morty", "Mr. Meeseeks")
    .add_sub("Morty", "Jessica");

    auto it = oc.begin_level_order();
    CHECK(*it == "Rick");
    ++it;
    CHECK(*it == "Beth");
    ++it;
    CHECK(*it == "Jerry");
    ++it;
    CHECK(*it == "Morty");
    ++it;
    CHECK(*it == "Summer");
    ++it;
    CHECK(*it == "Mr. Meeseeks");
    ++it;
    CHECK(*it == "Jessica");
    
    CHECK(it == oc.end_level_order());
}

TEST_CASE("checking reverse order") {
    OrgChart oc;
    oc.add_root("Rick")
    .add_sub("Rick", "Beth")
    .add_sub("Rick", "Jerry")
    .add_sub("Beth", "Morty")
    .add_sub("Beth", "Summer")
    .add_sub("Morty", "Mr. Meeseeks")
    .add_sub("Morty", "Jessica");

    auto it = oc.begin_reverse_order();
    CHECK(*it == "Mr. Meeseeks");
    ++it;
    CHECK(*it == "Jessica");
    ++it;
    CHECK(*it == "Morty");
    ++it;
    CHECK(*it == "Summer");
    ++it;
    CHECK(*it == "Beth");
    ++it;
    CHECK(*it == "Jerry");
    ++it;
    CHECK(*it == "Rick");
    
    CHECK(it == oc.reverse_order());
}

TEST_CASE("checking preorder") {
    OrgChart oc;
    oc.add_root("Rick")
    .add_sub("Rick", "Beth")
    .add_sub("Rick", "Jerry")
    .add_sub("Beth", "Morty")
    .add_sub("Beth", "Summer")
    .add_sub("Morty", "Mr. Meeseeks")
    .add_sub("Morty", "Jessica");

    auto it = oc.begin_preorder();
    CHECK(*it == "Rick");
    ++it;
    CHECK(*it == "Beth");
    ++it;
    CHECK(*it == "Morty");
    ++it;
    CHECK(*it == "Mr. Meeseeks");
    ++it;
    CHECK(*it == "Jessica");
    ++it;
    CHECK(*it == "Summer");
    ++it;
    CHECK(*it == "Jerry");
    
    CHECK(it == oc.end_preorder());
}
