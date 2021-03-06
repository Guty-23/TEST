#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <tuple>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <stdio.h>
#include <valarray>

typedef long long tint;
typedef unsigned long long utint;
typedef long double ldouble; 


#define forn(i,n) for(tint i=0;i<(tint)(n); i++)
#define forsn(i,s,n) for(tint i=(s);i<(tint)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl



using namespace std;

const tint nmod = 1000000007; // o el primo que deseamos


void imprimirVector (vector<tint> v)
{
	if (!v.empty())
	{ 
		int p = v.size();
		cout << "[";
		forn(i,p-1)
			cout << v[i] << ",";
		cout << v[p-1] << "]" << endl;
	}
	else
		cout << "[]" << endl;
}

tint toNumber (string s)
{
	tint Number;
	if ( ! (istringstream(s) >> Number) )
		Number = 0; // el string vacio lo manda al cero
	return Number;
}

string toString (tint number)
{    
    ostringstream ostr;
    ostr << number;
    return  ostr.str();
}

tint potLogMod (tint x, tint y) // Calcula: (x^y) mod nmod
{
	tint ans = 1;
	while (y > 0)
	{
		if (y % 2)
			ans = (x * ans) % nmod;
		x = (x * x) % nmod;
		y /= 2;
	}
	return ans;
}

tint invMod(tint a) // Solo funciona si nmod es primo y devuelve un numero b tal que: (a*b) = 1 mod nmod 
{
	return potLogMod(a,nmod-2);
}

tint mod(tint a)
{
	return ((a % nmod) + nmod) % nmod;
}


int main()
{
	#ifdef ACMTUYO
		assert(freopen("entrada.in", "r", stdin));
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	tint a,b,n,x;
	while (cin >> a >> b >> n >> x)
	{
		if (a == 1)
			cout << mod(x + mod(mod(b)*mod(n))) << "\n";
		else
			cout << mod(mod(potLogMod(a,n)*x) + mod(mod(b *(potLogMod(a,n) - 1)) * invMod(a-1))) << "\n";
	}
		
	return 0;
}


