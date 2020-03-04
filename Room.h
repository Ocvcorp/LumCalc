#pragma once
#include "GeometryObject.h"
#include "Luminary.h"
#include "CalcPlane.h"
#include <iostream>
//#include <vector>

class Room
{
public:
	Room(double, double, double,
		std::string rNum="Room ",
		std::string rName="Room",
		std::string fC="Д", std::string descr="",
		double fRC=20, double wRC=50, double cRC=70,
		double mF=0.71
		);	
	static int roomDefaultNumber;
	//setters
	void changeRoomLength(double);
	void changeRoomWidth(double);
	void changeRoomHeight(double);
	void changeRoomNumber(std::string);
	void changeRoomName(std::string);
	void changeFireCategory(std::string);
	void changeDescription(std::string);
	void changeFloorReflectionCoef(double);
	void changeWallsReflectionCoef(double);
	void changeCeilReflectionCoef(double);
	
	void insertLuminaryField(Luminary, unsigned int=1, unsigned int=1);//inserts luminaries to room directly from Form. No need of checking luminaries inside the room
	void insertObstructionsToRoom(std::vector <GeometryObject>);//for further radiocity version
	//CalcPlane calculateLightDistribution();
	//getters
	std::string getRoomNumber();
	std::string getRoomName();
	std::string getFireCategory();
	std::string getDescription();
	//std::vector<double> getCorners();
	double getRoomLength();
	double getRoomWidth();
	double getRoomHeight();
	std::vector<GeometryObject> getObstructions();//for further version
	double getFloorReflectionCoef();
	double getWallsReflectionCoef();
	double getCeilReflectionCoef();

	std::vector<Luminary> getRoomLuminaries();
	double getMF();
	CalcPlane getMainCalcPlane();
	~Room();
//Room description
private:
	
	std::string roomNumber;
	std::string roomName;
	std::string description;
	std::string fireCategory;
	//Room geometry
	//std::vector<double> corners; //for further versions 
	double roomLength;
	double roomWidth;
	double roomHeight;
	std::vector<GeometryObject> obstructions;
	//data for calculations
	double floorReflectionCoef;//floor reflection coefficient
	double wallsReflectionCoef;//walls reflection coefficient(first time it's similar for all walls)
	double ceilReflectionCoef;//ceil reflection coefficient
	
	std::vector <Luminary> luminaries;
	double mf; //maintance factor
	CalcPlane mainCalcPlane;
	/* vector <Luminary>setRoomLuminarieField
(vector <Luminary> allLums);//further method: it defines which luminaries frome scene included into room boundaries;
it runs automatically, and if it's needed,can be run by user (for example, if there are too many luminaries in scene)
*/
};
