#include "Room.h"

int Room::roomDefaultNumber = 1;
Room::Room(double roomL, double roomW, double roomH,
	std::string rNumber, std::string rName, std::string fireCat, std::string descriptn,
	double floorReflCoeff, double wallReflCoeff, double ceilReflCoeff,	double inputMF)
{
	//Room description
	roomNumber=rNumber+std::to_string(roomDefaultNumber++);
	roomName= rName;
	fireCategory= fireCat;
	description= descriptn;
	//Room geometry
	//std::vector<double> corners; //for further versions 
	roomLength=roomL;
	roomWidth=roomW;
	roomHeight=roomH;	
	//data for calculations
	floorReflectionCoef=floorReflCoeff;//floor reflection coefficient
	wallsReflectionCoef=wallReflCoeff;//walls reflection coefficient(first time it's similar for all walls)
	ceilReflectionCoef=ceilReflCoeff;//ceil reflection coefficient
	mf= inputMF; //maintance factor
	std::vector <Luminary> luminaries;
	CalcPlane mainCalcPlane;
}
//setters
void Room::changeRoomLength(double newLength){roomLength=newLength;}
void Room::changeRoomWidth(double newWidth){roomWidth=newWidth;}
void Room::changeRoomHeight(double newHeigth){roomHeight=newHeigth;}
void Room::changeRoomName(std::string newName){roomName=newName;}
void Room::changeRoomNumber(std::string newNumber){roomName=newNumber;}
void Room::changeFireCategory(std::string newFireCat){fireCategory=newFireCat;}
void Room::changeDescription(std::string newDescription){description=newDescription;}
void Room::changeFloorReflectionCoef(double newReflCoeff){floorReflectionCoef=newReflCoeff;}
void Room::changeWallsReflectionCoef(double newReflCoeff){wallsReflectionCoef=newReflCoeff;}
void Room::changeCeilReflectionCoef(double newReflCoeff){ceilReflectionCoef=newReflCoeff;}

void Room::insertLuminaryField(Luminary lumModel, unsigned int nLumRows, unsigned int nLumCols) 
{

	double xShift=getRoomLength()/nLumCols; 
	double yShift=getRoomWidth()/nLumRows;
	double x0(xShift / 2), y0(yShift / 2);
	
	for (int i=0; i<nLumRows; i++)
	{
		for (int j = 0; j < nLumCols; j++)
		{
			//coordinates from origin in left low corner
			lumModel.setCenterCoords2D(std::pair<double,double>{ x0 + xShift * i,y0 + yShift * j });
			luminaries.push_back(lumModel);
		}		
	}
	//
	//luminaries=lumSet;
}
void Room::insertObstructionsToRoom(std::vector <GeometryObject> geomObjSet){obstructions=geomObjSet;}//for further version

//getters
std::string Room::getRoomNumber(){return roomNumber;}
std::string Room::getRoomName(){return roomName;}
std::string Room::getFireCategory(){return fireCategory;}
std::string Room::getDescription(){return description;}
double Room::getRoomLength(){return roomLength;}
double Room::getRoomWidth(){return roomWidth;}
double Room::getRoomHeight(){return roomHeight;}
std::vector<GeometryObject> Room::getObstructions(){return obstructions;}////for further version
double Room::getFloorReflectionCoef(){return floorReflectionCoef;}
double Room::getWallsReflectionCoef(){return wallsReflectionCoef;}
double Room::getCeilReflectionCoef(){return ceilReflectionCoef;}
std::vector<Luminary> Room::getRoomLuminaries(){return luminaries;}
double Room::getMF(){return mf;}
CalcPlane Room::getMainCalcPlane(){return mainCalcPlane;}

/*CalcPlane calculateLightDistribution()
{

}*/

Room::~Room() {}