#include "FString.h"
using namespace std;

int main() 
{
	 FString a("Hello");
	 a += a + a + a;
	 cout << ("Xin chao " + a + FString(" world")).substr(0, 100).size();
	 return 1;
}