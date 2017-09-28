// Suffix Array
// Order : O(n log^2 (n))
/* Pseudocode

SortIndex[][] = { 0 }

for i = 0 to N-1
    SortIndex[0][i] = order index of the character at A[i]

doneTill = 1
step = 1

while doneTill < N
    L[] = { (0,0,0) } // Array of 3 tuples

    for i = 0 to N-1
        L[i] = ( SortIndex[step - 1][i],
                 SortIndex[step - 1][i + doneTill],
                 i
               )
    // We need to store the value of i to be able to retrieve the index

    sort L

    for i = 0 to N-1
        SortIndex[step][L[i].thirdValue] =
         SortIndex[step][L[i-1].thirdValue], if L[i] and L[i-1] have the same first and second values
            i, otherwise

    ++step
    doneTill *= 2
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 65536
#define MAXLG 17

char A[MAXN];

struct entry
{
    int nr[2];
    int p;
} L[MAXN];

int P[MAXLG][MAXN];
int N,i;
int stp, cnt;

int cmp(struct entry a, struct entry b)
{
    return a.nr[0]==b.nr[0] ?(a.nr[1]<b.nr[1] ?1: 0): (a.nr[0]<b.nr[0] ?1: 0);
}

int main()
{
    gets(A);
    for(N=strlen(A), i = 0; i < N; i++)
        P[0][i] = A[i] - 'a';

    for(stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
    {
        for(i=0; i < N; i++)
        {
            L[i].nr[0]=P[stp- 1][i];
            L[i].nr[1]=i +cnt <N? P[stp -1][i+ cnt]:-1;
            L[i].p= i;
        }
        sort(L, L+N, cmp);
        for(i=0; i < N; i++)
            P[stp][L[i].p] =i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? P[stp][L[i-1].p] : i;
    }
    return 0;
}