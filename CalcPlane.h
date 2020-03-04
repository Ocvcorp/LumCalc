#pragma once
#include <string>
#include <vector>
class CalcPlane
{
	public:
		CalcPlane(std::string cpN="Calculation Plane ", double cpH=0.8);	
		static int cpNumber;
		//getters
		std::string getCalcPlaneName();
		double getCalcPlaneHeight();
		std::vector<std::vector<double>> getLuxValues();//returns illumination values vector and a number of rows to transform in matrix
		//setters
		void changeCalcPlaneName(std::string);
		void changeCalcPlaneHeight(double);
		void changeIllumValues(std::vector<std::vector<double>>);		
	private:		
		std::string calcPlaneName;
		double calcPlaneHeight;
		std::vector<std::vector<double>> illuminationValues;
		
};

