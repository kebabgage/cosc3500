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

        // For loop for prey reproduction 
        int s = 0;
        while (s < prey_pop) {
            // Determine whether a prey will reproduce 
            random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
            if (random_float < a) {
                prey_popD += 1;
            }
            s++;
        }

        // For loop for predator death 
        int w = 0;
        while (w < pred_pop) {
            // Determine whether a predator will die 
            random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
            if (random_float < c) {
                pred_popD -= 1;
            }
            w++;
        }

        s = 0;
        w = 0;
        int total = 0;

        while (s < prey_pop * pred_pop) {

            // Determine whether a wolf will reproduce 
            random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
            if (random_float < e) {
                pred_popD += 1;
            }

            // Determine whether a wolf will eat 
            random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
            if (random_float < b) {
                prey_popD -= 1;
            }

            total++;

            s++;
        }

        printf("Total: %d -- pop * == %f\n", total, pred_pop * prey_pop);

        printf("Pred Pop -- BEFORE %f D %d AFTER %f\n", pred_pop, pred_popD, pred_pop - pred_popD);


        printf("Prey Pop -- BEFORE %f D %d AFTER %f\n", prey_pop, prey_popD, prey_pop - prey_popD);





    //     // Nested for loop for prey eaten and predator birth 

    //     int s = 0;
    //     while (s < pred_pop) {
    //         random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
    //         if (random_float < a) {
    //             sheep_pop_count += 1;
    //         }
    //     }
    
    //     // If there are still sheep 
    //     if (sheep_pop_count) {
    //         // For each prey 
    //         for(int s=0; s < sheep_pop_count; s++) {
    //             // Random chance that one prey reproduces
    //             random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
    //             if (random_float < a) {
    //                 sheep_pop_count += 1;
    //             }
    //         }
    //     }
        
    //     // If there are still wolves 
    //     if (wolf_pop_count) {
    //         // For each predator 
    //         for (int w=0; w < wolf_pop_count; w++) {

    //             if (!wolf_pop_count) {
    //                 break;
    //             }

    //             // For each sheep 
    //             for (int s=0; s < sheep_pop_count; s++) {
    //                 if (sheep_pop_count) {
    //                     random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
    //                         if (random_float < c) {
    //                             sheep_pop_count -= 1;
    //                         }
    //                 }
    //             }
    //             // For each wolf, see if it will eat a sheep
                

    //             // For each wolf, see if it will reproduce 
    //             random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
    //             if (random_float < wolf_reproduce) {
    //                 wolf_pop_count += 1;
    //             }

    //             if (wolf_pop_count) {
    //                 random_float = (float)rand()/(float)(RAND_MAX); //random float from 0 to 1
    //                 if (random_float < wolf_death) {
    //                     wolf_pop_count -= 1;
    //                 }
    //             }
    //         }
    //     }   
    // }
    }
    return 0;
}
