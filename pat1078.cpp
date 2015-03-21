#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int TSize, N, m;

int isPrime(int k)
{
	if (k == 1 || k == 0) {
		return 0;
	}
	for (int i = 2; i <= sqrt(k); i++) {
		if (k % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	scanf("%d%d", &TSize, &N);

	if (!isPrime(TSize)) {
		for (int i = TSize+1; i <= 2*TSize; i++) {
			if (isPrime(i)) {
				TSize = i;
				break;
			}
		}
	}

	int *hashTable = (int *) malloc(TSize * sizeof(int));
	for (int i = 0; i < TSize; i++) {
		hashTable[i] = 0;
	}

	int maxProbe = TSize;
	for (int i = 0; i < N; i++) {
		scanf("%d", &m);
		int pos = m % TSize;
		int j = 0;
		for (j = 0; j < maxProbe; j++) {
			int apos = (pos + j*j) % TSize;
			if (hashTable[apos] == 0) {
				hashTable[apos] = m;
				printf("%d", apos);
				break;
			}
		}
		if (j == maxProbe) {
			printf("-");
		}
		if (i < N-1) {
			printf(" ");
		}
	}
	return 0;
}