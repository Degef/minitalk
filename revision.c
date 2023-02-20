#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



void	print_bits(unsigned char octet)
{
	int i = 7;

	while (i + 1 > 0)
	{
		if (octet & (1<<i))
			write(1, "1", 1);
		else 
			write(1, "0", 1);
		i--;			
	}

}
int main()
{
	print_bits(2);
	return (0);
}

// a b c d e f g h i j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
