/* Given three points, find radius and center of circle */

double centx, centy, r;

void circle_vvv()
{
    double bx1 = (double)ax; double by1 = (double)ay;
    double cx1 = (double)bx; double cy1 = (double)by;
    double dx1 = (double)cx; double dy1 = (double)cy;
    double temp = cx1*cx1+cy1*cy1;
    double bc1 = (bx1*bx1 + by1*by1 - temp)/2.0;
    double cd1 = (temp - dx1*dx1 - dy1*dy1)/2.0;
    double det = (bx1-cx1)*(cy1-dy1)-(cx1-dx1)*(by1-cy1);
    det = 1/det;
    centx = (bc1*(cy1-dy1)-cd1*(by1-cy1))*det;
    centy = ((bx1-cx1)*cd1-(cx1-dx1)*bc1)*det;
    r = sqrt((cx-bx)*(cx-bx)+(cy-by)*(cy-by));
    return;
}
