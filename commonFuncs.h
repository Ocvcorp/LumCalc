#pragma once
#include <string>
#include <map>

namespace commonFuncs 
{
void extractInfoAfterTag(std::string& extractedInfo, std::string strWithTag, std::string tag);
}

double linearInterpolation(double q11, double q12, double q21, double q22, 
                            double x1, double x2, double y1, double y2, 
                            double x, double y);/*bilinear interpolation (https://helloacm.com) in (x,y), 
                                              q... - values in 4 points (with combination of x1,x2,y1,y2 coordinates)
                                              coditions to prevent deviding by zero: x1!=x2, y1!=y2*/
double linearInterpolation(double q1, double q2, 
                    double xy1, double xy2, 
                    double xy);/*linear interpolation in xy(the abscissa may be both x and y)
                                q1, q2 - values for 2 abscissas (xy1 and xy2)*/
                              