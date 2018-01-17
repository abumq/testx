#include <cassert>
#include <string>
#include "../src/testx.h"

using namespace muflihun::testx;

int main() {
    TestData<char, bool> IsNumberData = {
        TestCase('1', true),
        TestCase('a', false),
        //TestCase('a', true), // this will fail - uncomment to witness
    };
    
    for (auto& testcase : IsNumberData) {
        char c = testcase.get<0>();
        bool expected = testcase.get<1>();
        assert(isdigit(c) == expected);
    }

    static TestData<std::string, bool> SecondIsNumberData = {
        TestCase(std::string("1"), true), // either explicitly construct
		TestCase<std::string, bool>("2", true), // or do this
    };
}
