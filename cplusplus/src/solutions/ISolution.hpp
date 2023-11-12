#pragma once

class ISolution {
public:
    virtual ~ISolution() = default;

    virtual bool isReady() const = 0;
    virtual void describeIssue() const = 0;
    virtual void run() = 0;
};