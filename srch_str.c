#include <stdio.h>
#include <string.h>

#define NOT_FOUND 0
#define FOUND 1

int search(char *search, char *original, int length)
{

	int i=0, j=0, flag=NOT_FOUND;
	while (i < length) {
		printf(" DEBUG search[%d]=%c original[%d]=%c\n", j, search[j],
						i, original[i]);
		if (search[j] != original[i]) {
			i = i+length;
			flag = NOT_FOUND;
			j = 0;
			continue;
		}
		if (j == (strlen(search)-1)) {
			flag = FOUND;
			break;
		}
		i++; j++;
		
	}
	return flag;
}


int main ()
{
	if (!search("idprom", "idpro_dump", strlen("idprom_dump"))) {
		printf(" Search String Not found\n");
	} else {
		printf(" idprom_dump \n");
	}

	if (!search("idprom", "id_test", strlen("id_test"))) {
		printf(" Search String Not Found!\n");
	} else {
		printf(" id_test\n");
	}
	return 0;
}
	
	
		
		
	 
