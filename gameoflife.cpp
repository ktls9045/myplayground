#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

class LifeGame{
private:
    int row, col;
    vector<vector<int>> matrix;

public:
    LifeGame(int row = 10, int col = 10){
        this->row = row;
        this->col = col;
    }
    void init(double);
    void update(int);
    void update_1();
    void show();
};

void LifeGame::init(double p = 0.5){
    default_random_engine random(time(NULL));
    uniform_real_distribution<double> dis(0, 1);
    for(int i = 0; i < row; ++i){
        vector<int> tmp;
        for(int j = 0; j < col; ++j){
            if(dis(random) < p)
                tmp.push_back(1);
            else
                tmp.push_back(0);
        }
        matrix.push_back(tmp);
    }
}

void LifeGame::show(){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void LifeGame::update(int cnt = 100){
    for(int i = 0; i < cnt; ++i){
        show();
        update_1();
        Sleep(200);
        system("cls");
    }
}

void LifeGame::update_1(){
    int k1[8][2] = {{-1, -1}, {-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1}};
    vector<vector<int>> matrix_tmp(row, vector<int>(col, 0));
    for(int i = 1; i < row-1; ++i){
        for(int j = 1; j < col-1; ++j){
            for(int k = 0; k < 8; ++k){
                matrix_tmp[i][j] += matrix[i+k1[k][0]][j+k1[k][1]];
            }
        }
    }
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(matrix[i][j] == 0 && matrix_tmp[i][j] == 3){
                matrix[i][j] = 1;
            }
            else if(matrix[i][j] == 1 && (matrix_tmp[i][j] == 2 || matrix_tmp[i][j] == 3)){
                matrix[i][j] = 1;
            }
            else{
                matrix[i][j] = 0;
            }
        }
    }
}

int main(){
    LifeGame a(20, 20);
    a.init(0.5);
    a.update();
    return 0;
}
