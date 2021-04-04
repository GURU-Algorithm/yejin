#include <iostream>

using namespace std;

int myArr[100][100] = {0,};
bool visit[100] = {0,};
int cnt = 0;

void dfs(int start, int M){
  visit[start] = true;
  cnt ++;
  for(int i = 0; i < M; i++){
    if(myArr[start][i] == 1 && visit[i] == false) dfs(i,M);
  }
}

int main() {
  int N, M; // N 컴퓨터수, M 연결된 쌍의 수 cnt ++;
  cin >> N >> M;

  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    myArr[a][b] = 1;
    myArr[b][a] = 1;
  }

  dfs(1, N);
  cout << cnt-1;

  return 0;
}