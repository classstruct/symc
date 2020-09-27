#include"/storage/emulated/0/0/1/tao.h"
int main()
{
	char inputstr[200];
	cout<<"求导console，请输入关于x表达式:"<<endl;
    cin>>inputstr;
    char var[2]="x";
    funcs f1(inputstr,2,var);
    funcs f2=f1.singleder(var[0]);
    cout<<"derivative:"<<f2.show;
}
//可在tao.h中查找函数，当前支持求值，(多重)积分，(多重)导数，尚未支持不定积分