#include"/storage/emulated/0/0/tao.h"
int main()
{
	char inputstr[200];
	cout<<"求导console，请输入关于x表达式:"<<endl;
    cin>>inputstr;
    cout<<"debug log:"<<endl;;
    char var[2]="x";
    funcs f1(inputstr,2,var);
    funcs f2=f1.singleder(var[0]);
    cout<<"derivative:"<<f2.show;
}