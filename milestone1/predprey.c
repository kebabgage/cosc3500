//#include "hdf5.h"
#include <stdio.h>
#include <stdlib.h>

//#define FILE            "particles.h5"
#define DATASET         "DS1"
#define N               100
#define T               100
#define DECAY_CHANCE    0.03

int main (void) {
    double time_series[N][T] = {0};
    float random_float;
    int sheep_pop_count = 100;
    int wolf_pop_count = 50;

    //float decay_rate = 0.4;
    float sheep_reproduce = 0.05;
    float wolf_eat = 0.3;
    float wolf_reproduce = 0.04; 
    float wolf_death = 0.01;

    FILE *fout = fopen("output.p", "a");

    // For each time step 

    for (int t=0; t < T; t++) {
        fscanf(fout, "%d    %d      %d", &t, &sheep_pop_count, &wolf_pop_count);
        printf("Time -- %d\n", t);
        printf("BEFORE:\n");
        printf("Sheep count: %d\n", sheep_pop_count);
        printf("Wolf count: %d\n", wolf_pop_count);

        for(int s=0; s < sheep_pop_count; s++) {

            // For each sheep, see if it will reproduce 
            random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
            if (random_float < sheep_reproduce) {
                sheep_pop_count += 1;
            }
        }
        
        for (int w=0; w < wolf_pop_count; w++) {

            // For each wolf, see if it will eat a sheep
            random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
            if (random_float < wolf_eat) {
                sheep_pop_count -= 1;
            }

            // For each wolf, see if it will reproduce 
            random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
            if (random_float < wolf_reproduce) {
                wolf_pop_count += 1;
            }

            // For each wolf, see if it will die 
            random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
            if (random_float < wolf_death) {
                wolf_pop_count -= 1;
            }
            printf("AFTER:\n");
            printf("Sheep count: %d\n", sheep_pop_count);
            printf("Wolf count: %d\n", wolf_pop_count);
        }

        // Wolf eat sheep 

        // Wolf die? 

        // Wolf reproduce 
    }

/* 
    for (int i=0; i<N; i++) {
        printf("N: %d\n", i);
        for (int t=0; t<T; t++) {
            printf("N: %d\n", i);

            if (t==0) {
                time_series[i][t] = 1; // initial radiation
            } else {
                random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
                if (random_float<DECAY_CHANCE) { // less than DECAY_CHANCE, particle decay
                    time_series[i][t] = decay_rate*time_series[i][t-1];
                } else { // no decay
                    time_series[i][t] = time_series[i][t-1];
                }
            }
        }
    }
*/
    fclose(fout);
//    mat2hdf5(time_series);
    return 0;
}
