//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `push_front` and `has_push_front` unittests.
 */

#include <pycpp/sfinae/push_front.h>
#include <gtest/gtest.h>
#include <deque>
#include <vector>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(push_front, push_front)
{
    std::deque<int> d = {2, 3, 4};
    std::vector<int> v = {2, 3, 4};

    push_front()(d, 1);
    push_front()(v, 1);

    ASSERT_EQ(d.size(), 4);
    ASSERT_EQ(v.size(), 4);
    EXPECT_EQ(d.at(0), 1);
    EXPECT_EQ(v.at(0), 1);
}


TEST(push_front, has_push_front)
{
    using deque_type = std::deque<int>;
    using vector_type = std::vector<int>;

    static_assert(has_push_front<deque_type>::value, "");
    static_assert(!has_push_front<vector_type>::value, "");
}
