#include<bits/stdc++.h>

using namespace std;
#define boost        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  boost;
  int H,W;
  cin>>H>>W;
  char ch;
  int arr[H][W];
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++){
      cin>>ch;
      if(ch=='#')
        arr[i][j]=1;
      else
        arr[i][j]=0;
    }
    bool flag=true;
    int total=0;
    while(1){
      flag=true;
      for(int i=0;i<H;i++){  //checking is there any white spots in the board
        for(int j=0;j<W;j++){
          if(arr[i][j]==0){
            flag=false;
            break;
          }
        }
      if(flag==false)
          break;}
      if(flag)  //all turn to black so break out of loop
        break;
      else{
        total++;
        for(int i=0;i<H;i++){ // finding all the black spots and making all side of it white
          for(int j=0;j<W;j++){
            if(arr[i][j]==total){
              if(i-1>=0 && arr[i-1][j]==0) //upper block
                arr[i-1][j]=arr[i][j]+1;
              if(i+1<H && arr[i+1][j]==0) //lower block
                arr[i+1][j]=arr[i][j]+1;
              if(j-1>=0 && arr[i][j-1]==0) //left block
                arr[i][j-1]=arr[i][j]+1;
              if(j+1<W && arr[i][j+1]==0) //right block
                arr[i][j+1]=arr[i][j]+1;
            }
          }
        }
      }
    }
    cout<<total;
    return 0;
}
