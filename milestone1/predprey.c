//#include "hdf5.h"
#include <stdio.h>
#include <stdlib.h>

//#define FILE            "particles.h5"
#define DATASET         "DS1"
#define N               100
#define T               100

int main (void) {
    //double time_series[N][T] = {0};
    float random_float;
    float prey_pop = 100;
    float pred_pop = 50;

    float a = 0.7; // Prey reproduce 
    float b = 0.5; // Prey eaten 
    float c = 0.3; // Predator death 
    float e = 0.2; // Predator birth 

    // For each time step 
    for (int t=0; t < T; t++) {
        printf("Time: %d, Prey: %f, Pred: %f\n", t, prey_pop, pred_pop);

        int pred_popD = 0;
        int prey_popD = 0;

        int prey_born = 0;
        int pred_born = 0;
        int prey_death = 0;
        int pred_death = 0;
       
        int f = 0;
        int ff = 0;

        // For loop for prey reproduction 
        for (int s = 0; s < prey_pop; s++) {

            // PREY 
            f++;

            // Determine whether a prey will reproduce 
            random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
            if (random_float < a) {
                //prey_popD += 1;
                prey_born += 1;
            }
        }


        for (int s = 0; s < prey_pop; s++) {

            for (int w = 0; w < pred_pop; w++) {

                random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
                if (random_float < e) {
                    //pred_popD += 1;
                    pred_born += 1;
                }

                random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
                if (random_float < b) {
                    //prey_popD -= 1;
                    prey_death += 1;
                }

            }

            
        }

        

        // For loop for predator death 
        for (int w = 0; w < pred_pop; w++) {

            ff++;

            // Determine whether a predator will die 
            random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
            if (random_float < c) {
                //pred_popD -= 1;
                pred_death += 1;
            }
        }

        prey_pop += prey_born - prey_death;
        pred_pop += pred_born - pred_death;
    }
    return 0;
}
