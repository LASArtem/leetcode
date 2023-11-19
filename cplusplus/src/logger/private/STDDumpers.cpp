#include "STDDumpers.hpp"

namespace log {

std::ostream& operator<<(std::ostream& out, const log_size_t& value)
{
    return out << "size: " << value.mValue;
}

std::ostream& operator<<(std::ostream& out, const log_int8_t& value)
{
    return out << std::to_string(static_cast<std::int32_t>(value.mValue));
}

std::ostream& operator<<(std::ostream& out, const log_uint8_t& value)
{
    return out << std::to_string(static_cast<std::uint32_t>(value.mValue));
}

std::ostream& operator<<(std::ostream& out, const log_int32_t& value)
{
    return out << std::to_string(value.mValue);
}

std::ostream& operator<<(std::ostream& out, const log_int64_t& value)
{
    return out << std::to_string(value.mValue);
}

std::ostream& operator<<(std::ostream& out, const log_uint32_t& value)
{
    return out << std::to_string(value.mValue);
}

std::ostream& operator<<(std::ostream& out, const log_bool& value)
{
    return out << (value.mValue ? "true" : "false");
}

std::ostream& operator<<(std::ostream& out, const std::chrono::milliseconds& value)
{
    return out << value.count() << "mSec";
}

std::ostream& operator<<(std::ostream& out, const std::chrono::seconds& value)
{
    return out << value.count() << "sec";
}

std::ostream& operator<<(std::ostream& out, const std::runtime_error& value)
{
    out << "error(" << value.what() << ")";

    return out;
}

} // namespace log