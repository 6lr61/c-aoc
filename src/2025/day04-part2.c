#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char **data;
	size_t count;
	size_t cap;
} array;

void grow_array(array *a)
{
	a->cap *= 2;
	char **tmp = realloc(a->data, a->cap * sizeof(char*));
	a->data = tmp;
}

void insert(array *a, char *line, size_t n) 
{
	if (a->count + 1 > a->cap) {
		grow_array(a);
	}

	a->data[a->count++] = line;
}

void mark_movable(array *map, int rows, int cols)
{
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			// check if it's a roll of paper
			if (map->data[row][col] != '@') {
				continue;
			}

			// at square map[row][col]
			int count = 0;

			// check adjacent squares
			for (int dr = -1; dr <= 1; dr++) {
				for (int dc = -1; dc <= 1; dc++) {
					int new_row = row + dr;
					int new_col = col + dc;

					if (dr == 0 && dc == 0) {
						continue;
					}

					if (new_row < 0 ||
						new_col < 0 ||
						new_row >= rows ||
						new_col >= cols) {
						continue;
					}

					if (map->data[new_row][new_col] == '@' || map->data[new_row][new_col] == 'x') {
						count++;
					}
				}

			}

			if (count < 4) {
				map->data[row][col] = 'x';
			}

			count = 0;
		}

	}
}

int count_movable(array *map, int rows, int cols)
{
	int count = 0;

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (map->data[row][col] == 'x') {
				count++;
				map->data[row][col] = '.';
			}
		}
	}

	return count;
}

int main()
{
	// initialize map
	array map = {
		.data = malloc(16 * sizeof(char*)),
		.count = 0,
		.cap = 16,
	};

	char *line = NULL;
	size_t buf_size;
	ssize_t N = 0;
	size_t len = 0;

	while ((N = getline(&line, &buf_size, stdin)) != EOF) {
		N--;
		len = N;

		insert(&map, line, N);
		line = NULL;
	}


	// traverse the map
	int rows = map.count;
	int cols = len;
	int movable = 0;
	int new_movables;

	do {
		mark_movable(&map, rows, cols);
		new_movables = count_movable(&map, rows, cols);
		movable += new_movables;

	} while (new_movables > 0);
	
	printf("movable: %d\n", movable);
}
