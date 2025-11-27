#include <iostream>
#include <queue>
#define MAX 51
#include <typeinfo>
using namespace std;

int R, C;
char map[MAX][MAX];
pair<int, int> beaver_nest;
queue<pair<int, int> > water_q;
queue<pair<int, int> > hedgehog_q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int result_time;

void bfs(){

    while(!hedgehog_q.empty()){
        int water_start_count = water_q.size();
        for (int i=0; i<water_start_count; ++i){

            int current_water_x = water_q.front().first;
            int current_water_y = water_q.front().second;

            water_q.pop();

            for (int i=0; i<4; ++i){

                int next_water_x = current_water_x + dx[i];
                int next_water_y = current_water_y + dy[i];

                if ((0 <= next_water_x && next_water_x < R) && (0 <= next_water_y && next_water_y < C) 
                && map[next_water_x][next_water_y] == '.'){

                    water_q.push(make_pair(next_water_x, next_water_y));
                    map[next_water_x][next_water_y] = '*';
                }
            }
        }

        int hedgehog_start_count = hedgehog_q.size();

        for (int i=0; i<hedgehog_start_count; ++i){

            int current_hedgehog_x = hedgehog_q.front().first;
            int current_hedgehog_y = hedgehog_q.front().second;

            hedgehog_q.pop();

            for (int i=0; i<4; ++i){

                int next_hedgehog_x = current_hedgehog_x + dx[i];
                int next_hedgehog_y = current_hedgehog_y + dy[i];

                if ((next_hedgehog_x == beaver_nest.first) && (next_hedgehog_y == beaver_nest.second)){
                    result_time++;
                    cout << result_time;
                    return;
                }

                if ((0 <= next_hedgehog_x && next_hedgehog_x < R) && (0 <= next_hedgehog_y && next_hedgehog_y < C) 
                && map[next_hedgehog_x][next_hedgehog_y] == '.'){

                    hedgehog_q.push(make_pair(next_hedgehog_x, next_hedgehog_y));
                    map[next_hedgehog_x][next_hedgehog_y] = 'S';
                }
            }
        }

        result_time++;
    }

    cout << "KAKTUS";

    return;
}

int main(){

    cin >> R >> C;

    string row;
    for (int i=0; i<R; ++i){
        cin >> row;
        for (int j=0; j<C; ++j){
            map[i][j] = row[j];
            if (row[j] == 'S'){
                hedgehog_q.push(make_pair(i,j));
            }
            else if (row[j] == 'D'){
                beaver_nest = make_pair(i,j);
            }
            else if (row[j] == '*'){
                water_q.push(make_pair(i,j));
            }
        }
    }

    bfs();

}