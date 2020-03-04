#include "Luminary.h"

Luminary::Luminary(IESfile photometry_, std::pair<double,double> centerCoords_, double lumHeight_):
    flux(photometry_.getOutputFlux()),
    centerCoords2D(centerCoords_),
    lumHeight(lumHeight_),
    lumGeometry(photometry_.getLumGeometry()){}
Luminary::Luminary(LDTfile photometry_, std::pair<double,double> centerCoords_, double lumHeight_):
    flux(photometry_.getOutputFlux()),
    centerCoords2D(centerCoords_),
    lumHeight(lumHeight_),
    lumGeometry(photometry_.getLumGeometry()){}

//getters
double Luminary::getFlux() { return flux; }
std::pair<double,double> Luminary::getCenterCoords2D() { return centerCoords2D; }
double Luminary::getLumHeight(){return lumHeight;}
std::pair <GeometryType, std::vector<double>> Luminary::getLumGeometry() { return lumGeometry; }
//setters
void Luminary::setFlux(double newFlux) { flux = newFlux; }
void Luminary::setCenterCoords2D(std::pair<double,double> newCoords) { centerCoords2D = newCoords; }
void Luminary::setLumHeight(double newHeight){lumHeight=newHeight;}
void Luminary::setLumGeometry(std::pair <GeometryType, std::vector<double>> newGeometry) { lumGeometry=newGeometry; }

Luminary::~Luminary(){}