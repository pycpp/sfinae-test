//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `push_back` and `has_push_back` unittests.
 */

#include <pycpp/sfinae/push_back.h>
#include <gtest/gtest.h>
#include <unordered_set>
#include <vector>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(push_back, push_back)
{
    std::unordered_set<int> s = {2, 3, 4};
    std::vector<int> v = {2, 3, 4};

    push_back()(s, 1);
    push_back()(v, 1);

    ASSERT_EQ(s.size(), 4);
    ASSERT_EQ(v.size(), 4);
    EXPECT_TRUE(s.find(1) != s.end());
    EXPECT_EQ(v.at(3), 1);
}


TEST(push_back, has_push_back)
{
    using set_type = std::unordered_set<int>;
    using vector_type = std::vector<int>;

    static_assert(!has_push_back<set_type>::value, "");
    static_assert(has_push_back<vector_type>::value, "");
}
