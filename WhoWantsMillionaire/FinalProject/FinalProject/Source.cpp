#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>
#include <ctime>
#pragma comment(lib, "winmm.lib")
using namespace std;
//globals (ff,ph,ask = used/not used lifelines)
int ff = 1;
int ph = 1;
int ask = 1;
int invalid = 0;

void lifelinestext() {
	if (ff == 1) cout << "\n\t50/50\t";
	else cout << "\t50/50 Used\t";
	if (ph == 1) cout << "Phone\t";
	else cout << "Phone Used\t";
	if (ask == 1) cout << "Ask Audience\t" << endl;
	else cout << "Ask Audience Used\t\n";
}
void askauff(char let, char let2) {
	srand(time(NULL));
	int maxc = 100, minc = 50, maxw = 49, minw = 0;
	int correct = rand() % (maxc - minc + 1) + minc;
	int wrong = 100 - correct;
	char cbar[100];
	char wbar[100];
	for (int i = 0; i <= correct; i++) {
		cbar[i] = char(219);
	}
	cbar[correct + 1] = '\0';
	for (int i = 0; i <= wrong; i++) {
		wbar[i] = char(219);
	}
	wbar[wrong + 1] = '\0';
	if (let == 'a') {
		if (let2 == 'b') {
			cout << "a: "<< cbar << correct << "%" << endl;
			cout << "b: " << wbar << wrong << "%" << endl;
		}
		if (let2 == 'c') {
			cout << "a: " << cbar << correct << "%" << endl;
			cout << "c: " << wbar << wrong << "%" << endl;
		}
		if (let2 == 'd') {
			cout << "a: " << cbar << correct << "%" << endl;
			cout << "d: " << wbar << wrong << "%" << endl;
		}
	}
	else if (let == 'b') {
		if (let2 == 'a') {
			cout << "a: " << wbar << wrong << "%" << endl;
			cout << "b: " << cbar << correct << "%" << endl;
		}
		if (let2 == 'c') {
			cout << "b: " << cbar << correct << "%" << endl;
			cout << "c: " << wbar << wrong << "%" << endl;
		}
		if (let2 == 'd') {
			cout << "b: " << cbar << correct << "%" << endl;
			cout << "d: " << wbar << wrong << "%" << endl;
		}
	}
	else if (let == 'c') {
		if (let2 == 'a') {
			cout << "a: " << wbar << wrong << "%" << endl;
			cout << "c: " << cbar << correct << "%" << endl;
		}
		if (let2 == 'b') {
			cout << "c: " << wbar << wrong << "%" << endl;
			cout << "b: " << cbar << correct << "%" << endl;
		}
		if (let2 == 'd') {
			cout << "c: " << cbar << correct << "%" << endl;
			cout << "d: " << wbar << wrong << "%" << endl;
		}
	}
	else {
		if (let2 == 'a') {
			cout << "d: " << wbar << wrong << "%" << endl;
			cout << "a: " << cbar << correct << "%" << endl;
		}
		if (let2 == 'b') {
			cout << "d: " << wbar << wrong << "%" << endl;
			cout << "b: " << cbar << correct << "%" << endl;
		}
		if (let2 == 'c') {
			cout << "d: " << wbar << wrong << "%" << endl;
			cout << "c: " << cbar << correct << "%" << endl;
		}
	}
}
void phone(char clet, char cran[]) {
	cout << "We are now calling our contestants grandma to help him with this question.\n";
	PlaySound(TEXT("ring_1.wav"), NULL, SND_FILENAME);
	Sleep(1400);
	PlaySound(TEXT("ring_1.wav"), NULL, SND_FILENAME);
	Sleep(850);
	PlaySound(TEXT("pick-up.wav"), NULL, SND_FILENAME);
	cout << "Grandma: Hello?\n";
	Sleep(850);
	cout << "Hi, we are callig from Who wants to be a Millioner\nand your grandson is playing.\n";
	Sleep(850);
	cout << "He really needs your help with the question.\n";
	Sleep(850);
	cout << "Grandma: Oh i have been watching, the answer is clearlly " << clet << ": " << cran << ".\n I am 100% sure.\n";
	Sleep(850);
	cout << "We thank grandma very much for the help, lets see the answer now.\n";

}
int ffcheck(char corr[], char wron[], char corl, char wrl) {
	string an;
	char an2[100]{};
	int loop = 0;
	do {
		loop = 0;
		getline(cin, an);
		for (int i = 0; i < an.length(); i++) {
			an2[i] = an[i];
		}
		if (an.length() == 1) {
			if (an[0] == corl ||  an[0] == corl - 32) {
				return 0;
			}
			else if (an[0] == wrl || an[0] == wrl - 32) {
				return 1;
			}
		}
		if (strcmp(an2, corr) == 0){
			return 0;
		}
		else if (strcmp(an2, wron) == 0) {
			return 1;
		}
		else if (an == "50/50") {
			cout << "Already used\n" << ">>";
			loop = 1;
			continue;
		}
		else if (an == "Phone" || an == "phone") {
			if (ph == 1) {
				ph = 0;
				phone(corl,corr);
				loop = 1;
				continue;
			}
			else {
				cout << "Already used\n" << ">>";
				loop = 1;
				continue;
			}
		}
		else if (an == "Ask Audience" || an == "ask audience" || an == "Ask audience") {
			if (ask == 1) {
				ask = 0;
				askauff(corl, 'b');
				cout << ">>";
				loop = 1;
				continue;
			}
			else {
				cout << "Already used\n" << ">>";
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
}
int fiftyfifty(char letter, char c1[], char wr1[], char wr2[], char wr3[]) {
	srand(time(NULL));
	int ran = rand() % 3 + 1;
	int wrff = 0;
	char wrletter;
	if (letter == 'a') {
		if (ran == 1) {
			wrletter = 'b';
			cout << "\ta:" << c1 << "\t\tb:" << wr1 << endl;
			cout << "\tc:" << "\t\td:" << endl;
			lifelinestext();
			do {
				invalid = 0;
				wrff = ffcheck(c1, wr1, letter, wrletter);
			} while (invalid == 1);
		}
		else if (ran == 2) {
			wrletter = 'c';
			cout << "\ta:" << c1 << "\t\tb:" << endl;
			cout << "\tc:" << wr2 << "\t\td:" << endl;
			lifelinestext();
			do {
				invalid = 0;
				wrff = ffcheck(c1, wr1, letter, wrletter);
			} while (invalid == 1);
		}
		else {
			wrletter = 'd';
			cout << "\ta:" << c1 << "\t\tb:" << endl;
			cout << "\tc:" << "\t\td:" << wr3 << endl;
			lifelinestext();
			do {
				invalid = 0;
				wrff = ffcheck(c1, wr1, letter, wrletter);
			} while (invalid == 1);
		}
	}
	else if (letter == 'b') {
		if (ran == 1) {
			wrletter = 'a';
			cout << "\ta:" << wr1 << "\t\tb:" << c1 << endl;
			cout << "\tc:" << "\t\td:" << endl;
			lifelinestext();
			do {
				invalid = 0;
				wrff = ffcheck(c1, wr1, letter, wrletter);
			} while (invalid == 1);
		}
		else if (ran == 2) {
			wrletter = 'c';
			cout << "\ta:" << "\t\tb:" << c1 << endl;
			cout << "\tc:" << wr2 << "\t\td:" << endl;
			lifelinestext();
			do {
				invalid = 0;
				wrff = ffcheck(c1, wr1, letter, wrletter);
			} while (invalid == 1);
		}
		else {
			wrletter = 'd';
			cout << "\ta:" << "\t\tb:" << c1 << endl;
			cout << "\tc:" << "\t\td:" << wr3 << endl;
			lifelinestext();
			do {
				invalid = 0;
				wrff = ffcheck(c1, wr1, letter, wrletter);
			} while (invalid == 1);
		}
	}
	else if (letter == 'c') {
		if (ran == 1) {
			wrletter = 'a';
			cout << "\ta:" << wr1 << "\t\tb:" << endl;
			cout << "\tc:" << c1 << "\t\td:" << endl;
			lifelinestext();
			do {
				invalid = 0;
				wrff = ffcheck(c1, wr1, letter, wrletter);
			} while (invalid == 1);
		}
		else if (ran == 2) {
			wrletter = 'b';
			cout << "\ta:" << "\t\tb:" << wr2 << endl;
			cout << "\tc:" << c1 << "\t\td:" << endl;
			lifelinestext();
			do {
				invalid = 0;
				wrff = ffcheck(c1, wr1, letter, wrletter);
			} while (invalid == 1);
		}
		else {
			wrletter = 'd';
			cout << "\ta:" << "\t\tb:" << endl;
			cout << "\tc:" << c1 << "\t\td:" << wr3 << endl;
			lifelinestext();
			do {
				invalid = 0;
				wrff = ffcheck(c1, wr1, letter, wrletter);
			} while (invalid == 1);
		}
	}
	else if (letter == 'd') {
		if (ran == 1) {
			wrletter = 'a';
			cout << "\ta:" << wr1 << "\t\tb:" << endl;
			cout << "\tc:" << "\t\td:" << c1 << endl;
			lifelinestext();
			do {
				invalid = 0;
				wrff = ffcheck(c1, wr1, letter, wrletter);
			} while (invalid == 1);
		}
		else if (ran == 2) {
			wrletter = 'b';
			cout << "\ta:" << "\t\tb:" << wr2 << endl;
			cout << "\tc:" << "\t\td:" << c1 << endl;
			lifelinestext();
			do {
				invalid = 0;
				wrff = ffcheck(c1, wr1, letter, wrletter);
			} while (invalid == 1);
		}
		else {
			wrletter = 'c';
			cout << "\ta:" << "\t\tb:" << endl;
			cout << "\tc:" << wr3 << "\t\td:" << c1 << endl;
			lifelinestext();
			do {
				invalid = 0;
				wrff = ffcheck(c1, wr1, letter, wrletter);
			} while (invalid == 1);
		}
	}
	return wrff;
}
void askau(char let) {
	srand(time(NULL));
	int maxc = 99, minc = 50, maxw = 49, minw = 0;
	int correct = rand() % (maxc - minc + 1) + minc;
	int wrong1 = rand() % ((100 - correct) + 1);
	int wrong2 = rand() % (((100 - correct) - wrong1) + 1);
	int wrong3 = 100 - correct - wrong1 - wrong2;
	char cbar[100];
	char w1bar[100];
	char w2bar[100];
	char w3bar[100];
	for (int i = 0; i <= correct; i++) {
		cbar[i] = char(219);
	}
	cbar[correct+1] = '\0';
	for (int i = 0; i <= wrong1; i++) {
		w1bar[i] = char(219);
	}
	w1bar[wrong1 + 1] = '\0';
	for (int i = 0; i <= wrong2; i++) {
		w2bar[i] = char(219);
	}
	w2bar[wrong2 + 1] = '\0';
	for (int i = 0; i <= wrong3; i++) {
		w3bar[i] = char(219);
	}
	w3bar[wrong3 + 1] = '\0';
	if (let == 'a') {
		cout << "a: " << cbar << correct << "%" << endl;
		cout << "b: " << w1bar << wrong1 << "%" << endl;
		cout << "c: " << w2bar << wrong2 << "%" << endl;
		cout << "d: " << w3bar << wrong3 << "%" << endl;
	}
	else if (let == 'b') {
		cout << "a: " << w1bar << wrong1 << "%" << endl;
		cout << "b: " << cbar << correct << "%" << endl;
		cout << "c: " << w2bar << wrong2 << "%" << endl;
		cout << "d: " << w3bar << wrong3 << "%" << endl;
	}
	else if (let == 'c') {
		cout << "a: " << w2bar << wrong2 << "%" << endl;
		cout << "b: " << w1bar << wrong1 << "%" << endl;
		cout << "c: " << cbar << correct << "%" << endl;
		cout << "d: " << w3bar << wrong3 << "%" << endl;
	}
	else {
		cout << "a: " << w3bar << wrong3 << "%" << endl;
		cout << "b: " << w1bar << wrong1 << "%" << endl;
		cout << "c: " << w2bar << wrong2 << "%" << endl;
		cout << "d: " << cbar << correct << "%" << endl;
	}
}
int quest1() {
	system("cls");
	char cor[] = "4";
	char w1[] = "2";
	char w2[] = "6";
	char w3[] = "8";
	char corlet = 'a';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop = 0;
	cout << "Question 1: \t\t\t\t\t\t 0$\nHow many musicians are there in a quartet?" << endl;
	cout << "\n\ta: " << cor << "\t\tb: " << w1<< "\n\tc: " << w2 << "\t\td: " << w3 << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'a' || ans[0] == 'A') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0 || strcmp(ans, "phone") == 0) {
			if (ph == 1) {
				loop = 1;
				phone(corlet,cor);
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int quest2() {
	system("cls");
	char cor[] = "Recorder";
	char w1[] = "Restorer";
	char w2[] = "Rewinder";
	char w3[] = "Remover";
	char corlet = 'b';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop;
	cout << "Question 2: \t\t\t\t\t\t 500$\nA VCR is a 'video cassette what'?" << endl;
	cout << "\ta:" << w1 << "\tb:" << cor << "\n\tc:" << w3 << "\td:" << w3 << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'b' || ans[0] == 'B') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0 || strcmp(ans, "phone") == 0) {
			if (ph == 1) {
				loop = 1;
				phone(corlet, cor);
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int quest3() {
	system("cls");
	char cor[] = "8";
	char w1[] = "10";
	char w2[] = "6";
	char w3[] = "4";
	char corlet = 'd';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop;
	cout << "Question 3: \t\t\t\t\t\t 1000$\nHow many legs does an arachnid have?" << endl;
	cout << "\ta:" << w1 << "\t\tb:" << w2 << "\n\tc:" << w3 << "\t\td:" << cor << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'd' || ans[0] == 'D') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0) {
			if (ph == 1) {
				loop = 1;
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int quest4() {
	system("cls");
	char cor[] = "Pandora's v";
	char w1[] = "Jessica's";
	char w2[] = "Sophie's";
	char w3[] = "Sabrina's";
	char corlet = 'b';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop;
	cout << "Question 4: \t\t\t\t\t\t 2000$\nIn Greek mythology, whose box contained all the evils of the world?" << endl;
	cout << "\ta:" << w1 << "\tb:" << cor << "\n\tc:" << w2 << "\td:" << w3 << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'b' || ans[0] == 'B') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0 || strcmp(ans, "phone") == 0) {
			if (ph == 1) {
				loop = 1;
				phone(corlet, cor);
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int quest5() {
	system("cls");
	char cor[] = "Metallica";
	char w1[] = "Megadeth";
	char w2[] = "Led Zeppelin";
	char w3[] = "Black Sabbath";
	char corlet = 'c';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop;
	cout << "Question 5: \t\t\t\t\t\t 3000$\n'Master of Puppets' is considered the album masterpiece of which heavy metal band?" << endl;
	cout << "\ta:" << w1 << "\tb:" << w2 << "\n\tc:" << cor << "\td:" << w3 << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'c' || ans[0] == 'C') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0 || strcmp(ans, "phone") == 0) {
			if (ph == 1) {
				loop = 1;
				phone(corlet, cor);
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int quest6() {
	system("cls");
	char cor[] = "Jimmy Carter";
	char w1[] = "Richard Nixon";
	char w2[] = "John F Kennedy";
	char w3[] = "Ronald Reagan";
	char corlet = 'a';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop;
	cout << "Question 6: \t\t\t\t\t\t 5000$\nPrior to Bill Clinton, who was the last Democrat US president?" << endl;
	cout << "\ta:" << cor << "\t\tb:" << w1 << "\n\tc:" << w2 << "\td:" << w3 << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'a' || ans[0] == 'A') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0 || strcmp(ans, "phone") == 0) {
			if (ph == 1) {
				loop = 1;
				phone(corlet, cor);
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int quest7() {
	system("cls");
	char cor[] = "Emperor";
	char w1[] = "King";
	char w2[] = "Adelie";
	char w3[] = "Humboldt";
	char corlet = 'd';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop;
	cout << "Question 7: \t\t\t\t\t\t 7500$\nWhat is the largest species of penguin?" << endl;
	cout << "\ta:" << w1 << "\t\tb:" << w2 << "\n\tc:" << w3 << "\td:" << cor << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'd' || ans[0] == 'D') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0 || strcmp(ans, "phone") == 0) {
			if (ph == 1) {
				loop = 1;
				phone(corlet, cor);
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int quest8() {
	system("cls");
	char cor[] = "Tolkien";
	char w1[] = "Hardy";
	char w2[] = "Milne";
	char w3[] = "Wells";
	char corlet = 'd';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop;
	cout << "Question 8: \t\t\t\t\t\t 10000$\nWhich British writer had the initials J R R?" << endl;
	cout << "\ta:" << w1 << "\t\tb:" << w2 << "\n\tc:" << w3 << "\t\td:" << cor << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'd' || ans[0] == 'D') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0 || strcmp(ans, "phone") == 0) {
			if (ph == 1) {
				loop = 1;
				phone(corlet, cor);
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int quest9() {
	system("cls");
	char cor[] = "Islamabad";
	char w1[] = "Karachi";
	char w2[] = "Lahore";
	char w3[] = "Rawalpindi";
	char corlet = 'b';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop;
	cout << "Question 9: \t\t\t\t\t\t 15000$\nWhat is the capital of Pakistan?" << endl;
	cout << "\ta:" << w1 << "\tb:" << cor << "\n\tc:" << w2 << "\td:" << w3 << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'b' || ans[0] == 'B') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0 || strcmp(ans, "phone") == 0) {
			if (ph == 1) {
				loop = 1;
				phone(corlet, cor);
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int quest10() {
	system("cls");
	char cor[] = "Cain";
	char w1[] = "Kevin";
	char w2[] = "Connagh";
	char w3[] = "Chris";
	char corlet = 'c';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop;
	cout << "Question 10: \t\t\t\t\t\t 25000$\nIn the Bible, who is Abel's brother?" << endl;
	cout << "\ta:" << w1 << "\t\tb:" << w2 << "\n\tc:" << cor<< "\t\td:" << w3 << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'c' || ans[0] == 'C') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0 || strcmp(ans, "phone") == 0) {
			if (ph == 1) {
				loop = 1;
				phone(corlet, cor);
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int quest11() {
	system("cls");
	char cor[] = "Furies";
	char w1[] = "Angries";
	char w2[] = "Hoppies";
	char w3[] = "Huffies";
	char corlet = 'b';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop;
	cout << "Question 11: \t\t\t\t\t\t 50000$\nIn mythology, Tisiphone, Alecto and Megaera were known as the 'Three ... ?" << endl;
	cout << "\ta:" << w1 << "\tb:" << cor << "\n\tc:" << w2 << "\td:" << w3 << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'b' || ans[0] == 'B') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0 || strcmp(ans, "phone") == 0) {
			if (ph == 1) {
				loop = 1;
				phone(corlet, cor);
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int quest12() {
	system("cls");
	char cor[] = "Orient Express";
	char w1[] = "Eastern Rocket";
	char w2[] = "Balkan Bolter";
	char w3[] = "Asian Flyer";
	char corlet = 'b';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop;
	cout << "Question 12: \t\t\t\t\t\t 75000$\nWhich famous train ran between Paris and Istanbul from 1883 to 1961?" << endl;
	cout << "\ta:" << w1 << "\tb:" << cor << "\n\tc:" << w2 << "\t\td:" << w3 << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'b' || ans[0] == 'B') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0 || strcmp(ans, "phone") == 0) {
			if (ph == 1) {
				loop = 1;
				phone(corlet, cor);
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int quest13() {
	system("cls");
	char cor[] = "Marilyn Monroe";
	char w1[] = "James Dean";
	char w2[] = "Anne Frank";
	char w3[] = "Elvis Presley";
	char corlet = 'a';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop;
	cout << "Question 13: \t\t\t\t\t\t 150000$\nWhich of the following was born first?" << endl;
	cout << "\ta:" << cor << "\tb:" << w1 << "\n\tc:" << w2 << "\t\td:" << w3 << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'a' || ans[0] == 'A') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0 || strcmp(ans, "phone") == 0) {
			if (ph == 1) {
				loop = 1;
				phone(corlet, cor);
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int quest14() {
	system("cls");
	char cor[] = "Alan Alexander";
	char w1[] = "Andrew Algernon";
	char w2[] = "Albert Antony";
	char w3[] = "Arnold Alasdair";
	char corlet = 'c';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop;
	cout << "Question 14: \t\t\t\t\t\t 250000$\nWhat were the first names of Winnie-the-Pooh's creator A A Milne?" << endl;
	cout << "\ta:" << w1 << "\tb:" << w2 << "\n\tc:" << cor << "\td:" << w3 << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'c' || ans[0] == 'C') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0 || strcmp(ans, "phone") == 0) {
			if (ph == 1) {
				loop = 1;
				phone(corlet, cor);
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int quest15() {
	system("cls");
	char cor[] = "Indonesia";
	char w1[] = "India";
	char w2[] = "Thailand";
	char w3[] = "Papua New Guinea";
	char corlet = 'd';
	char ans[100];
	string ans2;
	int onecharcheck = 0;
	int loop;
	cout << "Question 15: \t\t\t\t\t\t 500000$\nIn which country is the island of Java?" << endl;
	cout << "\ta:" << w1 << "\t\t\tb:" << w2 << "\n\tc:" << w3 << "\td:" << cor << endl;
	lifelinestext();
	do {
		loop = 0;
		cin.getline(ans, 100);
		ans2 = ans;
		if (ans2.length() == 1) onecharcheck = 1;
		else onecharcheck = 0;
		if (onecharcheck == 1) {
			if (ans[0] >= 'a' && ans[0] <= 'd' || ans[0] >= 'A' && ans[0] <= 'D') {
				if (ans[0] == 'd' || ans[0] == 'D') {
					cout << "Correct answer" << endl;
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		if (strcmp(ans, cor) == 0) {
			cout << "Correct answer" << endl;
			return 0;
		}
		else if (strcmp(ans, w1) == 0 || strcmp(ans, w2) == 0 || strcmp(ans, w3) == 0) {
			return 1;
		}
		else if (strcmp(ans, "50/50") == 0) {
			if (ff == 1) {
				loop = 1;
				ff = 0;
				return fiftyfifty(corlet, cor, w1, w2, w3);
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Phone") == 0 || strcmp(ans, "phone") == 0) {
			if (ph == 1) {
				loop = 1;
				phone(corlet, cor);
				ph = 0;
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else if (strcmp(ans, "Ask Audience") == 0 || strcmp(ans, "ask audience") == 0 || strcmp(ans, "Ask audience") == 0) {
			if (ask == 1) {
				loop = 1;
				ask = 0;
				askau(corlet);
				cout << ">>";
				continue;
			}
			else {
				cout << "Lifeline already used" << endl;
				loop = 1;
				continue;
			}
		}
		else {
			cout << "Invalid Choice" << endl << "Try Again" << endl;
			invalid = 1;
		}
	} while (invalid == 1 || loop == 1);
	return 0;
}
int main() {
	int stoploop = 0;
	char stop[100]{};
	int qnum = 1, wrong = 0;
	cout << "Welcome to who want's to be a Millionaire " << endl;
	cout << "The rulles are simple, find the correct answer in the next 15 questions and you win a million." << endl;
	cout << "You can use 3 lifelines: " << endl;
	cout << "\t 1)50/50: From the 4 possible answers we delete 2.\n\t   There will be the right answer and one wrong for you to decide from." << endl;
	cout << "\t 2)Phone: You can use the phone to call a relative or a friend to help you with a question." << endl;
	cout << "\t 3)Ask Audience: The audience will help you by voting the answer they think is the correct one,\n\t   then you can choose by seeing the results." << endl;
	cout << "\t You can only use each lifeline 1 time." << endl;
	system("pause");
	while (qnum <= 15 && wrong == 0)
	{
		switch (qnum) {
		case 1:
		{
			wrong = quest1();
			break;
		}
		case 2:
		{
			wrong = quest2();
			break;
		}
		case 3:
		{
			wrong = quest3();
			break;
		}
		case 4:
		{
			wrong = quest4();
			break;
		}
		case 5:
		{
			wrong = quest5();
			cout << "You have reached 5 correct answers and have won 5000$.\n";
			cout << "You can choose to take that money and leave or continue.\n";
			cout << "This choise will only be available again aftes 5 more correct answers.\n";
			cout << "\tChoose: \n\tStop / Continue\n";
			do {
				cin.getline(stop, 100);
				if (strcmp(stop, "Stop") == 0 || strcmp(stop, "stop") == 0) {
					stoploop = 1;
				}
				else if (strcmp(stop, "Continue") == 0 || strcmp(stop, "continue") == 0) {
					stoploop = 1;
				}
				else {
					cout << "Invalide Answer." << " Try again.\n";
				}
			} while (stoploop == 0);
			break;
		}
		case 6:
		{
			wrong = quest6();
			break;
		}
		case 7:
		{
			wrong = quest7();
			break;
		}
		case 8:
		{
			wrong = quest8();
			break;
		}
		case 9:
		{
			wrong = quest9();
			break;
		}
		case 10:
		{
			wrong = quest10();
			cout << "You have reached 10 correct answers and have won 50000$.\n";
			cout << "You can choose to take that money and leave or continue.\n";
			cout << "This is the last time you get this choice.\n";
			cout << "\tChoose: \n\tStop / Continue\n";
			do {
				cin.getline(stop, 100);
				if (strcmp(stop, "Stop") == 0 || strcmp(stop, "stop") == 0) {
					stoploop = 1;
				}
				else if (strcmp(stop, "Continue") == 0 || strcmp(stop, "continue") == 0) {
					stoploop = 1;
				}
				else {
					cout << "Invalide Answer." << " Try again.\n";
				}
			} while (stoploop == 0);

			break;
		}
		case 11:
		{
			wrong = quest11();
			break;
		}
		case 12:
		{
			wrong = quest12();
			break;
		}
		case 13:
		{
			wrong = quest13();
			break;
		}
		case 14:
		{
			wrong = quest14();
			break;
		}
		case 15:
		{
			wrong = quest15();
			break;
		}
		}
		if (strcmp(stop, "Stop") == 0 || strcmp(stop, "stop") == 0) {
			break;
		}
		qnum++;
	}
	if (wrong == 1) {
		cout << "Wrong answer" << endl;
		cout << "You lost all your money." << endl;
		cout << "Even the money you had before you joined the game." << endl;
		cout << "You cry!!" << endl;
		cout << "The End." << endl;
	}
	if (wrong == 0 && qnum < 16) {
		if (qnum == 5) {
			cout << "Congratulations you won 5000$.";
		}
		if (qnum == 10) {
			cout << "Congratulations you won 50000$.";
		}
	}
	if (wrong == 0 && qnum == 16) {
		string winner = "CONGRATULATIONS YOU JUST WON 1MILLI";
		string winner2 = "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO";
		string winner3 = "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOON";
		for (int i = 0; i <= winner.length(); i++) {
			Sleep(100);
			cout << winner[i];
		}
		for (int i = 0; i <= winner2.length(); i++) {
			Sleep(100);
			cout << winner2[i];
		}
		for (int i = 0; i <= winner3.length(); i++) {
			Sleep(100);
			cout << winner3[i];
		}
	}

	return 0;
}