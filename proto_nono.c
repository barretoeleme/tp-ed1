// Bianca Barreto Leme 		24.1.4008
// Karina Miyu Kinukawa 	24.1.4022

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	EMPTY = 0,
	FULL
} Square;

typedef struct {
	int qntMemb;
	int *members;
} Hint;

typedef struct {
	int size;
	Hint *columns;
	Hint *lines;
	Square **mat;
} Nonogram;

Nonogram *nonoAlocate ()
{
	int n;
	Nonogram *game;

	scanf("%d", &n);

	game = (Nonogram*) malloc(sizeof(Nonogram));

	game->size = n;
	game->columns = (Hint*) malloc(game->size * sizeof(Hint));
	game->lines = (Hint*) malloc(game->size * sizeof(Hint));

	game->mat = (Square**) malloc(game->size * sizeof(Square*));
	for (int i = 0; i < game->size; i++) {
		game->mat[i] = (Square*) malloc(game->size * sizeof(Square));
	}

	return game;
}

void nonoRead (Nonogram *game)
{
	for (int i = 0; i < game->size; i++) {
		scanf("%d", &game->columns[i]->qntMemb);
		game->columns[i]->members = malloc(game->columns[i]->qntMemb * sizeof(int));
		for (int j = 0; j < game->columns[i]->qntMemb; j++) {
			scanf("%d", &game->columns[i]->members[j]);
		}
	}

	for (int i = 0; i < game->size; i++) {
		scanf("%d", &game->lines[i]->qntMemb);
		game->lines[i]->members = malloc(game->lines[i]->qntMemb * sizeof(int));
		for (int j = 0; j < game->lines[i]->qntMemb; j++) {
			scanf("%d", &game->lines[i]->members[j]);
		}
	}

}

void nonoFree (Nonogram *game)
{
	for (int i = 0; i < game->size; i++) {
		free(game->columns[i]->members);
		free(game->lines[i]->members);
		free(game->mat[i]);
	}
	free(game->columns);
	free(game->lines);
	free(game->mat);

	free(game);
}

void nonoSolveHint (Nonogram *game) // prototype
{
	for (int i = 0; i < game->size; i++) {
		for (int j = 0; j < game->lines[i]->qntMemb; j++) {
			game->mat[i][j] = FULL;
		}
	}
}

void nonoPrint (Nonogram *game)
{
	for (int i = 0; i < game->size; i++) {
		for (int j = 0; j < game->size; j++) {
			if (mat[i][j] == FULL) {
				printf("*");
			}
			else {
				printf(".");
			}
		}
		printf("\n");
	}
}

// int checkIfValid (Nonogram *game)
// {
// 	if ()
// }

int main()
{
	Nonogram *game;
	int n;

	game = nonoAlocate();
	nonoRead(game);
	nonoSolveHint(game);
	nonoPrint(game);
	nonoFree(game);

	return 0;
}