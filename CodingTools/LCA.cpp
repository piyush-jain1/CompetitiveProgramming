 //we could use dynamic programming. First, let’s compute a table P[1,N][1,logN] where P[i][j] is the 2j-th ancestor of i
// P[i][j] = T[i],  j = 0;
// P[i][j] = P[P[i][j-1]][j-1] , j > 0;

 void process3(int N, int T[MAXN], int P[MAXN][LOGMAXN])
  {
      int i, j;
   
  //we initialize every element in P with -1
      for (i = 0; i < N; i++)
          for (j = 0; 1 << j < N; j++)
              P[i][j] = -1;
   
  //the first ancestor of every node i is T[i]
      for (i = 0; i < N; i++)
          P[i][0] = T[i];
   
  //bottom up dynamic programing
      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
  }
  

  // Query
  //let’s see how we can make queries. Let L[i] be the level of node i in the tree. We must observe that if p and q are on the same level in the tree we can compute LCA(p, q) using a meta-binary search. So, for every power j of 2 (between log(L[p]) and 0, in descending order), if P[p][j] != P[q][j] then we know that LCA(p, q) is on a higher level and we will continue searching for LCA(p = P[p][j], q = P[q][j]). At the end, both p and q will have the same father, so return T[p]. Let’s see what happens if L[p] != L[q]. Assume, without loss of generality, that L[p] < L[q]. We can use the same meta-binary search  for finding the ancestor of p situated on the same level with q, and then we can compute the LCA  

  int query(int N, int P[MAXN][LOGMAXN], int T[MAXN], 
  int L[MAXN], int p, int q)
  {
      int tmp, log, i;
   
  //if p is situated on a higher level than q then we swap them
      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;
  
  //we compute the value of [log(L[p)]
      for (log = 1; 1 << log <= L[p]; log++);
      log--;
   
  //we find the ancestor of node p situated on the same level
  //with q using the values in P
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];
   
      if (p == q)
          return p;
   
  //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];
   
      return T[p];
  }
