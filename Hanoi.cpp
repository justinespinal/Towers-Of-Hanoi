#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> t[3];//creates a vector of size 3, each index being a tower
	int close, far, candidate=1, move = 1;//Candidate being 1 as it is the first disc we are allowed to move
	int n;
	cout << "Enter the amount of discs: ";
	cin >> n;//Enters the amount of discs
	if(n%2==0)//If even go counter clock wise, if odd go clockwise!
	{
		close = 2;//The closest is tower two because we go counter
		far = 1;//farthest is tower 1
	}
	else
	{
		close = 1;//The closest is tower one because we go clockwise
		far = 2;//farthest is tower 2
	}
	int from=0, to = close;// we are moving from tower 0
	//close determines the next tower we move to
	for(int i = n+1; i>=1; --i)
	{
		t[0].push_back(i);//Fills the 0th tower with numbers 1->n+1, n+1 used as a filler
	}
	t[1].push_back(n+1);//n+1 used as a filler
	t[2].push_back(n+1);//n+1 used as a filler
	while(t[1].size()<n+1)//The program will continue running while the 1st Tower (B) has less then n+1 discs including n+1
	{
		cout << "Move #" << move++ << ": From Tower " << (char)(from+'A') << " to Tower " << (char)(to+'A') << endl;
		t[to].push_back(t[from].back());//puts the back of the prev tower to the next tower
		t[from].pop_back();//deletes back of prev tower
		if(t[(to+1)%3].back()<t[(to+2)%3].back())
		{
			from = (to+1)%3;
		}
		else
		{
			from = (to+2)%3;
		}
		candidate = t[from].back();//candidate becomes the back to the new from tower!
		//now we find the to since we established the from!
		if(t[(from+close)%3].back()<candidate)//
		{
			to = (from+far)%3;
		}
		else
		{
			to = (from +close)%3;
		}
	}
	return 0;
}
