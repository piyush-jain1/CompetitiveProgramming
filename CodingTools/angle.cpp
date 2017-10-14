double angl(int ax, int ay, int bx, int by, int cx, int cy)
{
	double abx = bx - ax;
    double aby = by - ay;

    double cbx = bx - cx;
    double cby = by - cy;
	double angba = atan2(aby, abx);
	double angbc = atan2(cby, cbx);
	double rslt = angba - angbc;
	double rs = (rslt * 180.0) / PI;
	if(rs < 0.0)	rs += 360.0;
	return rs;
}