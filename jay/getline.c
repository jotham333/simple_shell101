ne_ptr = new_buf;
        }
        (*line_ptr)[i++] = c;
	        if (c == '\n') {
			            break;
				            }
    }

    if (bytes_read < 0) {
	            free(*line_ptr);
		            return -1;
			        }

    if (i ==
ssize_t _getline(char **line_ptr, size_t *line_size, FILE *stream) {
    static char buffer[4096];
    static size_t buffer_pos = 0;
    static size_t buffer_size = 0;
    ssize_t bytes_read = 0;
    size_t i = 0;
    char c;

    while (1) {
        if (buffer_pos >= buffer_size) {
            bytes_read = read(fileno(stream), buffer, sizeof(buffer));
            if (bytes_read <= 0) {
                break;
            }
            buffer_pos = 0;
            buffer_size = bytes_read;
        }
        c = buffer[buffer_pos++];
        if (i + 1 >= *line_size) {
            *line_size = *line_size ? *line_size * 2 : 512;
            char *new_buf = realloc(*line_ptr, *line_size);
            if (!new_buf) {
                free(*line_ptr);
         0) {
        *line_ptr = NULL;
        *line_size = 0;
        return -1;
    }

    (*line_ptr)[i] = '\0';

    return i;
}*/

