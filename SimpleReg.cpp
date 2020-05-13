#include "SimpleReg.h"
#include <iostream>
using namespace std;

SimpleReg::SimpleReg()
{
    head = NULL;
    teamCount = 0;
}

void SimpleReg::addTeam( const string tName, const string tColor, const int tyear )
{
    Node *newPtr = new Node;
    Node *cur = findTeam(tName);
    (newPtr -> t).setName(tName);
    (newPtr -> t).setColor(tColor);
    (newPtr -> t).setYear(tyear);

    if(tyear < 1800 || tyear > 2020)
        cout << "Please enter a valid year"<<endl;
    else if(cur != NULL)
    {
        cout << "Please enter a unique team!" << endl;
        return;
    }
    else if(head == NULL)
    {
        head = newPtr;
        newPtr->next = NULL;
        teamCount++;
        return;
    }
    else if(ifStringsEqual(tName,0) == "")
    {
        for(Node *ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if(ptr->next == NULL)
            {
                ptr->next = newPtr;
                newPtr->next = NULL;
                teamCount++;
                return;

            }
        }
    }

}

void SimpleReg::removeTeam( const string teamName )
{
    Node *deletePtr = findTeam(teamName);
    Node *prev;
    if(ifStringsEqual(teamName, 1) == "" )
    {
        cout << "Please enter a existing team name!" << endl;
        return;
    }
    if(ifStringsEqual(teamName, 1) != "")
    {
        string temp = ifStringsEqual(teamName, 1);
        deletePtr = findTeam(temp);
    }
    if((deletePtr->t).getName() == (head->t).getName())
    {
        prev = head;
        prev = head->next;
        head->next = NULL;
        head = prev;
        teamCount--;
    }
    else
    {
        for(Node *ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if(ptr->next == deletePtr)
            {
                prev = ptr;
            }
        }
        prev->next = deletePtr->next;
        deletePtr->next = NULL;
        delete deletePtr;
        deletePtr = NULL;
        teamCount--;
    }

}

void SimpleReg::displayAllTeams() const
{
    for(Node *printPtr = head; printPtr!=NULL; printPtr = printPtr->next)
        cout << "Team: "<< (printPtr->t).getName() << " Color: "<< printPtr->t.getColor() << " Year: " <<printPtr->t.getYear()<<endl;
    if(head == NULL){
        cout <<"-EMPTY-"<<endl;
    }

}
SimpleReg::Node *SimpleReg::findTeam(const string teamName) const
{
    for (Node *skip = head ; skip != NULL; skip = skip->next)
    {
        if(skip->t.getName() == teamName )
            return skip;
    }

    return NULL;
}


string SimpleReg::ifStringsEqual(const string string_1, const bool func) const
{
    unsigned int counter = 0;
    for(Node *lowPtr = head; lowPtr !=NULL ; lowPtr = lowPtr->next)
    {
        if((lowPtr->t).getName().size() == string_1.size())
        {
            for(unsigned int i = 0; i < string_1.size(); i++)
            {
                if(tolower(string_1[i]) == tolower((lowPtr->t).getName()[i]))
                {
                    counter++;

                }
                if(counter == string_1.size() && func == 0)
                {
                    cout << "Please enter a unique team for " << string_1<<endl;
                    return string_1;
                }

                if(counter == string_1.size() && func == 1)
                {
                    return lowPtr->t.getName();
                }
            }
            counter = 0;
        }
    }
    return "";
}



SimpleReg::~SimpleReg()
{
    Node* current = head;
    while( current != NULL )
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = 0;
}

