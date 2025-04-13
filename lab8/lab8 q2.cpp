#include<iostream>
#include<string>
using namespace std;

class Runs{
	int r;
	public:
		Runs(float r):r(r){};
		friend class StrikeRate;
};

class BallsFaced{
	int bf;
	public:
		BallsFaced(float bf):bf(bf){};
		friend class StrikeRate;
};

class StrikeRate{
	int sr;
	public:
		int getStrikeRate(const Runs &r, const BallsFaced &bf){
			return sr=(r.r /bf.bf)*100;
		}
};

int main(){
	Runs r(60);
	BallsFaced bf(30);
	StrikeRate sr;
	cout<<"Strike Rate: "<<sr.getStrikeRate(r,bf);
}