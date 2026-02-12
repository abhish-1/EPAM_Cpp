#include<iostream>
#include<list>
using namespace std;
class YT{
	int subs;
	string name;
	public:
	

		YT(int s, string n){
			subs = s;
			name = n;
		}
		friend ostream& operator<<(ostream& COUT, const YT& yt){
			COUT<<"Name is "<<yt.name<<" and subs are "<<yt.subs<<endl;
			return COUT;
		}
};
class MyCollection{
	list<YT> myList;
	public:
	
		void operator+=(YT &yt){
			myList.push_back(yt);
		}
		friend void operator<<(ostream &COUT, MyCollection &myCollection){
			for(YT yt: myCollection.myList){
				COUT<<yt;
			}
		}
	};

int main() {
	YT yt1(1000, "CodeWithHarry");
	YT yt2(2000, "CodeWithHarry2");
	cout<<yt1;
	MyCollection myCollection;
	myCollection+=yt1;	
	myCollection+=yt2;
	cout<<"Successfully added to collection"<<endl; 
	cout<<myCollection;
	cout<<"hi";
	return 0;
	
}