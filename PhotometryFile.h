#pragma once
#include <string>
#include <vector>

enum class SymmetryType
{
	SYMMETRY_AXIAL,
	SYMMETRY_QUADRANT,
	SYMMETRY_PLANE,
	SYMMETRY_NONE //asymmetric
};

enum class GeometryType
{
	GEOMETRY_POINT,
	GEOMETRY_SQUARE,
	GEOMETRY_CIRCLE
};

class PhotometryFile
{
public:
	PhotometryFile
	(
		std::string fullFilePath_ = "",
		std::string formatName_ = ""
	);
	double getOutputFlux();
	std::pair <GeometryType, std::vector<double>> getLumGeometry();
	~PhotometryFile();
protected:
	std::string fullFilePath;
	std::string fileName;
	std::string formatName;
	std::string manufactor;
	std::string model;
	SymmetryType symType;
	double outputFlux;
	std::vector<double> outputCandelas;//absolute candela values
	std::vector<double> outputGammaAngles;// Gamma angles for C-plane
	std::vector<double> outputC_Angles;// C angles
	std::pair <GeometryType, std::vector<double>> lumGeometry;//geometry data

	void plotCandelas(int azimutIndex1, int azimutIndex2);

};

