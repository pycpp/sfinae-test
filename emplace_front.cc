//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `emplace_front` and `has_emplace_front` unittests.
 */

#include <pycpp/sfinae/emplace_front.h>
#include <gtest/gtest.h>
#include <deque>
#include <vector>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(emplace_front, emplace_front)
{
    std::deque<int> d = {2, 3, 4};
    std::vector<int> v = {2, 3, 4};

    emplace_front()(d, 1);
    emplace_front()(v, 1);

    ASSERT_EQ(d.size(), 4);
    ASSERT_EQ(v.size(), 4);
    EXPECT_EQ(d.at(0), 1);
    EXPECT_EQ(v.at(0), 1);
}


TEST(emplace_front, has_emplace_front)
{
    using deque_type = std::deque<int>;
    using vector_type = std::vector<int>;

    static_assert(has_emplace_front<deque_type>::value, "");
    static_assert(!has_emplace_front<vector_type>::value, "");
}
