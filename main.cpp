#include <iostream>
using namespace std;
#include <stdlib.h>
#include "R.h"

int rotors[3][26]={0};
int sett[3];

int main(){
for(int i = 0;i<3;i++){
    for(int j = 0;j<26;j++){
        rotors[i][j]=rand()%26;
    }
}
cout<<"Enter message\r\n>";
string mess=GetStr();
int len = GetLen(mess);
cout<<"Enter your set\r\n";
for(int i = 0;i<3;i++){
    int k = 0;
    cin>>k;
    k%=26;
    sett[i]=k;
}
//Encryption
string encrypted;
for(int i = 0;i<len;i++){
    char ch = mess[i];
    int summ=0;
    for(int j = 0;j<3;j++){
        int k = 0;
        int shftd = sett[j];
        shftd%=26;
        k=rotors[j][shftd];
        sett[j]=sett[j]+1;
        summ+=k;
    }
    ch-=97;
    ch+=summ;
    ch%=26;
    ch+=97;
    encrypted+=ch;
}
cout<<encrypted;
//Decryption
string decrypted;
cout<<"\r\nEnter your set\r\n>";
for(int i = 0;i<3;i++){
    int k = 0;
    cin>>k;
    k%=26;
    sett[i]=k;
}
for(int i = 0;i<len;i++){
    char ch = encrypted[i];
    int summ=0;
    for(int j = 0;j<3;j++){
        int k = 0;
        int shftd = sett[j];
        shftd%=26;
        k=rotors[j][shftd];
        sett[j]=sett[j]+1;
        summ+=k;
    }
    ch-=97;
    ch-=summ;
    while(ch<0){
        ch+=26;
    }
    ch+=97;
    decrypted+=ch;
}
cout<<decrypted;
return 0;
}
