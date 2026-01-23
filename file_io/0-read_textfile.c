#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters it should read and print
 *
 * Return: actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_wrote;
	char *buffer;

	if (filename == NULL)
		return (0);

	/* 1. Open the file */
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	/* 2. Create a buffer to hold the letters */
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	/* 3. Read from the file */
	n_read = read(fd, buffer, letters);
	if (n_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	/* 4. Write to Standard Output */
	n_wrote = write(STDOUT_FILENO, buffer, n_read);

	/* 5. Cleanup */
	free(buffer);
	close(fd);

	/* Check if write failed or wrote the wrong amount */
	if (n_wrote == -1 || n_wrote != n_read)
		return (0);

	return (n_wrote);
}
