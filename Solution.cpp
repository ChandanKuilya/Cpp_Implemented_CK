#include <bits/stdc++.h>
using namespace std;

bool possibilityOfCrossing(int &p, int &a, int &b,int &pw,int arr[]) {
   // int enemyPowers[] = {k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11}; 
    //int enemyPowers[] = {15,14,13,45,11,17,19,10,9,21,33};
    //int enemyPowers[] = {10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60};
    //int enemyPowers[] = {10,9,8,7,12,1,5,11,4,3,2};
    int enemyPowers[11];
    for(int i=0;i<11;i++){
        enemyPowers[i]=arr[i];
    }
    int n=11;

    int currentPower = p;
    int skipCount = a;
    int rechargeCount = b;
    int rechargeAmount=pw;

    for (int i = 0; i < 11; i++) {
        if (currentPower < enemyPowers[i]) {
            return false;  // Abhimanyu loses the battle
        }
        
        if (skipCount > 0) {
        if(i<n-1 && (currentPower-enemyPowers[i])<enemyPowers[i+1]){
            skipCount--;
            continue;  // Skip battling
        }
          else{
            currentPower -= enemyPowers[i];

            if (rechargeCount > 0 && i < n - 1) {
            currentPower+=rechargeAmount;
            rechargeCount--;

            // Recharging  Abhimanyu's power(if possible) by the certain amount(pw)
            // and updating currentPower accordingly
          }
         }

         }
         else{
            currentPower -= enemyPowers[i];
            if (rechargeCount > 0 && i < n - 1) {
            currentPower+=rechargeAmount;
            rechargeCount--;

            // Recharging  Abhimanyu's power by the certain amount(pw)
            // and updating currentPower accordingly
          }
         }

        if(i==3 || i==7 ){
            currentPower -= (enemyPowers[i-1]/2);     // position 3 and 7 here represents k4 and k8 (as 0 indexed) which are iteratively next to k3 and k7, -->
            // --> So,Abhimanyu can be attacked from back here.
        }
    }

    return true;  // Abhimanyu successfully crosses the Chakravyuha
}

int main() {
 
 int arr[11];  // This arr elements would represent the 11 enemy powers :  k1,k2,k3.....k11
 cout<<"Enter the powers of enemies from k1 to k11: "<<'\n';
 for(int i=0;i<11;i++){
    cin>>arr[i];
 }

    // Test cases
    // Test Case 1
    int p1 = 20;
    int a1 = 2;
    int b1 = 1;
    int pw1=13;
    cout << "Test Case 1: " << (possibilityOfCrossing(p1, a1, b1,pw1,arr) ? "Yes" : "No") << '\n' ;
     //int arr1[11]={10,9,8,7,12,1,5,11,4,3,2}; gives "NO" output i.e Abhimanyu can not cross the Chakravyuh.

    // Test Case 2
    int p2 = 80;
    int a2 = 1;
    int b2 = 0;
    int pw2=20;
    cout << "Test Case 2: " << (possibilityOfCrossing(p2, a2, b2,pw2,arr) ? "Yes" : "No") << '\n' ;
    //int arr2[11]={10,9,8,7,12,1,5,11,4,3,2};  gives "Yes" output i.e Abhimanyu can cross the Chakravyuh.

    // Test Case 3
    int p3 = 150;
    int a3 = 3;
    int b3 = 2;
    int pw3=40;
    cout << "Test Case 3: " << (possibilityOfCrossing(p3, a3, b3,pw3,arr) ? "Yes" : "No") << '\n' ;
      // int arr3[11]={10,9,8,7,12,1,5,11,4,3,2}; gives "Yes" output i.e Abhimanyu can cross the Chakravyuh.

    // Test Case 4
    int p4 = 25;
    int a4 = 1;
    int b4 = 2;
    int pw4=5;
    cout << "Test Case 4: " << (possibilityOfCrossing(p4, a4, b4,pw4,arr) ? "Yes" : "No") << '\n' ;
      // int arr4[11]={10,9,8,7,12,1,5,11,4,3,2}; gives "No" output i.e Abhimanyu can not cross the Chakravyuh.

    return 0;
}
