﷽

# Overview
TestX is very simple single header to create typesafe test data for your testing framework. You simply make test data by specifying the types for each parameter and use them accordingly

[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/muflihun/testx/blob/master/LICENSE)
[![Donate](https://img.shields.io/badge/Donate-PayPal-green.svg)](https://www.paypal.me/MuflihunDotCom/25)

# Usage

```c++
#include <testx.h>

using namespace muflihun::testx;

//              c    expected
static TestData<char, bool> IsDigitTestData = {
  TestCase('1', true),
  TestCase('a', false),
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

You may have trouble creating some test cases that contain implicit contructors e.g, `std::string`

For them you will need to either specify the type or explicitely contruct the object:

```
    TestCase<std::string, bool>("string", true);
```

or

```
    TestCase(std::string("string"), true);
```

# License
```
The MIT License (MIT)

Copyright (c) 2017-present Muflihun Labs

https://github.com/muflihun/testx
https://muflihun.github.io/
https://muflihun.com/

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
