// function to check if two numbers are coprime

bool coprime(long long int u , long long int v)
{
	if( ((u & 1) == 0) && ( (v & 1) == 0) ) return false;

	while ((u & 1)==0) u >>= 1;
	if(u == 1) return true;

	do
	{
		while (( v & 1 ) == 0) v >>= 1;
		if ( v == 1 ) return true;

		if( u > v ) { long t = v; v = u; u = t; }
		v -= u;
	} while( v != 0);

	return false; 
}