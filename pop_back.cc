//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `pop_back` and `has_pop_back` unittests.
 */

#include <pycpp/sfinae/pop_back.h>
#include <gtest/gtest.h>
#include <deque>
#include <set>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(pop_back, pop_back)
{
    std::deque<int> d = {2, 3, 4};
    std::set<int> s = {2, 3, 4};

    pop_back()(d);
    pop_back()(s);

    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(s.size(), 2);
    EXPECT_EQ(d.at(1), 3);
    EXPECT_TRUE(s.find(4) == s.end());
}


TEST(pop_back, has_pop_back)
{
    using deque_type = std::deque<int>;
    using set_type = std::set<int>;

    static_assert(has_pop_back<deque_type>::value, "");
    static_assert(!has_pop_back<set_type>::value, "");
}
