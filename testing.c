#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Vector2;

/* * 
   * Adds two vectors together and stores the result in a 
   *  new vector struct.
   * */
Vector2 * add_vectors(Vector2* v1, Vector2* v2) {
    Vector2 *output = (Vector2*)malloc(sizeof(Vector2));
    output->x = v1->x + v2->x;
    output->y = v1->y + v2->y;
    return output;
}

int main(int argc, char* argv[]) {
    // read in number of vectors to add:
    printf("enter the number of vectors: ");
    int numVectors;
    scanf("%d", &numVectors);

    // create vectors to add:
    Vector2 v1 = {0.0f, 0.0f};
    Vector2 v2;

    // read in vectors:
    for (int i = 0; i < numVectors; i++) {
        // read in vector
        printf("enter the x component of vector number %d: ", i+1);
        scanf("%f", &v2.x);
        printf("enter the y component of vector number %d: ", i+1);
        scanf("%f", &v2.y);

        // add the vector together:
        Vector2 *sum = add_vectors(&v1, &v2);

        // copy the sum into vector v1:
        v1.x = sum->x;
        v2.y = sum->y;
    }

    printf("Final vector: (%f, %f)\n", v1.x, v1.y);

    return 0;
}