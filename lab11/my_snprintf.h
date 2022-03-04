#ifndef MY_SNPRINTF_H
#define MY_SNPRINTF_H

void write_to_buffer(char *buffer, int buf_size, int *index, char argument);
int my_snprintf(char *buffer, int buf_size, char *format, ...);
void init_buf(char *buf, int buf_size);

#endif

