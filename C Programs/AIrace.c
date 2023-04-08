#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POPULATION_SIZE 100
#define TRACK_LENGTH 1000
#define MUTATION_RATE 0.01

int population[POPULATION_SIZE][TRACK_LENGTH];

void initialize_population() {
    int i, j;
    for (i = 0; i < POPULATION_SIZE; i++) {
        for (j = 0; j < TRACK_LENGTH; j++) {
            population[i][j] = rand() % 3 - 1;
        }
    }
}

int evaluate_fitness(int car) {
    int i, fitness;
    fitness = 0;
    for (i = 0; i < TRACK_LENGTH; i++) {
        if (population[car][i] == 0) {
            fitness++;
        }
        if (i > 0 && population[car][i] == population[car][i-1]) {
            fitness += 2;
        }
    }
    return fitness;
}

void selection(int parents[2]) {
    int i, j, max_fitness, total_fitness;
    int fitness[POPULATION_SIZE];
    max_fitness = 0;
    total_fitness = 0;
    for (i = 0; i < POPULATION_SIZE; i++) {
        fitness[i] = evaluate_fitness(i);
        total_fitness += fitness[i];
        if (fitness[i] > fitness[max_fitness]) {
            max_fitness = i;
        }
    }
    parents[0] = max_fitness;
    for (i = 1; i < 2; i++) {
        int r = rand() % total_fitness;
        for (j = 0; j < POPULATION_SIZE; j++) {
            r -= fitness[j];
            if (r <= 0) {
                parents[i] = j;
                break;
            }
        }
    }
}

void crossover(int parent1, int parent2, int child) {
    int i;
    for (i = 0; i < TRACK_LENGTH; i++) {
        if (rand() % 2) {
            population[child][i] = population[parent1][i];
        } else {
            population[child][i] = population[parent2][i];
        }
    }
}

void mutate(int car) {
    int i;
    for (i = 0; i < TRACK_LENGTH; i++) {
        if (rand() < MUTATION_RATE) {
            population[car][i] = rand() % 3 - 1;
        }
    }
}

void next_generation() {
    int i, parents[2];
    for (i = 0; i < POPULATION_SIZE; i++) {
        selection(parents);
        crossover(parents[0], parents[1], i);
        mutate(i);
    }
}

int main() {
    srand(time(NULL));
    initialize_population();
    int i,j , max_fitness, max_fitness_car;
    for (i = 0; i < 100; i++) {
        next_generation();
        max_fitness = 0;
        max_fitness_car = 0;
        for (j = 0; j < POPULATION_SIZE; j++) {
            int fitness = evaluate_fitness(j);
            if (fitness > max_fitness) {
                max_fitness = fitness;
                max_fitness_car = j;
            }
        }
        printf("Generation %d: Car %d has fitness %d\n", i, max_fitness_car, max_fitness);
    }
    return 0;
}