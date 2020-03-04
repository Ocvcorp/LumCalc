#include "CalcPlane.h"
int CalcPlane::cpNumber=1;
CalcPlane::CalcPlane(std::string cpName, double cpH):
    calcPlaneName(cpName+std::to_string(cpNumber++)), 
    calcPlaneHeight(cpH),
    illuminationValues({{0.0}}) 
{}
//setters
void CalcPlane::changeCalcPlaneName(std::string newName) { calcPlaneName = newName; }
void CalcPlane::changeCalcPlaneHeight(double newHeight) { calcPlaneHeight=newHeight; }
void CalcPlane::changeIllumValues(std::vector<std::vector<double>> newIllumValues){illuminationValues=newIllumValues;}
//getters
std::string CalcPlane::getCalcPlaneName(){return calcPlaneName;}
double CalcPlane::getCalcPlaneHeight(){return calcPlaneHeight;}
std::vector<std::vector<double>> CalcPlane::getLuxValues(){return illuminationValues;}
