#ifndef TAO_H
#define TAO_H
#include<cmath>
#include<ctype.h>
#include<iostream>
#include<string>
#include<sstream>
#define LEN 100
#define delta 0.1
#define STA 1					// 真全开始
#define END 2					// 真全结束
#define MENB1 3					// 假参数位1
#define MENB2 4					// 假参数位2
#define MSTA 5					// 符号头
#define MEND 6					// 符号尾
using namespace std;
const int kts[6] = { 82, 216, 27, 272, 27, 216 };

inline int compstr(int n, char a[], const char rt[]);
class funcs
{
  public:int va_cmp(char);
	double func(int);
	double value(double *);
	void pp(int, int, int);
	  funcs(char *, short, char *);
	  funcs();
	  funcs(const char *);
	  funcs(const double);
	double loop_n(short, double *, double *);
	funcs derivative(char *);
	funcs singleder(char);
	friend funcs operator +(const funcs &, const funcs &);
	friend funcs operator -(const funcs &, const funcs &);
	friend funcs operator *(const funcs &, const funcs &);
	friend funcs operator /(const funcs &, const funcs &);
	funcs acos(const funcs &);
	funcs acot(const funcs &);
	funcs acsc(const funcs &);
	funcs asec(const funcs &);
	funcs asin(const funcs &);
	funcs atan(const funcs &);
	funcs ch(const funcs &);
	funcs cos(const funcs &);
	funcs cot(const funcs &);
	funcs csc(const funcs &);
	funcs exp(const funcs &);
	funcs ln(const funcs &);
	funcs sec(const funcs &);
	funcs sh(const funcs &);
	funcs sin(const funcs &);
	funcs tan(const funcs &);
	funcs th(const funcs &);
	funcs operator-();
	funcs pow(const funcs &, const funcs &);
	short va_num;
	char variable[10];
	short n, t;					// n算式长度,t运算次数
	short order[10][7];
	short invorder[LEN];
	short loc[LEN][2];
	char show[LEN];
  private:short nas[LEN];
	short type[LEN];
	double val[LEN];
	char dig[LEN][10];
	short isud[LEN];
	double _value[10];

};
inline int compstr(int n, char a[], const char rt[])
{
	int b = 1;
	for (int i = n; i < n + strlen(rt); i++)
	{
		if (a[i] != rt[i - n])
			b = 0;
	}
	return b;
}

funcs::funcs()
{
}

funcs::funcs(const char *a)
{
	strcpy(show, a);
}

funcs::funcs(double a)
{
	string b;
	stringstream ss;
	ss << a;
	ss >> b;
	strcpy(show, b.c_str());
}

funcs operator +(const funcs & a, const funcs & b)
{
	funcs f;
	char *p = f.show;
	char const *pa = a.show;
	char const *pb = b.show;
	p[0] = '(';
	while (*++p = *pa++);
	*p = ')';
	*++p = '+';
	*++p = '(';
	while (*++p = *pb++);
	*p = ')';
	return f;
}

funcs operator -(const funcs & a, const funcs & b)
{
	funcs f;
	char *p = f.show;
	char const *pa = a.show;
	char const *pb = b.show;
	p[0] = '(';
	while (*++p = *pa++);
	*p = ')';
	*++p = '-';
	*++p = '(';
	while (*++p = *pb++);
	*p = ')';
	return f;
}

funcs operator *(const funcs & a, const funcs & b)
{
	funcs f;
	char *p = f.show;
	char const *pa = a.show;
	char const *pb = b.show;
	p[0] = '(';
	while (*++p = *pa++);
	*p = ')';
	*++p = '*';
	*++p = '(';
	while (*++p = *pb++);
	*p = ')';
	return f;
}

funcs operator /(const funcs & a, const funcs & b)
{
	funcs f;
	char *p = f.show;
	char const *pa = a.show;
	char const *pb = b.show;
	p[0] = '(';
	while (*++p = *pa++);
	*p = ')';
	*++p = '/';
	*++p = '(';
	while (*++p = *pb++);
	*p = ')';
	return f;
}

funcs funcs::acos(const funcs & a)
{
	funcs f;
	strcpy(f.show, "acos(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::acot(const funcs & a)
{
	funcs f;
	strcpy(f.show, "acot(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::acsc(const funcs & a)
{
	funcs f;
	strcpy(f.show, "acsc(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::asec(const funcs & a)
{
	funcs f;
	strcpy(f.show, "asec(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::asin(const funcs & a)
{
	funcs f;
	strcpy(f.show, "asin(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::atan(const funcs & a)
{
	funcs f;
	strcpy(f.show, "atan(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::ch(const funcs & a)
{
	funcs f;
	strcpy(f.show, "ch(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::cos(const funcs & a)
{
	funcs f;
	strcpy(f.show, "cos(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::cot(const funcs & a)
{
	funcs f;
	strcpy(f.show, "cot(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::csc(const funcs & a)
{
	funcs f;
	strcpy(f.show, "csc(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::exp(const funcs & a)
{
	funcs f;
	strcpy(f.show, "exp(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::ln(const funcs & a)
{
	funcs f;
	strcpy(f.show, "ln(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::sec(const funcs & a)
{
	funcs f;
	strcpy(f.show, "sec(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::sh(const funcs & a)
{
	funcs f;
	strcpy(f.show, "sh(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::sin(const funcs & a)
{
	funcs f;
	strcpy(f.show, "sin(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::tan(const funcs & a)
{
	funcs f;
	strcpy(f.show, "tan(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::th(const funcs & a)
{
	funcs f;
	strcpy(f.show, "th(");
	strcat(f.show, a.show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::operator-()
{
	funcs f;
	strcpy(f.show, "-(");
	strcat(f.show, show);
	strcat(f.show, ")");
	return f;
}

funcs funcs::pow(const funcs & a, const funcs & b)
{
	funcs f;
	char *p = f.show;
	char const *pa = a.show;
	char const *pb = b.show;
	p[0] = '(';
	while (*++p = *pa++);
	*p = ')';
	*++p = '^';
	*++p = '(';
	while (*++p = *pb++);
	*p = ')';
	return f;
}

funcs funcs::derivative(char a[])
{
	funcs f(show, va_num, variable);
	short i;
	for (i = 0; i < va_num; i++)
	{
		f = f.singleder(a[i]);
	}
	return f;
}

void strabcpy(char *a, char *b, int st, int en)
{
	int i = 0;
	while (1)
	{
		if (i + st <= en)
		{
			a[i] = b[i + st];
			i++;
		}
		else
			break;
	}
}

bool have(char *a, char b)
{
	bool c = 0;
	for (int i = 0; i < strlen(a); i++)
		if (a[i] == b)
			c = 1;
	return c;
}

funcs funcs::singleder(char a)
{
	char left[10], right[10];
	strabcpy(left, show, order[t - 1][STA], order[t - 1][MSTA] - 1);
	strabcpy(right, show, order[t - 1][MEND] + 1, order[t - 1][END]);
	funcs f1(left, va_num, variable);
	funcs f2(right, va_num, variable);
	funcs f;
	if (t)
		switch (nas[order[t - 1][0]])
		{
		case 1:
			f = -f2.singleder(a) / pow(1 - pow(f2, 2), -0.5);
			break;
		case 2:
			f = -f2.singleder(a) / (1 + pow(f2, 2));
			break;
		case 3:
			f = -f2.singleder(a) / f2 / pow(pow(f2, 2) - 1, 0.5);
			break;
		case 4:
			f = f2.singleder(a) / f2 / pow(pow(f2, 2) - 1, 0.5);
			break;
		case 5:
			f = f2.singleder(a) / pow(1 - pow(f2, 2), -0.5);
			break;
		case 6:
			f = f2.singleder(a) / (1 + pow(f2, 2));
			break;
		case 7:
			f = f2.singleder(a) * sh(f2);
			break;
		case 8:
			f = -f2.singleder(a) * sin(f2);
			break;
		case 9:
			f = -f2.singleder(a) * pow(csc(f2), 2);
			break;
		case 10:
			f = -f2.singleder(a) * csc(f2) * cot(f2);
			break;
		case 11:
			f = exp(f2) * f2.singleder(a);
			break;
		case 12:
			f = f2.singleder(a) / f2;
			break;
		case 13:
			f = f2.singleder(a) * sec(f2) * tan(f2);
			break;
		case 14:
			f = f2.singleder(a) * ch(f2);
			break;
		case 15:
			f = f2.singleder(a) * cos(f2);
			break;
		case 16:
			f = f2.singleder(a) * pow(sec(f2), 2);
			break;
		case 17:
			f = f2.singleder(a) / pow(ch(f2), 2);
		case 18:
			f = -f2.singleder(a);
		case 40:
			f = *this * (ln(f1) * f2.singleder(a) + f2 / f1 * f1.singleder(a));
			break;
		case 41:
			f = f1 * f2.singleder(a) + f1.singleder(a) * f2;
			break;
		case 42:
			f = (f1.singleder(a) * f2 - f2.singleder(a) * f1) / pow(f2, 2);
			break;
		case 43:
			f = f1.singleder(a) + f2.singleder(a);
			break;
		case 44:
			f = f1.singleder(a) - f2.singleder(a);
			break;

		}
	else if (have(show, a))
		strcpy(f.show, "1");
	else
		strcpy(f.show, "0");
	return f;
}

int funcs::va_cmp(char t)
{
	int i;
	for (i = 0; i < va_num; i++)
		if (t == variable[i])
			return i + 1;
	return 0;
}

double funcs::func(int i)
{
	double s, t, result;
	int w1, w2;
	w2 = order[invorder[i]][MENB2];
	w1 = order[invorder[i]][MENB1];
	s = val[w2];
	t = val[w1];
	switch (nas[i])
	{
	case 1:
		result =::acos(s);
		break;
	case 2:
		result =::atan(1 / s);
		break;
	case 3:
		result =::asin(1 / s);
		break;
	case 4:
		result =::acos(1 / s);
		break;
	case 5:
		result =::asin(s);
		break;
	case 6:
		result =::atan(s);
		break;
	case 7:
		result =::cosh(s);
		break;
	case 8:
		result =::cos(s);
		break;
	case 9:
		result = 1 /::tan(s);
		break;
	case 10:
		result = 1 /::sin(s);
		break;
	case 11:
		result =::exp(s);
		break;
	case 12:
		result =::log(s);
		break;
	case 13:
		result = 1 /::cos(s);
		break;
	case 14:
		result =::sinh(s);
		break;
	case 15:
		result =::sin(s);
		break;
	case 16:
		result =::tan(s);
		break;
	case 17:
		result =::tanh(s);
		break;
	case 18:
		result = -s;
		break;
	case 40:
		result =::pow(t, s);
		break;
	case 41:
		result = t * s;
		break;
	case 42:
		result = t / s;
		break;
	case 43:
		result = t + s;
		break;
	case 44:
		result = t - s;
	}
	isud[w2] = 2;
	if (type[i] == 3)
		isud[w1] = 2;
	return result;
}								// 逐步运算

double funcs::value(double x[])
{
	int i, j, s;
	for (i = 0; i <= n; i++)
	{
		if (type[i] == 1)
			isud[i] = 1;
		else if (type[i] == 5)
		{
			isud[i] = 1;
			for (j = 0; j < va_num; j++)
				if (nas[i] == 20 + j)
					val[i] = x[j];
		}
		else
			isud[i] = 0;
	}
	double res = val[1];
	for (i = 0; i < t; i++)
	{
		res = val[order[i][0]] = funcs::func(order[i][0]);
		isud[order[i][0]] = 1;
	}
	return res;
}								// 确定运算顺序并调用运算函数

void funcs::pp(int s, int i, int j)
{
	int p;
	order[t][0] = s;
	order[t][MSTA] = order[t][MEND] = loc[s][0];
	invorder[s] = t;
	isud[s] = 1;
	for (p = s + 1; p < i; p++)
		if (isud[p] == 1)
		{
			if (type[p] == 1 || type[p] == 5)
				order[t][END] = loc[p][1];
			else
				order[t][END] = order[invorder[p]][END];
			order[t][MENB2] = p;
			isud[p] = 2;
			break;
		}
	for (p = s - 1; p > j; p--)
		if (isud[p] == 1)
		{
			if (type[p] == 1 || type[p] == 5)
				order[t][STA] = loc[p][0];
			else
				order[t][STA] = order[invorder[p]][STA];
			order[t][MENB1] = p;
			isud[p] = 2;
			t++;
			break;
		}
}

funcs::funcs(char r[], short _va_num, char va[])
{
	va_num = _va_num;
	strcpy(variable, va);
	strcpy(show, "(");
	strcat(show, r);
	strcat(show, ")");
	n = 0;
	type[n] = 4;
	isud[n] = 0;
	loc[n][0] = loc[n][1] = 0;
	nas[n++] = 31;
	int i, j;
	for (i = 0; i < strlen(r);)
	{
		isud[n] = 0;
		loc[n][0] = i + 1;
		if (i)
		{
			if ((isdigit(r[i - 1]) || va_cmp(r[i - 1])) && (r[i] == '(' || islower(r[i])))
			{
				nas[n] = 41;
				type[n++] = 3;
			}
		}
		if (islower(r[i]) && va_cmp(r[i]) == 0)
		{
			if (compstr(i, r, "acos"))
			{
				nas[n] = 1;
				i += 4;
			}
			else if (compstr(i, r, "acot"))
			{
				nas[n] = 2;
				i += 4;
			}
			else if (compstr(i, r, "acsc"))
			{
				nas[n] = 3;
				i += 4;
			}
			else if (compstr(i, r, "asec"))
			{
				nas[n] = 4;
				i += 4;
			}
			else if (compstr(i, r, "asin"))
			{
				nas[n] = 5;
				i += 4;
			}
			else if (compstr(i, r, "atan"))
			{
				nas[n] = 6;
				i += 4;
			}
			else if (compstr(i, r, "ch"))
			{
				nas[n] = 7;
				i += 2;
			}
			else if (compstr(i, r, "cos"))
			{
				nas[n] = 8;
				i += 3;
			}
			else if (compstr(i, r, "cot"))
			{
				nas[n] = 9;
				i += 3;
			}
			else if (compstr(i, r, "csc"))
			{
				nas[n] = 10;
				i += 3;
			}
			else if (compstr(i, r, "exp"))
			{
				nas[n] = 11;
				i += 3;
			}
			else if (compstr(i, r, "ln"))
			{
				nas[n] = 12;
				i += 2;
			}
			else if (compstr(i, r, "sec"))
			{
				nas[n] = 13;
				i += 3;
			}
			else if (compstr(i, r, "sh"))
			{
				nas[n] = 14;
				i += 2;
			}
			else if (compstr(i, r, "sin"))
			{
				nas[n] = 15;
				i += 3;
			}
			else if (compstr(i, r, "tan"))
			{
				nas[n] = 16;
				i += 3;
			}
			else if (compstr(i, r, "th"))
			{
				nas[n] = 17;
				i += 2;
			}
			type[n] = 2;
		}
		else if (r[i] == '^')
		{
			nas[n] = 40;
			type[n] = 3;
			i++;
		}
		else if (r[i] == '*')
		{
			nas[n] = 41;
			type[n] = 3;
			i++;
		}
		else if (r[i] == '/')
		{
			nas[n] = 42;
			type[n] = 3;
			i++;
		}
		else if (r[i] == '+')
		{
			nas[n] = 43;
			type[n] = 3;
			i++;
		}
		else if (r[i] == '-' && (isdigit(r[i - 1]) || va_cmp(r[i - 1]) || r[i - 1] == ')'))
		{
			nas[n] = 44;
			type[n] = 3;
			i++;
		}
		else if (r[i] == '-')
		{
			nas[n] = 18;
			type[n] = 2;
			i++;
		}
		else if (r[i] == '(')
		{
			nas[n] = 31;
			type[n] = 4;
			i++;
		}
		else if (r[i] == ')')
		{
			nas[n] = 32;
			type[n] = 4;
			i++;
		}
		else if (isdigit(r[i]))
		{
			for (j = i; j <= strlen(r); j++)
			{
				if (isdigit(r[j]) == 0 && r[j] != '.')
				{
					i = j;
					break;
				}
				else
				{
					dig[n][j - i] = r[j];
				}
			}
			nas[n] = 10;
			type[n] = 1;
		}
		else if (r[i] == ' ')
		{
			i++;
			continue;
		}
		else if (r[i] == '\0')
			break;
		else if (va_cmp(r[i]))
		{
			nas[n] = 19 + va_cmp(r[i]);
			type[n] = 5;
			i++;
		}
		else
			printf("第%d个字符有误\a\n", ++i);
		loc[n][1] = i;
		val[n++] = 0;
	}
	type[n] = 4;
	nas[n] = 32;
	isud[n] = 0;
	for (i = 0; i <= n; i++)
	{
		int k = 0, m = 0, l, j;
		if (type[i] == 1)
		{
			isud[i] = 1;
			for (j = 0; j != strlen(dig[i]); j++)
			{
				if (dig[i][j] == '.')
				{
					k++;
					m = j + 1;
				}
			}
			if (k >= 2)
				printf("数字有误\a\n");
			else if (k == 0)
			{
				for (j = 0; j < strlen(dig[i]); j++)
					val[i] +=::pow(10, strlen(dig[i]) - 1 - j) * (dig[i][j] - 48);
			}
			else if (m == strlen(dig[i]))
				printf("数字末尾有小数点\n");
			else
			{
				for (j = 0; j < strlen(dig[i]); j++)
				{
					if (j < m - 1)
						val[i] +=::pow(10, m - 2 - j) * (dig[i][j] - 48);
					else if (j >= m)
						val[i] +=::pow(10, m - 1 - j) * (dig[i][j] - 48);
				}
			}
		}
		else if (type[i] == 5)
			isud[i] = 1;
	}

	short s;
	t = 0;
	for (i = 0; i <= n; i++)
	{
		if (nas[i] == 32)
		{
			for (j = i; j > -1; j--)
			{
				if (nas[j] == 31 && isud[j] == 0)
				{
					isud[j] = 2;
					break;
				}
			}
			for (s = i - 1; s > j; s--)
			{
				if (type[s] == 2 && isud[s] == 0)
				{
					order[t][0] = s;
					order[t][MSTA] = loc[s][0];
					order[t][MEND] = loc[s][1];
					order[t][STA] = loc[s][0];
					invorder[s] = t;
					isud[s] = 1;
					for (int p = s + 1; p < i; p++)
						if (isud[p] == 1)
						{
							if (type[p] == 1 || type[p] == 5)
								order[t][END] = loc[p][1];
							else
								order[t][END] = order[invorder[p]][END];
							order[t][MENB2] = p;
							isud[p] = 2;
							t++;
							break;
						}
				}
			}
			for (s = j - 1; s < i; s++)
			{
				if (nas[s] == 40 && isud[s] == 0)
				{
					pp(s, i, j);
				}
			}
			for (s = j - 1; s < i; s++)
			{
				if ((nas[s] == 41 || nas[s] == 42) && isud[s] == 0)
				{
					pp(s, i, j);
				}
			}
			for (s = j - 1; s < i; s++)
			{
				if ((nas[s] == 43 || nas[s] == 44) && isud[s] == 0)
				{
					pp(s, i, j);
				}
			}
		}
	}
}

double funcs::loop_n(short n, double start[], double end[])
{
	short i = 0;
	double s = 0;
	_value[n] = start[n];
	if (n != va_num - 1)
	{
		s = -41 * loop_n(n + 1, start, end);
		for (; start[n] < end[n] ? _value[n] < end[n] : _value[n] > end[n]; _value[n] += delta)
		{
			if (i > 5)
				i = 0;
			s += kts[i++] * loop_n(n + 1, start, end);
		}
		s += 41 * loop_n(n + 1, start, end);
	}
	else
	{
		s = -41 * value(_value);
		for (; start[n] < end[n] ? _value[n] < end[n] : _value[n] > end[n]; _value[n] += delta)
		{
			if (i > 5)
				i = 0;
			s += kts[i++] * value(_value);
		}
		s += 41 * value(_value);
	}
	return s * delta / 140;
}
#endif