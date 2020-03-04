#pragma once
#include "PhotometryFile.h"
#include "IESfile.h"
#include "LDTfile.h"


class Luminary
{
public:
    //
    Luminary(IESfile photometry_, std::pair<double,double> centerCoords_={0.0, 0.0}, double lumHeight_=0.0);//IES
    Luminary(LDTfile photometry_, std::pair<double,double> centerCoords_={0.0, 0.0}, double lumHeight_=0.0);//LDT
    //photometry data for calculation 
    //getters
    double getFlux();
    std::pair<double, double> getCenterCoords2D();
    double getLumHeight();
    std::pair <GeometryType, std::vector<double>> getLumGeometry();
    //setters
    void setFlux(double);
    void setCenterCoords2D(std::pair<double,double>);
    void setLumHeight(double);
    void setLumGeometry(std::pair <GeometryType, std::vector<double>>);
    ~Luminary();
private:
    //photometry data for calculation  
    double flux;
    //geometry data for drawing
    std::pair<double,double> centerCoords2D;
    double lumHeight;
    std::pair <GeometryType, std::vector<double>> lumGeometry;
};

