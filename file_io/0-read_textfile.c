#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output.
 * @filename: name of the file to read.
 * @letters: number of letters it should read and print.
 *
 * Return: actual number of letters it could read and print.
 * 0 if the file cannot be opened or read, if filename is NULL,
 * or if write fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_wrote;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	n_read = read(fd, buffer, letters);
	if (n_read == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	n_wrote = write(STDOUT_FILENO, buffer, n_read);

	free(buffer);
	close(fd);

	if (n_wrote == -1 || n_wrote != n_read)
		return (0);

	return (n_wrote);
}
