#include "commonFuncs.h"

void commonFuncs::extractInfoAfterTag(std::string& extractedInfo, std::string strWithTag, std::string tag)
{
    int pos = strWithTag.rfind(tag);
    if ((pos != -1) && (strWithTag.size() > tag.size()))
        extractedInfo = strWithTag.substr(pos + tag.size());
}

double linearInterpolation(double q11, double q12, double q21, double q22, double x1, double x2, double y1, double y2, double x, double y) 
{
    double x2x1, y2y1, x2x, y2y, yy1, xx1;
    x2x1 = x2 - x1;
    y2y1 = y2 - y1;
    x2x = x2 - x;
    y2y = y2 - y;
    yy1 = y - y1;
    xx1 = x - x1;
    return 1.0 / (x2x1 * y2y1) * (
        q11 * x2x * y2y +
        q21 * xx1 * y2y +
        q12 * x2x * yy1 +
        q22 * xx1 * yy1
    );
}

double linearInterpolation(double q1, double q2, 
                    double xy1, double xy2, 
                    double xy)
{
    return (q2-q1)*(xy-xy1)/(xy2-xy1)+q1;
}

