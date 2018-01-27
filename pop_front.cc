//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `pop_front` and `has_pop_front` unittests.
 */

#include <pycpp/sfinae/pop_front.h>
#include <gtest/gtest.h>
#include <deque>
#include <set>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(pop_front, pop_front)
{
    std::deque<int> d = {2, 3, 4};
    std::set<int> s = {2, 3, 4};

    pop_front()(d);
    pop_front()(s);

    ASSERT_EQ(d.size(), 2);
    ASSERT_EQ(s.size(), 2);
    EXPECT_EQ(d.at(0), 3);
    EXPECT_TRUE(s.find(2) == s.end());
}


TEST(pop_front, has_pop_front)
{
    using deque_type = std::deque<int>;
    using set_type = std::set<int>;

    static_assert(has_pop_front<deque_type>::value, "");
    static_assert(!has_pop_front<set_type>::value, "");
}
