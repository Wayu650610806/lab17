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
void randData(double *adata,int N,int M){
    for(int i = 0; i < N*M; i++){
        *(adata+i) = rand()%101*0.01;
    }
}
void showData(double *adata,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << *(adata+i);
        if((i+1)%M==0) cout << endl;
        else cout << " ";
    }
}
void findRowSum(const double *a,double *b,int n,int m){
	
		for(int j=0;j<n;j++){
			*(b+j)=0;
			for(int i=0;i<n*m;i++){
				if((m*(j+1))>=(i+1)&&(m*j)<(i+1)){
				*(b+j)+=*(a+i);
				}
			}
			
		}
	
}
void findColSum(const double *a,double *b,int n,int m){
	for(int j=0;j<m;j++){
			*(b+j)=0;
			for(int i=0;i<n*m;i++){
				if((i)%m==(j)){
				*(b+j)+=*(a+i);
				}
			}
			
		}
}