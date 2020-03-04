#include "PhotometryFile.h"

PhotometryFile::PhotometryFile
(
	std::string fullFilePath_,
	std::string formatName_
) :
	fullFilePath(fullFilePath_),
	formatName(formatName_)
{
	fileName = "";
	manufactor = "";
	model = "";
	outputFlux = 0.0;
	symType = SymmetryType::SYMMETRY_NONE;
	std::vector<double> outputCandelas;
	std::vector<double> outputGammaAngles;
	std::vector<double> outputC_Angles;
	lumGeometry=std::make_pair(GeometryType::GEOMETRY_POINT, std::vector<double>({0.0}));
}

double PhotometryFile::getOutputFlux() { return outputFlux; }
std::pair <GeometryType, std::vector<double>> PhotometryFile::getLumGeometry() { return lumGeometry; }

void PhotometryFile::plotCandelas(int azimutIndex1, int azimutIndex2)
{
	double azimutC1=outputC_Angles.at(azimutIndex1);
	double azimutC2=outputC_Angles.at(azimutIndex2);
	
}



PhotometryFile::~PhotometryFile(){}