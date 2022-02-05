#include <unistd.h> 


void ft_print_reverse_alphabet(void) {
  char ch = 'z'; 
  while (ch >= 'a') {
    write(1, &ch, 1); 
    ch--;
  }
}
