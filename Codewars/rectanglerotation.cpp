// rectangle rotation

#include <math.h>

long long rectangle_rotation(int a, int b)
{
    int i, j=0, r=0, c;
    for(i=1; sqrt(i*i+j*j)<(a/2); i++){
        if (sqrt(i*i+(j+1)*(j+1)) < (a/2)) j++;
    }
    for(c=1; sqrt(c*c+r*r)<(b/2); c++){
        if (sqrt(c*c+(r+1)*(r+1)) < (b/2)) r++;
    }
     if(c != 1) c--;
    if(i != 1) i--;
    i = 2*(i);
    j = j*2+1;
    c = (c)*2;
    r = 2*(r)+1;
    return i*c + j*r;
}