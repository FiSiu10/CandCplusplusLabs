/*
 * Adds, removes or prints out integers of a queue using a dynamic linked list
 */

/* 
 * File:   queueMain.c
 * Author: Fiona Siu
 *
 * Created on February 5, 2018, 3:17 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int ac, char *av[]) {
    Queue queue = {NULL, NULL, 0};
    
    /*
     * Prompts the user to select 1 out of 3 options: 
     * Enter 1 to add an integer to the queue
     * Enter 0 remove an integer from the queue
     * Enter -1 to exit and print the items in the queue
     */
  
    int done = 0;
    while (!done) {
        int choice, nValid;
        do {
            printf("Enter 1 to add to queue or 0 to remove "
                    "(-1 to quit): ");
            nValid = scanf("%d", &choice);
        } while (nValid != 1 || choice < -1 || choice > 1);

        switch (choice) {
            case 0:
            {
                ItemType *item;
                if ((item = dequeue(&queue)) != NULL) {
                    printf("Removed " ITEM_FORMAT "\n", *item);
		    free (item);
                } else {
                    printf("Queue is empty\n");
                }
                break;
            }

            case 1:
            {
                ItemType *item = malloc (sizeof(ItemType));
                if (item == NULL) {
                    fprintf(stderr, "%s: Error allocating memory for item.\n", av[0]);
                    return EXIT_FAILURE;
                }

                printf ("Enter " ITEM_PROMPT ": ");
                if (scanf(ITEM_FORMAT, item) != 1) {
                    fprintf(stderr, "Unable to read " ITEM_PROMPT "\n");
                    break;
                }

                if ((item = enqueue(&queue, item)) != NULL) {
                    printf("Added " ITEM_FORMAT "\n", *item);
                } else {
                    fprintf(stderr, "%s: Error allocating memory to queue.\n", av[0]);
                    return EXIT_FAILURE;
                }
                break;
            }

            case -1:
            {
                done = 1;
                break;
            }


            default:
	      fprintf(stderr, "Invalid choice entered");
        }
    }
    
    //Prints out items in the queue
    printf ("Items remaining in the queue:\n");
    printQueue (queue, stdout);


    return EXIT_SUCCESS;
}

