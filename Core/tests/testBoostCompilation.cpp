//
// Created by marmus_a on 07/02/18.
//

#define BOOST_TEST_DYN_LINK           // A ajouter dans le cas d'une liaison dynamique à Boost Test
#define BOOST_TEST_MODULE TestBoost

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(TestingBoostCompilation) {
    BOOST_CHECK(true);
}
