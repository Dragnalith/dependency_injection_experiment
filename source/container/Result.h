#pragma once

namespace drgn
{

class Result
{
public:
    Result(bool success, const char* message)
        : m_isSuccess(success)
        , m_message(message)
    {}

    bool IsSuccess()
    {
        return m_isSuccess;
    }

private:
    bool m_isSuccess;
    const char* m_message;
};

class ResultSuccess
{
public:
    operator Result()
    {
        return Result(true, "Success");
    }
};

#define DRGN_RETURN_IF_FAILURE(r) do { if (!r.IsSuccess()) { return r; } } while (false)


}
