#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  

  int T;
  cin >> T;

  string str1 = "X won";
  string str2 = "O won";
  string str3 = "Draw";
  string str4 = "Game has not completed";
  string ans;


	for(int test_case = 1; test_case <= T; ++test_case){
    string myArr[4][4];
    int Onum = 0;
    int Xnum = 0;
    int empty = 0;

    //4*4칸에 넣는 코드 작성
    for(int i = 0; i < 4; i++){
      string tmp;
      cin >> tmp;
      for(int j = 0; j < 4; j++){
        myArr[i][j] = tmp[j];
        if(myArr[i][j] == ".") empty++;
      }
    }
    
    //가로축 확인
    for(int i = 0; i < 4; i ++){
      int tmpO=0;
      int tmpX=0;
      for(int j=0 ; j<4 ;j++){
        if(myArr[i][j]=="O") tmpO++;
        if(myArr[i][j]=="X") tmpX ++;
        if(myArr[i][j]=="T") {
          tmpX++;
          tmpO++;
        }
      }
      if(tmpO == 4) Onum++;
      if(tmpX == 4) Xnum++;
    }

    //세로축 확인
    for(int i = 0; i < 4; i ++){
      int tmpO=0;
      int tmpX=0;
      for(int j=0 ; j<4 ;j++){
        if(myArr[j][i]=="O") tmpO++;
        if(myArr[j][i]=="X") tmpX ++;
        if(myArr[j][i]=="T") {
          tmpX++;
          tmpO++;
        }
      }
      if(tmpO == 4) Onum++;
      if(tmpX == 4) Xnum++;
    }
    
    //오른쪽 아래 대각선
    int tmpO =0;
    int tmpX =0;
    for(int i=0; i<4; i++){
      if(myArr[i][i]=="O") tmpO++;
      if(myArr[i][i]=="X") tmpX++;
      if(myArr[i][i]=="T"){
        tmpX++;
        tmpO++;
      }
    }
    if(tmpO==4) Onum++;
    if(tmpX==4) Xnum++;

    tmpO = 0;//초기화
    tmpX = 0;//초기화
    //왼쪽 위 대각선
    // 0,3  1,2  2,1  3,0
    int dx[4] = {0,1,2,3};
    int dy[4] = {3,2,1,0};
    for(int i = 0; i < 4; i++){
      if(myArr[dx[i]][dy[i]]=="O") tmpO++;
      if(myArr[dx[i]][dy[i]]=="X") tmpX++;
      if(myArr[dx[i]][dy[i]]=="T"){
        tmpX++;
        tmpO++;
      }
    }
    if(tmpO==4) Onum++;
    if(tmpX==4) Xnum++;

    //최종출력
    if(empty == 0){ //가득찼음.
      if(Onum < Xnum) ans = str1;
      else if(Onum > Xnum) ans = str2;
      else ans = str3;
    }
    else{ //아직 안끝났음.
      if(Onum < Xnum) ans = str1;
      else if(Onum > Xnum) ans = str2;
      else ans = str4;
    }

    cout << "#" << test_case << " " << ans << endl;

	}
	return 0;
}