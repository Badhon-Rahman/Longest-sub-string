#include <iostream>

using namespace std;

int font = -1, rear = -1, longestStr = 0;
int DisplaySubString(string str){
          if(font == rear){
            cout << str[font];
            longestStr++;
          }
          else{
             for(int j = font; j < rear; j++){
                 cout << str[j];
                 longestStr++;
             }
          }
        cout << endl;
        cout << "The longest string length: " << longestStr << endl;
}

int LongestSubString(string str){
         int strSize = str.length() - 1;
         for(int i = 0; i < strSize; i++){

            if(font == -1 && rear == -1){
                font += 1;
                rear += 1;
            }
            else{
                rear += 1;
                     for(int x = font; x < rear; x++){

                         if(str[x] == str[rear]){
                            if(rear == strSize - 1){
                                font = rear;
                                DisplaySubString(str);
                                return 0;
                            }
                            else if((strSize - rear) > (strSize / 2)){
                                font = rear;
                                break;
                            }
                            else if((strSize - rear) < (strSize / 2)){
                                DisplaySubString(str);
                                return 0;
                            }
                         }
                    }
                }
         }
}

int main()
{
    string str = "BBaaBB";
    LongestSubString(str);
    return 0;
}
