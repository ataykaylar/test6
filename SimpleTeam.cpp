#include "SimpleTeam.h"

Team::Team()
{
    color = "";
    name = "";
    year = 0;
}

Team::Team(const string name, const string color, const int year)
{
    this->name = name;
    this->color = color;
    this->year = year;

}


string Team::getColor() const
{
    return color;

}

void Team::setColor(const string color)
{
    this->color = color;
}

string Team::getName() const
{
    return name;
}

void Team::setName(const string name)
{
    this->name = name;

}


int Team::getYear() const
{
    return year;
}

void Team::setYear(const int year)
{
    this->year = year;

}



