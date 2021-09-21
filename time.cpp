#include <iostream>
#include <ctime>
using namespace std;

int main() {

  // use time() with NULL argument
  //   cout << time(NULL);

  time_t current_time;
  
  // stores time in current_time
  time(&current_time);

  cout << current_time;
  cout << " seconds has passed since 00:00:00 GMT, Jan 1, 1970";
  return 0;
}