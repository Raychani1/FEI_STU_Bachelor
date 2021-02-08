#include <stdio.h>
#include <float.h>
int main()
{
    float epsilon1=1.0;
    double epsilon2=1.0;
    while (1 + epsilon1/2 > 1)
    {
        epsilon1 = epsilon1 / 2;
    }
    printf("Float epsilon: %e", epsilon1);

    while (1 + epsilon2/2> 1)
    {
        epsilon2 = epsilon2 / 2;
    }
    printf("\nDouble epsilon: %e", epsilon2);

    printf("\n\nFLT_EPSILON = %e\n", FLT_EPSILON);
    printf("DBL_EPSILON = %e\n", DBL_EPSILON);

    return 0;
}