# Overview
TestX is very simple single header to create typesafe test data for your testing framework. You simply make test data by specifying the types for each parameter and use them accordingly

By default, header comes with google testing header but feel free to change it to match your need.

# Usage

## Basic

```c++
#include <testx.h>

using namespace muflihun::testx;

static TestXData<const char*, bool> IsNumberTestData = {
  TestCase("124", true),
  TestCase("abc", false),
}
```

You can use `std::get` to get item without specifying the type

```c++
// this is google testing framework TEST macro
TEST(NumberUtils, IsNumber)
{
    for (auto& item : IsNumberTestData) {
        bool b = std::get<item>(1);
    }
    
}
```

## Using Custom Wrapper
You can also define test data using `TestDataWithGet` and `TestCase2` that contains `get` for each item.

```c++
#include <testx.h>

using namespace muflihun::testx;

static TestDataWithGet<const char*, bool> IsNumberTestData = {
  TestCase2("124", true),
  TestCase2("abc", false),
}
```

Now you can use `item.get<idx, type>` to get the item

```c++
// this is google testing framework TEST macro
TEST(NumberUtils, IsNumber)
{
    for (auto& item : IsNumberTestData) {
        bool b = item.get<1, bool>();
    }
    
}
```

# License
```
The MIT License (MIT)

Copyright (c) 2017 Muflihun Labs

https://github.com/muflihun/testx
https://muflihun.github.io
https://muflihun.com

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
