#include <bits/stdc++.h>
using namespace std;

class String{
public: 
    string str;
    String();
	String(string s){
        str = s;
    }
    void trimFrontBack(){
        while (isspace(str[0])){
            str.erase(0,1);
        }
        while (isspace(str[str.length()-1])){
            str.erase(str.length()-1);
        }
    }
    void trimExtraSpaces(){
        for (int i=0; i<str.length(); i++){
            if (isspace(str[i]) && isspace(str[i-1])){
                str.erase(i,1);
            }
        }
    }
    void uppercase(){
        for (int i=0; i<str.length(); i++){
            str[i] = toupper(str[i]);
        }
    }
    void lowercase(){
        for (int i=0; i<str.length(); i++){
            str[i] = tolower(str[i]);
        }
    }
    void append(){
        string apd;
        cout << "Nhập xâu ký tự nối thêm: "; cin >> apd;
        str += apd;
    }
    string extractRight(int n){
        if (n>str.length()){
            return str;
        }
        else{
            return str.substr(str.length()-n);
        }
    }
    string extractLeft(int n){
        if (n>str.length()){
            return str;
        }
        else{
            return str.substr(0, n);
        }
    }
    string extractMid(int i, int n){
        if (i+n>str.length()){
            return str.substr(i, str.length()-i);
        }
        else{
            return str.substr(i, n);
        }
    }
    void input(){
        cout << "Nhập xâu: ";
        cin >> str;
    }
    void output(){
        cout << "Kết quả: " << str << endl;
    }
};

void run(){
    String str;
    str.input();
    while(true){
        int choice, n;
        cout << "-------------------------------------------------------\n";
        cout << "Nhập 1 để: Cắt các ký trắng (dấu cách) ở hai đầu của xâu \n";
        cout << "Nhập 2 để: Cắt toàn bộ ký tự trắng thừa có trong xâu \n";
        cout << "Nhập 3 để: Chuyển đổi toàn bộ xâu ký tự thành xâu ký tự hoa \n";
        cout << "Nhập 4 để: Chuyển đổi toàn bộ xâu ký tự thành xâu ký tự thường \n";
        cout << "Nhập 5 để: Thực hiện nối thêm một xâu ký tự vào sau xâu ký tự hiện có \n";
        cout << "Nhập 6 để: Trích ra n ký tự ở phía phải của xâu \n";
        cout << "Nhập 7 để: Trích ra n ký tự ở phía trái của xâu \n";
        cout << "Nhập 8 để: Trích ra n ký tự kể từ vị trí thứ i của xâu \n";
        cout << "Nhập 9 để: Thoát \n";
        cout << "-------------------------------------------------------" << endl;
        cout << "Nhập từ 1-9: "; cin >> choice;
        switch (choice){
        case 1:
            str.trimFrontBack();
            str.output();
            break;
        case 2:
            str.trimExtraSpaces();
            str.output();
            break;
        case 3:
            str.uppercase();
            str.output();
            break;
        case 4:
            str.lowercase();
            str.output();
            break;
        case 5:
            str.append();
            str.output();
            break;
        case 6:
            cout << "Nhập n: "; cin >> n;
            str.extractRight(n);
            break;
        case 7:
            cout << "Nhập n: "; cin >> n;
            str.extractLeft(n);
            break;
        case 8:
            int i;
            cout << "Nhập i: "; cin >> i; cout << "Nhập n: "; cin >> n;
            str.extractMid(i,n);
            break;
        case 9:
            for (int i = 0; i < 6; i++){
                cout << "END" << endl;
            }
            break;
        default:
            cout << "--- Vui lòng nhập số từ 1 đến 8 ---" << endl;
        }
    }
}
int main(){
    run();
    return 0;
}
