//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `front` and `has_front` unittests.
 */

#include <pycpp/sfinae/front.h>
#include <gtest/gtest.h>
#include <deque>
#include <set>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(front, front)
{
    std::deque<int> d1 = {2, 3, 4};
    std::set<int> s = {2, 3, 4};
    const auto&d2 = d1;

    EXPECT_EQ(front()(d1), 2);
    EXPECT_EQ(front()(d2), 2);
    front()(d1) = 1;
    EXPECT_EQ(front()(d2), 1);
    EXPECT_EQ(front()(s), 2);
}


TEST(front, has_front)
{
    using deque_type = std::deque<int>;
    using set_type = std::set<int>;

    static_assert(has_front<deque_type>::value, "");
    static_assert(!has_front<set_type>::value, "");
}
