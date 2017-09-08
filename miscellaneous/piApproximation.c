#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double generalTerm(int x, int i) {
    long double r = 4.0 / (pow(x,(2*i-1)) * (2*i-1));
    return i%2 == 0 ? -r : r;
}

long double generalTermGregory(int i) { return generalTerm(1,i); }
long double generalTermMachin(int i) { return 4*generalTerm(5,i) - generalTerm(239,i); }
long double generalTermHutton(int i) { return generalTerm(2,i) + generalTerm(3,i); }
long double generalTermClausen(int i) { return 2*generalTerm(3,i) + generalTerm(7,i); }
long double generalTermDase(int i) { return generalTerm(2,i) + generalTerm(5,i) + generalTerm(8,i); }

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    FILE *f;
	f = fopen("piApproximationResults.csv","w");
    char string[(10+4)*5 + 4];
    long double s1 = 0;
    long double s2 = 0;
    long double s3 = 0;
    long double s4 = 0;
    long double s5 = 0;
    sprintf(string,"Gregory,Machin,Hutton,Clausen,Dase\n");
    fputs(string,f);
    printf("%s", string);
    for (int i=0;i<n;i++) {
        s1 += generalTermGregory(i+1);
        s2 += generalTermMachin(i+1);
        s3 += generalTermHutton(i+1);
        s4 += generalTermClausen(i+1);
        s5 += generalTermDase(i+1);
        sprintf(string,"%.10Lf,%.10Lf,%.10Lf,%.10Lf,%.10Lf\n",s1,s2,s3,s4,s5);
	    fputs(string,f);
        printf("%s", string);
    }
    fclose(f);
    return 0;
}
