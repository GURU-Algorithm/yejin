#include <iostream>
 
#define endl "\n"
#define MAX 1010
using namespace std;
 
int N, M;
int MAP[MAX][MAX];
int Candy[MAX][MAX];
 
int Max(int A, int B) { if (A > B) return A; return B; }
 
void Input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
 
void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            Candy[i][j] = Max(Max(Candy[i - 1][j], Candy[i][j - 1]), Candy[i - 1][j - 1]) + MAP[i][j];
        }
    }
    cout << Candy[N][M] << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}


