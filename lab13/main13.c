#include <stdio.h>
#include <string.h>

int main() {
	char s[] = { "jesus christ its jason bourne" };
	
	double massResult[27] = { 0 };		   //26 ����, 27�� ������
	double massFrequency[27] = { 0 };

	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == ' ')
			massResult[26]++;
		else
			massResult[s[i] - 97]++;
	}

	for (int i = 0; i < 27; i++) {
		massFrequency[i] = massResult[i] / strlen(s);
		if (massFrequency[i] > 0 && i<26)
			printf("%c=%.2f ", i + 97, massFrequency[i]);
	}  

	printf("space=%.2f", massFrequency[26]);

	return 0;
}