#include <iostream>
#include <vector>
#include <algorithm>

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
        int ans = 0;
        int N, K;
        cin >> N >> K;
        
        for(int i = 0; i < N; i++){
            int tmpint;
            cin >> tmpint;
            v.push_back(tmpint);
        }
        
        sort(v.begin(), v.end(), desc);
        
        for(int i = 0; i < K; i ++)ans += v[i];
        

    cout << "#" << test_case << " " << ans << endl;

	}
	return 0;
}