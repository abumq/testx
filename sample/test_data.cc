#include <cassert>
#include "../src/testx.h"

using namespace muflihun::testx;

int main() {
	TestData<char, bool> IsNumberData = {
		TestCase('1', true),
		TestCase('a', false),
		TestCase('a', true), // this will fail
	};
	
    for (auto& testcase : IsNumberData) {
        char c = testcase.get<0>();
		bool expected = testcase.get<1>();
	    assert(isdigit(c) == expected);
    }
}
