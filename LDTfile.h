#pragma once
#include "PhotometryFile.h"


class LDTfile: public PhotometryFile
{
public:
	LDTfile(std::string filePath_="");//reads file to ldt structure
	~LDTfile();
};

