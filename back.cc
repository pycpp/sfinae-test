//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `back` and `has_back` unittests.
 */

#include <pycpp/sfinae/back.h>
#include <gtest/gtest.h>
#include <deque>
#include <set>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(back, back)
{
    std::deque<int> d1 = {2, 3, 4};
    std::set<int> s = {2, 3, 4};
    const auto&d2 = d1;

    EXPECT_EQ(back()(d1), 4);
    EXPECT_EQ(back()(d2), 4);
    back()(d1) = 5;
    EXPECT_EQ(back()(d2), 5);
    EXPECT_EQ(back()(s), 4);
}


TEST(back, has_back)
{
    using deque_type = std::deque<int>;
    using set_type = std::set<int>;

    static_assert(has_back<deque_type>::value, "");
    static_assert(!has_back<set_type>::value, "");
}
