#pragma once

#include <string>

class CChurch
{
public:
    CChurch();
    void execute();
    void setCityName(const std::string& s);

private:
    std::string _cityName;
};
