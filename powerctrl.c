#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int z = 0;

void powerchange();

int main(int argc, char **argv)
{
	if (argc == 1 || argc > 2)
	{
		printf("Usage: sudo ./powerctrl [MIN/MID/MAX]\n");
	}
	else
	{
		printf("%s", argv[1]);
		if (strcmp(argv[1], "MIN") == 0)
		{
			z = 10;
			powerchange();
		}
		else if (strcmp(argv[1],"MID") == 0)
		{
			z = 50;
			powerchange();
		}
		else if (strcmp(argv[1],"MAX") == 0)
		{
			z = 100;
			powerchange();
		}
		else
		{
			printf ("Usage: sudo ./powerctrl [MIN/MID/MAX]");
		}
	}
	return 0;
}

void powerchange()
{
	char buf[100];
	snprintf(buf, sizeof(buf), "echo %i > /sys/devices/system/cpu/intel_pstate/max_perf_pct", z);
	system(buf);
	printf("Cpu clock set to %i \n", z);
	system("i7z");
}
