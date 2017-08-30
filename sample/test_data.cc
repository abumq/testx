#include <cassert>
#include <testx.h>

using namespace muflihun::testx;

static TestData<char, bool> isNumTestData = {
    TestCase('1', true),
    TestCase('a', false),
//    TestCase('1', false), // try uncommenting that and see it breaking
};

int main() {
    for (auto& item : isNumTestData) {
        char c = std::get<0>(item);
        bool expected = std::get<1>(item);
        assert(isdigit(c) == expected);
    }
}
