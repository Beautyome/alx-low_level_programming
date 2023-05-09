#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *allocate_buffer(const char *file);
void close_file(int fd);

/**
 * allocate_buffer - Allocate a buffer of 1024 bytes.
 * @file: The name of the file the buffer is associated with.
 *
 * Return: A pointer to the newly allocated buffer.
 */
char *allocate_buffer(const char *file)
{
	char *buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't allocate buffer for %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor  to be closed.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file_descriptor %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of one file to another file.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with the following error codes:
 * 97: Incorrect number of arguments.
 * 98: Unable to read from the source file.
 * 99: Unable to write to the destination file.
 * 100: Unable to close a file descriptor.
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = allocate_buffer(argv[1]);
	src_fd = open(argv[1], O_RDONLY);
	if (src_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (dest_fd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
			free(buffer);
			close_file(src_fd);
			exit(99);
		}

	while ((bytes_read = read(src_fd, buffer, 1024)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
			free(buffer);
			close_file(src_fd);
			close_file(dest_fd);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		close_file(src_fd);
		close_file(dest_fd);
	       	exit(98);
	}

	free(buffer);
	close_file(src_fd);
	close_file(dest_fd);

	return (0);
}
