ll numbered(string cake[])
{	
	ll num = 0;
	ll idx=1;
	FORD(i,3,0)
	{
		FORD(j,3,0)
		{	
			// cout<<cake[i][j];
			if(cake[i][j] == '1')
			{
				num += idx ;
			}
			idx *= 2;
		}
		// cout<<endl;
	}

	return num;
} 