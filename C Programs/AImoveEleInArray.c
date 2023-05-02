#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STATES 10
#define ACTIONS 2
#define REWARD_GOAL 100
#define LEARNING_RATE 0.01 // lower learning rate
#define DISCOUNT_FACTOR 0.8 // lower discount factor
#define EPSILON 0.2 // higher epsilon
#define TRAIN_EPISODES 50000 // increase training episodes
#define TEST_STEPS 20 // increase number of test steps

void print_state(int state);

int main()
{
    srand(time(NULL));

    int q[STATES][ACTIONS] = {{0}}; // initialize q-values to 0
    int state = rand() % STATES; // select random initial state
    int action;
    int reward;
    int new_state;

    for (int i = 0; i < TRAIN_EPISODES; i++) // train for TRAIN_EPISODES episodes
    {
        // choose an action based on epsilon-greedy policy
        if (rand() / (double)RAND_MAX < EPSILON)
        {
            action = rand() % ACTIONS;
        }
        else
        {
            if (q[state][0] > q[state][1])
            {
                action = 0;
            }
            else
            {
                action = 1;
            }
        }

        // observe new state and reward
        if (action == 0)
        {
            new_state = (state + 1) % STATES;
            reward = 0;
        }
        else
        {
            new_state = (state - 1 + STATES) % STATES;
            if (new_state == 0) reward = REWARD_GOAL;
            else reward = 0;
        }

        // update q-value using Q-learning algorithm
        q[state][action] += LEARNING_RATE * (reward + DISCOUNT_FACTOR * 
        (q[new_state][0] > q[new_state][1] ? q[new_state][0] : q[new_state][1]) - 
        q[state][action]);

        // print state and action for visualization
        printf("Episode %d, Step %d:\n", i+1, (new_state == 0 ? -1 : new_state)); // -1 indicates goal state
        print_state(state);
        printf("\n");
        if (action == 0)
        {
            printf("Action: Move to the right\n\n");
        }
        else
        {
            printf("Action: Move to the left\n\n");
        }

        state = new_state; // transition to new state
    }

    // test the learned policy
    state = rand() % STATES; // select random initial state
    printf("Test:\n");
    print_state(state);
    printf("\n");

    for (int i = 0; i < TEST_STEPS; i++) // take TEST_STEPS steps
    {
        if (q[state][0] > q[state][1])
        {
            printf("Action: Move to the right\n\n");
            state = (state + 1) % STATES;
        }
        else
        {
            printf("Action: Move to the left\n\n");
            state = (state - 1 + STATES) % STATES;
        }
        print_state(state);
        printf("\n");
    }

    return 0;
}

void print_state(int state)
{
    for (int i = 0; i < STATES; i++)
    {
        if (i == state)
        {
            printf("| A ");
        }
        else if (i == 0)
        {
            printf("| G ");
        }
        else
        {
            printf("|   ");
        }
    }
    printf("|\n");
}