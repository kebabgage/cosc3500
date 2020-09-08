int main() {
	// Model Parameters 

	float a = 0.7; // Prey reproduce 
	float b = 0.5; // Prey eaten 
	float c = 0.3; // 
	float e = 0.2;
	float dt = 0.001;
	int max_time = 10000; 

	// Initial time and populations 
	int t = 0;
	float x = 1.0;
	float y = 0.5;

	// Some empty lists 
	int t_array[max_time]; // = malloc();
	int x_array[max_time]; // = malloc();
	int y_array[max_time]; // = malloc();


	// Go through the model 
	while (t < max_time) {
		// Get the new values for t, x, y 
		t = t + dt; 
		// prey_pop = prey_pop + (prey_reproduce * prey_pop - prey_eaten * prey_pop * prey_pop)*dt
		x = x + (a * x - b * x * y) *dt;

		// pred_pop = pred_pop + (pred_death * pred_pop + amount_of_prey_born * prey_pop * pred_pop)
		y = y + (-1 * c * y + e * x * y) *dt;

		printf("Time: %d x: %f y: %f\n", t, x, y);

		t++;
	}

}