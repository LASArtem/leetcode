#pragma once

#include <algorithm>
#include <chrono>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <optional>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace log {

template<class TupType, size_t... I>
void print_tuple(std::ostream& out, const TupType& _tup, const std::index_sequence<I...> seq)
{
    (void)out;
    (void)seq;
    (void)_tup;
    (..., (out << ((I == 0U) ? "" : ", ") << std::get<I>(_tup)));
}

template<class... T>
void print_tuple(std::ostream& out, const std::tuple<T...>& _tup)
{
    print_tuple(out, _tup, std::make_index_sequence<sizeof...(T)>());
}

struct log_size_t {
    explicit log_size_t(const std::size_t& value)
        : mValue(value)
    {
    }
    std::size_t mValue;
};

template<typename _Key, typename _Tp>
struct log_map {
    explicit log_map(const std::map<_Key, _Tp>& value)
        : mValue(value)
    {
    }
    const std::map<_Key, _Tp>& mValue;
};

template<typename _Key, typename _Tp, uint32_t countToOutput = 0U>
struct log_unordered_map {
    explicit log_unordered_map(const std::unordered_map<_Key, _Tp>& value)
        : mValue(value)
        , mCountToOutput(countToOutput)
    {
    }
    const std::unordered_map<_Key, _Tp>& mValue;
    const uint32_t mCountToOutput;
};

template<typename _Tp>
struct log_set {
    explicit log_set(const std::set<_Tp>& value)
        : mValue(value)
    {
    }
    const std::set<_Tp>& mValue;
};

template<typename _Tp>
struct log_multiset {
    explicit log_multiset(const std::multiset<_Tp>& value)
        : mValue(value)
    {
    }
    const std::multiset<_Tp>& mValue;
};

template<typename _Tp, typename _Hash = std::hash<_Tp>>
struct log_unordered_set {
    explicit log_unordered_set(const std::unordered_set<_Tp, _Hash>& value)
        : mValue(value)
    {
    }
    const std::unordered_set<_Tp, _Hash>& mValue;
};

template<typename _Tp, uint32_t countToOutput = 0U>
struct log_vector {
    explicit log_vector(const std::vector<_Tp>& value)
        : mValue(value)
        , mCountToOutput(countToOutput)
    {
    }
    const std::vector<_Tp>& mValue;
    const uint32_t mCountToOutput;
};

template<typename _Tp>
struct log_deque {
    explicit log_deque(const std::deque<_Tp>& value)
        : mValue(value)
    {
    }
    const std::deque<_Tp>& mValue;
};

template<typename _Tp>
struct log_list {
    explicit log_list(const std::list<_Tp>& value)
        : mValue(value)
    {
    }
    const std::list<_Tp>& mValue;
};

template<typename _Tp>
struct log_initializer_list {
    explicit log_initializer_list(const std::initializer_list<_Tp>& value)
        : mValue(value)
    {
    }
    const std::initializer_list<_Tp>& mValue;
};

std::ostream& operator<<(std::ostream& out, const log_size_t& value);

struct log_int8_t {
    explicit log_int8_t(const std::int8_t& value)
        : mValue(value)
    {
    }
    std::int8_t mValue;
};

std::ostream& operator<<(std::ostream& out, const log_int8_t& value);

struct log_uint8_t {
    explicit log_uint8_t(const std::uint8_t& value)
        : mValue(value)
    {
    }
    std::uint8_t mValue;
};

std::ostream& operator<<(std::ostream& out, const log_uint8_t& value);

struct log_int32_t {
    explicit log_int32_t(const std::int32_t& value)
        : mValue(value)
    {
    }
    std::int32_t mValue;
};

std::ostream& operator<<(std::ostream& out, const log_int32_t& value);
struct log_int64_t {
    explicit log_int64_t(const std::int64_t& value)
        : mValue(value)
    {
    }
    std::int64_t mValue;
};

std::ostream& operator<<(std::ostream& out, const log_int64_t& value);

struct log_uint32_t {
    explicit log_uint32_t(const std::uint32_t& value)
        : mValue(value)
    {
    }

    std::uint32_t mValue;
};

std::ostream& operator<<(std::ostream& out, const log_uint32_t& value);

struct log_bool {

    explicit log_bool(const bool& value)
        : mValue(value)
    {
    }

    bool mValue;
};

std::ostream& operator<<(std::ostream& out, const log_bool& value);

template<typename _Key, typename _Tp>

std::ostream& operator<<(std::ostream& out, const std::map<_Key, _Tp>& _map)
{

    return out << log_map<_Key, _Tp>(_map);
}

template<typename _Key, typename _Tp>

std::ostream& operator<<(std::ostream& out, const log_map<_Key, _Tp>& _map)
{
    out << "{";
    for (auto it = _map.mValue.begin(); it != _map.mValue.end(); ++it) {
        if (it != _map.mValue.begin()) {
            out << ", ";
        }

        out << *it;
    }

    return (out << "}");
}

template<typename _Key, typename _Tp, uint32_t countToOutput = 0U>

std::ostream& operator<<(std::ostream& out, const std::unordered_map<_Key, _Tp>& _map)
{

    return out << log_unordered_map<_Key, _Tp, countToOutput>(_map);
}

template<typename _Key, typename _Tp, uint32_t countToOutput = 0U>

std::ostream& operator<<(std::ostream& out, const log_unordered_map<_Key, _Tp, countToOutput>& _map)
{
    out << "{";

    uint32_t counter = 0U;
    for (auto it = _map.mValue.begin(); it != _map.mValue.end(); ++it) {
        if ((countToOutput > 0U) && (countToOutput <= counter)) {
            break;
        }
        ++counter;

        if (it != _map.mValue.begin()) {
            out << ", ";
        }

        out << *it;
    }

    return (out << "}");
}

template<typename _Key>
std::ostream& operator<<(std::ostream& out, const std::set<_Key>& _set)
{

    return out << log_set<_Key>(_set);
}

template<typename _Key>
std::ostream& operator<<(std::ostream& out, const log_set<_Key>& _set)
{
    out << "{";
    for (auto it = _set.mValue.begin(); it != _set.mValue.end(); ++it) {
        if (it != _set.mValue.begin()) {
            out << ", ";
        }

        out << *it;
    }

    return (out << "}");
}

template<typename _Key>
std::ostream& operator<<(std::ostream& out, const std::multiset<_Key>& _set)
{

    return out << log_multiset<_Key>(_set);
}

template<typename _Key>
std::ostream& operator<<(std::ostream& out, const log_multiset<_Key>& _set)
{
    out << "{";
    for (auto it = _set.mValue.begin(); it != _set.mValue.end(); ++it) {
        if (it != _set.mValue.begin()) {
            out << ", ";
        }

        out << *it;
    }

    return (out << "}");
}

template<typename _Tp, typename _Hash = std::hash<_Tp>>
std::ostream& operator<<(std::ostream& out, const std::unordered_set<_Tp, _Hash>& _set)
{

    return out << log_unordered_set<_Tp, _Hash>(_set);
}

template<typename _Tp, typename _Hash = std::hash<_Tp>>

std::ostream& operator<<(std::ostream& out, const log_unordered_set<_Tp, _Hash>& _set)
{
    out << "{";
    for (auto it = _set.mValue.begin(); it != _set.mValue.end(); ++it) {
        if (it != _set.mValue.begin()) {
            out << ", ";
        }

        out << *it;
    }

    return (out << "}");
}

template<class... Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...>& _tup)
{
    out << "{";
    print_tuple(out, _tup);

    return out << "}";
}

template<typename _Tp, uint32_t countToOutput = 0U>

std::ostream& operator<<(std::ostream& out, const std::vector<_Tp>& _vector)
{

    return out << log_vector<_Tp, countToOutput>(_vector);
}

template<typename _Tp, uint32_t countToOutput = 0U>

std::ostream& operator<<(std::ostream& out, const log_vector<_Tp, countToOutput>& _vector)
{
    out << "{";

    uint32_t counter = 0U;
    for (auto it = _vector.mValue.begin(); it != _vector.mValue.end(); ++it) {
        if ((countToOutput > 0U) && (countToOutput <= counter)) {
            break;
        }
        ++counter;

        if (it != _vector.mValue.begin()) {
            out << ", ";
        }

        out << *it;
    }

    return (out << "}");
}

template<typename _Tp>

std::ostream& operator<<(std::ostream& out, const std::deque<_Tp>& deq)
{

    return out << log_deque<_Tp>(deq);
}

template<typename _Tp>

std::ostream& operator<<(std::ostream& out, const log_deque<_Tp>& deq)
{
    out << "{";
    for (auto it = deq.mValue.begin(); it != deq.mValue.end(); ++it) {
        if (it != deq.mValue.begin()) {
            out << ", ";
        }

        out << *it;
    }

    return (out << "}");
}

template<typename _Tp>

std::ostream& operator<<(std::ostream& out, const std::list<_Tp>& _list)
{

    return out << log_list<_Tp>(_list);
}

template<typename _Tp>

std::ostream& operator<<(std::ostream& out, const log_list<_Tp>& _list)
{
    out << "{";
    for (auto it = _list.mValue.begin(); it != _list.mValue.end(); ++it) {
        if (it != _list.mValue.begin()) {
            out << ", ";
        }

        out << *it;
    }

    return (out << "}");
}

template<typename _Tp>

std::ostream& operator<<(std::ostream& out, const std::initializer_list<_Tp>& _list)
{

    return out << log_initializer_list<_Tp>(_list);
}

template<typename _Tp>

std::ostream& operator<<(std::ostream& out, const log_initializer_list<_Tp>& _list)
{
    out << "{";
    for (auto it = _list.mValue.begin(); it != _list.mValue.end(); ++it) {
        if (it != _list.mValue.begin()) {
            out << ", ";
        }

        out << *it;
    }

    return (out << "}");
}

template<typename _Tp1, typename _Tp2>

std::ostream& operator<<(std::ostream& out, const std::pair<_Tp1, _Tp2>& _pair)
{

    return out << "{" << _pair.first << ", " << _pair.second << "}";
}

template<typename _Tp>

std::ostream& operator<<(std::ostream& out, const std::function<_Tp>& value)
{
    if (!value) {
        out << "nullfn";
    } else {
        out << "__lambda(...)";
    }

    return out;
}

template<typename _Tp>

std::ostream& operator<<(std::ostream& out, const std::unique_ptr<_Tp>& value)
{
    if (!value) {
        out << "nullptr";
    } else {
        out << value.get() << "(" << *value << ")";
    }

    return out;
}

template<typename _Tp>

std::ostream& operator<<(std::ostream& out, const std::shared_ptr<_Tp>& value)
{
    if (!value) {
        out << "nullptr";
    } else {

        out << value.get() << "(" << *value << ")";
    }

    return out;
}

template<typename _Tp = bool>

std::ostream& operator<<(std::ostream& out, const std::optional<bool>& value)
{
    if (value.has_value()) {
        out << log_bool(value.value());
    } else {
        out << "nullopt";
    }

    return out;
}

template<typename _Tp>

std::ostream& operator<<(std::ostream& out, const std::optional<_Tp>& value)
{
    if (value.has_value()) {
        out << value.value();
    } else {
        out << "nullopt";
    }

    return out;
}

template<typename _Tp>

std::ostream& operator<<(std::ostream& out, const std::weak_ptr<_Tp>& value)
{

    return out << value.lock();
}

std::ostream& operator<<(std::ostream& out, const std::chrono::milliseconds& value);
std::ostream& operator<<(std::ostream& out, const std::chrono::seconds& value);
std::ostream& operator<<(std::ostream& out, const std::runtime_error& value);

} // namespace log