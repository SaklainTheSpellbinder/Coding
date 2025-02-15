#include<stdio.h>
main(){
int f = 90;
int *fp = &f;
const int con = 32;  // 🔹 `con` is a constant integer
const int *conp;     // 🔹 `conp` is a pointer to a constant integer

printf("%d ", *fp);  // ✅ Prints 90
fp = &con; 
conp=&con;          // ⚠️ Warning: discards 'const' qualifier
*fp = 70;  
// *conp=80;          // ❌ Undefined behavior: trying to modify a constant

printf("%d %d", *fp, con);
}