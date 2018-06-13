#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*

Finding of all combination to move on a 2D graph
Consider we are moving in 2D plane from 0,0 to 2,2

Any horizontal movement will be termed a H 
Any Vertical movement will be termed as V
Alwasy start point is 0,0

for example for the above program the possiblity are: in lexcogicla order
HHVV HVHV HVVH VHHV VHVH VVHH

give input 2 select the second route and publish


*/

bool myfunction (string s1, string s2){
	return(s1 == s2);
}
void permature( int low, int high , vector <string> &temp, string final_com){

    for ( int i= low ; i<(high); i++){
		std::swap(final_com[low], final_com[i]);
		temp.push_back(final_com);
		permature(low+1,high, temp,final_com);
		std::swap(final_com[i], final_com[low]);		
	}
}	
vector <string> permutation( long int total_possibilty, int x1, int y1, int path){
	vector <string> temp;
	cout <<"Total possibility " << total_possibilty <<endl;
	string hor = "";
	string ver = "";
	int i,j;
	for (i=0;i<x1; i++)
		hor = hor+ 'H';
	for (i=0;i<y1; i++)
		ver = ver+ 'V';
    string final_com = hor+ver;
	temp.push_back(final_com);
    permature (0,x1+y1,temp,final_com);
	sort (temp.begin(),temp.end());
	temp.erase(unique(temp.begin(),temp.end()),temp.end());
	for (i =0; i < total_possibilty; i++){
		cout << temp.at(i) <<endl;
	}
	vector <string> finalpath;
	finalpath.push_back(temp.at(path));
	return finalpath;
}
long int fact (int num){
	return ((num==1)? 1 : num *fact(num-1));
}

vector<string> path_find ( int x1, int y1,int path){
	vector <string> temp;
	cout << "factorial add" << fact(x1+y1) << "fact x1" << fact(x1) << "fact y1" << fact(y1)<<endl;
    long int total_possibilty= (fact (x1+y1))/(fact(x1) * fact(y1));
	temp = permutation(total_possibilty, x1, y1, path);
	return temp;
}

int main(){
	int x1=0,y1=0, path=0;
	cout << "Provide X value" <<endl;
	cin >> x1;
	cout << "Provide Y value" <<endl;
	cin >> y1;
	cout <<"Path you like : " <<endl;
	cin >> path;
    vector<string> temp=path_find(x1,y1,path);
	cout << "Choosend position"<< path <<"value is" <<temp.at(0) <<endl;
	return 0;
}
