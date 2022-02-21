#include <iostream>
#include <string>
#include <vector>
using namespace std;




vector<int> decTobin(int a) {
  vector<int> binary_msg;


}


int main() {
  
  string user_message;
  vector<int> binary_message;

  cout << "Type the message to cypher: ";
  cin >> user_message;
  cout << user_message << endl;

  int store_msg[user_message.length()];
  for (int string_iterator = 0; string_iterator < user_message.length(); ++string_iterator){
    store_msg[string_iterator] = user_message[string_iterator];
    cout << store_msg[string_iterator] << " ";
  }
  cout << endl;
  binary_message = decTobin(store_msg);

  /*
  int a,b,c,d,e;
  a = 1 xor 0;
  b = 0 xor 0;
  c = 0 xor 1;
  d = 1 xor 1;
  e = 'H';
  cout << a << " " << b << " " << c << " " << d << " " << e << endl;
  */
/*
 int a[3*2];
 for (int i = 0; i < 6; ++i) {
   a[i] = 1;
 }
 for (int i = 0; i < 6; ++i) {
   cout << a[i];
 }
 cout << endl;
 */
}



