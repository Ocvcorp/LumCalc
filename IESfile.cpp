#include "IESfile.h"
#include <fstream>


IESfile::IESfile(std::string filePath_):PhotometryFile(filePath_,"IES"), 
    lampNumber(0),
    lampFlux(0.0),
    fluxCoeff(0.0),
    gammaNumber(0),
    azimutCNumber(0),
    cbaType(0), 
    unitSystem(0),
    lumWidth(0.0),
    lumLength(0.0),
    lumHeight(0.0),
    balastCoeff(0.0),
    iesVersion(0.0),
    lumPower(0.0)
{
    std::ifstream file(fullFilePath);
    std::string modelPart1 = "", modelPart2 = "";
    if (file.is_open())
    {
        std::string buff;
        getline(file, buff, '\n');
        int pos; //position of substring in some string
        while ((buff.find("TILT=") == -1) && (!file.eof()))
        {
            commonFuncs::extractInfoAfterTag(manufactor, buff, "[MANUFAC]");
            commonFuncs::extractInfoAfterTag(modelPart1, buff, "[LUMCAT]");
            commonFuncs::extractInfoAfterTag(modelPart2, buff, "[LUMINAIRE]");
            getline(file, buff, '\n');
        }

        file >> lampNumber
            >> lampFlux
            >> fluxCoeff
            >> gammaNumber
            >> azimutCNumber
            >> cbaType
            >> unitSystem
            >> lumWidth
            >> lumLength
            >> lumHeight
            >> balastCoeff
            >> iesVersion
            >> lumPower;
        //gamma (polar) angles
        double buffAngle = -1.0;
        //std::vector<double> outputGammaAngles;
        for (int i = 0; i < gammaNumber; i++) // try with generate and functors
        {
            file >> buffAngle;
            outputGammaAngles.push_back(buffAngle);
        }
        // azimut (C-) angles
        //std::vector<double> outputC_Angles;
        for (int i=0; i<azimutCNumber; i++)
        {
            file >> buffAngle;
            outputC_Angles.push_back(buffAngle);
        }
        // defining symmetry type
        double deltaCAngle = outputC_Angles.back() - outputC_Angles.front();
        if (deltaCAngle == 0)
            symType = SymmetryType::SYMMETRY_AXIAL;
            else if (deltaCAngle <= 90)
                symType = SymmetryType::SYMMETRY_QUADRANT;
                else if (deltaCAngle <= 180)
                    symType = SymmetryType::SYMMETRY_PLANE;
        else
            symType = SymmetryType::SYMMETRY_NONE;
        //output CandelaValues
        int candelaNumber=gammaNumber*azimutCNumber;
        for (int i=0; i<candelaNumber; i++)
        {
            file >> buffAngle;
            outputCandelas.push_back(buffAngle);
        }        
        //geometry
        GeometryType geometryType;
        if (lumWidth==lumLength==0)
            geometryType=GeometryType::GEOMETRY_POINT;
            else if (lumWidth<0||lumLength<0)
                geometryType=GeometryType::GEOMETRY_CIRCLE;
        else
            geometryType=GeometryType::GEOMETRY_SQUARE;   
        lumGeometry=std::make_pair(geometryType,std::vector<double>({lumWidth,lumLength,lumHeight}));

        file.close();
    }
}

IESfile::~IESfile() {};
