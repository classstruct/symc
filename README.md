# symc
c c++的形式运算
当前 0.9.4.7版本
修复无法添加乘号，但出现未知原因问题：930-931删去以后segfault，然而该两行仅有输出信息作用，可能是编译器问题。

展望未来：修复输入为sin2x时出的错误，求导结果按程序，其值应为sin2。
        修复删去930-931的未知bug
        识别多余括号并删去，增加最低优先级识别以避免多余括号
        识别0乘，1乘，0加，正负抵消，相倒抵消,估计是用辅助性正则表达式。
        不定积分：尚无思路。
        使用c重写：正在进行；使用cpp重写使代码更易懂和调试：正在进行。
欢迎加入。
        
©classstruct 2019-2020.联系qq 0x820db1ac 进行交流

