#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int a,b,c;
stringstream ss;

int main()
{
	cin >> a>>b;
	c = a+b;
	if (c < 0) {
		cout << "-";
		c = -c;
	}
	string s;
	ss << c;
	ss >> s;
	ss.clear();
	int k = s.size() % 3;
	if (k == 0) {
		k = 3;
	}
	for (int i = 0; i < s.size(); i++, k--) {
		if (k == 0 && i > 0 && i < s.size() - 1) {
			cout << ",";
			k = 3;
		}
		cout << s[i];
	}
	return 0;
}
