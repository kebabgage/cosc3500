int main() {
	// Model Parameters 

	int a = 0.7; // Prey reproduce 
	int b = 0.5; // Prey eaten 
	int c = 0.3; // 
	int e = 0.2;
	int dt = 0.001;
	int max_time = 100; 

	// Initial time and populations 
	int t = 0;
	int x = 1.0;
	int y = 0.5;

	// Some empty lists 
	int t_array[max_time]; // = malloc();
	int x_array[max_time]; // = malloc();
	int y_array[max_time]; // = malloc();


	// Go through the model 
	while (t < max_time):
		// Get the new values for t, x, y 
		t = t + dt; 
		// prey_pop = prey_pop + (prey_reproduce * prey_pop - prey_eaten * prey_pop * prey_pop)*dt
		x = x + (a*x - b*x*y)*dt;

		// pred_pop = pred_pop + (pred_death * pred_pop + amount_of_prey_born * prey_pop * pred_pop)
		y = y + (-c*y + e*x*y)*dt

		printf("%d %d %d", t, x, y);

		t++;

}