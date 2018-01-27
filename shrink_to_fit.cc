//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `shrink_to_fit` and `has_shrink_to_fit` unittests.
 */

#include <pycpp/sfinae/shrink_to_fit.h>
#include <gtest/gtest.h>
#include <list>
#include <vector>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(shrink_to_fit, shrink_to_fit)
{
    std::list<int> l;
    std::vector<int> v;

    shrink_to_fit()(l);
    shrink_to_fit()(v);
}


TEST(shrink_to_fit, has_shrink_to_fit)
{
    using list_type = std::list<int>;
    using vector_type = std::vector<int>;

    static_assert(!has_shrink_to_fit<list_type>::value, "");
    static_assert(has_shrink_to_fit<vector_type>::value, "");
}
