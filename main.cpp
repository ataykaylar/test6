#include <iostream>
#include "SimpleReg.h"
#include "SimpleTeam.h"
using namespace std;


#include <iostream>

using namespace std;

int main()
{
    SimpleReg reg;
    reg.addTeam("Team 1","Red", 2020);
    reg.removeTeam("TEAM 1");
    reg.addTeam("Team 3","Blue" ,1906);
     reg.addTeam("Team 2","Blue" ,1906);
     reg.addTeam("TEAM 2","Blue" ,1906);
      reg.addTeam("TEA 2","Blue" ,1906);
  reg.addTeam("Tea2","Blue" ,1906);
    reg.removeTeam("TeAM 3");
    reg.displayAllTeams();


    return 0;
}
