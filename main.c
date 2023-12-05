#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

int	main()
{
printf("%d\n",printf("% # +x\n",79));
printf("%d\n",ft_printf("% # +x\n",79));
}
