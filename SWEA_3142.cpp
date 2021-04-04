#include <iostream>

using namespace std;

int main(int argc, char** argv){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int T;
  cin >> T;

	for(int test_case = 1; test_case <= T; ++test_case){
    int ans;
    int n,m,Uni,Twin;
    cin >> n >> m;
    // n개 뿔, m마리..   유 x, 트 m-x        x + 2(m-x) = n
    // 2m -x = n
    // 2m -n = x
    Uni = 2*m -n;
    Twin = m - Uni;

    cout << "#" << test_case << " " << Uni << " " << Twin << endl;

	}
	return 0;
}