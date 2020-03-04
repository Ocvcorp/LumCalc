#pragma once
#include "PhotometryFile.h"
#include "commonFuncs.h"

class IESfile: public PhotometryFile
{
public:
	IESfile(std::string filePath_="");//reads file to ies structure
	~IESfile();
private:
    int lampNumber;
    double lampFlux;
    double fluxCoeff;
    int gammaNumber;
    int azimutCNumber;
    int cbaType; //photometry measuring type (C,gamma)/(B,beta)/(A,alpha)
    int unitSystem; // feets/meters
    double lumWidth;
    double lumLength;
    double lumHeight;
    double balastCoeff;
    double iesVersion;
    double lumPower;

};

