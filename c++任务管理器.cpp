//2024.4.12,中文版
#include <iostream>
#include <cstdlib>
#include <string>
void sys(const std::string& com) {
    system(com.c_str());
}
void out(const std::string& a) {
    std::cout << a << std::endl;
}
void out2(const std::string& a) {
    std::cout << a ;
}
void pau() {
	sys("pause");
}
void wel(){
	sys("title 任务管理器");
	out("欢迎使用定制版任务管理器");
    out("多次输入顺序均为:进程名称-参数");
    out("按任意键开始使用");
    pau();
    system("cls");
}
int doTaskManager() {
	while(true){
	sys("ver");
	out("程序版本:1.0");
	out("当前位置:主菜单");
	out("1=>停止进程");
    out("2=>运行文件");
    out("3=>列出进程");
    out("4=>电源菜单");
    out("5=>自定义指令");
    out("6=>设置背景色");
    out("7=>任务管理器");
    out("8=>启动记事本");
    out("9=>退出");
    out("输入选择并回车");
    int chose;
    out2("键入选择>>");
    std::cin >> chose;
    if (chose == 0) {
    	sys("cls");
		continue;
	}
	if (chose == 1) {
        std::string task_name;
        out2("进程名称>>");
        std::cin >> task_name;
        sys("taskkill /im " + task_name);
    } else if (chose == 2) {
        std::string task_name;
        out2("文件路径>>");
        std::cin >> task_name;
        sys("start " + task_name);
    } else if (chose == 3) {
        sys("tasklist");
    } else if (chose == 4) {
        out("当前位置:主菜单->电源菜单"); 
		out("电源菜单");
		out("1=>关机");
        out("2=>重启");
        out("3=>注销");
        out("0=>返回");
        out2(">>");
        int chose_power;
        std::cin >> chose_power;
        if (chose_power == 1) {
            sys("shutdown -s -t 0");
        } else if (chose_power == 2) {
            sys("shutdown -r -t 0");
        } else if (chose_power == 3) {
            sys("shutdown -l");
        } else {
        	out("按任意键返回");
        	chose=0;
		}
    } else if (chose == 5) {
        std::string task_name;
        out2("输入指令>>");
        std::cin >> task_name;
        sys(task_name);
    } else if (chose == 6) {
    	std::string task_name;
    	sys("cls");
		sys("color -help");
		out2("键入颜色:");
		std::cin >> task_name;
    	sys("color " + task_name);
	} else if(chose == 9) {
		return 0;
	} else if(chose == 7) {
		sys("start taskmgr.exe");
	} else if(chose == 8) {
		sys("notepad.exe");
	}else{
    	sys("cls");
		out("无效输入");
	}
	pau();
	sys("cls");
    }
}
int main() {
    wel();
	doTaskManager();
}
