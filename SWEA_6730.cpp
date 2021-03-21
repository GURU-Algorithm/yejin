#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool desc(int a, int b){
  return a > b;
}


int main(int argc, char** argv){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int T;
  cin>> T;

	for(int test_case = 1; test_case <= T; ++test_case){
    vector<int> v;
    vector<int> diff_1; //올라가기
    diff_1.push_back(0);
    vector<int> diff_2; //내려가기
    diff_2.push_back(0);

		int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
      int tmpint;
      cin >> tmpint;
      v.push_back(tmpint);
    }

    for(int i = 0; i < N-1; i++){
      if(v[i] - v[i+1] < 0){ //올라가기
        diff_1.push_back(abs(v[i]-v[i+1]));
      }
      else if(v[i] - v[i+1] > 0){ //내려가기
        diff_2.push_back(abs(v[i]-v[i+1]));
      }
    }


    sort(diff_1.begin(),diff_1.end(), desc);
    sort(diff_2.begin(),diff_2.end(), desc);
        
    cout << "#" << test_case << " " << diff_1[0] << " " << diff_2[0] << endl;

	}
	return 0;
}