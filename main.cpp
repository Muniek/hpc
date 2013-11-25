#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//fills given array with data get from serial iteration algorithm
void serial(vector< vector<double> > &res_a, int size, int computations) {
  double h = 1.0/(size - 1);
  
  for(int i = 0; i < size; i++)
    for(int j = 0; j < size; j++)
      res_a[i][j] = 0.0;

  for(int i = 0; i < size - 1; i++)
    res_a[i][0] = pow(sin(M_PI * i * h), 2);

  for(int ci = 0; ci < computations; ci++)
    for(int i = 1; i < size - 1; i++)
      for(int j = 1; j < size - 1; j++)
        res_a[i][j] = 0.25 * (res_a[i - 1][j] + res_a[i + 1][j] + res_a[i][j - 1] + res_a[i][j + 1]); 
}


main()  {
  int n = 50;
  vector< vector<double> > res_serial(n, vector<double>(n));
  serial(res_serial, n, 100);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      cout << res_serial[i][j] << " ";
    cout << endl;
  }
}
