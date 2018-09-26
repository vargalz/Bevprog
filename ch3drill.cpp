#include "std_lib_facilities.h"

int main()
{
cout << "Enter the name of the person you want to write to:\n";
string first_name;
cin >> first name;
cout << "Dear " << first_name << ",\n";
cout << "How are you? I am fine. I miss you.\n"
cout << "Write the name of the friend you want to talk about:\n";
string friend_name;
cin >> friend_name; 
cout << "Have you seen " << friend_name << "lately?.\n";
cout << "Enter an m if the friend is male and an f if the friend is female.\n";
char friend_gender = ' ';
cin >> friend_gender;
if (friend_gender=='m')
{
cout << "If you see " << friend_name << ""please ask him to call me.\n";
}
else if (friend_gender=='f')
{
cout << If you see " << friend_name << " please ask her to call me.\n";
}
cout << “I hear you just had a birthday and you are age years old.”
int age;
string simple_error="you're kidding!";
cin >> age;
if (age<=0)
{
cout << simple_error <<'\n';
}
else if (age>=110)
{
cout << simple_error <<'\n';
}
else
{ /*open*/ 
cout << "i heard you just had a birthday and now you are " << age << " years old.\n";

if (age<=12) 
{
cout << "next year you will be " << age+1 << "\n";
}
else if (age=17)
{
cout << "Next year you will be able to vote.\n";
}
else if (age>=70)
{
cout << "I hope you are enjoying retirement.\n";
}

/*close*/ }

string name;
cout<<"please enter your name:";
cin>> name;
cout << "\Yours sincerely,\n\n" <<name;
}