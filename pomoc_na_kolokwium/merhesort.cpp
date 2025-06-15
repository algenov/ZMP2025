#include <iostream>

using namespace std;

void merge(int tab[], int left1, int right1, int left2, int right2, int tmp_tab[]){
  int i=left1, j=left2, current=left1;
  while (i<=right1 && j<=right2){
    if (tab[i]<=tab[j]){
      tmp_tab[current]=tab[i];
      i++;
    }
    else {
      tmp_tab[current]=tab[j];
      j++;
    }
    current++;
  }
  if (i>right1 && j<=right2){
    while (j<=right2){
      tmp_tab[current]=tab[j];
      j++;
      current++;
    }
  }
  if (j>right2 && i<=right1){
    while (i<=right1){
      tmp_tab[current]=tab[i];
      i++;
      current++;
    }
  }
  int k=left1;
  while (k<=right2){
    tab[k]=tmp_tab[k];
    k++;
  }
}

void mergesort_pom(int tab[], int left, int right, int tmp_tab[]){
  if (left<right) {
    int mid=(left+right)/2;
    mergesort_pom(tab,left,mid,tmp_tab);
    mergesort_pom(tab,mid+1,right,tmp_tab);
    merge(tab,left,mid,mid+1,right,tmp_tab);
  }
}

void mergesort(int tab[], int size){
  int tmp_tab[size];
  mergesort_pom(tab,0,size-1,tmp_tab);
}

void show_tab(int tab[], int size){
  int i=0;
  while (i<size){
    cout << tab[i] << " ";
    i++;
  }
  cout << "\n";
}

int main(){
  int n;
  cin >> n;
  int tab[n];
  int i=0;
  while (i<n){
    cin >> tab[i];
    i++;
  }
  mergesort(tab,n);
  show_tab(tab,n);
  return 0;
}