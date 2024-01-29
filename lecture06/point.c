/* point.c */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {    // TODO: s/struct/union
    int x;
    int y;
} Point;

void point_format(Point *p, FILE *stream) {
    // TODO: Print point to stream
    fprintf(stream, "Point{x: %d, y: %d}\n", p->x, p->y);
}

int main(int argc, char *argv[]) {
    // TODO: Define some points
    Point p0 = {0};
    Point p1 = {1, 2};

    // TODO: Print size and locations of point structure
    printf("sizeof(Point) = %ld\n", sizeof(Point));
    printf("&p0   = 0x%lx\n", (intptr_t)&p0);
    printf("&p0.x = 0x%lx\n", (intptr_t)&p0.x);
    printf("&p0.y = 0x%lx\n", (intptr_t)&p0.y);

    // TODO: Use print_format to print point structure
    point_format(&p0, stdout);
    point_format(&p1, stdout);

    // TODO: Define array of points
    Point pa[] = {
	{3, 4},
	{5, 6},
	{0},	// Sentinel
    };

    // TODO: Loop through array with pointers and print each point
    for (Point *p = pa; p->x && p->y; p++) {
    	point_format(p, stdout);
    }

    return EXIT_SUCCESS;
}
