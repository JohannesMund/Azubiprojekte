#pragma once

class CTask
{
public:
    virtual void execute() = 0;

    bool isFinished();

    CTask();
    virtual ~CTask()
    {
    }

protected:
    bool _isFinished = false;
};
