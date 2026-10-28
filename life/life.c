#include "life.h"

static void	read_commands(char *cells, int width, int height)
{
	int		pen_row;
	int		pen_col;
	int		is_drawing;
	char	command;

	pen_row = 0;
	pen_col = 0;
	is_drawing = 0;
	while (read(0, &command, 1) > 0)
	{
		if (command == 'x')
			is_drawing = !is_drawing;
		else if (command == 'w' && pen_row > 0)
			pen_row--;
		else if (command == 's' && pen_row < height - 1)
			pen_row++;
		else if (command == 'a' && pen_col > 0)
			pen_col--;
		else if (command == 'd' && pen_col < width - 1)
			pen_col++;
		if (is_drawing)
			cells[pen_row * width + pen_col] = 1;
	}
}

static int	count_alive_neighbors(char *cells, int width, int height,
				int row, int col)
{
	int	row_offset;
	int	col_offset;
	int	neighbor_row;
	int	neighbor_col;
	int	count;

	count = 0;
	for (row_offset = -1; row_offset <= 1; row_offset++)
	{
		for (col_offset = -1; col_offset <= 1; col_offset++)
		{
			if (row_offset == 0 && col_offset == 0)
				continue ;
			neighbor_row = row + row_offset;
			neighbor_col = col + col_offset;
			if (neighbor_row < 0 || neighbor_row >= height
				|| neighbor_col < 0 || neighbor_col >= width)
				continue ;
			count += cells[neighbor_row * width + neighbor_col];
		}
	}
	return (count);
}

static void	compute_next_generation(char *current, char *next,
				int width, int height)
{
	int	row;
	int	col;
	int	index;
	int	alive_neighbors;

	for (row = 0; row < height; row++)
	{
		for (col = 0; col < width; col++)
		{
			index = row * width + col;
			alive_neighbors = count_alive_neighbors(current, width, height,
					row, col);
			if (current[index] == 1)
				next[index] = (alive_neighbors == 2 || alive_neighbors == 3);
			else
				next[index] = (alive_neighbors == 3);
		}
	}
}

static void	print_board(char *cells, int width, int height)
{
	int	row;
	int	col;

	for (row = 0; row < height; row++)
	{
		for (col = 0; col < width; col++)
		{
			if (cells[row * width + col] == 1)
				putchar('O');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

int	main(int ac, char **av)
{
	int		width;
	int		height;
	int		iterations;
	char	*current;
	char	*next;
	char	*tmp;

	if (ac != 4)
		return (1);
	width = atoi(av[1]);
	height = atoi(av[2]);
	iterations = atoi(av[3]);
	if (width <= 0 || height <= 0)
		return (1);
	current = calloc(width * height, sizeof(char));
	next = calloc(width * height, sizeof(char));
	if (!current || !next)
		return (1);
	read_commands(current, width, height);
	while (iterations > 0)
	{
		compute_next_generation(current, next, width, height);
		tmp = current;
		current = next;
		next = tmp;
		iterations--;
	}
	print_board(current, width, height);
	free(current);
	free(next);
	return (0);
}