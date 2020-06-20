#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "FindIE.h"
#include "FindTE.h"
#include "dataStructure.h"
#include <mgl2/mgl.h>

int main(int argc, char *argv[]) {

   int multiTriggerWindow = 20000;
   int sensorDim[2] = {260, 346}; 

   FILE *fp; 
    int count = 0;  // Line counter (result) 
    char filename[] = "sampleDataC.csv";

    count = sensorDim[0] * sensorDim[1];

    //values valueArray[sensorDim[0]][sensorDim[1]];
    int row = sensorDim[0];
    int column = sensorDim[1];

    values *valueArray = (values *)malloc(count * sizeof(values));
    values *inceptiveEvents = (values *)malloc(count * sizeof(values));
    values *trailingEvents = (values *)malloc(count * sizeof(values));

    char line[28];
    fp = fopen(filename, "r");

    int x;
    int y = 0;
    unsigned long long t;
    short p;

    int end = 0;

    while(fscanf(fp, "%d,%d,%llu,%hd", &x, &y, &t, &p) == 4)
    {
        
        fillTimeArray(&(valueArray[(x - 1) * sensorDim[0] + (y - 1)]), t, p);
    }

    for(int i = 0; i < (sensorDim[0] * sensorDim[1]); i++)
    {
        findIE(&inceptiveEvents[i], &valueArray[i], multiTriggerWindow);
        findTE(&trailingEvents[i], &valueArray[i], multiTriggerWindow);
    }

    FILE *f = fopen("isIE.csv", "w");
    for(int i = 0; i < (sensorDim[0] * sensorDim[1]); i++)
    {
        for(int j = 0; j < 10; j++)
        {
            //printf("%llu\n", inceptiveEvents[i].t[j]);
            
            if(inceptiveEvents[i].t[j] != 0)
            {
                //printf("%d,%d,%llu\n",  ((i / sensorDim[0]) + 1), ((i % sensorDim[0]) + 1), inceptiveEvents[i].t[j]);
                fprintf(f,"%d,%d,%llu\n",  ((i / sensorDim[0]) + 1), ((i % sensorDim[0]) + 1), inceptiveEvents[i].t[j]);
            }
            else
            {
                j = 11;
            }
            
        }
    }
    fclose(f);

    FILE *ft = fopen("isTE.csv", "w");
    for(int i = 0; i < (sensorDim[0] * sensorDim[1]); i++)
    {
        for(int j = 0; j < 10; j++)
        {
            //printf("%llu\n", inceptiveEvents[i].t[j]);
            
            if(trailingEvents[i].t[j] != 0)
            {
                //printf("%d,%d,%llu\n",  ((i / sensorDim[0]) + 1), ((i % sensorDim[0]) + 1), trailingEvents[i].t[j]);
                fprintf(f,"%d,%d,%llu\n",  ((i / sensorDim[0]) + 1), ((i % sensorDim[0]) + 1), trailingEvents[i].t[j]);
            }
            else
            {
                j = 11;
            }
            
        }
    }
    fclose(ft);

   return 0;
}