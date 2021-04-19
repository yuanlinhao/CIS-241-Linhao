#include "file_lib.h"
#include "sorter.h"
#include <stdio.h>
	
/*
 * Read the file from the command-line.
 * Usage:
 * ./a.out FILE_TO_READ FILE_TO_WRITE
 *
 */

int main(int argc, char** argv){
	// Read the original file.
	char* content = NULL;
	size_t count = load_file(argv[1], &content);
	

	// Sort the file with the function you wrote.
	sort(content, (int)count);

	// Write out the new file.
	save_file(argv[2], content, count);
	free(content);
	return 0;
}

// You can see if your file worked correctly by using the
// command:
//
// diff ORIGINAL_FILE NEW_FILE
//
// If the command returns ANYTHING the files are different.
