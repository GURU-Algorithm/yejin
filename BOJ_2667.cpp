#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[25][25]={0,};
bool visited[25][25]={0,};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int len, cnt =0;
string tmp;

vector<int> num_vec;

void dfs(int x, int y){
  cnt++;
  visited[x][y] = 1;

  for(int i=0; i <4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    
    if(ny<0 || ny>=len || nx<0 || nx>=len)
      continue;
    //방문 안했고, 배추 있으면 계속 탐색
    if(arr[nx][ny] && !visited[nx][ny]){
      dfs(nx,ny);
    }
  }
}

int main() {
  cin >> len;
  for(int i = 0; i < len; i++){
    cin >> tmp;
    for(int j = 0; j < len; j++){
      arr[i][j] = tmp[j] - '0'; //문자열숫자로
    }
  }

  for(int i=0; i < len; i++){
    for(int j = 0; j < len;j++){
      if(arr[i][j]==1 && !visited[i][j]){
        cnt = 0;
        dfs(i,j);
        num_vec.push_back(cnt);
      }
    }
  }

  sort(num_vec.begin(), num_vec.end());
  cout << num_vec.size() << endl;
  for(int i = 0;i < num_vec.size(); i++)
    cout << num_vec[i] << endl;
  return 0;
}