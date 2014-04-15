#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
 
using namespace std;
 
int main(void)
{
        int ev1, ev2, at, d;
        int t = 1;
 
        while (1)
        {
                scanf ("%d %d %d %d", &ev1, &ev2, &at, &d);
                if (!ev1) break;
               
                double p = at/6.0f;
                double q = 1 - p;
 
                int pos = ceil ((float)ev1 / d);
                int len = pos + ceil((float)ev2 / d);
                vector<double> s(len+1);
               
                s[pos] = 1;
                while ((s[0] + s[len]) < 0.99999f)
                {
                        for (int i = 1; i < len; i ++)
                        {
                                if (s[i] == 0) continue;
                                s[i-1] += q*s[i];
                                s[i+1] += p*s[i];
                                s[i] = 0;
                        }
                }
 
                printf ("%.01f\n", s[len]*100);
        }
 
        return 0;
}