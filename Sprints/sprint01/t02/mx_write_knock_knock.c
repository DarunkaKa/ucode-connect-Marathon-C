#include <unistd.h>
#include <string.h>
void mx_write_knock_knock(void);
int main(void){
	mx_write_knock_knock();
}
void mx_write_knock_knock(void){
	write(1, "Follow the white rabbit.\n", strlen("Follow the white rabbit.\n"));
	write(1, "Knock, knock, Neo.\n", strlen("Knock, knock, Neo.\n"));
}
