#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
std::string padStart(const std::string& str, size_t num, char ch) {
    std::string result = str;
    if (num > str.size()) {
        result.insert(0, num - str.size(), ch);
    }
    return result;
}
string a(string str) {
    int i = std::stoi(str.substr(0, 2));
    int i2 = std::stoi(str.substr(2, 2));
    int i3 = std::stoi(str.substr(4, 2));
    int i4 = std::stoi(str.substr(6, 2));
    int i5 = std::stoi(str.substr(8));

    int i6 = i4 ^ i3;
    int i7 = i5 ^ i3;
    int i8 = i3 ^ (i6 + i7);
    int i9 = i ^ i7;
    int i10 = i2 ^ i7;
    return padStart(std::to_string(i9), 2, '0') +
           padStart(std::to_string(i10), 2, '0') +
           padStart(std::to_string(i6), 2, '0') +
           padStart(std::to_string(i7), 2, '0') +
           padStart(std::to_string(i8), 2, '0');
}
string b(string str) {
     int i = std::stoi(str.substr(0, 2));
    int i2 = std::stoi(str.substr(2, 2));
    int i3 = std::stoi(str.substr(4, 2));
    int i4 = std::stoi(str.substr(6, 2));
    int i5 = std::stoi(str.substr(8));

    int i6 = i5 ^ (i3 + i4);
    int i7 = i4 ^ i6;
    int i8 = i3 ^ i6;
    int i9 = i ^ i6;
    int i10 = i2 ^ i6;
    return padStart(std::to_string(i9), 2, '0') +
           padStart(std::to_string(i10), 2, '0') +
           padStart(std::to_string(i8), 2, '0') +
           padStart(std::to_string(i7), 2, '0') +
           padStart(std::to_string(i6), 2, '0');
}

string c(string str){
    int i = std::stoi(str.substr(0, 2));
    int i2 = std::stoi(str.substr(2, 2));
    int i3 = std::stoi(str.substr(4));

    int i5 = i3 ^ (i + i2);
    int i6 = i ^ i5;
    int i4 = i2 ^ i5;

    return padStart(std::to_string(i6), 2, '0') +
           padStart(std::to_string(i4), 2, '0') +
           padStart(std::to_string(i5), 2, '0');
}

string d(string str){
    int i = std::stoi(str.substr(0, 2));
    int i2 = std::stoi(str.substr(2, 2));
    int i3 = std::stoi(str.substr(4));

    int i5 = i2 ^ i;
    int i6 = i3 ^ i;
    int i4 = i ^ (i5 + i6);

    return padStart(std::to_string(i5), 2, '0') +
           padStart(std::to_string(i6), 2, '0') +
           padStart(std::to_string(i4), 2, '0');
}

void middle(string str,char fill)
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bInfo;
    GetConsoleScreenBufferInfo(hOutput, &bInfo);
    int dwSizeX=bInfo.dwSize.X,dwSizey=bInfo.dwSize.Y;
    int len=str.length();
	int x=dwSizeX/2-len/2;
	for(int i=0;i<x;i++){
		cout<<fill;
	}
	
	cout<<str;
	for(int i=x+len;i<dwSizeX;i++){
		cout<<fill;
	}
	cout<<endl;
}
int main(){
	calc: //冒号标签 
	system("cls");
	int mode; 
	system("title 小天才校验码计算器"); 
	middle("小天才校验码计算 - 原ENCODE",'=');
	middle("开发:cmc,汉化:[B站]B-windows10-user",'-') ;
	cout<<"[当前位置]主菜单"<<endl;
	cout<<"0->退出程序"<<endl;
	cout<<"1->调试检验"<<endl;
	cout<<"2->自检校验"<<endl; 
	cout<<"键入模式选择>>";
	cin>>mode;
	if(mode == 0) return 0; //add 
	if(mode==1){
		middle("ADB自检码计算",'=');
		cout<<"[当前位置]主菜单>ADB校验码计算"<<endl;
		cout<<"输入 -1 返回"<<endl;
		cout<<"键入手表显示的数字>>";
		string s;
		cin>>s;
		if(s == "-1") goto calc;
		middle("结果",'=') ;
		middle(a(b(s)),' ') ;
	}else{
		middle("自检码计算",'=');
		cout<<"[当前位置]主菜单>自检校验码计算"<<endl;
		cout<<"输入 -1 返回"<<endl; 
		cout<<"键入手表显示的数字>>";
		string s;
		cin>>s;
		if(s == "-1") goto calc;
		string R1=c(s);
		middle("结果",'=') ;
		middle(d(R1),' ') ;
	}
	system("pause");
	return 0;
} 
