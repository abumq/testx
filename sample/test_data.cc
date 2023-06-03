#include <cassert>
#include <string>
#include "../src/testx.h"

using namespace testx;

void containsNumberTest()
{
    // a sample function
    auto containsNumber = [](const std::string& s) -> bool {
        for (auto& c : s) {
            if (isdigit(c)) {
                return true;
            }
        }
        return false;
    };
    
    // sample test data
    TestData<std::string, bool> ContainsNumberData = {
        { "abc123", true },
        { "abc", false },
    };
    
    for (auto& testcase : ContainsNumberData) {
        auto s = testcase.get<0>();
        auto expected = testcase.get<1>();
        assert(containsNumber(s) == expected);
    }

}

void isNumberTest()
{
    TestData<char, bool> IsNumberData = {
        { '1', true },
        { 'a', false },
    };
    
    for (auto& testcase : IsNumberData) {
        char c = testcase.get<0>();
        bool expected = testcase.get<1>();
        assert(isdigit(c) == expected);
    }
}

int main()
{
    containsNumberTest();
    isNumberTest();
}
