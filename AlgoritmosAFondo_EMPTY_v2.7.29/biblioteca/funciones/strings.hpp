#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <string>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

// Length of a string
inline int length(const std::string& s){return static_cast<int>(s.size());}

// Count occurrences of a character
inline int charCount(const std::string& s,char c){int cnt=0;for(char ch:s) if(ch==c)++cnt;return cnt;}

// Substring from d to h (exclusive)
inline std::string substring(const std::string& s,int d,int h){if(d<0)d=0;if(h>static_cast<int>(s.size()))h=s.size();if(d>=h)return"";return s.substr(d,h-d);}
// Substring from d to end
inline std::string substring(const std::string& s,int d){if(d<0)d=0;if(d>=(int)s.size())return"";return s.substr(d);}

// Find first index of a character
inline int indexOf(const std::string& s,char c){size_t p=s.find(c);return p==std::string::npos?-1:static_cast<int>(p);} 

// Find first index of a character starting from offset
inline int indexOf(const std::string& s,char c,int offset){ if(offset<0)offset=0; size_t p=s.find(c,static_cast<size_t>(offset)); return p==std::string::npos?-1:static_cast<int>(p);} 

// Find first index of a substring
inline int indexOf(const std::string& s,const std::string& toSearch){size_t p=s.find(toSearch);return p==std::string::npos?-1:static_cast<int>(p);} 

// Find first index of a substring starting from offset
inline int indexOf(const std::string& s,const std::string& toSearch,int offset){ if(offset<0)offset=0; size_t p=s.find(toSearch,static_cast<size_t>(offset)); return p==std::string::npos?-1:static_cast<int>(p);} 

// Find last index of a character
inline int lastIndexOf(const std::string& s,char c){size_t p=s.rfind(c);return p==std::string::npos?-1:static_cast<int>(p);} 

// Find n‑th occurrence of a character
inline int indexOfN(const std::string& s,char c,int n){if(n<=0)return-1;int count=0;for(size_t i=0;i<s.size();++i){if(s[i]==c){++count;if(count==n)return static_cast<int>(i);}}return-1;} 

// Character to integer conversion (base 36)
inline int charToInt(char c){if(c>='0'&&c<='9')return c-'0';if(c>='A'&&c<='Z')return c-'A'+10;if(c>='a'&&c<='z')return c-'a'+10;return-1;} 
inline char intToChar(int i){if(i>=0&&i<=9)return '0'+i;if(i>=10&&i<=35)return 'A'+(i-10);return '\0';} 

// Return digit at position i (0‑based from right)
inline int getDigit(int n,int i){if(i<0)return-1; long long m=(n<0)?-(long long)n:(long long)n;for(int d=0;d<i;++d){if(m<10)return-1;m/=10;}return(int)(m%10);}
inline int digitCount(int n){if(n==0)return 1;int cnt=0;while(n){++cnt;n/=10;}return cnt;} 

// Integer to string
inline std::string intToString(int i){return std::to_string(i);} 

// String to integer (given base)
inline int stringToInt(const std::string& s,int b){try{return std::stoi(s,nullptr,b);}catch(...){return 0;}}
// String to integer (base 10)
inline int stringToInt(const std::string& s){try{return std::stoi(s);}catch(...){return 0;}} 

// char to string
inline std::string charToString(char c){return std::string(1,c);} 
inline char stringToChar(const std::string& s){return s.empty()?'\0':s[0];} 
inline std::string stringToString(const std::string& s){return s;} 
inline std::string doubleToString(double d){char buf[64];std::snprintf(buf,sizeof(buf),"%g",d);return buf;} 
inline double stringToDouble(const std::string& s){try{return std::stod(s);}catch(...){return 0.0;}} 

inline bool isEmpty(const std::string& s){return s.empty();}
inline bool startsWith(const std::string& s,const std::string& pre){return s.size()>=pre.size()&&s.compare(0,pre.size(),pre)==0;}
inline bool endsWith(const std::string& s,const std::string& suf){if(suf.size()>s.size())return false;return s.compare(s.size()-suf.size(),std::string::npos,suf)==0;}
inline bool contains(const std::string& s,char c){return s.find(c)!=std::string::npos;}
inline std::string replace(const std::string& s,char oldC,char newC){std::string r=s;for(char& ch:r)if(ch==oldC)ch=newC;return r;}
inline std::string insertAt(const std::string& s,int pos,char c){if(pos<0)pos=0;if(pos>static_cast<int>(s.size()))pos=s.size();return s.substr(0,pos)+std::string(1,c)+s.substr(pos);}
inline std::string removeAt(const std::string& s,int pos){if(pos<0||pos>=static_cast<int>(s.size()))return s;return s.substr(0,pos)+s.substr(pos+1);}
inline std::string ltrim(const std::string& s){size_t i=0;while(i<s.size()&&std::isspace(static_cast<unsigned char>(s[i])))++i;return s.substr(i);}
inline std::string rtrim(const std::string& s){size_t i=s.size();while(i&&std::isspace(static_cast<unsigned char>(s[i-1])))--i;return s.substr(0,i);}
inline std::string trim(const std::string& s){return rtrim(ltrim(s));}
inline std::string replicate(char c,int n){if(n<=0)return"";return std::string(static_cast<size_t>(n),c);}
inline std::string spaces(int n){return replicate(' ',n);} 
inline std::string lpad(const std::string& s,int n,char c){int pad=n-(int)s.size();return(pad>0?replicate(c,pad):"")+s;}
inline std::string rpad(const std::string& s,int n,char c){int pad=n-(int)s.size();return s+(pad>0?replicate(c,pad):"");}
inline std::string cpad(const std::string& s,int n,char c){int total=n-(int)s.size();if(total<=0)return s;int left=total/2;return replicate(c,left)+s+replicate(c,total-left);}

inline bool isDigit(char c){return std::isdigit(static_cast<unsigned char>(c));}
inline bool isLetter(char c){return std::isalpha(static_cast<unsigned char>(c));}
inline bool isUpperCase(char c){return std::isupper(static_cast<unsigned char>(c));}
inline bool isLowerCase(char c){return std::islower(static_cast<unsigned char>(c));}
inline char toUpperCase(char c){return std::toupper(static_cast<unsigned char>(c));}
inline char toLowerCase(char c){return std::tolower(static_cast<unsigned char>(c));}
inline std::string toUpperCase(const std::string& s){std::string r=s;std::transform(r.begin(),r.end(),r.begin(),::toupper);return r;}
inline std::string toLowerCase(const std::string& s){std::string r=s;std::transform(r.begin(),r.end(),r.begin(),::tolower);return r;}
inline int cmpString(const std::string& a,const std::string& b){return a.compare(b);} 
inline int cmpDouble(double a,double b){return (a>b)-(a<b);}

inline char* stringToCString(const std::string& s){char* ret=new char[s.size()+1];std::copy(s.begin(),s.end(),ret);ret[s.size()]='\0';return ret;} 
inline std::string cStringToString(const char c[]){return std::string(c);} 

#endif // _TSTRINGS_T_