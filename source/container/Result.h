#pragma once

namespace drgn
{

class Result
{
protected:
    Result(bool success)
        : m_isSuccess(success)
    {}

public:
    bool IsSuccess()
    {
        return m_isSuccess;
    }

private:
    bool m_isSuccess;
};


}