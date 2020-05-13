#ifndef SIMPLETEAM_H
#define SIMPLETEAM_H

#include <string>
using namespace std;
class Team
{
public:
    Team();
    Team(const string name, const string color, const int year);
    string getColor() const;
    void setColor(const string color);
    string getName() const;
    void setName(const string name);
    int getYear() const;
    void setYear(const int year);
private:
    string name;
    string color;
    int year;
};
#endif
