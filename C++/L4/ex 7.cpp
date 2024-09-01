#include <stdio.h>

main()
{
    int i;
    float mt, ml, mf;
    
    for(i=0; i<=30; i++)
    {
        printf("digite sua mt e a ml");
        scanf("%f %f", &mt, &ml);
        mf = (mt * 0.6) + (ml * 0.4);
        printf("sua media final foi %f\n", mf);
        if (mf>=7)
        {
            printf("voce foi bem\n");
        }
        else if (mf>=5 && mf<7)
        {
            printf("voce foi razoavel\n");
        }
        else if (mf<5)
        {
            printf("voce foi mal, desista\n");
        }
    }      
}