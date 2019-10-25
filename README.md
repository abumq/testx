﷽

# Overview
TestX is extremely simple header to create typesafe test data.

[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/amrayn/testx/blob/master/LICENSE)
[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://amrayn.com/donate)

# Usage

You can see practical usage on residue tests [basic](https://github.com/amrayn/residue/blob/develop/test/utils-test.h#L65) and [using wrapper](https://github.com/amrayn/residue/blob/develop/test/url-test.h)

```c++
#include <testx.h>

using namespace amrayn::testx;

//              c    expected
static TestData<char, bool> IsDigitTestData = {
  { '1', true },
  { 'a', false },
}
```

You can use `std::get` to get item without specifying the type

```c++
void testNumber() {
    for (auto& item : IsDigitTestData) {
        auto c = item.get<0>();
        bool expected = item.get<1>();
        assert(isdigit(c) == expected));
    }

}
```

# Explicit Type
You can specify the test case type and re-use it using wrapper types (`TestDataW` and `TestCaseW`)

```
    
using URLTestCase = TestCase<std::string, std::string, std::string, std::string, std::string, std::string>;
 
        // Notice the TestDataW instead of TestData
        // if we used TestData we would do:
        //         TestData<std::string, std::string, std::string, std::string, std::string, std::string>
static TestDataW<URLTestCase> URLTestData = {
    { "https://192.168.1.100:3322/p1?q=1", "https", "192.168.1.100", "3322", "/p1", "q=1" },
    { "http://192.168.1.19:3000/p2?q2=2", "http", "192.168.1.19", "3000", "/p2", "q2=2" },
    { "HTTP://LOCALHOST:3000/PATH?QUERY1=1&QUERY2=2", "HTTP", "LOCALHOST", "3000", "/PATH", "QUERY1=1&QUERY2=2" },
    { "http://localhost:3000/path?query1=1&query2=2", "http", "localhost", "3000", "/path", "query1=1&query2=2" },
    { "http://localhost", "http", "localhost", "80", "", "" },
    { "http://localhost:3000", "http", "localhost", "3000", "", "" },
    { "http://localhost:3000/", "http", "localhost", "3000", "/", "" },
    { "localhost:3000/", "http", "localhost", "3000", "/", "" },
    { "localhost", "http", "localhost", "80", "", "" },
    { "http://localhost", "http", "localhost", "80", "", "" },
    { "https://localhost", "https", "localhost", "443", "", "" },
    { "localhost/", "http", "localhost", "80", "/", "" },
    { "HTTP://LOCALHOST:3000/PATH?QUERY1=1&QUERY2=2", "HTTP", "LOCALHOST", "3000", "/PATH", "QUERY1=1&QUERY2=2"},

};

void testUrl(const Url& url, const URLTestCase& item) // using URLTestCase that was previously defined
{
    ASSERT_EQ(url.protocol(), item.get<1>());
    ASSERT_EQ(url.host(), item.get<2>());
    ASSERT_EQ(url.port(), item.get<3>());
    ASSERT_EQ(url.path(), item.get<4>());
    ASSERT_EQ(url.query(), item.get<5>());
    ASSERT_TRUE(url.isValid());
}

TEST(UrlTest, TestUrls)
{
    for (const auto& item : URLTestData) {
        Url url(item.get<0>());
        testUrl(url, item);
    }
}
```

# License
```
The MIT License (MIT)

Copyright (c) 2017-present Amrayn Web Services

https://github.com/amrayn/testx
https://amrayn.com

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```
