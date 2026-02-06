#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}
void randData(double *p, int N, int M){
    for(int i = 0; i < N*M; i++){
        p[i] = (double)rand() / RAND_MAX;
    }
}
void showData(double *p, int row, int col){
    cout << fixed << setprecision(2);

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << *(p + i*col + j) << " ";
        }
        cout << endl;
    }
}
void findRowSum(const double *p, double *sum, int N, int M){
    for(int i = 0; i < N; i++){
        sum[i] = 0;
        for(int j = 0; j < M; j++){
            sum[i] += *(p + i*M + j);
        }
    }
}
void findColSum(const double *p, double *sum, int N, int M){
    for(int j = 0; j < M; j++){
        sum[j] = 0;
        for(int i = 0; i < N; i++){
            sum[j] += *(p + i*M + j);
        }
    }
}
