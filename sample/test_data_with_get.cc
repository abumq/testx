#include <cassert>
#include <testx.h>

using namespace muflihun::testx;

static TestDataWithGet<char, bool> isNumTestData = {
    TestCase2('1', true),
    TestCase2('a', false),
//    TestCase2('1', false), // try uncommenting that and see it breaking
};

int main() {
    for (auto& item : isNumTestData) {
        char c = item.get<0, char>();
        bool expected = item.get<1, bool>();
        assert(isdigit(c) == expected);
    }
}
