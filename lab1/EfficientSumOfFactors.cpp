int sumofFactors(int n) 
{ 
    // Traversing through all prime factors. 
    int res = 1; 
    for (int i = 2; i <= sqrt(n); i++) 
    { 
  
          
        int curr_sum = 1; 
        int curr_term = 1; 
        while (n % i == 0) { 
  
            // THE BELOW STATEMENT MAKES 
            // IT BETTER THAN ABOVE METHOD  
            //  AS WE REDUCE VALUE OF n. 
            n = n / i; 
  
            curr_term *= i; 
            curr_sum += curr_term; 
        } 
  
        res *= curr_sum; 
    } 
  
    // This condition is to handle  
    // the case when n is a prime 
    // number greater than 2. 
    if (n >= 2) 
        res *= (1 + n); 
  
    return res; 
} 