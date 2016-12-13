#include <stdio.h>


void swap(int *a, int *b)
{
	int t=0;
	
	t = *a;
	*a = *b;
	*b = t;
}


void order_2(int *a, int *b, int ref)
{
	if (*a < ref) {
		*b = *a;
		*a = ref;
	}

	if (*b < ref) {
		if (ref < *a)
		    *b = ref;
	}
		
	if (*b > *a) {
		swap(a, b);
	} 
	
	if (*b == *a) {
		*b = ref;
	}
}	

		
void order_3(int *a, int *b, int *c, int ref)
{
	order_2(b, c, ref);
	order_2(a, b, ref);
}

void order_4(int *a, int *b, int *c, int *d, int ref)
{
	order_3(b, c, d, ref);
	order_3(a, b, c, ref);
}


void print_elements(int *element, int length)
{
	int i=0;
	printf(" Elements =  ");
	for(i = 0; i < 10; i++) {
		printf(" %d", element[i]); 
	}
	printf("\n");
}


// Algorithm to find second largest !
void find_second_largest(int *element, int length)
{
	int first, second, i;
	first = element[0];
	second = element[1];

	print_elements(element, length);
	for (i=2; i<length; i++) {
	  order_2(&first, &second, element[i]);
	}
	printf(" first=%d, second=%d\n", first, second);
}


// Algorithm to find third largest !

void find_third_largest(int *element, int length)
{
	int first, second, third, i;
	first = element[0];
	second = element[1];
	third = element[2];
	
	print_elements(element, length);
	for (i=3; i<length; i++) {
	  order_3(&first, &second, &third, element[i]);
	}
	printf(" first=%d, second=%d, third = %d\n", first, second, third);
}

// Algorithm to find fourth largest !

void find_fourth_largest(int *element, int length)
{
	int first, second, third, fourth, i;
	first = element[0];
	second = element[1];
	third = element[2];
	fourth = element[3];
	
	print_elements(element, length);
	for (i=4; i<length; i++) {
	  order_4(&first, &second, &third, &fourth, element[i]);
	}
	printf(" first=%d, second=%d, third = %d fouth = %d\n", 
			first, second, third, fourth);
}
		

int main()
{
	int i = 0;
	int sequence[8][10] = {
				{100, 8, 10 ,1, 2, 3, 11, 12, 99, 1},
				{100, 100, 100 ,100, 2, 3, 11, 12, 99, 1},
				{10, 10, 10 ,10, 2, 3, 11, 12, 99, 1},
				{100, 100, 100 ,100, 100, 100, 100, 100, 100, 99},
				{99, 100, 100 ,100, 100, 100, 100, 100, 100, 100},
				{1009, 1001, 10 ,9100, 9900, -100, 1009, 100, 100, 990},
				{-1009, -1001, 10 ,-9100, -9900, -100, -1009, -100, -100, -990},
				{12, 8, 10 ,1, 2, 3, 11, 100, 99, 1},
			 };
	
	printf(" Testing Second largest with various sequences ..\n");
	for (i=0; i<7; i++) {
		find_second_largest(sequence[i], 10);
	}
	printf("\n");
	printf(" Testing third largest with various sequences ..\n");
	for (i=0; i<8; i++) {
		find_third_largest(sequence[i], 10);
	}
	printf("\n\n Testing fourth largest with various sequences ..\n");
	for (i=0; i<8; i++) {
		find_fourth_largest(sequence[i], 10);
	}
	
	
	return 0;
}
		
			

	
