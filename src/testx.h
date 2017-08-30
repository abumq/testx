//
//  Bismillah ar-Rahmaan ar-Raheem
//
//  TestX 1.0.0
//  Single header, header only helper for creating test data
//
//  Copyright (c) 2017 Muflihun Labs
//
//  This library is released under the MIT Licence.
//
//  https://github.com/muflihun/testx
//  https://muflihun.github.io
//  http://muflihun.com
//
#ifndef MUFLIHUN_TEST_X_H
#define MUFLIHUN_TEST_X_H

#include <initializer_list>
#include <tuple>
#include <vector>

namespace muflihun {
namespace testx {

///
/// \brief Custom testx case, a wrapper for tuple with get function
///
template <typename... TCase>
class CustomTestXCase {
public:
    CustomTestXCase(TCase... t) { m_wrapper = std::make_tuple(t...); }
    template <int index, typename TResult>
    TResult get() const { return std::get<index>(m_wrapper); }

private:
    std::tuple<TCase...> m_wrapper;
};

///
/// \brief Generic class for test data that needs test case type
///  implementation.
///
/// \note Please do not use this directly. Please refer to the docs
/// for details
///
template <typename TestCaseType, typename... T>
class GenericTestXData {
public:
    using Item = TestCaseType;
    using Container = std::vector<Item>;


    template <typename TItem>
    GenericTestXData(std::initializer_list<TItem> t) : m_testCases(t) {
    }

    GenericTestXData(T... t) {
        m_testCases.push_back(Item(t...));
    }

    virtual ~GenericTestXData() {}

    typename Container::iterator begin() { return m_testCases.begin(); }
    typename Container::iterator end() { return m_testCases.end(); }
private:
    Container m_testCases;
};

template <typename... T>
using TestData = GenericTestXData<std::tuple<T...>, T...>;

template <typename... T>
typename TestData<T...>::Item TestCase(T... f) {
    return typename TestData<T...>::Item(f...);
}

template <typename... T>
using TestDataWithGet = GenericTestXData<CustomTestXCase<T...>, T...>;

template <typename... T>
typename TestDataWithGet<T...>::Item TestCase2(T... f) {
    return typename TestDataWithGet<T...>::Item(f...);
}

} // namespace testx
} // namespace muflihun

#endif // MUFLIHUN_TEST_X_H
