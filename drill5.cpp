#include "std_lib_facilities.h"


int main()
{
int i = 0;
try {

	cout << ++i << ".  Success!" << "\n";
	cout << ++i << ".  Success!" << "\n";
	cout << ++i << ".  Success!" << "\n";
	cout << ++i << ".  Success!" << "\n";

	int res = 7; vector<int> v(10); v[5] = res; 
		cout << ++i << ".  Success!" << "\n";

	vector<int> v1(10); v1[5] = 7; 
		if (v1[5]==7) cout << ++i << ".  Success!" << "\n";

	bool cond = true; 
		if (cond) cout << ++i << ".  Success!" << "\n";
		else cout << "Fail!\n";

	bool c = false; 
		if (!c) cout << ++i << ".  Success!" << "\n";
		else cout << "Fail!\n";

	string s = "ape"; bool c1 = "fool"<s; 
		if (!c1) cout << ++i << ".  Success!" << "\n";

	string s1 = "ape"; 
		if (s1!="fool") cout << ++i << ". Success!" << "\n";

	string s2 = "ape"; 
		if (s2!="fool") cout << ++i << ". Success!" << "\n";

	string s3 = "ape"; 
		if (s3<"fool") cout << ++i << ". Success!" << "\n";

	vector<char> v2(5); 
		for (int i=0; i<v2.size(); ++i); cout << ++i << ". Success!" << "\n";

	vector<char> v3(5); 
		for (int i=0; i<v3.size(); ++i) ; cout << ++i << ". Success!" << "\n";

	string s4; 
		for (int i=0; i<s4.length(); ++i) cout << s4[i];
			if (true) cout << ++i << ". Success!" << "\n";
			else cout << "Fail!\n";

	int x = 2000; char c2 = x; 
		if (c2 != 2000) cout << ++i << ". Success!" << "\n"; 
		cout<<++i<<". ";
	
	string s5 = "Success!\n"; 
		for (int i=0; i<s5.length(); ++i) cout << s5[i];

	vector <string> v4(5); 
		for (int i=0; i<=v.size(); ++i); cout << ++i << ". Success!" << "\n";

	int i1=0; int j = 9; 
		while (i1 != 10) ++i1; 
			if (j<i1) cout << ++i << ". Success!" << "\n";

	int x1 = 2; double d = 5/double(x1); 
		if (d==2+0.5) cout << ++i << ". Success!" << "\n";

	cout<<++i<<". ";
	string s6 = "Success!\n"; 
		for (int i=0; i<=10; ++i) cout << s6[i];

	int i2=0; int j2 = 9; 
		while (i2<10) ++i2; 
			if (j2<i2) cout << ++i << ". Success!" << "\n";

	int x2 = 4; double d2 = 5/double(x2-2); 
		if (d2==2+0.5) cout << ++i << ". Success!" << "\n";


cout << ++i << ". Success!" << "\n";
keep_window_open();
return 0;

}

catch (exception& e) {
cerr << "error: " << e.what() << '\n';
keep_window_open();
return 1;

}

catch (...) {
cerr << "Oops: unknown exception!\n";
keep_window_open();
return 2;

}
}