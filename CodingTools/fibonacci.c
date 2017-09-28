    const int MAX_SMALL_SIZE = 1000;
     
    int fibonacci(int n) {
    	if n < 0 {
    		int sign = n % 2 == 0? -1 : 1;
    		return fibonacci(-n) * sign;
    	}
    	if n < MAX_SMALL_SIZE {
    		return fibonacci_small(n);
    	}
    	else 
    	{
    		return fibonacci_large(n);
    	}
    }
     
    int fibonacci_small(int n) {
    	int a = 0;
    	int b = 1;
    	for i in 0..n do {
    		b += a;
    		a = b - a;
    	}
    	return a;
    }
     
    int fibonacci_large(int n) {
    	int a = 0;
    	int b = 1;
    	int mask = 1 << highest_bit(n);
    	while mask > 0 {
    		if n&mask == 0 {
    			int newa = a*a + b*b;
    			b = 2*a*b + b*b;
    			a = newa;
    		}
    		else {
    			int newa = 2*a*b + b*b;
    			b = (a + b)*(a + b) + b*b;
    			a = newa;
    		}
    	}
    	return a;
    }