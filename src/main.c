#include <stdio.h>
#include <stdlib.h>

int dayNumber(int g, int n) {
  int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if ((n == 2) && ((g % 400 == 0) || ((g % 100 != 0) && (g % 4 == 0)))) {
	return 29;
  }
  return d[n - 1];
}

void yesterday(int g, int n, int m) {
  if (m == 1) {
	if (n == 1) {
	  printf("%d.%d.%d\n", 12, 31, g - 1);
	  return;
	}
	printf("%d.%d.%d\n", n, dayNumber(g, n), g);
	return;
  }
  printf("%d.%d.%d\n", n, m - 1, g);
}

void tomorrow(int g, int n, int m) {
  if (m == dayNumber(g, n)) {
	if (n == 12) {
	  printf("%d.%d.%d\n", 1, 1, g + 1);
	  return;
	}
	printf("%d.%d.%d\n", n + 1, 1, g);
	return;
  }
  printf("%d.%d.%d\n", n, m + 1, g);
}

int main(int argc, char *argv[]) {
  int g = atoi(argv[1]), n = atoi(argv[2]), m = atoi(argv[3]);
  printf("Today: %d.%d.%d\n", n, m, g);
  printf("Yesterday: ");
  yesterday(g, n, m);
  printf("Tomorrow: ");
  tomorrow(g, n, m);
}
