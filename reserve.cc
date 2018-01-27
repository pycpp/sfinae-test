//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `reserve` and `has_reserve` unittests.
 */

#include <pycpp/sfinae/reserve.h>
#include <gtest/gtest.h>
#include <deque>
#include <vector>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(reserve, reserve)
{
    std::deque<int> deq;
    std::vector<int> vec;

    reserve()(deq, 10);
    reserve()(vec, 10);
}


TEST(reserve, has_reserve)
{
    using deque_type = std::deque<int>;
    using vector_type = std::vector<int>;

    static_assert(!has_reserve<deque_type>::value, "");
    static_assert(has_reserve<vector_type>::value, "");
}
