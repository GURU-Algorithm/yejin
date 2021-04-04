#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int N; // 체스판길이
int minNum[300][300]; //최소이동횟수
bool visit[300][300]; //방문여부
pair<int,int> Now, End;
queue<pair<int,int>> Q;

void BFS(int x, int y){
  Q.push(make_pair(x, y));
  visit[x][y] = true;
  while(!Q.empty()){
    int x = Q.front().first;
    int y = Q.front().second;
    Q.pop();

    if(x == End.first && y == End.second){
      cout << minNum[x][y] << endl;
      while(!Q.empty()) Q.pop();
      break;
    }

  for(int i = 0; i < 8 ; i++){
    int tx = x + dx[i];
    int ty = y + dy[i];

    if(tx >=0 && tx < N && ty >=0 && ty <N){
      if(visit[tx][ty] == false){
        visit[tx][ty] = true; //방문표시
        minNum[tx][ty] = minNum[x][y]+1; // 한칸더감
        Q.push(make_pair(tx,ty));
      }
    }
  }
  }
}




int main(int argc, char** argv){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int T;
	cin >> T;

	for(int test_case = 1; test_case <= T; ++test_case){
    int ans;
    cin >> N;
    cin >> Now.first >> Now.second >> End.first >> End.second;
    BFS(Now.first, Now.second);
    memset(minNum, 0, sizeof(minNum));
    memset(visit, 0, sizeof(visit));

	}
	return 0;
}