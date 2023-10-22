#include "../inc/pathfinder.h"

void mx_create_matrices(t_pathfinder *pathfinder) {
    int size = pathfinder->isl_count;
    int path_count = pathfinder->path_count;
    int x = 0;
    int y = 0;

    pathfinder->matrices.paths = (int ***) malloc(sizeof(int **) * size);
    pathfinder->matrices.bridges = (int **) malloc(sizeof(int *) * size);
    pathfinder->matrices.path_size = (int **) malloc(sizeof(int *) * size);
    for (int i = 0; i < size; ++i) {
        pathfinder->matrices.paths[i] = (int **) malloc(sizeof(int *) * size);
        pathfinder->matrices.bridges[i] = (int *) malloc(sizeof(int) * size);
        pathfinder->matrices.path_size[i] = (int *) malloc(sizeof(int) * size);
    }
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            pathfinder->matrices.bridges[i][j] = MX_INT_MAX;

    for (int i = 0; i < path_count; ++i) {
        for (x = 0; x < size; ++x) {
            if (!mx_strcmp(pathfinder->paths[i]->island1, pathfinder->islands[x]))
                break;
        }
        for (y = 0; y < size; ++y) {
            if (!mx_strcmp(pathfinder->paths[i]->island2, pathfinder->islands[y]))
                break;
        }
        pathfinder->matrices.bridges[x][y] = pathfinder->paths[i]->bridge;
        pathfinder->matrices.bridges[y][x] = pathfinder->paths[i]->bridge;
        pathfinder->matrices.paths[x][y] =(int *) malloc(sizeof(int) * 2);
        pathfinder->matrices.paths[x][y][0] = x;
        pathfinder->matrices.paths[x][y][1] = y;
        pathfinder->matrices.paths[y][x] =(int *) malloc(sizeof(int) * 2);
        pathfinder->matrices.paths[y][x][0] = y;
        pathfinder->matrices.paths[y][x][1] = x;
        pathfinder->matrices.path_size[x][y] = 2;
        pathfinder->matrices.path_size[y][x] = 2;
    }
}

