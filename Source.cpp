#include <iostream>
#include <math.h>
#include <time.h>
#include <Windows.h>

using namespace std;

char** makeRandomStrings(char* source, int count, int length){
	srand(GetTickCount());
	char** A = new char*[count];
	for (int i = 0; i < count; i++) {
		A[i] = new char[length + 1];
	}
	for (int i = 0; i < count; i++) {
		int r = rand() % 10 + 1;
		for (int j = 0; j < r; j++) {
			A[i][j] = source[rand() % 36];
		}
		A[i][r] = '\0';
	}
	for (int i = 0; i < 10; i++) {
		cout << A[i] << endl;
	}
	return A;
}

char** copyStrings(char** strings, int count, int length) {
	char** copy = new char*[count];
	for (int i = 0; i < count; i++) {
		copy[i] = new char[length + 1];
	}
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < length; j++) {
			copy[i][j] = strings[i][j];
		}
	}
	return copy;
}

char** radixSort(char** strings, int count) {
	return NULL;
}

void selectionSort(char** strings, int count) {
	cout << endl;
	int i, j, k, minIndex;
	char* tmp;
	bool x = false;
	for (i = 0; i < count; i++) {
		minIndex = i;
		for (j = i + 1; j < count; j++) {
			for (k = 0; k < 10; k++) {
				if (strings[j][k] < strings[minIndex][k]) {
					cout << strings[j] << " < " << strings[minIndex] << endl;
					minIndex = j;
					goto again;
				}
			}
		again:;
			/*k = 0;
			while (strings[j][k] != '\0' && strings[minIndex][k] != '\0') {
				k++;
			}*/
		}
		if (minIndex != i) {
			//swap the min and the beginning of the unsorted section
			tmp = strings[i];
			strings[i] = strings[minIndex];
			strings[minIndex] = tmp;
		}
	}
}

int main() {
	//make the list of characters to choose from
	char lettersAndNumbers[36];
	for (int i = 0; i < 10; i++) {
		lettersAndNumbers[i] = 48 + i;
	}
	for (int i = 10; i < 36; i++) {
		lettersAndNumbers[i] = 65 - 10 + i;
	}
	for (int i = 0; i < 36; i++) {
		cout << lettersAndNumbers[i];
	}
	cout << endl;

	int count = 10;
	int length = 10;
	//while (count <= 50000) {
		cout << "\t\t" << count << endl;
		char** A = makeRandomStrings(lettersAndNumbers, count, length);

		//char** ACopy1 = copyStrings(A, count, length);
		//start timer
		//char** sorted1 = radixSort(ACopy1, count);
		//end timer

		char** ACopy2 = copyStrings(A, count, length);
		//start timer
		selectionSort(A, count);
		//end timer

		cout << "\n\nsorted: " << endl;
		for (int i = 0; i < 10; i++) {
			cout << ACopy2[i] << endl;
		}

		count += 5000;
	//}
	return 0;

}